# Settings files

 Settings files allows you to change certain settings within an instance of a run of your executable. You can run multiple intances of an application with nodes of a certain name given by the settings.

 
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

