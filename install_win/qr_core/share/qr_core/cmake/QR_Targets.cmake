###########################################################################################
#These are a collection of helper functions meant to deal with anything relating to targets.
#
#There are many different types of targets and depending on what project type QR_PROJECT_TYPE you are in (SIMPLECPP_PROJECT ROS2_PROJECT INTERFACE)
#you can only make certain targets
###########################################################################################


if(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")
include(${QR_CORE_INSTALL_DIR}/cmake/QR_Targets_cppsimple.cmake)
elseif(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")
include(${QR_CORE_INSTALL_DIR}/cmake/QR_Targets_ROS2QT.cmake)
elseif(QR_PROJECT_TYPE STREQUAL "INTERFACE")
#you shouldnt be able to create any targets. the interface target is automatically created by ros2
elseif(QR_PROJECT_TYPE STREQUAL "QR")
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Targets_ROS2QT.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/QR_Targets_cppsimple.cmake)
else()
message(FATAL_ERROR "HADI: you never defined the variable QR_PROJECT_TYPE. this should have been defined at the beginning of your cmakelists.txt file. You must have removed it.")
endif()








#"class" type Target
#NAME_OF_TARGET: name of the target
#the target type: CPPIntegration, CPPLibrary, ROSLibrary, UnitTest
#MAY_CREATE_MORE_THAN_ONE: amount of targets allowed, whether one or many
#MAY_LINK_TO_EXTERNAL: whether this module is capable of linking to targets from external modules.
macro(IsATarget)
    set(options )
    set(oneValueArgs NAME_OF_TARGET TARGET_TYPE MAY_CREATE_MORE_THAN_ONE MAY_LINK_TO_EXTERNAL)
    set(multiValueArgs    )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(NAME_OF_TARGET ${_arg_NAME_OF_TARGET})
    set(TARGET_TYPE ${_arg_TARGET_TYPE})
    set(MAY_CREATE_MORE_THAN_ONE ${_arg_MAY_CREATE_MORE_THAN_ONE})

    if(${MAY_CREATE_MORE_THAN_ONE} STREQUAL "FALSE")
        if(${TARGET_TYPE}_CREATED STREQUAL "TRUE")
            message(FATAL_ERROR "HADI: you tried to create multiple targets for target of type ${TARGET_TYPE} . You can only create one of this kind of target")
        endif()
    endif()

    set(${TARGET_TYPE}_CREATED TRUE)




endmacro()



#"class" Link
#NAME_OF_TARGET: name of the target
#the target type: CPPIntegration, CPPLibrary
#MAY_CREATE_MORE_THAN_ONE_LINK: amount of links allowed for this type to type, whether one or many
#MAY_LINK_TO_EXTERNAL: whether this module is capable of linking to targets from external modules.
macro(IsALINK)
    set(options )
    set(oneValueArgs TARGET_NAME_FROM TARGET_NAME_TO TO_MODULE FROM_TYPE TO_TYPE MAY_CREATE_MORE_THAN_ONE_LINK MAY_LINK_TO_EXTERNAL)
    set(multiValueArgs    )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(MAY_CREATE_MORE_THAN_ONE_LINK ${_arg_MAY_CREATE_MORE_THAN_ONE_LINK})
    set(MAY_LINK_TO_EXTERNAL ${_arg_MAY_LINK_TO_EXTERNAL})
    set(TO_MODULE ${_arg_TO_MODULE})
    set(TARGET_NAME_TO ${_arg_TARGET_NAME_TO})
    set(TARGET_NAME_FROM ${_arg_TARGET_NAME_FROM})
    set(FROM_TYPE ${_arg_FROM_TYPE})
    set(TO_TYPE ${_arg_TO_TYPE})

    if(${TO_MODULE} STREQUAL "FALSE")
    endif()

    # check if this link is valid for the amount created thus far.
    if(${MAY_CREATE_MORE_THAN_ONE_LINK} STREQUAL "FALSE")
        if(${TARGET_NAME_FROM}_${TO_TYPE}_CREATED STREQUAL "TRUE")
            message(FATAL_ERROR "HADI: you tried to create multiple links from target of type ${FROM_TYPE} , to target of type  ${TO_TYPE} .You can only create one of this kind of this link")
        endif()
    endif()



    set(${TARGET_NAME_FROM}_${TO_TYPE}_CREATED TRUE)


    #get the target's full name based on the type
    set(MODULE_EXTENSION)
    if(TO_TYPE STREQUAL "CPPLibrary")
        set(TO_TARGET_FULL_NAME ${TO_MODULE}_CPPlib)
        set(MODULE_EXTENSION _cp)
    elseif(TO_TYPE STREQUAL "CPPIntegration")
        set(TO_TARGET_FULL_NAME ${TARGET_NAME_TO})
        set(MODULE_EXTENSION _cp)
    elseif(TO_TYPE STREQUAL "ROSLibrary")
        set(TO_TARGET_FULL_NAME ${TO_MODULE}_ROSlib)
        set(MODULE_EXTENSION _rqt)
    elseif(TO_TYPE STREQUAL "ROSIntegration")
        set(TO_TARGET_FULL_NAME ${TARGET_NAME_TO})
        set(MODULE_EXTENSION _rqt)
    elseif(TO_TYPE STREQUAL "Interface")
        set(TO_TARGET_FULL_NAME ${TO_MODULE}_i)
        set(MODULE_EXTENSION _i)
    endif()


    #check if this link is valid for external modules
    if(TO_MODULE STREQUAL "${MODULE_NAME}")
        set(MODULE_NAMESPACE "")
    else()
        if(MAY_LINK_TO_EXTERNAL STREQUAL FALSE)
            message(FATAL_ERROR "HADI: you tried to link to an external module for target ${TARGET_NAME_FROM}  to external module ${TO_MODULE}. this is not allowed for this target's type to link to external modules")
        endif()
        set(MODULE_NAMESPACE "${TO_MODULE}${MODULE_EXTENSION}::")
    endif()

    #now that everything is valid, I can grab the to target name, and the module name and just link it here.

    #make a special case for FROM_TYPE ROSLIBRARY TO_TYPE CPPLIBRARY
    if(FROM_TYPE STREQUAL "ROSLibrary" AND TO_TYPE STREQUAL "CPPLibrary")#
            target_link_libraries(${TARGET_NAME_FROM}  ${TO_MODULE}_cp::${TARGET_NAME_TO})
#        elseif(FROM_TYPE STREQUAL "CPPLibrary" AND TO_TYPE STREQUAL "CPPLibrary")
#            message("==========s ${TARGET_NAME_FROM}  ${MODULE_NAMESPACE}_cp ${TO_TARGET_FULL_NAME}")
#            target_link_libraries(${TARGET_NAME_FROM}  ${MODULE_NAMESPACE}_cp${TO_TARGET_FULL_NAME})
        else()
            message("==========s ${TARGET_NAME_FROM}  ${MODULE_NAMESPACE} ${TO_TARGET_FULL_NAME}")
            target_link_libraries(${TARGET_NAME_FROM}  ${MODULE_NAMESPACE}${TO_TARGET_FULL_NAME})
    endif()





    #"private" member variables for saving links
    set(${NAME_OF_TARGET}_LinkedToTargetNames ${${NAME_OF_TARGET}_linkedTargetsModuleNames} ${TO_TARGET_FULL_NAME})
    set(${NAME_OF_TARGET}_linkedTargetsModuleNames ${${NAME_OF_TARGET}_linkedTargetsModuleNames} ${MODULE_NAMESPACE})

endmacro()





#******************************************************************************************************************************************************************
# This will get a library ready for colcon building. Colcon will take all include files
# and install them in the proper directory for find_package to find it. Finally, this
# will create the proper Target_FIND.cake files for findpackage.
macro(QR_export_library_for_colcon)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    if(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")
        set(_arg_FOR_TARGET  ${MODULE_NAME}_ROSlib)
    elseif(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")
        set(_arg_FOR_TARGET  ${MODULE_NAME}_CPPlib)
    endif()

    set(_arg_LIBRARY_INCLUDES_DIRECTORY include)

    message("9999999999999999999 ${_arg_LIBRARY_INCLUDES_DIRECTORY} sss ${_arg_FOR_TARGET} ")

 message("CMAKE_COMMAND  ------------------${CMAKE_COMMAND}")

    # the shared library goes into the global lib dir so it can
    # be used as a composable node by other projects
#    install(TARGETS
#      ${_arg_FOR_TARGET}
#      EXPORT export_${_arg_FOR_TARGET} # associates an "export_*" target with the library target
#      LIBRARY DESTINATION lib
#      RUNTIME DESTINATION bin
#    )


install(TARGETS
  ${_arg_FOR_TARGET}
  EXPORT export_${_arg_FOR_TARGET} # associates an "export_*" target with the library target
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
#install(DIRECTORY "C:/QR_sync/world/include/world_cp" DESTINATION "include")#C:/QR_sync/world/rosqt/install_win/world_rqt/world_cp")

#install(TARGETS
#  ${_arg_FOR_TARGET}
#  EXPORT ${_arg_FOR_TARGET}_export # associates an "export_*" target with the library target
#  LIBRARY DESTINATION lib
#  RUNTIME DESTINATION bin
#)

    #when you do a normal build, CMAKE_INSTALL_PREFIX is simply usr/local.
    #However when you do a colcon build, CMAKE_INSTALL_PREFIX is
    #/home/user/Documents/qt_stuff/ros2_template2/install/my_composable_node
    #so in that case, the following command will take alldirectories and files in the
    #include directory and copy it to the CMAKE_INSTALL_PREFIX
    install(
      DIRECTORY ${_arg_LIBRARY_INCLUDES_DIRECTORY}
      DESTINATION ${CMAKE_INSTALL_PREFIX}
    )
    message("CMAKE_INSTALL_PREFIX -----------------------------------------------${CMAKE_INSTALL_PREFIX}")

    # this is what probably builds the cmake config files
#    ament_export_targets(export_${_arg_FOR_TARGET})
# found here https://github.com/ament/ament_cmake/issues/329
#    ament_export_libraries(${_arg_FOR_TARGET}_export HAS_LIBRARY_TARGET)
    ament_export_targets(export_${_arg_FOR_TARGET})


endmacro()
