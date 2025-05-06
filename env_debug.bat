set PHPRC=%CD%\php_debug.ini
set PATH=%CD%\..\..\SDK\php-sdk-binary-tools\phpdev\vs16\x86\php-8.1.31-sources\Debug_TS;%PATH%
#set USE_ZEND_ALLOC=0
set ZEND_DONT_UNLOAD_MODULES=1

start "Glide debug" /D %CD% cmd.exe /K