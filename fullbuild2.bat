call c:\opt\ros\foxy\x64\setup.bat

cd C:\QR_Sync\QR_Core 
call ourcolcon.bat
call oursource.bat

cd ../ros2_template2/IF
cd presetup
rd /s /q "build"
colcon build
cd ..
call ourcolcon.bat
call oursource.bat



cd ..
cd presetup
rd /s /q "build"
colcon build
cd ..
call ourcolcon.bat
call oursource.bat

C:\Qt\Tools\QtCreator\bin\qtcreator.exe
 
