#THIS IS    A GENERATRED FILE. DONT MODIFY IT HERE. MODIFY it in the generatedfiles ".in" file

#this is the cmake file that runs (AUTOMATICALLY ON Find_Package(qr_core) )  when other projects link to this project.




# Default to C99
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



#if the compiler is MSVC, make sure that it is has this compile opetion telling it to run in "dynamic release" mode
#not having this will result in mismatch between target linkings.
#only do this for SIMPLECPP_PROJECT projects
if( QR_PROJECT_TYPE  STREQUAL "SIMPLECPP_PROJECT" OR  QR_PROJECT_TYPE  STREQUAL "ROS2_PROJECT")
    if (MSVC)
    add_compile_options(/MD)
    endif()
endif()



if(WIN32)
    set(QR_CORE_DIR C:/QR_sync/QR_Core)
    set(QR_CORE_INSTALL_DIR C:/QR_sync/QR_Core/install_win/qr_core/share/qr_core)

    include(${QR_CORE_DIR}/cmake/QR_Templates.cmake)
else()
    set(QR_CORE_DIR /home/hadi/QR_Sync/QR_Core)
    set(QR_CORE_INSTALL_DIR /home/hadi/QR_Sync/QR_Core/install_lin/qr_core/share/qr_core)

    #set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/linux)
endif()


#if not defined, define it
if( NOT DEFINED POJECT_PACKAGE_DESCRIPTION)
    set(POJECT_PACKAGE_DESCRIPTION "define the POJECT_PACKAGE_DESCRIPTION variable in your cmake file before calling Find_List_Of_Ros_Packages to fill this in.")
endif()
if( NOT DEFINED POJECT_PACKAGE_AUTHOR)
    set(POJECT_PACKAGE_AUTHOR "Default Name")
endif()
if( NOT DEFINED POJECT_PACKAGE_EMAIL)
    set(POJECT_PACKAGE_EMAIL "default@gmail.com")
endif()




include(${QR_CORE_INSTALL_DIR}/cmake/QR_Templates.cmake)

include(${QR_CORE_INSTALL_DIR}/cmake/MultiParameterTemplate.cmake)

include(${QR_CORE_INSTALL_DIR}/cmake/QR_Core.cmake)


include_directories("${QR_CORE_DIR}/include/qr_core")

#include all third party libraries
#cereal
include_directories(${QR_CORE_DIR}/ThirdPartyLibs/cereal/include)



#if this is a setup project just generated needed files then return
if( QR_PROJECT_TYPE  STREQUAL "QR_PROJECT_SETUP")
message("CGEN Not being used for interface project ${PROJECT_NAME}")
set(ISForQT FALSE)

include(${QR_CORE_INSTALL_DIR}/cmake/QR_PreSetup.cmake)
QR_presetup_of_project_files(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")

return()
endif()




#QR_project()



#if the project type is an interface, dont allow it to use cgen as there shouldnt be a need for it
if( QR_PROJECT_TYPE  STREQUAL "INTERFACE")
#do nothing
message("CGEN Not being used for interface project ${PROJECT_NAME}")
set(ISForQT FALSE)

else()
    #set(CMAKE_BUILD_TYPE "")

    #endif()
    include("${QR_CORE_INSTALL_DIR}/cmake/CgenCmakeConfigFunctions.cmake")
    Cgen_Start(
        CGEN_DIRECTORY_OF_CACHE "GenericConfig"
        )


#any options presented here will be global options that all QR projects must configure
#however make sure to set the option in the if statement above in case it is used in other places.
    Cgen_Option(
            NAME ISForQT
            DESCRIPTION "is this for QT or for a bare ROS project."
            POSSIBLEVALUES TRUE FALSE
            CONSTRICTS_LATER_OPTIONS
    )


endif()









#Generate_File_Using_Cgen(
#                INPUT_DIRECTORY ${QR_CORE_DIR}/GeneratedFiles
#        OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
#        INPUT_FILE_NAME testcgen
#        OUTPUT_FILE_NAME testFromCgen2
#        OUTPUT_FILE_EXTENSION .cpp
#)


#option(ISForQT "is this for QT or for a bare ROS project." FALSE)
#add_compile_definitions(ISForQT__${ISForQT})


