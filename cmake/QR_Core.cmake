#QR_PROJECT_TYPE
#--------------
#SIMPLECPP_PROJECT
#ROS2_PROJECT
#INTERFACE



if(QR_PROJECT_TYPE STREQUAL "QR")
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Targets.cmake)
else()
    include(${QR_CORE_INSTALL_DIR}/cmake/QR_Targets.cmake)
endif()




#put this in your top level project (simplecpp project)
macro(QR_module MODULE_NAME)

    set(VARIABLE_NAME1 MODULE_NAME)
    set(VARIABLE_VALUE1 ${MODULE_NAME})
    #set a file that will be the file the current module will read from
    QR_Generate_File(
            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/config
            INPUT_FILE_NAME single_variable
            OUTPUT_FILE_NAME module_name
            OUTPUT_FILE_EXTENSION cmake
    )


    set(VARIABLE_NAME1 MODULE_NAME_DEP)
    set(VARIABLE_VALUE1 ${MODULE_NAME})
    #set a file that will what OTHER modules will read from. this is needed because the variables set need to be
    #different for the different contexts. (dont want to overwrite the MODULE_NAME vairable in other modules)
    QR_Generate_File(
            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/config
            INPUT_FILE_NAME single_variable
            OUTPUT_FILE_NAME module_name_dep
            OUTPUT_FILE_EXTENSION cmake
    )



endmacro()




#******************************************************************************************************************************************************************
#This will add the AO to the module into a list. When QR_done is called, it will generate a file named AOConfig.cmake
macro(QR_set_AO AO)
set(AO_TO_SET ${AO_TO_SET} ${AO} )
endmacro()


#******************************************************************************************************************************************************************
#this will pull the cmake file that has the module name for this module
macro(QR_project)

    #use this variable to get the base path to the module
    set(MODULE_BASE_PATH)
    set(MODULE_NAMESPACE)



    if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")

        add_compile_definitions(SIMPLECPP_PROJECT)
        set(MODULE_BASE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

        #read what the module name is
        include(config/module_name.cmake)

        #append a "cp" to the project name
        project(${MODULE_NAME}_cp)

        set(MODULE_NAMESPACE ${MODULE_NAME}_cp)



    elseif(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")

        add_compile_definitions(ROS2_PROJECT)

        set(MODULE_BASE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")

        include(${MODULE_BASE_PATH}/config/module_name.cmake)

        #include the AOconfig.cmake as you will need those variables defined in the _cp project
        include(${MODULE_BASE_PATH}/config/AOConfig.cmake)

        #append a "rqt" to the project name
        project(${MODULE_NAME}_rqt)

        set(MODULE_NAMESPACE ${MODULE_NAME}_rqt)


    elseif(QR_PROJECT_TYPE STREQUAL "INTERFACE")

        set(MODULE_BASE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../..")

        include(${MODULE_BASE_PATH}/config/module_name.cmake)

        #append a "i" to the project name
        project(${MODULE_NAME}_i)

        set(MODULE_NAMESPACE ${MODULE_NAME}_i)


    else()
        message(FATAL_ERROR "HADI: you didnt specify the variable QR_PROJECT_TYPE")

    endif()

    #add some global preprocessors
    add_compile_definitions(MODULE_NAMESPACE=${MODULE_NAMESPACE})
    add_compile_definitions(MODULE_NAME=${MODULE_NAME})
    add_compile_definitions(DataNodeName=${MODULE_NAME}DataAccessNode)
    add_compile_definitions(CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})



    #generate initial setup files

    #generate the Config file from the generated files folder for Config.in.
#    QR_Generate_File(
#            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
#            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
#            INPUT_FILE_NAME Config
#            OUTPUT_FILE_NAME Config
#            OUTPUT_FILE_EXTENSION hpp
#    )

# set(AO_TO_SET ${AO_TO_SET} AllSurrogates)#NoAODesignPattern)
# set(AO_TO_SET ${AO_TO_SET} AllRealAO)

if(QR_PROJECT_TYPE STREQUAL "INTERFACE")
else()
#_QR_Generate_Config() this is now done in cgen generate

    message("Config file  built. at location  ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}")
endif()


    #generate the visibiliry control file from the generated files folder for visibility_control.in.
#    QR_Generate_File(
#            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
#            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
#            INPUT_FILE_NAME visibility_control
#            OUTPUT_FILE_NAME visibility_control
#            OUTPUT_FILE_EXTENSION h
#    )



    #get source and header files
    QR_Get_Source_And_Header_files()



endmacro()






#******************************************************************************************************************************************************************
#generate the config file that is used for settings. Will generate a config per AO_TO_SET that is set
# PACKAGES_CPP_LIST: this is for packages of CPP_Library type
# PACKAGES_ROSQT_LIST: this is for packages of ROS_Library type
# PACKAGES_INTERFACE_LIST: for INTERFACES type packages ONLY
 macro(_QR_Generate_Config)
     set(options)
     set(oneValueArgs)
     set(multiValueArgs  )
     cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



     MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )

     #create the MP template for packages.xml
     MP_create_instance_of_multiparameter_template(

         LIST_OF_ALL_TEMPLATE_VARIABLES
                    SETTINGS

         GROUPS_OF_MULTIPARAMS SETTING_GROUP

         IS_THIS_USING_CGEN TRUE

         NAMEOFTEMPLATE CONFIG_TEMPLATE
         WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
         INPUT_FILE_NAMES     Config
         OUTPUT_FILE_NAMES    Config
         OUTPUT_FILE_EXTENSIONS hpp)


     #foreach AO_TO_SET that is set, create a settings file.
     foreach(AOset ${AO_TO_SET})

         MP_define_group_of_multiparams_for_template_instance(
             FORTHISGROUP SETTING_GROUP
             NAME_OF_TEMPLATE CONFIG_TEMPLATE)


         MP_define_multiparameter(
             FOR_PARAMETER SETTINGS
             WITH_VALUE "
             #ifdef ${AOset}Real
             class QR_Settings
             {
             public:
               std::string id;

               //put the variables you want to have as settings
               //for example
               //int size1;
               //std:string someothersetting
               ##UserCode_${AOset}a

               // This method lets cereal know which data members to serialize.
               template<class Archive>
               void serialize(Archive & archive)
               {

                 //you need to now set these variables in the archive. For example
                 //for example:
                 //archive(CEREAL_NVP(id),CEREAL_NVP(size1), CEREAL_NVP(someothersetting));
                 ##UserCode_${AOset}b

               }
             };


             ##UserCode_${AOset}c

             #endif
             "
             )

         MP_done_defining_group()

       endforeach()

       MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE CONFIG_TEMPLATE
           ADDITIONAL_GENERATED_FILE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})


