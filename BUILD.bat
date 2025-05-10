echo hello batch files
MD ..\IMG2
MD ..\IMG2\Program Files (x86)
MD ..\IMG2\System
cd boot
CALL BUILD.bat
copy BOOT.bin ..\..\IMG2
cd ..
cd Zarya\core
CALL BUILD.bat
copy KERNEL.MNT ..\..\..\IMG2
pause
