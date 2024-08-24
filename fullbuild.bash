#!/bin/bash

source ~/ros2_foxy/ros2-linux/setup.bash
source /opt/ros/foxy/setup.bash

cd ~/QR_sync/QR_Core 
rm -r build
colcon build --build-base build/lincol --event-handlers console_cohesion+ --install-base install_lin
source ./install_lin/setup.bash


cd ../ros2_template2/IF
rm -r build
colcon build --build-base build/lincol --event-handlers console_cohesion+ --install-base install_lin
source ./install_lin/setup.bash


cd ..
rm -r build
colcon build --build-base build/lincol --event-handlers console_cohesion+ --install-base install_lin
source ./install_lin/setup.bash

 
