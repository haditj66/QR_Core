# 🧠 Surrogate AO  

Surrogate AOs extend the features of **SimpleROS AOs**.  
They function the same way but also support **surrogate functions** and **data synchronization properties**.

---

## 📘 Table of Contents

- [AEROS](https://github.com/haditj66/QR_Core)
- [Installation](https://github.com/haditj66/QR_Core/blob/master/doc/Installation.md)
- [Creating an AEROS project](https://github.com/haditj66/QR_Core/blob/master/doc/Creating_an_AERTOS_project.md)
  - [Creating Targets and Links](https://github.com/haditj66/QR_Core/blob/master/doc/CreatingTargetsAndLinks.md)
  - [Settings Files](https://github.com/haditj66/QR_Core/blob/master/doc/SettingsFiles.md)
  - [Unit Testing](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/UnitTesting.md)
  - [Launch Files](https://github.com/haditj66/QR_Core/blob/master/doc/tools/LaunchFiles.md)
- [AEROS Concepts](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_concepts.md)
  - [Active Objects (AO)](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/AOs.md)
  - [QR_PubSub_Tutorial](https://github.com/haditj66/QR_Core/blob/master/doc/QR_PubSub_Tutorial.md)
    - [SimpleROSAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SimpleROSAO.md)
      - [SurrogateAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SurrogateAO.md)
  - [Timers](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Timers.md)
  - [Events / Interfaces](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Events.md)
  - [Finite State Machine](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/FSM.md)
  - [Target PC or Embedded Device](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Target_PC_Or_Embed.md)
- [Example Projects](https://github.com/haditj66/QR_Core/blob/master/doc/Examples.md)
  - [Example World](https://github.com/haditj66/QR_Core/blob/master/doc/example/world.md)
  - [Example Sometest](https://github.com/haditj66/QR_Core/blob/master/doc/example/sometest.md)
- [AEROS Tools](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_TOOLS.md)

---

## ⚙️ Surrogate Functions  

Surrogate functions are similar to service functions, but they are directly tied to a **C++ class object's function** that you can unit test within the C++ project file.  
The implementation of this function corresponds to the instance of that C++ function.  

In addition to surrogate functions, you can still use standard service functions as before.

---

## 🧩 Surrogate Objects  

You can have a real AO, and also create **surrogates** of that same AO instance.  
For example, if you create an instance called `"World1"`, you can reference it in its own module.  

However, if another module wants to call a function from that AO, it uses a **proxy object** called a *surrogate*, which abstracts the respective service function’s client behind a normal function call.

In short, surrogate objects are **fake versions** of the real AO running in another module.

You can get a surrogate instance in code with:

```cpp
WorldBase* wo = WorldBase::GetObjectFromPool("World1");
```

Here, `"World1"` is the name of the instance you want.  
Make sure that instance has been created before calling it — adding a null check on `wo` is good practice.

---

## 🔄 Surrogate Properties  

These represent the **data** of the surrogate object.  
For example, in a surrogate named `Gameobject`, you might have properties like `positionx`, `positiony`, and `isStatic`.  
You can make them *public* or *private set*.  

A **private set** means no other instance can modify that parameter.

### ✳️ Data Synchronization

Surrogate properties automatically keep data synchronized across all surrogate instances using the `DataSync` class in `QR_Core`.  
The process works as follows:

1. A `setPosx()` call is made on some `Gameobject` surrogate AO.  
2. Within that surrogate, the property is changed locally.  
3. A service call is made to the **real AO**, which updates the property and publishes an event named `setPosxChanged`.  
4. All surrogates subscribe to that event and update their property values in their callbacks.  
5. A unique *DataSync session ID* (`int64`) is passed along.  
   The surrogate that made the original call compares this ID and ignores the update if it matches its own call (since it already applied it).

---

## 🧱 How Surrogates Are Instantiated  

Whenever a real AO is created, it publishes an event called `<Name>Initialized`.  
A class called `<Name>Init` (located in `<Name>Surrogate.h`) uses a node called `DataAccessManager` to subscribe to these events and then automatically creates surrogate instances for the corresponding real AOs.

---

## 🧩 Creating a Surrogate AO  

In your config file, define a class that inherits from `AOSurrogateNode<T>`.  

Here’s an example of a Surrogate AO named **World**:

```csharp
public class World : AOSurrogateNode<World>
{
    [SurrogateData(false)]
    public Int32 numofgameobjects { get; set; }

    public World(string instanceName, bool isSurrogate) : base(instanceName, isSurrogate)
    {
    }

    [SurrogateServiceFunction]
    public MoveResponse MoveObject(Gameobject objToMove, Move move)
    {
        return MoveResponse.SUCCESS;
    }

    [SurrogateServiceFunction]
    public AddObjectResponse AddObjectToWorld(Gameobject objToMove, int posy, int posx)
    {
        return AddObjectResponse.SUCCESS;
    }

    [ServiceFunction]
    public void DoAThing(int num1)
    {
        return 1;
    }

    public override List<ROSTimer> SetAllTimers()
    {
        return new List<ROSTimer>() { };
    }

    public override List<ROSPublisher> SetAllPublishers()
    {
        return new List<ROSPublisher>() { };
    }

    public override List<ROSSubscriber> SetAllSubscribers()
    {
        return new List<ROSSubscriber>() { };
    }
}
```

You can then instantiate it in your config target:

```csharp
World world = new World("World1", false);
```

To create a surrogate of it in another module:

```csharp
World world = new World("World1", true);
```

---

## 🧠 Writing Code for the AO in Application  

Below is the structure and hierarchy of files generated for a Surrogate AO named **World**.

```
WorldBase
├── WorldBase_cppobj
│   ├── World
│   └── WorldSurrogate
└── WorldInit
    └── WorldNodeAO → World
                      │
                      └── WorldNode
```

### File Breakdown

| File | Description |
|------|--------------|
| **WorldBase.h** | Contains `WorldBase` and `WorldBase_cppobj`, includes all interfaces. |
| **World.h** | The main user-implemented class, includes `WorldBase.h`. |
| **WorldSurrogate.h** | Defines `WorldSurrogate` and `WorldInit`, includes `World.h`. |
| **WorldNodeAO.h** | The real AO object for ROS, includes `World.h`. |
| **WorldNode.hpp** | Node instance of `WorldNodeAO`, includes `WorldNodeAO.h`. |

---

### Class Purposes

- **World** — The simple C++ object containing user-defined logic.  
- **WorldSurrogate** — The ROS-side surrogate class that forwards messages to wherever the real AO resides.  
- **WorldInit** — Responsible for creating surrogate AOs when the real ones are initialized.  
- **WorldNodeAO** — The ROS-facing AO that handles all incoming ROS service calls and forwards them to its internal object.  
- **WorldNode** — The actual instantiated ROS node (you can have multiple instances).

---

After generating your project, the AO code will be produced automatically.  
You’ll mainly interact with:

- `World.h` (C++ project): implement normal logic.  
- `WorldNode.hpp` (ROS project): implement service functions you declared.

Example:

```cpp
MoveResponse MoveObject(GameobjectBase* AOObj, Move move)
{
    //UserCode_SectionMoveObjectimp
        // Custom user logic
    //UserCode_SectionMoveObjectimp_end
}
```

Note that it correctly recognizes `GameobjectBase` as another AO type.  
This AO is sent as a **string ID** in the service call’s client and retrieved as the surrogate instance in the service callback.

---

⚠️ **Important:**  
Only write code within the `UserCode_Section` regions of generated files.  
Anything outside those blocks will be overwritten when you regenerate your project.
