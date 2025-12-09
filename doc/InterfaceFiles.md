# Working With Interface Files in CGen / QR Framework

This guide explains how to work with message interface (`.msg`) files in your module using CGen’s QR event system.

It covers:

1. Creating simple module-local interface files  
2. Creating publishers from interface files  
3. Creating interface files from ROS packages  
4. Composing interface files from other interfaces  
5. Subscribing to publishers outside your module  
6. Publishing events outside your module  

---

# 1. Creating Simple Message Interface Files in Your Module

Simple `.msg` interface files correspond to QR events created inside your module.

We’ll use **SomeTestEvent** as the example.

---
Here is the code from config for creating 3 different types of interfaces. ros common interface, normal interface, and a composited interface 
```
        public static QREventMSGNonQR pointcloud2msg;
        public static QREventMSG sometestmsg;
        public static QREventMSG pointcloudTest2msg;

        public static RosTarget rosTarget;
        public livoxmock()
        {

               pointcloud2msg = new QREventMSGNonQR("PointCloud2",
            "livoxmock/lidardata",
            "#include <sensor_msgs/msg/point_cloud2.hpp>",
            "sensor_msgs::msg::PointCloud2");

            rosTarget = new RosTarget("sensor_msgs",
           new List<QREventMSGNonQR>()
           {
                pointcloud2msg
           }); 

            sometestmsg = new QREventMSG("livoxmock", "SomeTestEvent",
            new FunctionArgs<Int32>("a"),
            new FunctionArgs<float>("b"));

            
            pointcloudTest2msg = new QREventMSG("livoxmock", "PointCloudMSGTest",
            new FunctionArgs<QREventMSGNonQR>(pointcloud2msg, "clouddata"),
            new FunctionArgs<QREventMSG>(sometestmsg, "testdata"),
            new FunctionArgs<Int32>("numofpointsfilteredout"));


        }


```

## Step 1 — Declare the interface variable outside your constructor

```csharp
public static QREventMSG sometestmsg;
```

This ensures the interface definition exists before publishers/subscribers reference it.

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

Once your interface is defined, you can create publishers in your AONode:

```csharp
ROSPublisher.CreatePublisher(string name, QREventMSGBase eventMsg, bool includeInstanceName);
```

---

### Example

```csharp
return new List<ROSPublisher>()
{
    ROSPublisher.CreatePublisher("pub1", livoxmock.pointcloud2msg, true),
    ROSPublisher.CreatePublisher("pub2sometest", livoxmock.sometestmsg, true),
    ROSPublisher.CreatePublisher("pub3sometest", livoxmock.pointcloudTest2msg, true)
};
```

---

### Explanation of Arguments

| Argument | Meaning |
|---------|---------|
| `"pub1"` | Name of publisher inside the AO |
| `livoxmock.pointcloud2msg` | The interface type for the message |
| `true` | If true → topic becomes `<instance>/topic` |

Example:

If AO instance is `livoxMockedDriver`:

```
pub1, true  → livoxMockedDriver/lidardata  
pub1, false → lidardata  
```

---

# 3. Creating Interface Files From ROS Packages (QREventMSGNonQR)

Use this when referencing ROS types such as `sensor_msgs/PointCloud2`.

---

### IMPORTANT  
**All `QREventMSGNonQR` definitions must be created *before* any normal QREventMSG definitions.**

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

---

## Step 3 — Register the ROS package

```csharp
rosTarget = new RosTarget(
    "sensor_msgs",
    new List<QREventMSGNonQR>() { pointcloud2msg }
);
```

---

## CMakeLists.txt requirement

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

Composite `.msg` files can include:

- Other module-local messages (`QREventMSG`)
- ROS package messages (`QREventMSGNonQR`)
- Primitive values

---

### Example: PointCloudMSGTest

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

# 5. Subscribing to Publishers Outside Your Module

To subscribe to a publisher defined in **another module**, you must use the **4-argument overload**:

```csharp
ROSSubscriber.CreateSubscriber<TAOClass>(
    string subscriberName,
    string publisherName,
    QREventMSGBase eventMsg,
    string instanceNameOfAO
);
```

---

## Meaning of Arguments

| Parameter | Meaning |
|----------|---------|
| `TAOClass` | AO class that *owns* the publisher |
| `subscriberName` | Name of subscriber in *your* module |
| `publisherName` | Name used in the publisher's AO |
| `eventMsg` | Interface definition of the message |
| `instanceNameOfAO` | The AO instance being subscribed to |

---

## Example from the `interfacetest` module

```csharp
ROSSubscriber.CreateSubscriber<livoxmockProject.LivoxMockedDriver>(
    "ssub1",
    "SomeTestEvent",
    livoxmockProject.livoxmock.sometestmsg,
    "livoxMockedDriver"
);

ROSSubscriber.CreateSubscriber<livoxmockProject.LivoxMockedDriver>(
    "ssub2",
    "PointCloudMSGTest",
    livoxmock.pointcloudTest2msg,
    "livoxMockedDriver"
);
```

Explanation:

- You are inside module **interfacetest**
- Subscribing to events published by **livoxmock**
- From the AO instance `"livoxMockedDriver"`

---

# 6. Publishing Events Outside Your Module

If you want your module to publish an event that *belongs to another module*, simply reference it.

### Example

```csharp
ROSPublisher.CreatePublisher("pub2", livoxmockProject.livoxmock.sometestmsg, false);
```

Now **interfacetest** publishes an event type belonging to **livoxmock**.

Subscribers anywhere can subscribe normally.

---

# Summary Table

| Feature | API / Type Used |
|---------|------------------|
| Create local `.msg` | `QREventMSG` |
| Create ROS-based `.msg` | `QREventMSGNonQR` |
| Publisher creation | `ROSPublisher.CreatePublisher()` |
| Subscriber creation | `ROSSubscriber.CreateSubscriber()` |
| Subscribe to other modules | 4-argument overload |
| Publish cross-module | Use interface from another module |

---

