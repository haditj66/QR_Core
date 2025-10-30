# 🎯 Targets

You can create **executable targets** in your projects and link them to other targets from other modules.  

Below are all the available **target types**:

| Target Type | Description |
|--------------|-------------|
| 🧱 **CPP Library Target** | One per CPP project. Automatically created in `InitCPPLibrary()` within the config file. |
| 🌐 **ROS Library Target** | One per ROS project. Automatically created in `InitROSLibrary()` within the config file. |
| 🚀 **ROS Executable Target** | One or more per ROS project. |
| ⚙️ **CPP Executable Target** | One or more per CPP project. |
| 🧪 **CPP Unit Test Target** | Each CPP project has one unit test target by default. |
| 🔗 **Interface Target** | Automatically created. Contains all ROS interfaces used across modules. |

---

### 📊 Project Structure Reference

![Project Structure](https://github.com/haditj66/QR_Core/blob/main/doc/images/project_structure.PNG)

---

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

---

## ⚙️ Creating a Target

Targets are created in the **config file**.  
Add an attribute to a function — the function name becomes the **target name**.

For example, to create a ROS target named `myfirstexe`:

```csharp
[QRTarget_RosEXE(sometest.TargetCode_if, sometest.TargetCode_rqtLibrary)]
public void myfirstexe()
{
}
```

For CPP targets, use `QRTarget_cpEXE` instead.

Library targets are created as instances within:
- `InitCPPLibrary()` → for CPP libraries  
- `InitROSLibrary()` → for ROS libraries  

---

## 🧩 Creating Target AOs

Inside your target function (e.g., `myfirstexe()`), define **Active Objects (AOs)**, create **events**, and perform other initialization.  
When you generate the project, all AOs defined in that target function will be generated automatically.

---

## 🔗 Linking Targets

To link one target to another, declare it in the constructor of the appropriate `QRTarget_####` class.

Each module exposes its own linkable codes:
- `TargetCode_cppLibrary`
- `TargetCode_rqtLibrary`
- `TargetCode_if`

Example — linking a **ROS library** from module `sometest` to a **CPP library** in module `world2`:

```csharp
new QRTarget_RosLib(world2Project.world2.TargetCode_cppLibrary);
```

### Linking Reference

![Link Structure 1](https://github.com/haditj66/QR_Core/blob/main/doc/images/Link1.PNG)  
![Link Structure 2](https://github.com/haditj66/QR_Core/blob/main/doc/images/Link2.PNG)

---

➡️ **Next:** [Settings Files](https://github.com/haditj66/QR_Core/blob/master/doc/SettingsFiles.md)
