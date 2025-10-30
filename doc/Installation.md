
# Installation
 
Installation instructions for AERTOS.
  
TableOfContentsForQRCore47896205709769

## Table of Contents
- [AEROS](https://github.com/haditj66/QR_Core)
- [Installation](https://github.com/haditj66/QR_Core/blob/master/doc/Installation.md)
- [Creating an AEROS project](https://github.com/haditj66/QR_Core/blob/master/doc/Creating_an_AERTOS_project.md)
	- [Creating Targets And Links](https://github.com/haditj66/QR_Core/blob/master/doc/CreatingTargetsAndLinks.md)
	- [Generate_project](https://github.com/haditj66/QR_Core/blob/master/doc/Generate_project.md)
	- [Settings Files](https://github.com/haditj66/QR_Core/blob/master/doc/SettingsFiles.md)
	- [Unit Testing](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/UnitTesting.md)
	- [Launch Files](https://github.com/haditj66/QR_Core/blob/master/doc/tools/LaunchFiles.md)
- [AEROS concepts](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_concepts.md) 
    - [Active Objects (AO)](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/AOs.md) 
	- [PubSub_Tutorial](https://github.com/haditj66/QR_Core/blob/master/doc/QR_PubSub_Tutorial.md)
	- [Timers](https://github.com/haditj66/QR_Core/blob/master/doc/QR_Timers.md)
	- [creating NonQR Target Tutorial](https://github.com/haditj66/QR_Core/blob/master/doc/AEROS_NonQR_Target_Tutorial.md)
		- [SimpleROSAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SimpleROSAO.md)
			- [SurrogateAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SurrogateAO.md)  
    - [Timers](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Timers.md)  
	- [Events/Interfaces](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Events.md)
    - [Finite State Machine](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/FSM.md)
    - [Target PC or embedded device](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Target_PC_Or_Embed.md) 
- [Example Projects](https://github.com/haditj66/QR_Core/blob/master/doc/Examples.md)
    - [Example world](https://github.com/haditj66/QR_Core/blob/master/doc/example/world.md)
    - [Example sometest](https://github.com/haditj66/QR_Core/blob/master/doc/example/sometest.md)
- [AERTOS Tools](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_TOOLS.md)
    
TableOfContentsForQRCore47896205709769

### Page Contents
- [Installing QR_Core](#Installing QR_Core)

- [Building example modules after installing QRCore](#Building example modules after installing QRCore)
 



 # Installing QR_Core

### Prerequisites:

- ROS2 jazzy: https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html
-ubuntu (24.04 currently being used)
- CgenMin: follow installation instructions there: https://github.com/haditj66/CgenMin
- Configuration Project: https://github.com/haditj66/AEROSConfigProject
- Template Project: https://github.com/haditj66/templateprojectwev
-qt creator or visual code ide wih ROS and cmake extension

optional but very usefull during development:
-syncthing: syncing files with windows when developing on cgenMin.



#### step1: clone QR_Core
open a terminal and cd to the QR_Sync directory. Then clone QR_Core. 

    cd ~/QR_Sync
    git clone git@github.com:haditj66/QR_Core.git

    
#### step2: build QR_Core.
 To do this cd into the QR_Core directory and run remove the build directory in case it is currently there. Then run ourcolcon which will build it.

    `cd ~/QR_Sync/QR_Core
    `rm -rf build`
    `ourcolcon`
	
	(optional)----------
	To verify, source QR_Core 
    `oursource`
	 
 
#### step3: build configure project.
This will be used to configure your Ros project.
	cd ~/QR_Sync
	git clone git@github.com:haditj66/AEROSConfigProject.git
     
	 Now get the template project. This project will be used as the template when you run QR_init
	 cd ~/QR_Sync
	 git@github.com:haditj66/templateprojectwev.git
	 
#### step4: get ide
qt creator: seems to work best 
visual code: this is best when it works for development.

 ---
# Building example modules after installing QRCore
To build a new module after cloning it, the easiest way is to run these two bash scrips located in the base directory of that module 

`modulefullclean.bash` 

and then 

    modulefullbuild.bash
---

world2: example projects
cd ~/QR_Sync
git clone git@github.com:haditj66/world2.git
git clone git@github.com:haditj66/sometest.git
 

#### step1: Source all dependencies
In a terminal go to all modules that this one depends on and source them all by running `oursource`. Also source the current module you are opening. 
#### step2: open qt creator
you can run openqt command or run just open qt ide yourself using the command you got when you installed it. 
#### step3: make sure you change the build path inside qt ide
You need to change the binary directory, in projects tab, or in cmake configurations wizard upon start, go to the details button. Give the directory being the one you are currently on, and with path, <CURRENT_DIR>/build/lin . Finally press reconfigure cmake when the window pops up. 

Build and debug as usual. 


 ### TroubleShooting
  - **you do a ourcolcon but it mentions that yourmodulename_i package is missing.**
 did you have your module's interface project sourced? it is located in baseDir/rosqt/IF
 - **you do a ourcolcon for a module but it mentions that qtcore package is missing:**
 did you have QRCore sourced?
 - **you do a ourcolcon for a module but it mentions something about cmakeCache wrong directory.**:
Try deleting the build folder and running ourcolcon again. 
- **you do a ourcolcon for a module with qt ui on and it mentions that it cant find Qt5Config.cmake files:**
try this

     `sudo apt-get install qtbase5-dev`
   ` sudo apt-get install qtdeclarative5-dev`

as mentioned here 
https://stackoverflow.com/questions/59601055/cmake-configure-fails-to-find-qt5-on-linux

- **QR_Core does not build first time running ourcolcon because it mentions something about colcon not being a supported command:**
did you install colcon? If not, do this

 

    `sudo apt update`
    `sudo apt install python3-colcon-common-extensions`
     
 ---



---
Next [Creating an AEROS project](https://github.com/haditj66/QRCore/blob/master/doc/Creating_an_AERTOS_project.md)