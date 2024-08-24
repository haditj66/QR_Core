# What is QR_Core?
  - An acronym for **Q**t-**R**OS
  - In hindsight, not the best acroym as it's not really related to Qt, but the name stuck so we're going with it

  - TLDR: CMake extensions that will help code generate common files for our ROS2 projects. For the sake of abstracting project building within our new team's software architecture environment.
  - A core ROS2/QT project that all other "QR" projects will depend on. It has all cmake files that will be common to all "QR" projects.
  - It will also give code generation utilities in the form of cmake functions.


 # Installing QR_Core

### Prerequisites:
- CgenMin  : https://github.com/haditj66/CgenMin
- Qt
- ROS2 foxy



#### step1: clone QR_Core
open a terminal and cd to the QR_Sync directory. Then clone QR_Core. 

    cd ~/QR_Sync
    git clone git@github.com:Instapath/QR_Core.git 

    
#### step2: build QR_Core.
 To do this cd into the QR_Core directory and run remove the build directory in case it is currently there. Then run ourcolcon which will build it.

    cd ~/QR_Sync/QR_Core
    rm -rf build
    ourcolcon
    
#### step3: Verify installation (optional)
To verify, source QR_Core

    oursource

 clone any of the example modules into QR_Sync, cd into their directory, and try building them. To do this,
 go into the base directory and run the bash script

     modulefullclean.bash
you can then run `ourcolcon` to build any project in that module. If it finishes, everything is verified.

 ---
### Building a new module after cloning it
To build a new module after cloning it, the easiest way is to run these two bash scrips located in the base directory of that module 

`modulefullclean.bash` 

and then 

    modulefullbuild.bash
---
### IDE open and debugging for a module
If this is your first time cloning the module you want to debug, follow the "Building a new module after cloning it" above.

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
 
# Why does QR_Core exist?

First, we devised a workflow needed for LUCI-ROS development based on an event-driven architecture.

1. Create a C++ project for some modular functionality (functionX).
2. Unit test functionX.
3. Create interface data types for functionX.
4. Wrap functionX in ROS functionality.
5. Integration testing functionX with functionY from another module.

We are currently using Qt, C++, ROS, etc. technologies. Each of these require a suite of development tools to work with. These tools are scattered and not integrated with each other.

These tools include:
  - CMake: a build system for C++
  - Colcon: A C++ package management tool
  - Qt C++ Framework
  - OS's: Windows, Linux
  - IDE's: QtCreator, CLION

QR_Core creates a single environment that integrates all the scattered tools with cross platform compatibility. QR_Core abstracts these tools from the developers so they don't have to learn about the integration process or other nuances specific to each tool.

# Basic QR_Core based project structure 
A simple illustration of a "QR_Core" module, vs a regular "module" (or projects containing subprojects)

<p><img src="doc/qr_core_modules0.drawio.png"></p>

[Link to DrawIO diagram](https://drive.google.com/file/d/19_254mHf4ZNGt5-cRjytHBCTdEuoW6eN/view?usp=sharing)

# Quickstart
  - See section QRCore Tutorial 1 in [Hadi's OneNote Notes](https://1drv.ms/u/s!ApEzxR-IU_EYlrl8ZrkMNE2u3l0BJA?e=bKl6Xr)
  - TODO: tutorial or link to tutorial here

## Requirements
 - See ROS VM setup guide. (todo: rename and link [rostmp](https://github.com/Instapath/rostmp) repo, should be DevEnv Setup guide or something)



# References
  - [Hadi's OneNote Notes](https://1drv.ms/u/s!ApEzxR-IU_EYlrl8ZrkMNE2u3l0BJA?e=bKl6Xr)













