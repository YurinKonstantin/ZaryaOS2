MD ..\IMG2
tools\pathcopy2.exe create ..\Zaray.img 1474560
cd boot
CALL BUILD.bat
copy BOOT.bin ..\..\IMG2
cd ..
tools\pathcopy2.exe copypart ..\IMG2\BOOT.bin 0 0 ..\Zaray.img 0
cd Zarya\core
CALL BUILD.bat
copy KERNEL.MNT ..\..\..\IMG2
cd ..
cd baseApp
CALL BUILD.bat
pause
