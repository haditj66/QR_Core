# Creating an AEROS project

 These are the components to creating an AERTOS project.


TableOfContentsForQRCore47896205709769

## Table of Contents
- [AEROS](https://github.com/haditj66/QRCore)
- [Installation](https://github.com/haditj66/QRCore/blob/master/doc/Installation.md)
- [Creating an AEROS project](https://github.com/haditj66/QRCore/blob/master/doc/Creating_an_AERTOS_project.md)
	- [Creating Targets And Links](https://github.com/haditj66/QRCore/blob/master/doc/CreatingTargetsAndLinks.md)
	- [Settings Files](https://github.com/haditj66/QRCore/blob/master/doc/SettingsFiles.md)
	- [Unit Testing](https://github.com/haditj66/QRCore/blob/master/doc/concepts/UnitTesting.md)
	- [Launch Files](https://github.com/haditj66/QRCore/blob/master/doc/tools/LaunchFiles.md)
- [AEROS concepts](https://github.com/haditj66/QRCore/blob/master/doc/AERTOS_concepts.md) 
    - [Active Objects (AO)](https://github.com/haditj66/QRCore/blob/master/doc/concepts/AOs.md) 
		- [SimpleROSAO](https://github.com/haditj66/QRCore/blob/master/doc/concepts/SimpleROSAO.md)
			- [SurrogateAO](https://github.com/haditj66/QRCore/blob/master/doc/concepts/observers/SurrogateAO.md)  
    - [Timers](https://github.com/haditj66/QRCore/blob/master/doc/concepts/Timers.md)  
	- [Events/Interfaces](https://github.com/haditj66/QRCore/blob/master/doc/concepts/Events.md)
    - [Finite State Machine](https://github.com/haditj66/QRCore/blob/master/doc/concepts/FSM.md)
    - [Target PC or embedded device](https://github.com/haditj66/QRCore/blob/master/doc/concepts/Target_PC_Or_Embed.md) 
- [Example Projects](https://github.com/haditj66/QRCore/blob/master/doc/Examples.md)
    - [Example world](https://github.com/haditj66/QRCore/blob/master/doc/example/blinky.md)
    - [Example sometest](https://github.com/haditj66/QRCore/blob/master/doc/example/motor_speed_controller.md)
- [AERTOS Tools](https://github.com/haditj66/QRCore/blob/master/doc/AERTOS_TOOLS.md)
    
TableOfContentsForQRCore47896205709769


### Page Contents
- [Overview](#overview)

- [initializing new module](##initializing new module)
  
- [The Config file](## The Config file)

- [ProjectTests](## Project config file.)

- [Declaring events in project](#declaring-events-in-project)

- [peripheral declaration](#peripheral-declaration)

- [Libraries project depends on](#libraries-project-depends-on)

- [additional include and src files](#additional-include-and-src-files)

- [write your own cmake for a project](#write-your-own-cmake-for-a-project)

- [the cmakegui for cmake options](#the-cmakegui-for-cmake-options)


 
 
## Overview

A module is what is built in a AEROS workspace. For example the world2 example is a module. The module is borken into three projects. 
-the cpp project is what you would think of a simple cpp console application. Non-threaded, and is meant as a project to unit test algorithms 
and such.
 
    
   ![](https://github.com/haditj66/QR_Core/tree/master/doc/images/project_structure.png)

##initializing new module

 You may need to set the directory of you ROS2 installation do this with. example: -s opt/ros/jazzy
  cgen QRinit -s <Directory>
 
 To create a brand new AEROS project, run the following command in the directory you want the project to be. 

     cgen QRinit <name>
	 
	 

----

 
## The Config file
 
 The config project is a C# file script that you will link to the config solution. The file is located in your module 
 <module_Base_Directory>/config/<modulename.cs>

open the configuration project 
     QR_sync/ConfigProjects
Add the config file to the solution by "add existing item". Make sure to "add as link" (little arrow button next to add).
 
    

## Project config file.

As explained, a module is made of three projects. You can configure all these in this file. The module is the class that inherits from QRModule. For example,
a module named sometest will be class 
```class sometest : QRModule```
-You can link other projects in the InitCPPLibrary, InitIFLibrary,  and InitROSLibrary. This is described more in [Creating Targets And Links](https://github.com/haditj66/QRCore/blob/master/doc/CreatingTargetsAndLinks.md) page.

-"class sometestSettings : TargetSettings" is a class that you will use to describe what all settings files will look like. Decribred more in [Settings Files](https://github.com/haditj66/QRCore/blob/master/doc/SettingsFiles.md)

-GetTargetSetting() is where you can create new setting files for the module to use. This is decribred more in [Settings Files](https://github.com/haditj66/QRCore/blob/master/doc/SettingsFiles.md)

-Each project can have multiple targets. You can create executable targets by giving a function the attribute QRTarget_cpEXE or QRTarget_RosEXE for the cpp or ROS project respectively.
within those functions you can create instances of AO that you will use in that project. 

 ## generating the project.

when you are done with the config file project, you can build ctrl-shift-b the solution to save you settings. In a terminal, within a directory of your module,
run the cgen command to generate the projects configuration

`cgen QR_generate <projectType> <targetName>`
projectType: r for a rosqt project, c for a cpp project
projectName: the target name that you want to generate


## sourcing and colcon building projects
every project in a module links to the interface project. When sourcing, you have to source all dependencies first before you can colcon build. For example if you wanted to open up a ros projects, you need to source dependencies from interface to cpp library

interface building and sourcing
```
cd <moduleDir>/rosqt/IF
ourcolcon
oursource
```
cpp building and sourcing
```
cd <moduleDir>
ourcolcon
oursource
```
finally ros building and sourcing
```
cd <moduleDir>/rosqt
ourcolcon
oursource
```

## Opening project in IDE
You can use either QT creator or visual code for this. In either case, you will need to open the IDE in the terminal with the project you want to work on sourced already.
you can source projects with the `oursource` command in the respective project directory. Then open the ide from the sourced terminal.

##QTCreator
you can run `~/Qt/Tools/QtCreator/bin/qtcreator &` or whereever you installed it. From there, go to the project tab to the left and make sure that the build directory is correct.

##visual code
you can run `. code`. Make sure you have the cmake extension and ROS extension installed.

THIS IS AUTOMATICALLY DONE BY AEROS BUT I WILL LEAVE IT HERE FOR FYI: You can look in the lauunch.json file located in the .vscode folder. 
In the "configurations" section, for every executable target, you will see the configurations automatically written for every target you set.




 ---
Next [Creating Targets And Links](https://github.com/haditj66/QRCore/blob/master/doc/CreatingTargetsAndLinks.md)
 
 
