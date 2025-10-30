# 🧩 Sometest Example

This is an example project that is used to **test the AOs and module linking** in **AEROS**.  
It is available here:  
👉 [https://github.com/haditj66/sometest](https://github.com/haditj66/sometest)

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

## 🌐 Overview

This example project is a **separate module** that links to the **`world2`** module.  
It is designed to test **cross-module linking**, **Surrogate AO interactions**, and to create a **small stress test** by spawning multiple `Gameobject` AOs and moving them across the grid managed by `world2`.

The goal is to demonstrate:
- Linking between modules via `TargetCode_*` references  
- Creating and controlling Surrogate AOs from another module  
- Coordinating large numbers of AO instances asynchronously  
- Testing AEROS’s event system and non-blocking communication

---

## ⚙️ Targets Defined

The `sometest` project defines multiple targets in its config:

| Target Name | Type | Description |
|--------------|------|-------------|
| `defaultTest` | `QRTarget_cpEXE` | The main CPP target used to initialize AOs and test world interaction logic. |
| `defaultTestRos` | `QRTarget_RosEXE` | The ROS executable target that connects to the world2 ROS environment and runs surrogate-based tests. |
| `TargetCode_cppLibrary` | Library | Core CPP logic for sometest. |
| `TargetCode_rqtLibrary` | Library | ROS-side library for sometest. |
| `TargetCode_if` | Interface | Shared interface target. |

All executable targets link against `world2Project.world2.TargetCode_cppLibrary` and `world2Project.world2.TargetCode_rqtLibrary` to connect with the world module.

---

## 🧠 Active Objects (AOs) Used

### 🟦 `World` (Surrogate AO)

This is a **Surrogate AO** for the real `World2` AO defined in the `world2` project.  
It allows `sometest` to control and interact with the world remotely through service functions.

**Main Functions:**
```csharp
[SurrogateServiceFunction]
public MoveResponse MoveObject(Gameobject objToMove, Move move)
```

```csharp
[SurrogateServiceFunction]
public AddObjectResponse AddObjectToWorld(Gameobject objToMove, int posy, int posx)
```

These enable gameobjects from `sometest` to move within the world grid or be added to it.

---

### 🟩 `Gameobject` (Surrogate AO)

The `Gameobject` AO acts as a **movable object** that can be spawned within the `sometest` environment.  
Each one can send requests to the `World` surrogate for movement or interaction.

**Example Usage:**
```csharp
Gameobject gameobject = new Gameobject("Rock3", false);
World worldsur = new World("World1", true);
```

Here, the second argument (`true`) marks `World1` as a surrogate instance — meaning it represents the real world running in another module.

---

## ⏱️ Timers

The `sometest` module can define timers to automate test routines, such as:
- Sending periodic movement commands
- Refreshing test state
- Publishing data to simulate real ROS timing

Example pattern:
```csharp
public override List<ROSTimer> SetAllTimers()
{
    return new List<ROSTimer>()
    {
        new ROSTimer("testTimer", 1000)
    };
}
```

This creates a 1-second repeating timer, allowing automated movement or world interaction events.

---

## 📡 Publishers and Subscribers

The project uses AEROS publishers and subscribers for **event-driven testing** between modules.

| Component | Role | Example Event | Description |
|------------|------|---------------|-------------|
| `TestSimple` AO | Publisher | `SomeTestEvent` | Publishes integer messages for testing communication. |
| `World` Surrogate | Subscriber | `ObjectAdded` | Listens for updates when new objects are added to the world. |
| `World` Surrogate | Publisher | `MoveCompleted` | Notifies other modules that a movement request has finished. |

**Publisher Example:**
```csharp
ROSPublisher.CreatePublisher("pub1", new QREventMSGTemplate<int>("SomeTestEvent", "somesize"), true)
```

---

## 🔗 Linking to World2

The link between `sometest` and `world2` occurs through the library targets:

```csharp
protected override QRTarget_cpLib InitCPPLibrary()
{
    return new QRTarget_cpLib(sometest.TargetCode_if, world2Project.world2.TargetCode_cppLibrary);
}

protected override QRTarget_RosLib InitROSLibrary()
{
    return new QRTarget_RosLib(
        sometest.TargetCode_cppLibrary, 
        world2Project.world2.TargetCode_cppLibrary,
        world2Project.world2.TargetCode_rqtLibrary
    );
}
```

This ensures both modules share interface definitions and can communicate using ROS and CPP code generated from their config.

---

## 🧩 Integration Flow

The interaction between `sometest` and `world2` works like this:

```
Sometest Module → World2 Module
     |                   |
     |— Creates Gameobject surrogate
     |— Calls World.AddObjectToWorld()
     |— Publishes events (e.g., move complete)
     |<— Subscribes to updates (e.g., grid changes)
```

This demonstrates how multiple AEROS modules can share AOs and synchronize their state through Surrogate mechanisms and ROS interfaces.

---

## 🖼️ Diagram

![world](https://github.com/haditj66/QR_Core/blob/main/doc/images/world.PNG)

---

### Summary

The `sometest` module demonstrates:
- How to link two modules (`sometest` ↔ `world2`) using QR target linking  
- How to define and control **Surrogate AOs** remotely  
- How to use **timers, publishers, and subscribers** for simulation testing  
- How to coordinate large AO systems asynchronously across modules
