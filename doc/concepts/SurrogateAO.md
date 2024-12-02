# Surrogate AO  
These add additional features from the SimpleROS AO. They work just like SimpleROS AO however they also allow surrogate functions and data syncing properties. 


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
 


## Surrogate functions  
Surrogate functions are like service functions however they are tied to a class object's function that you can unit test in the cpp project file. The implementatino of
this function will thus be the instance of that cpp function. In addition to surrogate functions, you can also set service functions as before. 


## Surrogate objects
You can have the real AO but then you will have what I call surrogates of that instance of the AO. If you create an instance called "world1" . you will be able to reference this instance 
in its own module. However if a seperate module wants to call a function from that AO, it will use a proxy object called surrogate that has the respective serivce function's client abstracted in a normal function call.
In short. surrogate objects are the fake version of the real AO being run another module.

You can get an instance of a surrogate in code by using 
```
WorldBase* wo = WorldBase::GetObjectFromPool("World1");
```
Where world1 is the name of the instance you want. Make sure that instance of AO has been created though before attempting to call. A null check on "wo" would be good practice.

## Surrogate properties  
These are the data of the surrogate object. For example, in surrogate named gameobject, there is a property named positionx, positiony, and isstatic. You can set them to be public or private set.
A private set means that no other instance will be able to change that parameter. 

Surrogate properties have the feature of keeping all data synced accross all Surrogate objects. This is done with the "DataSync" class in QR_core. This is done by the following steps

- A setPosx is called on some gameobject surrogate AO. 
- Within that surrogate, the property is immediately changed within that surrogate. 
- a service call is made to the real AO where the service function will change that property in the real AO. Afterwards, it will publish an event named setposxChanged.
- All surrogates subscribe to that event and in their callbacks will change the property. 
- a datasync session id has been given in the original setposx service call. this id, of int64 int64, will be forwarded to service functino and published event. The surrogate that made the original call checks the id, if it is a match, will ignore the setting of the property as it has already done so.




### How surrogates are instantiated. 
Whenever a real AO is instantiated, it publishes an event called <Name>Ininitialized. A class called <Name>Init located in <Name>Surrogate.h file, using Node called DataAccessManager,  subscribes to all these events and will then 
create an instance of a surrogate in the module for the respective real AO just created. 

 
## Creating a Surrogate AO
In your config file, you can do so by creating a class that inherits from AOSurrogateNode. Here is an example of a Surrogate AO name World. This AO has two surrogate functions. 
One named MoveObject, and the other named AddObjectToWorld. You can see that you can actually pass other Surrogate AO to the functions and use them as you normally would in a normal oop class.
The pattern will make it so that a surrogate is grabed in place of the passed in AO. 

```

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
        public void  DoAThing(int num1)
        {
            return 1;
        }




        public override List<ROSTimer> SetAllTimers()
        {
            return new List<ROSTimer>()
            { 
            };
        }

        public override List<ROSPublisher> SetAllPublishers()
        {
            return new List<ROSPublisher>()
            { 
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
World world = new World("World1", false);
```
 
To create a surroagate of this in another module, you would do
```
World world = new World("World1", true);
```
 
 
## writing  code for the AO in application

Here is a file structure and class structure of this pattern when generated. This example is for a surrogate AO named World

                //there are many files associated with this AO. These are all the files

                //Here is the hierarchy of the files
                //                          WorldBase
                //                          /       \
                //                         /         \      
                //             WorldBase_cppobj       \
                //                       /            \
                //                      /              \
                //                  World         WorldSurrogate  

                //                        WorldInit

                //                        WorldNodeAO --> World 
                //                             |
                //                             |
                //                        WorldNode

                //here are .h files. 
                //WorldBase.h:  WorldBase - WorldBase_cppobj
                //      includes=> All interfaces
                //            
                //World.h:  World
                //      includes=> WorldBase.h
                //
                //WorldSurrogate.h: WorldSurrogate - WorldInit
                //      includes=> World.h
                //
                //WorldNodeAO.h: WorldNodeAO  
                //      includes=> World.h
                //
                //WorldNode.hpp: WorldNode
                //      includes=> WorldNodeAO.h

                //---------------------------------------------------------------------------------------------------
                //World: this is the class that is just the simple cpp object. This is the one the user fills logic with.

                //---------------------------------------------------------------------------------------------------
                //WorldSurrogate: this is the class ROS will use to take place of the world object. It is a surrogate that
                //will be used to forward messages to whereever the real WorldAO is

                //---------------------------------------------------------------------------------------------------
                //WorldInit: this is a node that is responsible for creating the surrogates AO when the real one is created.
                //The real AO sends an event when it is created that WorldInit will use.

                //---------------------------------------------------------------------------------------------------
                //WorldNodeAO: This is the real AO object for ROS. this class will be the one to handle any ROS calls to it
                //where it will simply forward those calls to the cpp object it has.

                //---------------------------------------------------------------------------------------------------
                //WorldNode: This is the instance of the WorldNodeAO. You can have multiple instances of nodes of type WorldnodeAO .

After you generate your project, it will have the AO code generated.  
You will only be interested in the file World.h located in the cpp project and WorldNode.hpp located in the ros project. In the world file, you can implement the functions as though it was a normal cpp function.
in the  WorldNode file you would implement any service functions you declared. 
 ```
   MoveResponse MoveObject(GameobjectBase* AOObj,Move move)
    {
		//UserCode_SectionMoveObjectimp
			blablabla
		//UserCode_SectionMoveObjectimp_end
    }
```
Notice how it has the GameobjectBase as the correct type as it recoginizes it is another AO. This AO will be sent as a string id when it is called in the service function's client. and then retrieved as the surrogate function within the service callback




NOTE: Only write code in the UserCode_Section of these generated file as it will be overwritten next generate elsewhere in the file. 
 