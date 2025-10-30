# ⏱️ Tutorial: Setting Up and Using Timers in AERTOS / QR-Core

This tutorial explains how **Timers** are configured in the C# configuration files  
and how they are translated into **C++ code** after generation.

Examples are based on real code from your `cablecam/config/cablecam.cs` and `sometest.cs` nodes.

---

## 🧩 Section 1: Configuring Timers in the Config File

### 1. Overview

Timers in AERTOS are periodic callbacks that let your node perform repeated actions  
(such as checking sensor data, updating states, or publishing messages).

You define timers inside your node class (which inherits from `AONode<T>` or `AOSurrogateNode<T>`)  
by overriding the `SetAllTimers()` method.

Each timer is defined using the **`ROSTimer`** object, which takes:

| Parameter | Description |
|------------|--------------|
| `string name` | The timer’s internal identifier |
| `int period_ms` | The interval in milliseconds |

---

### 2. Example Definition

```csharp
public class Cablecamobject : AONode<Cablecamobject>
{
    public Cablecamobject(string instanceName) : base(instanceName)
    {
    }

    public override List<ROSTimer> SetAllTimers()
    {
        return new List<ROSTimer>()
        {
            new ROSTimer("timer1", 3000)
        };
    }

    // Example method called by timer
    private void OnTimer1()
    {
        Console.WriteLine("Timer1 triggered after 3 seconds.");
    }
}
```

✅ **What this does:**

- Declares one timer named `"timer1"`.
- The timer triggers every **3000 milliseconds (3 seconds)**.
- The system will automatically call the function bound to that timer (`OnTimer1`) when generated.

---

### 3. Using Multiple Timers

You can define as many timers as you want:

```csharp
public override List<ROSTimer> SetAllTimers()
{
    return new List<ROSTimer>()
    {
        new ROSTimer("sensorUpdate", 500),
        new ROSTimer("stateSync", 2000),
        new ROSTimer("diagnostics", 10000)
    };
}
```

Each timer runs independently and can trigger different callbacks  
once the code is generated.

---

## ⚙️ Section 2: Generated Code in C++

After you run the code generator (macro2 / CgenMin), the timers you declared  
are converted into **ROS 2 timers** in the generated C++ source.

The following example shows what that looks like under the hood.

### 1. Generated C++ Structure

```cpp
#include "rclcpp/rclcpp.hpp"
#include "Cablecamobject.hpp"

void Cablecamobject::Init()
{
    // Create a timer with a 3000 ms interval
    timer1_ = node_->create_wall_timer(
        std::chrono::milliseconds(3000),
        std::bind(&Cablecamobject::OnTimer1, this)
    );
}

void Cablecamobject::OnTimer1()
{
    RCLCPP_INFO(rclcpp::get_logger("Cablecamobject"), "Timer1 triggered after 3 seconds.");
}
```

✅ **Explanation:**

| Part | Purpose |
|------|----------|
| `create_wall_timer()` | Creates a ROS 2 timer object. |
| `std::chrono::milliseconds(3000)` | Sets the period defined in your config. |
| `std::bind(&Cablecamobject::OnTimer1, this)` | Binds the callback to the class method. |
| `RCLCPP_INFO(...)` | Logs when the timer fires. |

---

### 2. Handling Multiple Timers

If you define multiple timers in C#, the generator will create multiple members:

```cpp
void Cablecamobject::Init()
{
    sensorUpdate_ = node_->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&Cablecamobject::OnSensorUpdate, this));

    stateSync_ = node_->create_wall_timer(
        std::chrono::milliseconds(2000),
        std::bind(&Cablecamobject::OnStateSync, this));

    diagnostics_ = node_->create_wall_timer(
        std::chrono::milliseconds(10000),
        std::bind(&Cablecamobject::OnDiagnostics, this));
}
```

---

## 🧠 Section 3: Summary and Tips

| Step | What You Do | What It Generates |
|------|--------------|------------------|
| **1. Define timer in C#** | `new ROSTimer("timer1", 3000)` | Adds timer info to generator metadata |
| **2. Run generator** | `macro2` | Creates `create_wall_timer` code in C++ |
| **3. Implement callback** | `void OnTimer1()` | C++ method bound to the ROS 2 timer |
| **4. Runtime behavior** | Timer triggers periodically | Calls your logic automatically |

**Tips:**
- Timer names should be unique per node.  
- Keep periods above ~50 ms to avoid excessive callback frequency.  
- You can use timers to trigger publishers — common pattern is to publish sensor data inside the timer callback.

---

## ✅ Example Integration: Timer → Publisher

You can also publish data on each timer tick:

```csharp
public override List<ROSTimer> SetAllTimers()
{
    return new List<ROSTimer>()
    {
        new ROSTimer("publishLoop", 1000)
    };
}

private void OnPublishLoop()
{
    Console.WriteLine("Publishing periodic update every 1s");
    // ROSPublisher.GetPublisherOfName("ControlMessage").Publish(...);
}
```

Which would generate something like:

```cpp
publishLoop_ = node_->create_wall_timer(
    std::chrono::seconds(1),
    std::bind(&Cablecamobject::OnPublishLoop, this));
```

Timers are the backbone of periodic behavior — they make it easy to simulate loops, periodic messages,  
or background housekeeping in your nodes.

---

**That’s all you need to configure and use timers in AERTOS / QR-Core.**
