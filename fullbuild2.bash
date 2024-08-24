#!/bin/bash

source /home/user/ros2_foxy/ros2-linux/setup.bash
source /opt/ros/foxy/setup.bash

cd /home/user/QR_Sync/QR_Core
rm -r build
chmod +x ./ourcolcon.bash
chmod +x ./oursource.bash
bash ./ourcolcon.bash
source ./oursource.bash

cd ../ros2_template2/IF
cd presetup
rm -r build
colcon build
cd ..
chmod +x ./ourcolcon.bash
chmod +x ./oursource.bash
bash ./ourcolcon.bash
source ./oursource.bash



cd ..
cd presetup
rm -r build
colcon build
cd ..
chmod +x ./ourcolcon.bash
chmod +x ./oursource.bash
bash ./ourcolcon.bash
source ./oursource.bash

/home/user/Qt/Tools/QtCreator/bin/qtcreator &
 
