##############################################################################
# PROJECT This cmake file is for this qr_core project. It does NOT  run when other projects link to this project!
##############################################################################
set(BUILD_INTERFACES 1)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


set(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 3.5)
project(qr_core C CXX)



set(POJECT_PACKAGE_DESCRIPTION "QRCore is the base package all other QR packages will depend on. This package provides cmake extensions for building ROS projects with code generation capabilities." )
set(POJECT_PACKAGE_AUTHOR Hadi Jaber)
set(POJECT_PACKAGE_EMAIL haditjuta@gmail.com)



set(QR_PROJECT_TYPE QR)
set(QR_CORE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(ISForQT OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Templates.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/MultiParameterTemplate.cmake)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Core.cmake)


#include all third party libraries
#cereal
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ThirdPartyLibs/cereal/include)




set(MODULE_NAME qr_core)



#find_package(ament_cmake REQUIRED)
#find_package(ament_cmake_auto REQUIRED)
#find_package(ament_cmake_ros REQUIRED)

#set(_arg_PACKAGES_LIST ${_arg_PACKAGES_LIST} "rclcpp" "rclcpp_components")
#set(_arg_INTERFACE_LIST ${_arg_INTERFACE_LIST} ${MODULE_NAME} )

#find_package(rosidl_default_generators REQUIRED)

#set(ROS2_DEPENDENCIES ${_arg_PACKAGES_LIST})
#set(ALL_DEPENDS ${_arg_INTERFACE_LIST})
#set(ALL_DEPENDS ${ALL_DEPENDS} ${_arg_PACKAGES_LIST})
#ament_auto_find_build_dependencies(REQUIRED  ${ALL_DEPENDS})




#foreach(pkg ${ROS2_DEPENDENCIES})
#  find_package(${pkg} REQUIRED)
#endforeach()

#find_package(rosidl_default_generators REQUIRED)
#find_package(std_msgs REQUIRED)
#find_package(builtin_interfaces REQUIRED)
#ament_auto_find_build_dependencies(REQUIRED ${ALL_DEPENDS})
#ament_auto_find_build_dependencies(REQUIRED )



#create presetup files for QR_core
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_PreSetup.cmake)
QR_presetup_of_project_files(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


message("CMAKE_BINARY_DIR 9999999999999999999999  ${CMAKE_BINARY_DIR}")

#include("cmake/MyCmakeHelpers.cmake")

#option(ISForQT "is this for QT or for a bare ROS project." FALSE)
#add_compile_definitions(ISForQT__${ISForQT})

if(WIN32)
    set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/win)
else()
    set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/lin)
endif()





#set(CMAKE_BUILD_TYPE "Debug")
###################################################################################
#grab cgen
###################################################################################
#set(CMAKE_BUILD_TYPE "Debug")


if (WIN32)

    #set(CODEGENGUI_PATH "C:/QR_Sync/CgenMin/CgenMin")
    set(CgenConfigPath "C:/QR_Sync/CgenMin/CgenMin")
    FILE(READ "${CgenConfigPath}/CgenCmakeConfigFunctions.cmake" contentsOut)
    FILE(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CgenCmakeConfigFunctions.cmake" ${contentsOut})
else()

    set(USERNAME $ENV{USER})
    set(CgenConfigPath "/home/${USERNAME}/QR_Sync/CgenMin/CgenMin")#C:/CodeGenerator/CgenCmakeGui")
    FILE(READ "${CgenConfigPath}/CgenCmakeConfigFunctions.cmake" contentsOut)
    FILE(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CgenCmakeConfigFunctions.cmake" ${contentsOut})


endif()
#endif()
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CgenCmakeConfigFunctions.cmake")
Cgen_Start(
    CGEN_DIRECTORY_OF_CACHE "GenericConfig"
    )

#old way-----------
#if (WIN32)

#    set(CODEGENGUI_PATH "C:/CodeGenerator/CgenCmakeGui")
#    FILE(READ "${CODEGENGUI_PATH}/CgenCmakeConfigFunctions.cmake" contentsOut)
#    FILE(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CgenCmakeConfigFunctions.cmake" ${contentsOut})
#endif()
##endif()
#include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CgenCmakeConfigFunctions.cmake")
#Cgen_Start(
#    CGEN_DIRECTORY_OF_CACHE "GenericConfig"
#    )


###################################################################################





Cgen_Option(
        NAME IsThisForQt
        DESCRIPTION "is this for Qt"
        POSSIBLEVALUES TRUE FALSE
        CONSTRICTS_LATER_OPTIONS
)


Cgen_Option(
        NAME IsThisForNodes
        DESCRIPTION "is this for nodes"
        POSSIBLEVALUES Composable NotComposable
        CONSTRICTS_LATER_OPTIONS
)




#qrcore_dir should depend on the install directory. which for ament is
# install/${PROJECT_NAME}
# I think ament requires you to make it share/${PROJECT_NAME}

set(INSTALL_DIR share/${PROJECT_NAME})


#this is to match with colcon's base install directory. For us, it will be install_win for windows and install_lin for linux
if(WIN32)

    set(QR_CORE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install_win/${PROJECT_NAME}/${INSTALL_DIR})
#	set(QR_CORE_INSTALL_DIR_WIN ${QR_CORE_INSTALL_DIR})
else()

    set(QR_CORE_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install_lin/${PROJECT_NAME}/${INSTALL_DIR})
# 	set(QR_CORE_INSTALL_DIR_LIN ${QR_CORE_INSTALL_DIR})
endif()




#in order to generate the qr_cmake_autos file, I need to know the directory of QR_CORE_DIR . I need
#to know it for both windows and linux. However I cannot overwrite the linux location when running
#in windows and vice versa. So I need a location to put the location in case the other OS already set it.
#--------------------------------------------------------------------------------------------------------------------------
if(WIN32)
    QR_Generate_File(
           WORKINGDIRECTORYOFINPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}
           WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake
           INPUT_FILE_NAME QR_Location_Win
           OUTPUT_FILE_NAME QR_Location_Win
           OUTPUT_FILE_EXTENSION cmake
    )
else()

    QR_Generate_File(
           WORKINGDIRECTORYOFINPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}
           WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake
           INPUT_FILE_NAME QR_Location_Lin
           OUTPUT_FILE_NAME QR_Location_Lin
           OUTPUT_FILE_EXTENSION cmake
    )

