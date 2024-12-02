# SimpleROS AO  
These are simple ROS2 AO. They provide an easy way to create ROS2 services and to be able to call those services in a easy way where all ROS2 stuff is abstracted into a simple cpp function call.
As with any AO, you can also publish and subscribe to messages and set timers.

TableOfContentsForQRCore47896205709769

## Table of Contents
- [AEROS](https://github.com/haditj66/QR_Core)
- [Installation](https://github.com/haditj66/QR_Core/blob/master/doc/Installation.md)
- [Creating an AEROS project](https://github.com/haditj66/QR_Core/blob/master/doc/Creating_an_AERTOS_project.md)
	- [Creating Targets And Links](https://github.com/haditj66/QR_Core/blob/master/doc/CreatingTargetsAndLinks.md)
	- [Settings Files](https://github.com/haditj66/QR_Core/blob/master/doc/SettingsFiles.md)
	- [Unit Testing](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/UnitTesting.md)
	- [Launch Files](https://github.com/haditj66/QR_Core/blob/master/doc/tools/LaunchFiles.md)
- [AEROS concepts](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_concepts.md) 
    - [Active Objects (AO)](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/AOs.md) 
		- [SimpleROSAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SimpleROSAO.md)
			- [SurrogateAO](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/SurrogateAO.md)  
    - [Timers](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Timers.md)  
	- [Events/Interfaces](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Events.md)
    - [Finite State Machine](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/FSM.md)
    - [Target PC or embedded device](https://github.com/haditj66/QR_Core/blob/master/doc/concepts/Target_PC_Or_Embed.md) 
- [Example Projects](https://github.com/haditj66/QR_Core/blob/master/doc/Examples.md)
    - [Example world](https://github.com/haditj66/QR_Core/blob/master/doc/example/blinky.md)
    - [Example sometest](https://github.com/haditj66/QR_Core/blob/master/doc/example/motor_speed_controller.md)
- [AERTOS Tools](https://github.com/haditj66/QR_Core/blob/master/doc/AERTOS_TOOLS.md)
    
TableOfContentsForQRCore47896205709769
 
 
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
 
## writing  code for the AO in application
After you generate your project, it will have the AO code generated. There will be two files generated.
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
```
NOTE: Only write code in the UserCode_Section of these generated file as it will be overwritten next generate elsewhere in the file. 
 