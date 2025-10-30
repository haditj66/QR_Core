# Settings files

 Settings files allows you to change certain settings within an instance of a run of your executable. You can run multiple intances of an application with nodes of a certain name given by the settings.

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

## Creating a settings class structure
Do this in the config file. This is the class within your QRModule class. for example 
```
   public class sometestSettings : TargetSettings
   {
       public int size1 { get; set; }
       public string id { get; set; } 
   }
```
You can put primitive parameters here. For example if you want a parameter named size2 of type int put: ```public int size2 { get; set; }```

## Creating a settings instance
populate this in the GetTargetSetting() function in your config file. This will write the settings file at location /config/ALLAOSettings

## selecting a settings instance
do this in terminal. cd to your module directory and run 
```cgen QR_select <typeOfTheProject> <SettingFileName>```
 <typeOfTheProject> is 'r' for rosqt and 'c' for cpp
<SettingFileName> name of file. leave empty to get a list of available ones.

## Getting settings in application
The settings can be obtained in your project from the QRSettings class. This is populated from the "cereal" library. cereal grabs
the settings from your selected cerial file and serializes it into that class. You can get that data from the instance named ```QRSettings```. For example 
```std::string someName =  QRSettings.id;```

