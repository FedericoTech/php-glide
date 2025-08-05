--TEST--
grTexCalcMemRequired
--FILE--
<?php
grGlideInit();

foreach(GrAspectRatio_t::cases() as $grAspectRatio_t) {
    foreach (GrLOD_t::cases() as $grLOD_t_a) {
        foreach (GrLOD_t::cases() as $grLOD_t_b) {

            $amount = grTexCalcMemRequired(
                $grLOD_t_b,
                $grLOD_t_a,
                $grAspectRatio_t,
                GrTextureFormat_t::GR_TEXFMT_16BIT
            );

            echo "$grAspectRatio_t->name, s: $grLOD_t_b->name, l: $grLOD_t_a->name: amount: $amount\n";
        }
        echo PHP_EOL;
    }
}

grGlideShutdown();
?>
--EXPECT--
GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_256: amount: 16384
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_256: amount: 20480
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_256: amount: 21504
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_256: amount: 21760
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_256: amount: 21824
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_256: amount: 21840
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_256: amount: 21848
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_256: amount: 21856
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_256: amount: 21856

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_128: amount: 4096
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_128: amount: 5120
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_128: amount: 5376
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_128: amount: 5440
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_128: amount: 5456
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_128: amount: 5464
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_128: amount: 5472
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_128: amount: 5472

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_64: amount: 1024
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_64: amount: 1280
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_64: amount: 1344
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_64: amount: 1360
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_64: amount: 1368
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_64: amount: 1376
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_64: amount: 1376

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_32: amount: 256
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_32: amount: 320
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_32: amount: 336
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_32: amount: 344
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_32: amount: 352
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_32: amount: 352

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_16: amount: 64
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_16: amount: 80
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_16: amount: 88
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_16: amount: 96
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_16: amount: 96

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_8: amount: 16
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_8: amount: 24
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_8: amount: 32
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_8: amount: 32

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_4: amount: 8
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_4: amount: 16
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_4: amount: 16

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_8x1, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_8x1, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_256: amount: 32768
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_256: amount: 40960
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_256: amount: 43008
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_256: amount: 43520
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_256: amount: 43648
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_256: amount: 43680
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_256: amount: 43688
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_256: amount: 43696
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_256: amount: 43696

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_128: amount: 8192
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_128: amount: 10240
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_128: amount: 10752
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_128: amount: 10880
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_128: amount: 10912
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_128: amount: 10920
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_128: amount: 10928
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_128: amount: 10928

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_64: amount: 2048
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_64: amount: 2560
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_64: amount: 2688
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_64: amount: 2720
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_64: amount: 2728
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_64: amount: 2736
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_64: amount: 2736

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_32: amount: 512
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_32: amount: 640
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_32: amount: 672
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_32: amount: 680
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_32: amount: 688
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_32: amount: 688

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_16: amount: 128
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_16: amount: 160
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_16: amount: 168
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_16: amount: 176
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_16: amount: 176

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_8: amount: 32
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_8: amount: 40
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_8: amount: 48
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_8: amount: 48

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_4: amount: 8
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_4: amount: 16
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_4: amount: 16

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_4x1, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_4x1, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_256: amount: 65536
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_256: amount: 81920
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_256: amount: 86016
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_256: amount: 87040
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_256: amount: 87296
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_256: amount: 87360
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_256: amount: 87376
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_256: amount: 87384
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_256: amount: 87384

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_128: amount: 16384
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_128: amount: 20480
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_128: amount: 21504
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_128: amount: 21760
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_128: amount: 21824
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_128: amount: 21840
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_128: amount: 21848
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_128: amount: 21848

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_64: amount: 4096
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_64: amount: 5120
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_64: amount: 5376
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_64: amount: 5440
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_64: amount: 5456
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_64: amount: 5464
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_64: amount: 5464

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_32: amount: 1024
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_32: amount: 1280
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_32: amount: 1344
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_32: amount: 1360
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_32: amount: 1368
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_32: amount: 1368

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_16: amount: 256
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_16: amount: 320
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_16: amount: 336
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_16: amount: 344
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_16: amount: 344

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_8: amount: 64
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_8: amount: 80
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_8: amount: 88
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_8: amount: 88

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_4: amount: 16
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_4: amount: 24
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_4: amount: 24

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_2x1, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_2x1, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_256: amount: 131072
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_256: amount: 163840
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_256: amount: 172032
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_256: amount: 174080
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_256: amount: 174592
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_256: amount: 174720
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_256: amount: 174752
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_256: amount: 174760
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_256: amount: 174768

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_128: amount: 32768
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_128: amount: 40960
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_128: amount: 43008
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_128: amount: 43520
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_128: amount: 43648
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_128: amount: 43680
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_128: amount: 43688
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_128: amount: 43696

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_64: amount: 8192
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_64: amount: 10240
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_64: amount: 10752
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_64: amount: 10880
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_64: amount: 10912
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_64: amount: 10920
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_64: amount: 10928

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_32: amount: 2048
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_32: amount: 2560
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_32: amount: 2688
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_32: amount: 2720
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_32: amount: 2728
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_32: amount: 2736

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_16: amount: 512
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_16: amount: 640
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_16: amount: 672
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_16: amount: 680
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_16: amount: 688

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_8: amount: 128
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_8: amount: 160
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_8: amount: 168
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_8: amount: 176

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_4: amount: 32
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_4: amount: 40
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_4: amount: 48

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_2: amount: 16

