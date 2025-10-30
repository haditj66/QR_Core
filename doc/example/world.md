# 🌍 World Example

This is an example project used to **test Active Objects (AOs)** in the **AEROS framework**.  
It is available here:  
👉 [https://github.com/haditj66/world2](https://github.com/haditj66/world2)

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

This example represents a **small simulated world** that consists of a **2D grid**.  
Different **gameobjects** can occupy and interact within this grid — some are movable, while others remain static.  

It serves as a demonstration of:
- 🧩 **Resource sharing** between modules  
- ⚡ **Asynchronous, non-blocking Active Object logic**  
- ⏱️ **Real-time event handling and communication** in ROS 2  

---

## 🧠 Active Objects (AOs) Used

### 🟦 `World2` (Surrogate AO)
Acts as the **central controller** or “server” for the simulation.  
It manages the world grid, processes moves, and coordinates all gameobjects.

**Responsibilities:**
- Maintains the 2D map and occupancy grid.  
- Receives move and update requests from GameObjects.  
- Publishes state-change events (`PositionChanged`, `ObjectAdded`, etc.).  
- Synchronizes data with its surrogate AOs across modules.  

**Surrogate Details:**
- Declared as a `AOSurrogateNode<World>` in the config.  
- Implements `SurrogateServiceFunction`s like:
  ```csharp
  [SurrogateServiceFunction]
  public MoveResponse MoveObject(Gameobject objToMove, Move move)
  ```
- Has synchronized properties such as:
  - `numofgameobjects`
  - `GridState` (implied by Move/Add operations)

---

### 🟩 `Gameobject` (Surrogate AO)
Represents any entity in the world — creatures, obstacles, or static items.

**Key Surrogate Properties:**
- `positionx`
- `positiony`
- `isStatic` (true for immovable objects like rocks)

**Functionality:**
- Registers itself with the `World2` AO upon creation.
- Responds to world updates and move results.
- Can initiate move events (calls to `World2.MoveObject()`).

---

## ⏱️ Timers

Timers are used to **drive periodic updates** in the world simulation.  
Each AO can define its own timers through `SetAllTimers()`.

In this example:
- The main `World2` AO uses timers to periodically publish world state changes or trigger physics updates.
- Example pattern:
  ```csharp
  new ROSTimer("WorldUpdateTimer", 1000) // 1-second interval
  ```

These timers generate callback events on the CPP side that can be expanded for AI, physics, or game logic.

---

## 📡 Publishers and Subscribers

The World example demonstrates AEROS’s **event-driven communication** system.  
Each AO can define publishers/subscribers using:

```csharp
public override List<ROSPublisher> SetAllPublishers()
public override List<ROSSubscriber> SetAllSubscribers()
```

**In this project:**

| Component | Role | Example Event | Description |
|------------|------|---------------|-------------|
| `World2` AO | Publisher | `WorldGridUpdated` | Broadcasts changes in the world grid state. |
| `Gameobject` AO | Subscriber | `WorldGridUpdated` | Reacts to new world state data (e.g., object moved). |
| `Gameobject` AO | Publisher | `ObjectMoved` | Announces that it has changed position. |
| `World2` AO | Subscriber | `ObjectMoved` | Updates the grid when an object moves. |

This demonstrates how **cross-module pub/sub communication** works cleanly through QR-generated code.

---

## 🧭 Project Structure and Interaction

The **World2** module interacts with the **sometest** module during generation.  
For instance, `sometest` can spawn `Gameobject` surrogates and control them by calling functions defined in `World2`.

A simplified relationship:
```
Sometest (client)  →  World2 (server)
   |                    |
   |—> Surrogate: Gameobject
   |—> Calls: World2.MoveObject()
   |<— Publishes: PositionChanged
```

---

## 🖼️ Simulation Snapshot

![world](https://github.com/haditj66/QR_Core/blob/main/doc/images/world.PNG)

The image above shows the conceptual world grid used in this demo —  
where movable and static gameobjects coexist and interact under AO-driven logic.

---

### Summary

This example demonstrates:
- How **AEROS AOs** and **SurrogateAOs** interact through events, publishers, and timers.  
- How **inter-module communication** occurs automatically through generated interfaces.  
- The simplicity of building a small, event-driven “world simulation” entirely through config-defined logic.
