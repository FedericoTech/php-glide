<?php

class ObjParser {
    public array $vertices = [];   // [[x,y,z], ...]
    public array $texcoords = [];  // [[u,v,(w)], ...]
    public array $normals = [];    // [[nx,ny,nz], ...]
    public array $faces = [];      // [[ [v,vt,vn], ... ], ...]

    public function load(string $filename): void {
        $lines = file($filename, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

        foreach ($lines as $line) {
            $line = trim($line);
            if ($line === '' || $line[0] === '#') {
                continue; // skip comments / blanks
            }

            $parts = preg_split('/\s+/', $line);
            $type = array_shift($parts);

            switch ($type) {
                case 'v':  // vertex
                    $this->vertices[] = array_map('floatval', $parts);
                    break;

                case 'vt': // texcoord
                    $this->texcoords[] = array_map('floatval', $parts);
                    break;

                case 'vn': // normal
                    $this->normals[] = array_map('floatval', $parts);
                    break;

                case 'f':  // face
                    $face = [];
                    foreach ($parts as $p) {
                        $indices = explode('/', $p);

                        $v  = $indices[0] !== '' ? $this->resolveIndex((int)$indices[0], count($this->vertices)) : null;
                        $vt = (isset($indices[1]) && $indices[1] !== '') ? $this->resolveIndex((int)$indices[1], count($this->texcoords)) : null;
                        $vn = (isset($indices[2]) && $indices[2] !== '') ? $this->resolveIndex((int)$indices[2], count($this->normals)) : null;

                        $face[] = ['v' => $v, 'vt' => $vt, 'n' => $vn];
                    }
                    $this->faces[] = $face;
                    break;

                // ignore other keywords (o, g, usemtl, mtllib, etc.)
            }
        }
    }

    private function resolveIndex(int $i, int $count): int {
        if ($i > 0) {
            return $i - 1;          // OBJ is 1-based
        }
        return $count + $i;         // Negative indices are relative
    }
}

function normalize(array $v): array
{
    $len = sqrt($v[0]**2 + $v[1]**2 + $v[2]**2);
    return $len > 0 ? [$v[0]/$len, $v[1]/$len, $v[2]/$len] : [0,0,0];
}

function dot(array $a, array $b): float
{
    return $a[0]*$b[0] + $a[1]*$b[1] + $a[2]*$b[2];
}

function shade(array $normal, array $light, array $baseColor): array
{
    $n = normalize($normal);
    $l = normalize($light);

    $intensity = max(0, dot($n, $l));

    return [
        $baseColor[0] * $intensity,
        $baseColor[1] * $intensity,
        $baseColor[2] * $intensity
    ];
}

function rotate_point(GrVertex $point, float $angle_rad, $origin = null)
{
	if ($origin === null) {
		$origin = new GrVertex;
		$origin->x = 0.0;
		$origin->y = 0.0;
    }

    $sin = sin($angle_rad);
    $cos = cos($angle_rad);

    // Translate point back to origin
    $x = $point->x - $origin->x;
    $y = $point->y - $origin->y;

    // Rotate
    $x_new = $x * $cos - $y * $sin;
    $y_new = $x * $sin + $y * $cos;
	
	$new = clone $point;
	//$new = new GrVertex;
	
	$new->x = $x_new + $origin->x;
	$new->y = $y_new + $origin->y;

    // Translate back
    return $new;
}

function rotateX(GrVertex $v, float $angle) : GrVertex
{
    $r = clone $v;
    $s = sin($angle);
    $c = cos($angle);

    $v->y = $r->y * $c - $r->z * $s;
    $v->z = $r->y * $s + $r->z * $c;
    return $v;
}

function rotateY(GrVertex $v, float $angle) : GrVertex
{
    $r = clone $v;
	
    $s = sin($angle);
    $c = cos($angle);
    $v->x = $r->x * $c - $r->z * $s;
   
    $v->z = $r->x * $s + $r->z * $c;
    return $v;
}

function rotateZ(GrVertex $v, float $angle) : GrVertex
{
    $r = clone $v;
    $s = sin($angle);
    $c = cos($angle);

    $v->x = $r->x * $c - $r->y * $s;
    $v->y = $r->x * $s + $r->y * $c;
    return $v;
}

/**
 * @param GrVertex $v
 * @param float $fov    Field of View
 * @param float $aspect Aspect ratio of the viewport (width / height).
 * @param float $nearZ
 * @return GrVertex
 */
function project(GrVertex $v, float $fov, float $aspect, float $nearZ) : GrVertex
{
    $scale = 1.0 / ($v->z + $nearZ);
    $v->x *= $scale * $fov * $aspect;
    $v->y *= $scale * $fov;
	$v->oow = $scale;
	return $v;
}

//this handler is to gracefully close the script when CTRL+C
function ctrl_handler(int $event)
{
    switch ($event) {
        case PHP_WINDOWS_EVENT_CTRL_C:
            grGlideShutdown();
			exit();
            break;
        case PHP_WINDOWS_EVENT_CTRL_BREAK:
            echo "You have pressed CTRL+BREAK\n";
            break;
    }
}

sapi_windows_set_ctrl_handler('ctrl_handler');

grGlideInit();

grErrorSetCallback(function($message, $fatal){
	var_dump($message, $fatal);
});

$hwConfig = new GrHwConfiguration;

if(!grSstQueryBoards($hwConfig)){
    echo 'ERROR: grSstQueryBoards din\'t work!' . PHP_EOL;
    grGlideShutdown();
}

echo "$hwConfig->num_sst boards\n";

$hwConfig = new GrHwConfiguration;


if(!grSstQueryHardware($hwConfig)){
	echo 'ERROR: grSstQueryHardware din\'t work!' . PHP_EOL;
	grGlideShutdown();
}

if(!$hwConfig->num_sst){
	echo 'ERROR: no 3Dfx Interactive Graphics Accelerator!' . PHP_EOL;
	grGlideShutdown();
	return -1;
}

switch($hwConfig->SSTs[0]->type){
	case GrSstType::GR_SSTTYPE_VOODOO:
		echo 'hardware Voodoo 1 (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_SST96:
		echo 'hardware Voodoo rush (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_AT3D:
		echo 'hardware Voodoo rush AT3D (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_Voodoo2:
		echo 'hardware Voodoo 2 (glide 2)' . PHP_EOL;
		break;
	default:
		echo "hardware unknown type: {$hwConfig->SSTs[0]->type->toInt()} (glide 2)\n";
		break;
}

$height = grSstScreenHeight();
$width = grSstScreenWidth();

echo "resolution: $height x $width\n";

// Select SST 0 and open up the hardware
grSstSelect(0);

if(!grSstWinOpen(
	null,									// hWin cast to FxU32 or null if console app or Voodoo 1 or full screen.
	GrScreenResolution_t::GR_RESOLUTION_640x480,	// screen resolution
	GrScreenRefresh_t::GR_REFRESH_60Hz,				// refresh rate
	GrColorFormat_t::GR_COLORFORMAT_ABGR,							// color format
	GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT,							// origin location
	2,												// number of buffers
	0												// number of aux buffers
)) {
    printf("ERROR: failed to open graphics context! (glide 2)\n");
    grGlideShutdown();
    return -1;
};