GR_ASPECT_1x1, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_1x1, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_256: amount: 65536
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_256: amount: 81920
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_256: amount: 86016
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_256: amount: 87040
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_256: amount: 87296
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_256: amount: 87360
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_256: amount: 87376
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_256: amount: 87384
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_256: amount: 87384

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_128: amount: 16384
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_128: amount: 20480
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_128: amount: 21504
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_128: amount: 21760
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_128: amount: 21824
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_128: amount: 21840
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_128: amount: 21848
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_128: amount: 21848

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_64: amount: 4096
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_64: amount: 5120
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_64: amount: 5376
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_64: amount: 5440
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_64: amount: 5456
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_64: amount: 5464
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_64: amount: 5464

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_32: amount: 1024
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_32: amount: 1280
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_32: amount: 1344
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_32: amount: 1360
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_32: amount: 1368
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_32: amount: 1368

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_16: amount: 256
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_16: amount: 320
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_16: amount: 336
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_16: amount: 344
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_16: amount: 344

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_8: amount: 64
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_8: amount: 80
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_8: amount: 88
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_8: amount: 88

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_4: amount: 16
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_4: amount: 24
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_4: amount: 24

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_1x2, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_1x2, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_256: amount: 32768
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_256: amount: 40960
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_256: amount: 43008
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_256: amount: 43520
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_256: amount: 43648
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_256: amount: 43680
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_256: amount: 43688
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_256: amount: 43696
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_256: amount: 43696

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_128: amount: 8192
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_128: amount: 10240
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_128: amount: 10752
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_128: amount: 10880
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_128: amount: 10912
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_128: amount: 10920
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_128: amount: 10928
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_128: amount: 10928

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_64: amount: 2048
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_64: amount: 2560
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_64: amount: 2688
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_64: amount: 2720
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_64: amount: 2728
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_64: amount: 2736
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_64: amount: 2736

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_32: amount: 512
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_32: amount: 640
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_32: amount: 672
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_32: amount: 680
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_32: amount: 688
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_32: amount: 688

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_16: amount: 128
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_16: amount: 160
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_16: amount: 168
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_16: amount: 176
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_16: amount: 176

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_8: amount: 32
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_8: amount: 40
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_8: amount: 48
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_8: amount: 48

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_4: amount: 8
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_4: amount: 16
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_4: amount: 16

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_1x4, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_1x4, s: GR_LOD_1, l: GR_LOD_1: amount: 8

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_256: amount: 16384
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_256: amount: 20480
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_256: amount: 21504
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_256: amount: 21760
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_256: amount: 21824
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_256: amount: 21840
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_256: amount: 21848
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_256: amount: 21856
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_256: amount: 21856

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_128: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_128: amount: 4096
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_128: amount: 5120
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_128: amount: 5376
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_128: amount: 5440
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_128: amount: 5456
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_128: amount: 5464
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_128: amount: 5472
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_128: amount: 5472

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_64: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_64: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_64: amount: 1024
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_64: amount: 1280
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_64: amount: 1344
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_64: amount: 1360
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_64: amount: 1368
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_64: amount: 1376
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_64: amount: 1376

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_32: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_32: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_32: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_32: amount: 256
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_32: amount: 320
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_32: amount: 336
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_32: amount: 344
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_32: amount: 352
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_32: amount: 352

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_16: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_16: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_16: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_16: amount: 0
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_16: amount: 64
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_16: amount: 80
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_16: amount: 88
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_16: amount: 96
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_16: amount: 96

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_8: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_8: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_8: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_8: amount: 0
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_8: amount: 0
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_8: amount: 16
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_8: amount: 24
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_8: amount: 32
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_8: amount: 32

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_4: amount: 0
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_4: amount: 8
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_4: amount: 16
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_4: amount: 16

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_2: amount: 0
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_2: amount: 8
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_2: amount: 8

GR_ASPECT_1x8, s: GR_LOD_256, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_128, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_64, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_32, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_16, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_8, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_4, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_2, l: GR_LOD_1: amount: 0
GR_ASPECT_1x8, s: GR_LOD_1, l: GR_LOD_1: amount: 8