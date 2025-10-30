# Interfaces/Events
 
These are the ROS2 Timers.

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
 
 
## Creating timers
Every AO can have timers. You can create a timer by adding it to an AO class. For example, in a TestSimple2 AO
```
        public override List<ROSTimer> SetAllTimers()
        {
            return new List<ROSTimer>()
            {
                new ROSTimer("testTimer2", 1000)
            };
        }
```

  