#     Generate_File_Using_Cgen(
#             INPUT_DIRECTORY ${QR_CORE_DIR}/GeneratedFiles
#             OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
#             INPUT_FILE_NAME Config
#             OUTPUT_FILE_NAME Config
#             OUTPUT_FILE_EXTENSION .hpp
#     )

endmacro()


#******************************************************************************************************************************************************************

#this will generate files from an input file INPUT_FILE_NAME located at WORKINGDIRECTORYOFINPUTFILE
#over to output file OUTPUT_FILE_NAME located at WORKINGDIRECTORYOFOUTPUTFILE with extenstion OUTPUT_FILE_EXTENSION
#IF_FILE_DOESNT_EXIST: set to TRUE or ON if you only want to generate the file if it does NOT exist
function(QR_Generate_File )
    set(options)
    set(oneValueArgs IF_FILE_DOESNT_EXIST WORKINGDIRECTORYOFINPUTFILE WORKINGDIRECTORYOFOUTPUTFILE INPUT_FILE_NAME OUTPUT_FILE_NAME OUTPUT_FILE_EXTENSION)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    #if the file exists, dont do anything if the IF_FILE_EXISTS is true otherwise, if not defined, default to false
    if(DEFINED _arg_IF_FILE_DOESNT_EXIST )
        if(${_arg_IF_FILE_DOESNT_EXIST} STREQUAL "ON" OR ${_arg_IF_FILE_DOESNT_EXIST} STREQUAL "TRUE" )

            #check if it exists. If it does, do nothing
            if(EXISTS ${_arg_WORKINGDIRECTORYOFOUTPUTFILE}/${_arg_OUTPUT_FILE_NAME}.${_arg_OUTPUT_FILE_EXTENSION})
                return()
            endif()

        endif()
    endif()


    message("**************************${_arg_WORKINGDIRECTORYOFINPUTFILE}/GeneratedFiles/${_arg_INPUT_FILE_NAME} ")
    message("**************************${_arg_WORKINGDIRECTORYOFOUTPUTFILE}/${_arg_OUTPUT_FILE_NAME}.${_arg_OUTPUT_FILE_EXTENSION}  ")


    if(NOT DEFINED _arg_WORKINGDIRECTORYOFINPUTFILE)
        set(_arg_WORKINGDIRECTORYOFINPUTFILE ${CMAKE_SOURCE_DIR})
    endif()

    #first make sure the input file even exists. if not, dont do anything
    if (NOT EXISTS ${_arg_WORKINGDIRECTORYOFINPUTFILE}/GeneratedFiles/${_arg_INPUT_FILE_NAME}.in)
        message(WARNING "HADI: the input file ${_arg_WORKINGDIRECTORYOFINPUTFILE}/GeneratedFiles/${_arg_INPUT_FILE_NAME}.in  did not exist when
                attempting to cgen generate macro.")
        return()
    endif ()

    #generate the file
    configure_file(${_arg_WORKINGDIRECTORYOFINPUTFILE}/GeneratedFiles/${_arg_INPUT_FILE_NAME}.in
            ${_arg_WORKINGDIRECTORYOFOUTPUTFILE}/${_arg_OUTPUT_FILE_NAME}.${_arg_OUTPUT_FILE_EXTENSION} @ONLY)


 endfunction()





#this will find all packages that are for INTERFACES type packages ONLY
#  macro(QR_Find_List_Of_Ros_Interfaces)
#      set(options)
#      set(oneValueArgs)
#      set(multiValueArgs PACKAGES_LIST)
#      cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
#  endmacro()



 #******************************************************************************************************************************************************************
#this will find all packages for ROS2 as well as autogenerating the package.xml file.
# PACKAGES_CPP_LIST: this is for packages of CPP_Library type
# PACKAGES_ROSQT_LIST: this is for packages of ROS_Library type
# PACKAGES_INTERFACE_LIST: for INTERFACES type packages ONLY
  macro(QR_Find_List_Of_Ros_Packages)
      set(options)
      set(oneValueArgs)
      set(multiValueArgs PACKAGES_CPP_LIST  PACKAGES_ROSQT_LIST PACKAGES_INTERFACE_LIST NON_QR_PACKAGES_LIST NON_QR_PACKAGES_INTERFACE_LIST)
      cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



      #based on PACKAGES_CPP_LIST, append a _cp . or if PACKAGES_ROSQT_LIST append a _rqt
      foreach(pkg ${_arg_PACKAGES_CPP_LIST})

        #if you are linking the cpp project via the copy and paste method, ignore same module cpp project linking.
        if(DEFINED COPY_PASTE_STYLE_LINKING)
            if("${pkg}" STREQUAL "${MODULE_NAME}")
            else()
                set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} ${pkg}_cp )
            endif()

        else()
            #if not copy-and-paste linking, just add everything as usual.
            set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} ${pkg}_cp )
        endif()
      endforeach()

      foreach(pkg ${_arg_PACKAGES_ROSQT_LIST})
        set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} ${pkg}_rqt )
      endforeach()


      foreach(pkg ${_arg_NON_QR_PACKAGES_LIST})
        set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} ${pkg} )
      endforeach()

      #again for interfaces
      foreach(pkg ${_arg_PACKAGES_INTERFACE_LIST})
        set(_arg_INTERFACE_LIST ${_arg_INTERFACE_LIST} ${pkg}_i )
      endforeach()
      #by default have a link to this modules internal interface. (if not the interface project itself)
      if(QR_PROJECT_TYPE STREQUAL "INTERFACE" OR QR_PROJECT_TYPE STREQUAL "QR")
          message("OVER HERE!!!!!!!!!!!!!!!!!! 1")
      else()
        set(_arg_INTERFACE_LIST ${_arg_INTERFACE_LIST} ${MODULE_NAME}_i )
        set(_arg_INTERFACE_LIST ${_arg_INTERFACE_LIST} qr_core )
      endif()

      foreach(pkg ${_arg_NON_QR_PACKAGES_INTERFACE_LIST})
        set(_arg_INTERFACE_LIST ${_arg_INTERFACE_LIST} ${pkg} )
      endforeach()




