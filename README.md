# AEROS

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

# What is AEROS?
  - This is a small ecosystem of code generation tools to create ROS2 projects in c++. There are patterns
  and tools built in to help quick prototyping. This is done through cmake and cgenMin, a dotnet application handling a 
  bulk of the code generation. In addition to code generation, QR_core holds code needed for the implementations
  of the patterns used here.
  

 
# Basic QR_Core based project structure 

   ![](https://github.com/haditj66/QR_Core/tree/master/doc/images/project_structure.png)












