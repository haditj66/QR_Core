# Working With Interface Files in CGen / QR Framework

This guide explains how to define message interface (`.msg`) files in your module using CGen’s QR event system.

It covers:

1. Creating simple module-local interface files  
2. Creating publishers from interface files 
3. Creating interface files from ROS packages
4. Composing interface files from other interfaces  

---

# 1. Creating Simple Message Interface Files in Your Module

Simple `.msg` interface files correspond to QR events created inside your module.

We will use **SomeTestEvent** as the example.

---

## Step 1 — Declare the interface variable outside your constructor

```csharp
public static QREventMSG sometestmsg;
```

This ensures the interface definition is globally accessible before publishers/subscribers are created.

---

## Step 2 — Define the interface inside your constructor

```csharp
public livoxmock()
{
    sometestmsg = new QREventMSG("livoxmock", "SomeTestEvent",
        new FunctionArgs<Int32>("a"),
        new FunctionArgs<float>("b"));
}
```

Generated `.msg`:

```
int32 a
float32 b
```

---

# 2. Creating Publishers From Interface Files

Once your interface message is defined, you can create ROS publishers inside your AONode using:

```csharp
ROSPublisher.CreatePublisher(string publisherName, QREventMSG/QREventMSGNonQR eventRef, bool includeInstanceName);
```

### Example

```csharp
return new List<ROSPublisher>()
{
    ROSPublisher.CreatePublisher("pub1", livoxmock.pointcloud2msg, true),
    ROSPublisher.CreatePublisher("pub2sometest", livoxmock.sometestmsg, true),
    ROSPublisher.CreatePublisher("pub3sometest", livoxmock.pointcloudTest2msg, true)
};
```

### Explanation of Arguments

| Argument | Meaning |
|---------|---------|
| `"pub1"` | The internal name of the publisher inside your AO |
| `livoxmock.pointcloud2msg` | The interface instance that defines the message format |
| `true` | If **true**, the topic becomes `<instance_name>/<topic>`; if **false**, it becomes `<topic>` |

### Example:

If your AO instance name is `livoxMockedDriver`:

```csharp
ROSPublisher.CreatePublisher("pub1", livoxmock.pointcloud2msg, true)
```

Publishes to:

```
livoxMockedDriver/lidardata
```

But if set to `false`, the topic becomes:

```
lidardata
```

---

# 3. Creating Interface Files From ROS Packages (QREventMSGNonQR)

Use this when publishing or subscribing to ROS package message types such as `sensor_msgs/PointCloud2`.

---

## Important  
**All ROS-based interface messages must be defined BEFORE any regular QREventMSG definitions.**

---

## Step 1 — Declare outside constructor

```csharp
public static QREventMSGNonQR pointcloud2msg;
```

---

## Step 2 — Define inside constructor

```csharp
pointcloud2msg = new QREventMSGNonQR(
    "PointCloud2",
    "livoxmock/lidardata",
    "#include <sensor_msgs/msg/point_cloud2.hpp>",
    "sensor_msgs::msg::PointCloud2"
);
```

| Argument | Meaning |
|----------|---------|
| `"PointCloud2"` | Name of generated `.msg` |
| `"livoxmock/lidardata"` | Topic name (optional) |
| `#include <...>` | Required include header |
| `"sensor_msgs::msg::PointCloud2"` | Full namespace |

---

## Step 3 — Register ROS dependency using RosTarget

```csharp
rosTarget = new RosTarget(
    "sensor_msgs",
    new List<QREventMSGNonQR>() { pointcloud2msg }
);
```

---

## Required CMakeLists additions

```cmake
QR_Find_List_Of_Ros_Packages(
    NON_QR_PACKAGES_INTERFACE_LIST
        example_interfaces
        std_msgs
        sensor_msgs
)
```

---

# 4. Composing Interface Files From Other Interfaces

You can include:

- ROS interface messages (`QREventMSGNonQR`)
- Local module interface messages (`QREventMSG`)
- Primitive arguments

Example: `PointCloudMSGTest`

---

## Step 1 — Define in constructor

```csharp
pointcloudTest2msg = new QREventMSG(
    "livoxmock",
    "PointCloudMSGTest",

    new FunctionArgs<QREventMSGNonQR>(pointcloud2msg, "clouddata"),
    new FunctionArgs<QREventMSG>(sometestmsg, "testdata"),
    new FunctionArgs<Int32>("numofpointsfilteredout")
);
```

Generated `.msg`:

```
sensor_msgs/PointCloud2 clouddata
livoxmock/SomeTestEvent testdata
int32 numofpointsfilteredout
```

---

# Summary

| Feature | Type Used |
|--------|------------|
| Simple module-defined `.msg` | `QREventMSG` |
| ROS package `.msg` | `QREventMSGNonQR` |
| Publishers | `ROSPublisher.CreatePublisher()` |
| Composite messages | Mix of QREventMSG & QREventMSGNonQR |

---

