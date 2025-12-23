# SimpleROS AO  
These are simple ROS2 AO. They provide an easy way to create ROS2 services and to be able to call those services in a easy way where all ROS2 stuff is abstracted into a simple cpp function call.
As with any AO, you can also publish and subscribe to messages and set timers.
 
 
## Creating a SimpleROS AO
In your config file, you can do so by creating a class that inherits from AONode. Here is an example of a SimpleROS AO name TestSimple. This AO has two service functions. 
One named GiveName, and the other named AddTwoNumbers. 

```
    public class TestSimple : AONode<TestSimple>
    { 

        public TestSimple(string instanceName) : base(instanceName)
        {
        }

        [ServiceFunction]
        public int AddTwoNumbers(int a, int b)
        {
            return 0;
        }

        [ServiceFunction]
        public string GiveName()
        {
            return "";
        }  
        
        public override List<ROSTimer> SetAllTimers()
        {
            return new List<ROSTimer>()
            {
                new ROSTimer("testTimer", 1000)
            };
        }
         
        public override List<ROSPublisher> SetAllPublishers()
        {
            return new List<ROSPublisher>()
            {
                ROSPublisher.CreatePublisher("pub1", new QREventMSGTemplate<int>("world2", "SomeTestEvent", "somesize"), true)
            };
        }
        public override List<ROSSubscriber> SetAllSubscribers()
        {
            return new List<ROSSubscriber>()
            {
            };
        }
         
    }
```

Now in the target function of your config file, you can create an instance of this AO if you want that target to have this AO in it. 

```
TestSimple testSimple = new TestSimple("TestSimple1");
```
 
## Service Functions 
You can declare a service function like the following 
```
        [ServiceFunction]
        public int AddTwoNumbers(int a, int b)
        {
            return 0;
        }
```
This will be converted to a Ros2 service


After you generate your project,   There will be two files generated.
-TestSimpleNode.hpp
-TestSimpleNodeSurrogate.h
 You will only be interested in the file TestSimpleNode.hpp . In that file, there will be the service function implementations, you can implement what your service function will do here.
 ```
 	void AddTwoNumbers(const std::shared_ptr<world2_i::srv::AddTwoNumbers::Request>  request,
                            std::shared_ptr<world2_i::srv::AddTwoNumbers::Response> response )
    { 
		//UserCode_SectionAddTwoNumbers1
response->result = request->a+request->b;
//UserCode_SectionAddTwoNumbers1_end 
 
    }
 
  

## Creating Service Functions with QREventSRV

Service functions may return a `QREventSRV` directly. This way of declaring a service function is needed when you want a QREvent or NonQREvent as an argument or return type

```csharp
[ServiceFunction]
public QREventSRV FilterPointCloud()
{
    return new QREventSRV(
        "livoxmock",
        "FilterPointCloud",

        // Return type
        new FunctionArgs<QREventMSGNonQR>(
            livoxmock.dataFilteredOutmsg,
            "output_cloud"
        ),

        // Request arguments
        new FunctionArgs<Int32>("num_filtered")
    );
}
```

This generates a ROS service with:
- Request: `int32 num_filtered`
- Response: `sensor_msgs/PointCloud2 output_cloud`

