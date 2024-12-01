# Targets

 You can create executable targets in your projects and link them to other targets from other modules. Here are all the target types
 -cpp library target: one target per cpp project. Automatically created in InitCPPLibrary() function in config file
 -ros library target: one target per ros project. automatically created in InitROSLibrary() function in config file
 -ros executable target: 1 to many per ros project;
 -cpp executable target: 1 to many per cpp project;
 -cpp unit tests target: Each cpp project has one target by default. 
 -Interface target: automatically created. This target has all the ROS interfaces used. 
 
Look at below diagram for reference 
 ![](https://github.com/haditj66/QR_Core/tree/master/doc/images/project_structure.png)
   
   
TableOfContentsForQRCore47896205709769

TableOfContentsForQRCore47896205709769

## Creating a target
Do this in the config file. Add the following attribute to a function. That function name will now be your target name. for example a target named myfirstexe
```
    [QRTarget_RosEXE(sometest.TargetCode_if, sometest.TargetCode_rqtLibrary)]
	public void myfirstexe()
	{
	}
```
use QRTarget_cpEXE for cpp projects targets.

For the libraryies, create an instance of them in the InitCPPLibrary and InitROSLibrary.

## Creating target AOS
in the function of myfirstexe() or whereever your target function is, you can define AOs, create events, and etc. When you generate your target, it will generate the AOs
you defined within that target function.

## linking a target
To link targets to other targets, simply delcare this in the constructor of QRTarget_####( here ). Every module has codes to link to. 
-TargetCode_cppLibrary 
-TargetCode_rqtLibrary
-TargetCode_if

for example, if I wanted to link a ros library from module sometest, to a cpp library in module world2
```new QRTarget_RosLib(world2Project.world2.TargetCode_cppLibrary);```

Look at below for reference of linking structure 
 ![](https://github.com/haditj66/QR_Core/tree/master/doc/images/Link1.png)
 ![](https://github.com/haditj66/QR_Core/tree/master/doc/images/Link2.png)
 
 
 ---
Next [Settings Files](https://github.com/haditj66/QRCore/blob/master/doc/SettingsFiles.md)