#      if(${_arg_PACKAGES_INTERFACE_LIST} STREQUAL "")
#          set
#      endif()



    # Para aplicacion QWidgets añadir --> Core Gui Widgets
    # Para aplicacion QML añadir --> Core Gui Quick
    if(${ISForQT} STREQUAL "ON" )

        find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED) #Ejemplo para QWidget

        if(${ISForQT} STREQUAL "ON" )


            file(GLOB QtHEADERS
                "${CMAKE_CURRENT_SOURCE_DIR}/include/MyQtHeaders/*.hpp"  "${CMAKE_CURRENT_SOURCE_DIR}/include/MyQtHeaders/*.h"
              )
          file(GLOB QtSOURCES
              "${CMAKE_CURRENT_SOURCE_DIR}/src/MyQtSrcs/*.cpp"  "${CMAKE_CURRENT_SOURCE_DIR}/include/MyQtHeaders/*.c"
            )

            file(GLOB UIS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
              ui/*.ui
              )
            file(GLOB RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
              resources/*.qrc
              )

          QT5_ADD_RESOURCES(QT_RESOURCES ${RESOURCES})
          QT5_WRAP_UI(QT_UIS ${UIS})
          QT5_WRAP_CPP(QT_HEADERS ${QtHEADERS})

             message("QtSOURCES -------- ${QtSOURCES}")
              message("QtHEADERS -------- ${QtHEADERS}")

        endif()
    endif()

    find_package(ament_cmake REQUIRED)
    find_package(ament_cmake_auto REQUIRED)



    #dont include any ros stuff if this is a simple cpp project
    if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")


#        find_package(ament_cmake_ros REQUIRED)

#        #by default "rclcpp" and "rclcpp_components" should be included in every ros2 project.
       set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} "rclcpp" "rclcpp_components")

#       #for interface stuff. std_msgs and builtin_interfaces are really commonly used so I'll keep them here as default
#       find_package(rosidl_default_generators REQUIRED)
#       find_package(std_msgs REQUIRED)
#       find_package(builtin_interfaces REQUIRED)



        MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )

        #create the MP template for packages.xml
        MP_create_instance_of_multiparameter_template(

            LIST_OF_ALL_TEMPLATE_VARIABLES
                       PACKAGE_DEPEND
                       PACKAGE_INTERFACE_DEPEND
                       PACKAGE_INTERFACE_EXECDEPEND

            GROUPS_OF_MULTIPARAMS PACKAGES PACKAGE_INTERFACES

            IS_THIS_USING_CGEN FALSE

            NAMEOFTEMPLATE PACKAGEXML
            WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
            INPUT_FILE_NAMES     packagecpp
            OUTPUT_FILE_NAMES    package
            OUTPUT_FILE_EXTENSIONS xml)

    else()

        set(PKGNAME)
        if(QR_PROJECT_TYPE STREQUAL "QR")
            set(PKGNAME packageqr)
        elseif(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")
            set(PKGNAME packageros)
        else()
            set(PKGNAME package)
        endif()


        find_package(ament_cmake_ros REQUIRED)

        #by default "rclcpp" and "rclcpp_components" should be included in every ros2 project.
       set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} "rclcpp" "rclcpp_components")

       #for interface stuff. std_msgs and builtin_interfaces are really commonly used so I'll keep them here as default
       find_package(rosidl_default_generators REQUIRED)
       find_package(std_msgs REQUIRED)
       find_package(builtin_interfaces REQUIRED)



       MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )

       #create the MP template for packages.xml
       MP_create_instance_of_multiparameter_template(

           LIST_OF_ALL_TEMPLATE_VARIABLES
                      PACKAGE_DEPEND
                      PACKAGE_INTERFACE_DEPEND
                      PACKAGE_INTERFACE_EXECDEPEND

           GROUPS_OF_MULTIPARAMS PACKAGES PACKAGE_INTERFACES

           IS_THIS_USING_CGEN FALSE

           NAMEOFTEMPLATE PACKAGEXML
           WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
           INPUT_FILE_NAMES     ${PKGNAME}
           OUTPUT_FILE_NAMES    package
           OUTPUT_FILE_EXTENSIONS xml)

    endif()






      foreach(pkg ${_arg_PACKAGES_LIST})

          MP_define_group_of_multiparams_for_template_instance(
              FORTHISGROUP PACKAGES
              NAME_OF_TEMPLATE PACKAGEXML)

          MP_define_multiparameter(
              FOR_PARAMETER PACKAGE_DEPEND
              WITH_VALUE "<depend>${pkg}</depend>\n"
              )

          MP_done_defining_group()

        endforeach()


        #define template packages for interfaces
        foreach(pkg ${_arg_INTERFACE_LIST})

            MP_define_group_of_multiparams_for_template_instance(
                FORTHISGROUP PACKAGE_INTERFACES
                NAME_OF_TEMPLATE PACKAGEXML)

            MP_define_multiparameter(
                FOR_PARAMETER PACKAGE_INTERFACE_DEPEND
                WITH_VALUE "<build_depend>${pkg}</build_depend>\n<buildtool_depend>${pkg}</buildtool_depend>\n"
                )

            MP_define_multiparameter(
                FOR_PARAMETER PACKAGE_INTERFACE_EXECDEPEND
                WITH_VALUE "<exec_depend>${pkg}</exec_depend>\n"
                )

            MP_done_defining_group()

          endforeach()


        #set(_arg_Macro4 1)
        MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE PACKAGEXML
            ADDITIONAL_GENERATED_FILE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR})



        #put all package variables in the a variable for the  ament_auto_find_build_dependencies
        set(ROS2_DEPENDENCIES ${_arg_PACKAGES_LIST})
        set(ALL_DEPENDS ${_arg_INTERFACE_LIST})
        set(ALL_DEPENDS ${ALL_DEPENDS} ${_arg_PACKAGES_LIST})
        ament_auto_find_build_dependencies(REQUIRED ${ALL_DEPENDS})









      #message("**************************${_arg_PACKAGES_LIST}")



   endmacro()




   #******************************************************************************************************************************************************************
   #this will grab all .h .hpp in include/PROJECTNAME directory and .cpp .c files in src directory
   #
   macro(QR_Get_Source_And_Header_files)



#       file(GLOB HEADERS
#           "${CMAKE_CURRENT_SOURCE_DIR}/components/*.hpp"  "${CMAKE_CURRENT_SOURCE_DIR}/components/*.h"
#         )
#       file(GLOB SOURCES
#           "${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp"  "${CMAKE_CURRENT_SOURCE_DIR}/components/*.c"
#         )



       ##############################################################################
       # get my source and header files
       ##############################################################################


       file(GLOB HEADERS
           "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.hpp"  "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h"
         )
       file(GLOB SOURCES
           "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
         )

     #remove the main files associated for exe targets.
     file(GLOB SOURCES_MAIN_REMOVE
          "${CMAKE_CURRENT_SOURCE_DIR}/src/*_QRmain.cpp"
       )

   if(  SOURCES_MAIN_REMOVE STREQUAL "" )
   else()
       list(REMOVE_ITEM SOURCES ${SOURCES_MAIN_REMOVE})
   endif()


       ##############################################################################
       # QT5 - FILES PATH | AUTO SET
       ##############################################################################

       set(CMAKE_INCLUDE_CURRENT_DIR ON)





   endmacro()








   #******************************************************************************************************************************************************************
   # register nodes in your library target as composable
   macro(QR_Register_Nodes_As_Composable)
       set(options)
       set(oneValueArgs)
       set(multiValueArgs NODE_LIST_TO_REGISTER)
       cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

       foreach(node ${_arg_NODE_LIST_TO_REGISTER})
       #message("node -------- ${node}")
       rclcpp_components_register_nodes(${MODULE_NAME}_ROSlib  "${MODULE_NAME}::${node}")

       endforeach()


   endmacro()












   ################################################################################
   #mes ang srv stuff
   ################################################################################



#call this function before you start creating interfaces in cmake
   macro(QR_initialize_interfaces)
       set(options)
       set(oneValueArgs )
       set(multiValueArgs )
       cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


       if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")

           if(NOT DEFINED GAURD_TO_INTERFACE_TEMPLATE_INIT)
               set(GAURD_TO_INTERFACE_TEMPLATE_INIT 1)


               MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )

               #create an instance of the CMAKE_FOR_INTERFACE template.
               MP_create_instance_of_multiparameter_template(
                   LIST_OF_ALL_TEMPLATE_VARIABLES
                              INTERFACES_CREATED
                              SERVICES_CREATED

                   GROUPS_OF_MULTIPARAMS INTERFACES SERVICES

                   NAMEOFTEMPLATE cmake_interface_template
                   WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
                   INPUT_FILE_NAMES     Cmake_For_Interface
                   OUTPUT_FILE_NAMES    CMakeLists
                   OUTPUT_FILE_EXTENSIONS txt)

           endif()

       endif()

   endmacro()




#******************************************************************************************************************************************************************
#creates an msg interface. this will work differently depending on the project type of interface or ros2 project type.
#NAME_OF_MESSAGE
#INTERFACE_PKGS_THIS_PKG_DEPENDS_ON: all other interfaces this interface uses.
   macro(QR_create_message_interface)
       set(options)
       set(oneValueArgs NAME_OF_MESSAGE)
       set(multiValueArgs INTERFACE_PKGS_THIS_PKG_DEPENDS_ON)
       cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})




        ########
        #if the QR_PROJECT_TYPE is a ROS2_PROJECT, set the group variables in the MP templates
        ########
        if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")


      #Do this part just once


           #create a new group for template instance.
           MP_define_group_of_multiparams_for_template_instance(
               FORTHISGROUP INTERFACES
               NAME_OF_TEMPLATE cmake_interface_template)

           set(temp_arg_inter ${_arg_INTERFACE_PKGS_THIS_PKG_DEPENDS_ON})


            #message("temp_arg_inter =================   ${temp_arg_inter}")
            string(REPLACE ";" " " temp_arg_inter "${temp_arg_inter}")
            #message("temp_arg_inter =================   ${temp_arg_inter}")

           MP_define_multiparameter(
               FOR_PARAMETER INTERFACES_CREATED
               WITH_VALUE "
QR_create_message_interface(
NAME_OF_MESSAGE
${_arg_NAME_OF_MESSAGE}

INTERFACE_PKGS_THIS_PKG_DEPENDS_ON
${temp_arg_inter}
)\n"
               )


           MP_done_defining_group(  )


        #return()
        endif()


        ########
        #if the QR_PROJECT_TYPE is an INTERFACE, set the appropriate variables and call whatever needs to be called
        #to create the interface
        ########
        if(QR_PROJECT_TYPE STREQUAL "INTERFACE" OR QR_PROJECT_TYPE STREQUAL "QR")


            message("OVER HERE!!!!!!!!!!!!!!!!!! 2")

                   #if a file of that name does not exist get, create it.
                   if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/msg/${_arg_NAME_OF_MESSAGE}.msg)
                           file(WRITE msg/${_arg_NAME_OF_MESSAGE}.msg "string blablas" )
                   endif()

                   #since rosidl_generate_interfaces needs to be called only once, put all interfaces
                   #into a variable
                   list(APPEND ALL_INTERFACES_CREATED  "msg/${_arg_NAME_OF_MESSAGE}.msg")
                   list(APPEND ALL_DEPENDENCIES_NEED_FOR_INTERFACES  "${_arg_INTERFACE_PKGS_THIS_PKG_DEPENDS_ON}")

        #       string(REPLACE " " ":" ALL_INTERFACES_CREATED ${ALL_INTERFACES_CREATED})
        #       string(REPLACE " " ":" ALL_DEPENDENCIES_NEED_FOR_INTERFACES ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})

        #return()
        endif()

   endmacro()









   #******************************************************************************************************************************************************************
   #creates an msg interface. this will work differently depending on the project type of interface or ros2 project type.
   #NAME_OF_MESSAGE
   #INTERFACE_PKGS_THIS_PKG_DEPENDS_ON: all other interfaces this interface uses.
      macro(QR_create_service_interface)
          set(options)
          set(oneValueArgs NAME_OF_MESSAGE)
          set(multiValueArgs INTERFACE_PKGS_THIS_PKG_DEPENDS_ON)
          cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})




           ########
           #if the QR_PROJECT_TYPE is a ROS2_PROJECT, set the group variables in the MP templates
           ########
           if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")


         #Do this part just once


              #create a new group for template instance.
              MP_define_group_of_multiparams_for_template_instance(
                  FORTHISGROUP SERVICES
                  NAME_OF_TEMPLATE cmake_interface_template)

              set(temp_arg_inter ${_arg_INTERFACE_PKGS_THIS_PKG_DEPENDS_ON})


               #message("temp_arg_inter =================   ${temp_arg_inter}")
               string(REPLACE ";" " " temp_arg_inter "${temp_arg_inter}")
               #message("temp_arg_inter =================   ${temp_arg_inter}")

              MP_define_multiparameter(
                  FOR_PARAMETER SERVICES_CREATED
                  WITH_VALUE "
   QR_create_service_interface(
   NAME_OF_MESSAGE
   ${_arg_NAME_OF_MESSAGE}

   INTERFACE_PKGS_THIS_PKG_DEPENDS_ON
   ${temp_arg_inter}
   )\n"
                  )


              MP_done_defining_group(  )


           #return()
           endif()


           ########
           #if the QR_PROJECT_TYPE is an INTERFACE, set the appropriate variables and call whatever needs to be called
           #to create the interface
           ########
           if(QR_PROJECT_TYPE STREQUAL "INTERFACE" OR QR_PROJECT_TYPE STREQUAL "QR")
               message("OVER HERE!!!!!!!!!!!!!!!!!! 3")


                      #if a file of that name does not exist get, create it.
                      if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/srv/${_arg_NAME_OF_MESSAGE}.srv)
                              file(WRITE srv/${_arg_NAME_OF_MESSAGE}.srv "string blaresponse\n---\nstring blainput" )
                      endif()

                      #since rosidl_generate_interfaces needs to be called only once, put all interfaces
                      #into a variable
                      list(APPEND ALL_INTERFACES_CREATED  "srv/${_arg_NAME_OF_MESSAGE}.srv")
                      list(APPEND ALL_DEPENDENCIES_NEED_FOR_INTERFACES  "${_arg_INTERFACE_PKGS_THIS_PKG_DEPENDS_ON}")

           #       string(REPLACE " " ":" ALL_INTERFACES_CREATED ${ALL_INTERFACES_CREATED})
           #       string(REPLACE " " ":" ALL_DEPENDENCIES_NEED_FOR_INTERFACES ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})

           #return()
           endif()

      endmacro()









   #******************************************************************************************************************************************************************
   #finished creating interface.
    macro(QR_done_creating_interfaces)
        set(options)
        set(oneValueArgs  )
        set(multiValueArgs  )
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})




        if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")

            MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE cmake_interface_template
                ADDITIONAL_GENERATED_FILE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/rosqt/IF)

        #return()
        endif()

        if(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")

            MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE cmake_interface_template
                ADDITIONAL_GENERATED_FILE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/IF)

        #return()
        endif()


        if(QR_PROJECT_TYPE STREQUAL "INTERFACE" OR QR_PROJECT_TYPE STREQUAL "QR")
            message("OVER HERE!!!!!!!!!!!!!!!!!! 4")

            message("ALL_INTERFACES_CREATED ssssssss00000000000000000000000000000 ${ALL_INTERFACES_CREATED}")

            #generate msg files
#            rosidl_generate_interfaces(${MODULE_NAME}
#               ${ALL_INTERFACES_CREATED}
#              DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES} #builtin_interfaces std_msgs # ${INTERFACE_PKGS_THIS_PKG_DEPENDS_ON}  #
#              ADD_LINTER_TESTS
#              )

#this is the correct way to do it I guess. As explained here
#              ${ALL_INTERFACES_CREATED}
#https://github.com/ros2/rosidl/issues/441

#          rosidl_generate_interfaces(${MODULE_NAME}
#              LIBRARY_NAME ${MODULE_NAME}_rqt
#              DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})

#rosidl_generate_interfaces(${MODULE_NAME}
#    ${ALL_INTERFACES_CREATED}
#    LIBRARY_NAME ${MODULE_NAME}_i
#    DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})

list(LENGTH ALL_INTERFACES_CREATED list_length)

if(QR_PROJECT_TYPE STREQUAL "INTERFACE" )
    if(NOT list_length EQUAL 0)

    rosidl_generate_interfaces(${MODULE_NAME}_i
        ${ALL_INTERFACES_CREATED}
        LIBRARY_NAME ${MODULE_NAME}_i
        DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})
    endif()
elseif(QR_PROJECT_TYPE STREQUAL "QR")
    if(NOT list_length EQUAL 0)

    rosidl_generate_interfaces(${MODULE_NAME}
        ${ALL_INTERFACES_CREATED}
        DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES} #builtin_interfaces std_msgs # ${INTERFACE_PKGS_THIS_PKG_DEPENDS_ON}  #
        ADD_LINTER_TESTS
               )
    endif()
endif()

        #return()
        endif()



  endmacro()



   #******************************************************************************************************************************************************************
   #build the interface project associated with this project. Note that (at least for now) in a windows
   #environment this wont be done as it would give an error while building within an ide.
    macro(QR_build_interface_project)
        set(options)
        set(oneValueArgs  )
        set(multiValueArgs  )
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

        #TODO: DONT BUILD ANY PROJECT AS A SUBDIRECTORY ANYMORE. TOO MANY ISSUES CAN POP UP AND I WONT KNOw WHICH PROJECT  IT IS
        #COMING FROM.
        if(NOT WIN32)
            if(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")
                #add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/IF)
            endif()

            if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")
                message("asdasdasdasdasdasdasdasdasdasdasdasd")
                #add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/rosqt/IF)
            endif()

        endif()

  endmacro()



   #creates an msg interface
   #NAME_OF_MESSAGE
   #INTERFACE_PKGS_THIS_PKG_DEPENDS_ON: all other interfaces this interface uses.
#   macro(QR_create_service_interface)
#       set(options)
#       set(oneValueArgs NAME_OF_SERVICE)
#       set(multiValueArgs INTERFACE_PKGS_THIS_PKG_DEPENDS_ON)
#       cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


#       #generate msg files
#       rosidl_generate_interfaces(${MODULE_NAME}
#         msg/${_arg_NAME_OF_MESSAGE}.msg
#         DEPENDENCIES  ${_arg_INTERFACE_PKGS_THIS_PKG_DEPENDS_ON} #builtin_interfaces std_msgs # ${INTERFACE_PKGS_THIS_PKG_DEPENDS_ON}  #
#         ADD_LINTER_TESTS
#         )

#   endmacro()



    #******************************************************************************************************************************************************************
    #utility function for set source group
    function(Set_Sources_in_SourceGroup )
    set(options)
    set(oneValueArgs NAMEOFGROUP)
    set(multiValueArgs LISTOFSOURCES)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    foreach(source IN LISTS _arg_LISTOFSOURCES)
    source_group("${_arg_NAMEOFGROUP}" FILES "${source}")
    endforeach()
    endfunction()




   #******************************************************************************************************************************************************************
   #call this function at the end of your cmake QR  project
    macro(QR_done)
        set(options)
        set(oneValueArgs )
        set(multiValueArgs )
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


        QR_build_interface_project()

        #for organization
        Set_Sources_in_SourceGroup(NAMEOFGROUP "Include files" LISTOFSOURCES  ${HEADERS})
        Set_Sources_in_SourceGroup(NAMEOFGROUP "Qt Include files" LISTOFSOURCES  ${QtHEADERS})
        Set_Sources_in_SourceGroup(NAMEOFGROUP "Qt Source files" LISTOFSOURCES  ${QtSOURCES})
#        source_group("Include files" FILES ${HEADERS})
#        source_group("Qt Include files" FILES ${QtHEADERS})
#        source_group("Qt Source files" FILES ${QtSOURCES})



        # generate the AO config file. This will be read by the module and linked modules to get all AOs that exist.
        set(VARIABLE_VALUE1 ${AO_TO_SET})
        set(VARIABLE_NAME1 AO_TO_SET)
        QR_Generate_File(
                WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
                WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/config
                INPUT_FILE_NAME single_variable
                OUTPUT_FILE_NAME AOConfig
                OUTPUT_FILE_EXTENSION cmake
        )




        #this will wrap up ament and also send any extra files you want in the package.
        #most likely, a cgen cmake options file for that package will be wrapped up. This will
        # be some options that that particular package will need.
        ament_package(
            CONFIG_EXTRAS "${MODULE_BASE_PATH}/config/AOConfig.cmake" #send this file out so that all other modules that link to this module will be able to have the list of AOs used.
            )
          #CONFIG_EXTRAS "cmake/bla.cmake"

        #end cgen
        Cgen_End()


    endmacro()













################################################################################
#utilities
################################################################################


   #******************************************************************************************************************************************************************
   #Will give you a list range of number from TO to FROM
   #FROM:
   #TO:
   #RETURNEDLIST: returned list
   function(give_range_of_ints)
       set(options)
       set(oneValueArgs FROM TO )
       set(multiValueArgs)
       cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

       set(INCLIST ${_arg_FROM} )
       set(INCR ${_arg_FROM})
       while(${INCR} LESS ${_arg_TO})
           MATH(EXPR INCR "${INCR}+1")
           set(INCLIST ${INCLIST} ${INCR})

       endwhile()

       set(RETURNEDLIST ${INCLIST}  PARENT_SCOPE)

   endfunction()





#******************************************************************************************************************************************************************
   #Will give you a list of directories within a directory
   #example of usage
   #SUBDIRLIST(SUBDIRS ${MY_CURRENT_DIR})
   #FOREACH(subdir ${SUBDIRS})
   #	  ADD_SUBDIRECTORY(${subdir})
   #ENDFOREACH()
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()




#******************************************************************************************************************************************************************
   #this function will take a string and make all uppercase letters lowercase.
   #also, any uppercase letters will have an underscore before the letter. (except for the first letter)
   #example:
   #helloWorld  ->  hello_world
   #HelloWorld  ->  hello_world
   #INPUT_STRING: the string passed into the function
   #OUTPUT_STRING: output of the function
   function(to_lowercase_with_underscore)
          set(options )
          set(oneValueArgs   INPUT_STRING)
          set(multiValueArgs   )

          cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
   #       set(hell A B C D E F G H I J K L M N O P Q R S T U V W X Y Z )
          #string(FIND ${_arg_INPUT_STRING} w liststr)

          #set(output_copy ${_arg_INPUT_STRING})

             string(REGEX MATCHALL  "[A-Z]"  hell ${_arg_INPUT_STRING} )

          foreach(UpperLetter ${hell})
              string(TOLOWER ${UpperLetter} LowerLetter)
              string(FIND ${_arg_INPUT_STRING} ${UpperLetter} liststr)

                   if(NOT ${liststr} STREQUAL -1 )
                       if(NOT DEFINED boolGuard)
                          set(boolGuard 1)
                       string(REPLACE "${UpperLetter}" "${LowerLetter}" _arg_INPUT_STRING ${_arg_INPUT_STRING})
                        else()
                          string(REPLACE "${UpperLetter}" "_${LowerLetter}" _arg_INPUT_STRING ${_arg_INPUT_STRING})
                       endif()
                   endif()

          endforeach()



          set(OUTPUT_STRING ${_arg_INPUT_STRING} PARENT_SCOPE)

   endfunction()



#******************************************************************************************************************************************************************
#return true if string has any digit in .
#string_has_any_digits(INPUT_STRING whatev_erRrstring2315)
function(string_has_any_digits)
          set(options)
          set(oneValueArgs INPUT_STRING )
          set(multiValueArgs)
          cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
   #is meant to have the output result

          string(REGEX MATCH "[0-9]" findnum ${_arg_INPUT_STRING} )
          if("${findnum}"  STREQUAL "" )
              set(ARG_OUTPUT_BOOL FALSE)
          else()
              set(ARG_OUTPUT_BOOL TRUE)
          endif()
          set(OUTPUT_BOOL ${ARG_OUTPUT_BOOL} PARENT_SCOPE)


endfunction()






#******************************************************************************************************************************************************************
#get all targets in a cmake file so far
#get_all_targets(all_targets)
#message("All targets: ${all_targets}")
function(get_all_targets var)
    set(targets)
    get_all_targets_recursive(targets ${CMAKE_CURRENT_SOURCE_DIR})
    set(${var} ${targets} PARENT_SCOPE)
endfunction()

macro(get_all_targets_recursive targets dir)
    get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)
    foreach(subdir ${subdirectories})
        get_all_targets_recursive(${targets} ${subdir})
    endforeach()

    get_property(current_targets DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
    list(APPEND ${targets} ${current_targets})
endmacro()







##########################
##generate a cgen macro file given a .in file located in the GeneratedFiles folder
##INPUT_FILE_NAME: the .in file name in the GeneratedFiles folder that will be used to generate the file
##OUTPUT_FILE_NAME: the name of the file outputted. (just name without extension not including path )
##OUTPUT_FILE_EXTENSION: extension of output file
##OUTPUT_DIRECTORY the directory to put the generated file
##INPUT_DIRECTORY the directory that your inpur cgen file is in. make sure that the file is of extension .cgenM.in
#function(Generate_File_Using_Cgen )
#    set(options)
#    set(oneValueArgs INPUT_DIRECTORY OUTPUT_DIRECTORY INPUT_FILE_NAME OUTPUT_FILE_NAME OUTPUT_FILE_EXTENSION
#        Macro1 Macro2 Macro3 Macro4 Macro5 Macro6 Macro7 Macro8 Macro9 Macro10
#        Macro11 Macro12 Macro13 Macro14 Macro15 Macro16 Macro17 Macro18 Macro19 Macro20
#        Macro21 Macro22 Macro23 Macro24 Macro25 Macro26 Macro27 Macro28 Macro29 Macro30
#        Macro31 Macro32 Macro33 Macro34 Macro35 Macro36 Macro37 Macro38 Macro39 Macro40
#        Macro41 Macro42 Macro43 Macro44 Macro45 Macro46 Macro47 Macro48 Macro49 Macro50
#        LoopIncrement1 LoopIncrement2 LoopIncrement3 LoopIncrement4 LoopIncrement5
#        LoopIncrement6 LoopIncrement7 LoopIncrement8 LoopIncrement9 LoopIncrement10
#        )
#    set(multiValueArgs)
#    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


#    #if generated file does not exist yet, create it
#    #if(NOT EXISTS "${_arg_WORKINGDIRECTORY}/${_arg_OUTPUT_FILE_NAME}.${OUTPUT_FILE_EXTENSION}")
#        #file(WRITE "${_arg_WORKINGDIRECTORY}/${_arg_OUTPUT_FILE_NAME}.${OUTPUT_FILE_EXTENSION}" "newfile")
#        #ctest_sleep(5)
#    #endif()


#    if(${OUTPUT_FILE_EXTENSION} STREQUAL "xml")
#        set(COMMENT_CGEN "<!--")
#        set(COMMENT_CGEN_END "-->")
#    elseif(${OUTPUT_FILE_EXTENSION} STREQUAL "cmake")
#        set(COMMENT_CGEN "#")
#        set(COMMENT_CGEN_END "")
#    else()
#        set(COMMENT_CGEN "//")
#        set(COMMENT_CGEN_END "")
#    endif()

#    #first make sure the input file even exists. if not, dont do anything
#    if (NOT EXISTS ${_arg_INPUT_DIRECTORY}/${_arg_INPUT_FILE_NAME}.in)
#        message(WARNING "HADI: the input file ${_arg_INPUT_DIRECTORY}/${_arg_INPUT_FILE_NAME}.in  did not exist when
#                attempting to cgen generate macro.")
#        return()
#    endif ()

#    #take the file and append the required header stuff for cgen. You'll then need to generate an intermediary file
#    # so to not disturb the original configure .in file.
#    File(READ ${_arg_INPUT_DIRECTORY}/${_arg_INPUT_FILE_NAME}.in CONTENTS_OF_FILE)
#    set(CONTENTS_OF_FILE1
#"##Macro1 @_arg_Macro1@
###Macro2 @_arg_Macro2@
###Macro3 @_arg_Macro3@
###Macro4 @_arg_Macro4@
###Macro5 @_arg_Macro5@
###Macro6 @_arg_Macro6@
###Macro7 @_arg_Macro7@
###Macro8 @_arg_Macro8@
###Macro9 @_arg_Macro9@
###Macro10 @_arg_Macro10@
###Macro11 @_arg_Macro11@
###Macro12 @_arg_Macro12@
###Macro13 @_arg_Macro13@
###Macro14 @_arg_Macro14@
###Macro15 @_arg_Macro15@
###Macro16 @_arg_Macro16@
###Macro17 @_arg_Macro17@
###Macro18 @_arg_Macro18@
###Macro19 @_arg_Macro19@
###Macro20 @_arg_Macro20@
###Macro21 @_arg_Macro21@
###Macro22 @_arg_Macro22@
###Macro23 @_arg_Macro23@
###Macro24 @_arg_Macro24@
###Macro25 @_arg_Macro25@
###Macro26 @_arg_Macro26@
###Macro27 @_arg_Macro27@
###Macro28 @_arg_Macro28@
###Macro29 @_arg_Macro29@
###Macro30 @_arg_Macro30@
###Macro31 @_arg_Macro31@
###Macro32 @_arg_Macro32@
###Macro33 @_arg_Macro33@
###Macro34 @_arg_Macro34@
###Macro35 @_arg_Macro35@
###Macro36 @_arg_Macro36@
###Macro37 @_arg_Macro37@
###Macro38 @_arg_Macro38@
###Macro39 @_arg_Macro39@
###Macro40 @_arg_Macro40@
###Macro41 @_arg_Macro41@
###Macro42 @_arg_Macro42@
###Macro43 @_arg_Macro43@
###Macro44 @_arg_Macro44@
###Macro45 @_arg_Macro45@
###Macro46 @_arg_Macro46@
###Macro47 @_arg_Macro47@
###Macro48 @_arg_Macro48@
###Macro49 @_arg_Macro49@
###Macro50 @_arg_Macro50@

###LoopIncrement1 @_arg_LoopIncrement1@
###LoopIncrement2 @_arg_LoopIncrement2@
###LoopIncrement3 @_arg_LoopIncrement3@
###LoopIncrement4 @_arg_LoopIncrement4@
###LoopIncrement5 @_arg_LoopIncrement5@
###LoopIncrement6 @_arg_LoopIncrement6@
###LoopIncrement7 @_arg_LoopIncrement7@
###LoopIncrement8 @_arg_LoopIncrement8@
###LoopIncrement9 @_arg_LoopIncrement9@
###LoopIncrement10 @_arg_LoopIncrement10@

###ToFile @_arg_OUTPUT_FILE_NAME@@_arg_OUTPUT_FILE_EXTENSION@")
#set(CONTENTS_OF_FILE "${CONTENTS_OF_FILE1}\n${CONTENTS_OF_FILE}")


#    File(WRITE ${_arg_INPUT_DIRECTORY}/${_arg_INPUT_FILE_NAME}.cgenM.in "${CONTENTS_OF_FILE}")

#    #generate the file
#    configure_file(${_arg_INPUT_DIRECTORY}/${_arg_INPUT_FILE_NAME}.cgenM.in
#            ${_arg_OUTPUT_DIRECTORY}/${_arg_OUTPUT_FILE_NAME}.cgenM @ONLY)


#    message("running cgen macro at directory ${_arg_OUTPUT_DIRECTORY}")

#    #run cgen macro in this directory to generate the cmake generated file
#    execute_process(COMMAND  cgen macro
#            WORKING_DIRECTORY ${_arg_OUTPUT_DIRECTORY}
#            OUTPUT_VARIABLE outVar
#            ERROR_VARIABLE errorVar)

#                        message("${outVar}")
#                        message("${errorVar}")

#if(NOT EXISTS "${_arg_OUTPUT_DIRECTORY}/${_arg_OUTPUT_FILE_NAME}.${OUTPUT_FILE_EXTENSION}")
#                execute_process(COMMAND  cgen macro
#            WORKING_DIRECTORY ${_arg_OUTPUT_DIRECTORY}
#            OUTPUT_VARIABLE outVar
#            ERROR_VARIABLE errorVar)

#    endif()


#    #remove that cgen file so that it does not get called again with every execution of cgen in that directory
#    file(REMOVE  ${_arg_OUTPUT_DIRECTORY}/${_arg_OUTPUT_FILE_NAME}.cgenM)


#endfunction()


