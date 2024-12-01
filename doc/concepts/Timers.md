# Interfaces/Events
 
These are the ROS2 Timers.

TableOfContentsForQRCore47896205709769

TableOfContentsForQRCore47896205709769
 
 
## Creating timers
Every AO can have timers. You can create a timer by adding it to an AO class. For example, in a TestSimple2 AO
```
        public override List<ROSTimer> SetAllTimers()
        {
            return new List<ROSTimer>()
            {
                new ROSTimer("testTimer2", 1000)
            };
        }
```

  