#Launch files

 Launch files is just a tool to run multiple executable targets in a script. It will source what needs to be sourced and run the targets specified. 

TableOfContentsForQRCore47896205709769

TableOfContentsForQRCore47896205709769

## Creating a Launch file
These are lcoated in the QR_Sync\world2\rosqt\Launches directory. You can create a new launch file with extension ".QRL" . You can set a run command like sometest

```
QR_run <modulename> <exeTargetName> <settingFile>
```
<modulename>: name of the module
<exeTargetName>: target name you want to run
<settingFile>: setting file you want to use.

Here is an example of a launch file 

```
QR_run world2 defaultTestRos MySetting1 
WaitForMilliseconds 3000 
//QR_run world2 test2 MySetting1
QR_run sometest defaultTestRos MySetting1
WaitForUserApproval
```