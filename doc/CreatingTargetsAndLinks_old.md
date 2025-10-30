# Targets

 You can create executable targets in your projects and link them to other targets from other modules. Here are all the target types
 -cpp library target: one target per cpp project. Automatically created in InitCPPLibrary() function in config file
 -ros library target: one target per ros project. automatically created in InitROSLibrary() function in config file
 -ros executable target: 1 to many per ros project;
 -cpp executable target: 1 to many per cpp project;
 -cpp unit tests target: Each cpp project has one target by default. 
 -Interface target: automatically created. This target has all the ROS interfaces used. 
 
Look at below diagram for reference  
![Project Structure](https://github.com/haditj66/QR_Core/blob/main/doc/images/project_structure.PNG)    
   
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

## Creating a target
Do this in the config file. Add the following attribute to a function. That function name will now be your target name. for example a target named myfirstexe
```
    [QRTarget_RosEXE(sometest.TargetCode_if, sometest.TargetCode_rqtLibrary)]
	public void myfirstexe()
	{
	}
```
use QRTarget_cpEXE for cpp projects targets.

For the libraryies, create an instance of them in the InitCPPLibrary and InitROSLibrary.

## Creating target AOS
in the function of myfirstexe() or whereever your target function is, you can define AOs, create events, and etc. When you generate your target, it will generate the AOs
you defined within that target function.

## linking a target
To link targets to other targets, simply delcare this in the constructor of QRTarget_####( here ). Every module has codes to link to. 
-TargetCode_cppLibrary 
-TargetCode_rqtLibrary
-TargetCode_if

for example, if I wanted to link a ros library from module sometest, to a cpp library in module world2
```new QRTarget_RosLib(world2Project.world2.TargetCode_cppLibrary);```

Look at below for reference of linking structure 
![link1](https://github.com/haditj66/QR_Core/blob/main/doc/images/Link1.PNG) 
![link2](https://github.com/haditj66/QR_Core/blob/main/doc/images/Link2.PNG)  
 
 
 ---
Next [Settings Files](https://github.com/haditj66/QR_Core/blob/master/doc/SettingsFiles.md)
