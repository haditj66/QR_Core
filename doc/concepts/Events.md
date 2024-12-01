
# Interfaces/Events
 
These are the ROS2 interfaces. These are created automatically when you create certain AOs but can also be created individually for ROS2 subscription/publishing purposes.

TableOfContentsForQRCore47896205709769

TableOfContentsForQRCore47896205709769
 
 
## What are events
These are just ROS2 interfaces. However for AEROS, You cant create Actions. For that, you will have to do it manually as ROS2 describes. AEROS can generate ROS2 serices and messages.

 
## subcribing/publishing an event
Within the config file of your module. Whe you describe an AO, you can define publishing and subscribing. For example, take an AO called TestSimple, and one called TestSimple2.
TestSimple published a message named pub1. TestSimple2 subscribes to that message

in class TestSimple
```
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
```
in class TestSimple2
```
        public override List<ROSSubscriber> SetAllSubscribers()
        {
            return new List<ROSSubscriber>()
            {
                 ROSSubscriber.CreateSubscriber("sub1", ROSPublisher.GetPublisherOfName("pub1"), "TestSimple1")
            };
        }
```

Now in code, you can publish like this

```
pub1_Publish(counter);
 ```

The subscription callback will be generated in the AOs node file 
```
void sub1_callback(const world2_i::msg::SomeTestEvent::SharedPtr msg)
{   
}
```
 
 
 
 ## Enum events
 You can create interfaces from enums in your config file. Here is an example 
 ```
     [QREnum(typeof(world2))]
    public enum MoveResponse
    {
        SUCCESS =1,
        OBJECT_ALREADY_THERE = 2,
        OBJECT_IMMOVABLE = 3,
        CELL_OUT_OF_BOUNDS = 4,
        CELL_DESTROYED = 5
    }
 ```
 For now, make sure it follows numeric order 1,2,3,4...
 You can use this type as an argument to a service function or surrogateService function.
 
 ## Enum events in code
 Then in your application you can compare values as though it was a normal enum. For example like this
 ```
 ret.result = MoveResponse::SUCCESS;
 ```
