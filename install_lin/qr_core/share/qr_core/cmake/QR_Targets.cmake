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
        #special case for FROM_TYPE "ROSIntegration"  TO_TYPE "ROSLibrary" as you need to take into account the FOR_REAL_AO
        if(FROM_TYPE STREQUAL "ROSIntegration" AND TO_TYPE STREQUAL "ROSLibrary")
            set(TO_TARGET_FULL_NAME ${TO_TARGET_FULL_NAME}_${_arg_FOR_REAL_AO})
        endif()


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
    set(oneValueArgs FOR_THE_TARGET_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    if(QR_PROJECT_TYPE STREQUAL "ROS2_PROJECT")
        set(_arg_FOR_TARGET  ${_arg_FOR_THE_TARGET_NAME})# ${MODULE_NAME}_ROSlib)
        if(DEFINED COPY_PASTE_STYLE_LINKING)
            message("starting copy-paste linking to cpp")
            _QR_install_src_files_to_cpp()
        endif()
    elseif(QR_PROJECT_TYPE STREQUAL "SIMPLECPP_PROJECT")
        set(_arg_FOR_TARGET  ${MODULE_NAME}_CPPlib)
        if(DEFINED COPY_PASTE_STYLE_LINKING)
            _QR_install_src_files_to_rosqt()
        endif()

    endif()

    set(_arg_LIBRARY_INCLUDES_DIRECTORY include)

    message("9999999999999999999 ${_arg_LIBRARY_INCLUDES_DIRECTORY} sss ${_arg_FOR_TARGET} ")

# message("CMAKE_COMMAND  ------------------${CMAKE_COMMAND}")

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




#******************************************************************************************************************************************************************
#do a precheck that the files in TEMPDIRSRC and TEMPDIRINC are all the SAME contents as the files in the destination install files.
#if one is of different content, run a fatal error saying that the user must have modified the file at the rosqt file and will need to delete or
# resolve that conflict.
macro(_QR_check_installed_files_same_as_rosqt)



    #first grab all the files in the temp directories
    set(AllFilescpp)
    set(AllFilesinc)
    if(EXISTS "${TEMPDIRSRC}")
        #get all files in this directory
        file(GLOB AllFilescpp
            "${TEMPDIRSRC}/*.*"
          )
    endif()
    if(EXISTS "${TEMPDIRINC}")
        #get all files in this directory
        file(GLOB AllFilesinc
            "${TEMPDIRINC}/*.*"
          )
    endif()

    set(ALLFILES ${AllFilescpp} ${AllFilesinc})

    #grab all files in the destination installation directory.
    file(GLOB AllFilesToChecksrc
        "${CMAKE_CURRENT_SOURCE_DIR}/rosqt/src/*.*"
      )
    file(GLOB AllFilesToCheckinc
        "${CMAKE_CURRENT_SOURCE_DIR}/rosqt/include/${MODULE_NAME}_rqt/*.*"
      )
    set(ALLFILESTOCHECK ${AllFilesToChecksrc} ${AllFilesToCheckinc})



    #iterate through all files to check, find the matching file in the ALLFILES. get the contents of both.
    #if there are any differences between the two files, throw a fatal error telling user they need to fix the conflict.
    foreach(filToCheck ${ALLFILESTOCHECK})
        foreach(fil ${ALLFILES})
            #get the name of the files
            #get file name and extention
            get_filename_component(filFileNamecheck ${filToCheck} NAME)
            get_filename_component(filFileName ${fil} NAME)

            #strip trailing newlines


#            message("sssssssssssssssssssssssssssssss ${filFileNamecheck}")
#            message("sssssssssssssssssssssssssssssss ${filFileName}")


            if("${filFileNamecheck}" STREQUAL "${filFileName}")
                #get the contents of both
                file(READ ${filToCheck} filFileContentscheck )
                file(READ ${fil} filFileContents )

                string(STRIP "${filFileContentscheck}" filFileContentscheck)
                string(STRIP "${filFileContents}" filFileContents)

                #if they are different, throw a fatal_error.
                if("${filFileContentscheck}" STREQUAL "${filFileContents}")
                    message("checking contents of \n ${filFileNamecheck}  \n ${filFileName} ")
                else()


                    message("\n\ninstall file contents -----------------------------------------------------------------------\n\n")
                    message("${filFileContents}")

                    message("\n\nrosqt file contents -----------------------------------------------------------------------\n\n")
                    message("${filFileContentscheck}")

                    message(WARNING "HADI: There was a conflict between file \n ${filToCheck} \n and file \n ${fil}
                         did you modify that file in rosqt? If you did, you need to resolve the conflict by either copying contents in the file from
                        the rosqt directory into the directory of the cpp project's temp installation folder AND the cpp project original file so it does not get overwritten.
                        or copy contents of temp file to rosqt file.")


                endif()

            endif()


        endforeach()

    endforeach()

endmacro()


#******************************************************************************************************************************************************************
# This will install all src and include files to directory rosqt/src and rosqt/include/${MODULE_NAME}_rqt respectively.
#also any mentions of "world_cp" will be changed to "world_rqt" . Any mention of "world_CPPlib" will be changed to "world_ROSlib"
macro(_QR_install_src_files_to_rosqt)

    set(TEMPDIRSRC "${CMAKE_CURRENT_SOURCE_DIR}/build/tempinstallfiles/src")
    set(TEMPDIRINC "${CMAKE_CURRENT_SOURCE_DIR}/build/tempinstallfiles/${MODULE_NAME}_rqt")


    _QR_check_installed_files_same_as_rosqt()



    #first delete the temp directories
    if(EXISTS "${TEMPDIRSRC}")
        file(REMOVE_RECURSE  ${TEMPDIRSRC})
    endif()
    if(EXISTS "${TEMPDIRINC}")
        file(REMOVE_RECURSE  ${TEMPDIRINC})
    endif()


    #grab all header files used. With the exception of Config.h and visibility_control.h
    file(GLOB CPPHEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_cp/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_cp/*.h"
      )
    file(GLOB CPPSOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
      )


    #remove the main files associated for exe targets.
    file(GLOB SOURCES_MAIN_REMOVE
         "${CMAKE_CURRENT_SOURCE_DIR}/src/*_QRmain.cpp"
      )

    #remove the files with Config.h and visibility_control.h
    file(GLOB HEADERS_REMOVE
         "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_cp/Config.hpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_cp/visibility_control.h"
      )

    if(  SOURCES_MAIN_REMOVE STREQUAL "" )
    else()
      list(REMOVE_ITEM CPPSOURCES ${SOURCES_MAIN_REMOVE})
    endif()
#    message("HEADERS_REMOVE  rrrrrrrrrrrrrr  ${HEADERS_REMOVE}")
    list(REMOVE_ITEM CPPHEADERS ${HEADERS_REMOVE})

    #itereate through files
    foreach(fil ${CPPSOURCES})

        _QR_process_file_for_copy_paste_install(DestinationOfFile ${TEMPDIRSRC} fil ${fil})

#        #get file name and extention
#        get_filename_component(filFileName ${fil} NAME)
#        get_filename_component(filFileExt ${fil} EXT)

#        #get contents from the file
#        file(READ ${fil} filFileContents )

#        #replace any mention of world_cp with world_rqt
#        string(REPLACE "${MODULE_NAME}_cp" "${MODULE_NAME}_rqt" outfilFileContents "${filFileContents}")
#        string(REPLACE "${MODULE_NAME}_CPPlib" "${MODULE_NAME}_rqt" outfilFileContents "${outfilFileContents}")

#        #write this to a directory build/tempinstallfiles
#        file(WRITE "${TEMPDIRSRC}/${filFileName}" "${outfilFileContents}" )

    endforeach()

    foreach(fil ${CPPHEADERS})


        _QR_process_file_for_copy_paste_install(DestinationOfFile ${TEMPDIRINC} fil ${fil})

#        #get file name and extention
#        get_filename_component(filFileName ${fil} NAME)
#        get_filename_component(filFileExt ${fil} EXT)
##        cmake_path(GET ${fil} FILENAME filFileName)
##        cmake_path(GET ${fil} EXTENSION [LAST_ONLY] filFileExt)

#        #get contents from the file
#        file(READ ${fil} filFileContents )

#        #replace any mention of world_cp with world_rqt
#        string(REPLACE "${MODULE_NAME}_cp" "${MODULE_NAME}_rqt" outfilFileContents "${filFileContents}")
#        string(REPLACE "${MODULE_NAME}_CPPlib" "${MODULE_NAME}_rqt" outfilFileContents "${outfilFileContents}")

#        #write this to a directory build/tempinstallfiles
#        file(WRITE "${TEMPDIRINC}/${filFileName}" "${outfilFileContents}" )

    endforeach()


    install(
      DIRECTORY ${TEMPDIRSRC}
      DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/rosqt
    )

    install(
    DIRECTORY ${TEMPDIRINC}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/rosqt/include
  )



endmacro()




#******************************************************************************************************************************************************************
# This will install all src and include files to directory rosqt/src and rosqt/include/${MODULE_NAME}_rqt respectively.
#also any mentions of "world_cp" will be changed to "world_rqt" . Any mention of "world_CPPlib" will be changed to "world_ROSlib"
macro(_QR_install_src_files_to_cpp)

    set(TEMPDIRSRC "${CMAKE_CURRENT_SOURCE_DIR}/build/tempinstallfiles/src")
    set(TEMPDIRINC "${CMAKE_CURRENT_SOURCE_DIR}/build/tempinstallfiles/${MODULE_NAME}_cp")





    #first delete the temp directories
    if(EXISTS "${TEMPDIRSRC}")
        file(REMOVE_RECURSE  ${TEMPDIRSRC})
    endif()
    if(EXISTS "${TEMPDIRINC}")
        file(REMOVE_RECURSE  ${TEMPDIRINC})
    endif()


    #grab all header files used. With the exception of Config.h and visibility_control.h
    file(GLOB CPPHEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_rqt/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_rqt/*.h"
      )
    file(GLOB CPPSOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
      )

  #unlike from cpp to rosqt, I need to match if this file exists in the cpp project. If it does then I keep, if not then remove.
  file(GLOB CPPHEADERS_CPP
      "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/*.hpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/*.h"
    )
  file(GLOB CPPSOURCES_CPP
      "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp"
      "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.c"
    )



    #remove the main files associated for exe targets.
    file(GLOB SOURCES_MAIN_REMOVE
         "${CMAKE_CURRENT_SOURCE_DIR}/src/*_QRmain.cpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/../src/*_QRmain.cpp"
      )

    #remove the files with Config.h and visibility_control.h
    file(GLOB HEADERS_REMOVE
         "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_rqt/Config.hpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_rqt/visibility_control.h"
         "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/Config.hpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/visibility_control.h"
      )



    if(  SOURCES_MAIN_REMOVE STREQUAL "" )
    else()
      list(REMOVE_ITEM CPPSOURCES ${SOURCES_MAIN_REMOVE})
      list(REMOVE_ITEM CPPSOURCES_CPP ${SOURCES_MAIN_REMOVE})
    endif()
#    message("HEADERS_REMOVE  rrrrrrrrrrrrrr  ${HEADERS_REMOVE}")
    list(REMOVE_ITEM CPPHEADERS ${HEADERS_REMOVE})
    list(REMOVE_ITEM CPPHEADERS_CPP ${HEADERS_REMOVE})

    #itereate through files
    foreach(fil ${CPPSOURCES})

        #iterate through all cpp source files. If one of them is a match, go ahead and process it.
        foreach(fil_cpp ${CPPSOURCES_CPP})
            get_filename_component(fil_cppFileName ${fil_cpp} NAME)
            get_filename_component(fil_cppFileExt ${fil_cpp} EXT)
            get_filename_component(filFileName ${fil} NAME)
            get_filename_component(filFileExt ${fil} EXT)

            if(${fil_cppFileName} STREQUAL ${filFileName})
                if(${fil_cppFileExt} STREQUAL ${filFileExt})
                    _QR_process_file_for_copy_paste_install_FROM_ROS_TO_CPP(DestinationOfFile ${TEMPDIRSRC} fil ${fil})
                endif()
            endif()

        endforeach()



    endforeach()

    foreach(fil ${CPPHEADERS})


        #iterate through all cpp source files. If one of them is a match, go ahead and process it.
        foreach(fil_cpp ${CPPHEADERS_CPP})
            get_filename_component(fil_cppFileName ${fil_cpp} NAME)
            get_filename_component(fil_cppFileExt ${fil_cpp} EXT)
            get_filename_component(filFileName ${fil} NAME)
            get_filename_component(filFileExt ${fil} EXT)

            if(${fil_cppFileName} STREQUAL ${filFileName})
                if(${fil_cppFileExt} STREQUAL ${filFileExt})
                    _QR_process_file_for_copy_paste_install_FROM_ROS_TO_CPP(DestinationOfFile ${TEMPDIRINC} fil ${fil})
                endif()
            endif()

        endforeach()



    endforeach()


    install(
      DIRECTORY ${TEMPDIRSRC}
      DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/..
    )

    install(
    DIRECTORY ${TEMPDIRINC}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../include
  )



endmacro()





#******************************************************************************************************************************************************************
# Process the file for installation by replacing mentions of modules using the COPY_PASTE_LINK_METHOD with the _rqt
macro(_QR_process_file_for_copy_paste_install_FROM_ROS_TO_CPP)
    set(options)
    set(oneValueArgs DestinationOfFile fil)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(fil ${_arg_fil})

    #get file name and extention
    get_filename_component(filFileName ${fil} NAME)
    get_filename_component(filFileExt ${fil} EXT)
#        cmake_path(GET ${fil} FILENAME filFileName)
#        cmake_path(GET ${fil} EXTENSION [LAST_ONLY] filFileExt)

    #get contents from the file
    file(READ ${fil} filFileContents )

    #go through each module that is of copy_paste_link_method that this module links to. They need to be changed as well

    set(All_MODULES_TO_PROCESS ${MODULE_NAME} ${MODULES_USING_COPY_PASTE_METHOD})
    set(outfilFileContents "${filFileContents}")
    foreach(M_P_NAME ${All_MODULES_TO_PROCESS})
        #replace any mention of world_cp with world_rqt
        message("replacing name ${M_P_NAME}")
        string(REPLACE "${M_P_NAME}_rqt" "${M_P_NAME}_cp" outfilFileContents "${outfilFileContents}")
        string(REPLACE "namespace ${M_P_NAME}_CPPlib" "namespace ${M_P_NAME}_rqt" outfilFileContents "${outfilFileContents}")
        string(REPLACE "namespace  ${M_P_NAME}_CPPlib" "namespace ${M_P_NAME}_rqt" outfilFileContents "${outfilFileContents}")

    endforeach()

    #write this to a directory build/tempinstallfiles
    file(WRITE "${_arg_DestinationOfFile}/${filFileName}" "${outfilFileContents}" )

endmacro()


#******************************************************************************************************************************************************************
# Process the file for installation by replacing mentions of modules using the COPY_PASTE_LINK_METHOD with the _rqt
macro(_QR_process_file_for_copy_paste_install)
    set(options)
    set(oneValueArgs DestinationOfFile fil)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(fil ${_arg_fil})

    #get file name and extention
    get_filename_component(filFileName ${fil} NAME)
    get_filename_component(filFileExt ${fil} EXT)
#        cmake_path(GET ${fil} FILENAME filFileName)
#        cmake_path(GET ${fil} EXTENSION [LAST_ONLY] filFileExt)

    #get contents from the file
    file(READ ${fil} filFileContents )

    #go through each module that is of copy_paste_link_method that this module links to. They need to be changed as well

    set(All_MODULES_TO_PROCESS ${MODULE_NAME} ${MODULES_USING_COPY_PASTE_METHOD})
    set(outfilFileContents "${filFileContents}")
    foreach(M_P_NAME ${All_MODULES_TO_PROCESS})
        #replace any mention of world_cp with world_rqt
        message("replacing name ${M_P_NAME}")
        string(REPLACE "${M_P_NAME}_cp" "${M_P_NAME}_rqt" outfilFileContents "${outfilFileContents}")
        string(REPLACE "${M_P_NAME}_CPPlib" "${M_P_NAME}_rqt" outfilFileContents "${outfilFileContents}")

    endforeach()

    #write this to a directory build/tempinstallfiles
    file(WRITE "${_arg_DestinationOfFile}/${filFileName}" "${outfilFileContents}" )

endmacro()