endif()






if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Location_Win.cmake)

    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Location_Win.cmake)

    #append the install directory as this is what depending packages will use
    #set(QR_CORE_DIR_WIN ${QR_CORE_DIR_WIN}/${INSTALL_DIR_FINAL})
else()
    set(QR_CORE_DIR_WIN)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Location_Lin.cmake)

    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Location_Lin.cmake)

    #append the install directory as this is what depending packages will use
    #set(QR_CORE_DIR_LIN ${QR_CORE_DIR_LIN}/${INSTALL_DIR_FINAL})
else()
    set(QR_CORE_DIR_LIN)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles/qr_cmake_autos.in
        ${CMAKE_CURRENT_SOURCE_DIR}/qr_cmake_autos.cmake @ONLY)

#QR_Generate_File(
#       WORKINGDIRECTORYOFINPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}
#       WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}
#       INPUT_FILE_NAME qr_cmake_autos
#       OUTPUT_FILE_NAME qr_cmake_autos
#       OUTPUT_FILE_EXTENSION cmake
#)
#--------------------------------------------------------------------------------------------------------------------------

#QR_Get_Source_And_Header_files()

#QR_CreateTarget_CPPLibrary()
#QR_target_done()







#generate the Config file from the generated files folder for Config.in.

# Default to C99



##############################################################################
# create msg and srv files
##############################################################################

if (DEFINED BUILD_INTERFACES)


    message("Building interfaces --------------------------------------")

    #this will grab all msg files and srv files and
    file(GLOB MSGS_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/msg/*.msg"
      )
    file(GLOB SRVS_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/srv/*.srv"
      )
    file(GLOB ACTION_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/action/*.action"
      )



  QR_Find_List_Of_Ros_Packages(
      PACKAGES_LIST

      PACKAGES_INTERFACE_LIST

      )



  QR_initialize_interfaces()


  ##create msg files for all msg files found
  foreach(msg IN LISTS MSGS_FILES)
  #string(REGEX MATCH "${CMAKE_CURRENT_SOURCE_DIR}/msg/(*.).msg" NEW_VAR "${msg}")

#  if(WIN32)
      string(REGEX REPLACE "${QR_CORE_DIR}/msg/" ""  NEW_VAR "${msg}")#C:/QR_sync/QR_Core/msg/"
#  else()
#      string(REGEX REPLACE "C:/QR_sync/QR_Core/msg/" ""  NEW_VAR "${msg}")
#  endif()
      string(REGEX REPLACE "\.msg" ""  NEW_VAR "${NEW_VAR}")
      message("building message interface ================   ${NEW_VAR}")
      QR_create_message_interface(
          NAME_OF_MESSAGE
          ${NEW_VAR}
          INTERFACE_PKGS_THIS_PKG_DEPENDS_ON
          )
  endforeach()
  ##create srv files for all srv files found
  foreach(srv IN LISTS SRVS_FILES)
#      string(REGEX REPLACE "${QR_CORE_DIR}/msg/" ""  NEW_VAR "${msg}")#C:/QR_sync/QR_Core/msg/"
      string(REGEX REPLACE "${QR_CORE_DIR}/srv/" ""  NEW_VAR "${srv}")
      #string(REGEX REPLACE "C:/QR_sync/QR_Core/srv/" ""  NEW_VAR "${srv}")
      string(REGEX REPLACE "\.srv" ""  NEW_VAR "${NEW_VAR}")
      message("building service interface ================   ${NEW_VAR}")

      QR_create_service_interface(
          NAME_OF_MESSAGE
          ${NEW_VAR}
          INTERFACE_PKGS_THIS_PKG_DEPENDS_ON
          )
  endforeach()

    #QR_create_service_interface(
    #    NAME_OF_MESSAGE
    #    VoidInt
    #    INTERFACE_PKGS_THIS_PKG_DEPENDS_ON
    #    builtin_interfaces std_msgs
    #    )

    QR_done_creating_interfaces()

    #rosidl_generate_interfaces(${MODULE_NAME}
    #    srv/VoidInt.srv
    #    LIBRARY_NAME ${MODULE_NAME}_i
    #    DEPENDENCIES  ${ALL_DEPENDENCIES_NEED_FOR_INTERFACES})

    ament_export_dependencies(rosidl_default_runtime)


    message("MSGS_FILES ================   ${MSGS_FILES}")
    message("SRVS_FILES ================   ${SRVS_FILES}")
    message("ACTION_FILES ================   ${ACTION_FILES}")


    source_group("msg files" FILES  ${MSGS_FILES})
    source_group("srv files" FILES ${SRVS_FILES})
    source_group("action files" FILES ${ACTION_FILES})

else()
    find_package(ament_cmake REQUIRED)
    find_package(ament_cmake_auto REQUIRED)
    find_package(ament_cmake_ros REQUIRED)


endif()






ament_package(
  CONFIG_EXTRAS "qr_cmake_autos.cmake"
)

install(
  DIRECTORY cmake
  DESTINATION ${INSTALL_DIR}
)
install(
  DIRECTORY include
  DESTINATION ${INSTALL_DIR}
)

Cgen_End()

#ament_package()
