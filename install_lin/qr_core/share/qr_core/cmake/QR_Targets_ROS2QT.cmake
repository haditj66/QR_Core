##############################################################################################################################
#target creation functions meant for ROS2_PROJECTS types
##############################################################################################################################






# do this when you are done creating a target
macro(QR_target_done)
    set(options)
    set(oneValueArgs )#IS_EXTERNAL_MODULE
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})




    # finish doing things such as generating files or whatever based on the type of target it was
    if(TARGET_TYPE STREQUAL "ROSLibrary")
        #I dunno what files are needed to be generated based on the targets it linked to. Probably none

        # export the library for colcon by default. Do this for ALL ros library names. Remeber they have an extension based on the AO
        # that is active for that library.
        foreach(roslib ${ALL_ROS_LIBRARIES})
            QR_export_library_for_colcon(FOR_THE_TARGET_NAME ${roslib})
        endforeach()

    elseif(TARGET_TYPE STREQUAL "ROSIntegration")

        #generate QR_main files

        #create the main.cpp file for this project based on if this is going ot be a single exe node
        #or if this will be a multiple composable nodes exe target.
        if( ${IS_FOR_COMPOSABLES} STREQUAL "FALSE"  OR ${IS_FOR_COMPOSABLES} STREQUAL "OFF")


            list(GET NODES_TO_COMPOSE 0 NODE_NAME)
            list(GET FROM_MODULE_NODES_TO_COMPOSE 0 FROM_MODULE_NODES)

        if(NOT ${FOR_REAL_AO} STREQUAL "AllSurrogates")
        if(NOT ${FOR_REAL_AO} STREQUAL "AllRealAO")

            if( list_len  GREATER   1)
                message(FATAL_ERROR "HADI: when creating exe target ${NAME_OF_TARGET} for QR_CreateEXE_Target() you gave more than one node for variable FOR_NODES
                    while trying to create an exe target this not composable. NODES_TO_COMPOSE= ${NODES_TO_COMPOSE} meaning that it can only support one node.")
            endif()
        endif()
        endif()


             #if for single node main

             if(${WantToGenerateMain} STREQUAL "TRUE" OR ${WantToGenerateMain} STREQUAL "True" OR ${WantToGenerateMain} STREQUAL "ON")

                 QR_Generate_File(
                     WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
                     WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles
                     INPUT_FILE_NAME main_single_node
                     OUTPUT_FILE_NAME ${NAME_OF_TARGET}_QRmain
                     OUTPUT_FILE_EXTENSION cpp
                 )

                 Generate_File_Using_Cgen(
                     INPUT_DIRECTORY ${QR_CORE_DIR}/GeneratedFiles
                     OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
                     INPUT_FILE_NAME main_single_node
                     OUTPUT_FILE_NAME ${NAME_OF_TARGET}_QRmain
                     OUTPUT_FILE_EXTENSION .cpp
                 )
            endif()
            set(WantToGenerateMain "")

#             QR_Generate_File(
#                 WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
#                 WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/src
#                 INPUT_FILE_NAME main_single_node
#                 OUTPUT_FILE_NAME ${NAME_OF_TARGET}_QRmain
#                 OUTPUT_FILE_EXTENSION cpp
#                 IF_FILE_DOESNT_EXIST TRUE
#             )


        else()
            #if for composable nodes main

            MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )




                   MP_create_instance_of_multiparameter_template(
                       LIST_OF_ALL_TEMPLATE_VARIABLES
                                  NODE_INCLUDE
                                  NODE_CREATION

                       GROUPS_OF_MULTIPARAMS NODES

                       IS_THIS_USING_CGEN TRUE

                       NAMEOFTEMPLATE ${NAME_OF_TARGET}
                       WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
                       INPUT_FILE_NAMES     main_composable_nodes
                       OUTPUT_FILE_NAMES    ${NAME_OF_TARGET}_QRmain
                       OUTPUT_FILE_EXTENSIONS cpp )



                   set(index 0)

                   foreach(NODE_NAME IN LISTS NODES_TO_COMPOSE)


                       list(GET FROM_MODULE_NODES_TO_COMPOSE ${index} FROM_MODULE_NODES)


                       MP_define_group_of_multiparams_for_template_instance(
                           FORTHISGROUP NODES
                           NAME_OF_TEMPLATE ${NAME_OF_TARGET})

                       MP_define_multiparameter(
                           FOR_PARAMETER NODE_INCLUDE
                           WITH_VALUE "#include \"${FROM_MODULE_NODES}/${NODE_NAME}.hpp\" \n"
                           )
                       MP_define_multiparameter(
                           FOR_PARAMETER NODE_CREATION
                           WITH_VALUE
    "   auto node_${NODE_NAME} =
     std::make_shared<${FROM_MODULE_NODES}::${NODE_NAME}>(rclcpp::NodeOptions());
     exec.add_node(node_${NODE_NAME});\n\n"
                           )

                       MP_done_defining_group(  )

                       MATH(EXPR index "${index}+1")

                   endforeach()

                   MP_done_with_instance_of_multiparameter_template(
                       NAMEOFTEMPLATE ${_arg_NAMEOFTEMPLATE}
                       ADDITIONAL_GENERATED_FILE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src)


        endif()



         if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/${NAME_OF_TARGET}_QRmain.cpp)
             message(ERROR "HADI: the main file for the target ${NAME_OF_TARGET} you are trying to build does not exist. It needs to be named ${${NAME_OF_TARGET}_QRmain.cpp}")
         endif()


    endif()


endmacro()



#******************************************************************************************************************************************************************
# grab all the source files associated with the _cp project. This is only needed when copy and paste method of linking is used.
macro(_QR_grab_all_cpp_files)

    file(GLOB CPPHEADERS_ORIG
        "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/*.h"
      )
    file(GLOB CPPSOURCES_ORIG
        "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.c"
      )

  #remove the main files associated for exe targets.
  file(GLOB SOURCES_MAIN_REMOVE
       "${CMAKE_CURRENT_SOURCE_DIR}/../src/*_QRmain.cpp"
    )

  #remove the files with Config.h and visibility_control.h
  file(GLOB HEADERS_REMOVE
         "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/Config.hpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/../include/${MODULE_NAME}_cp/visibility_control.h"
    )

  #remove the CPPHEADERS from HEADERS and CPPSOURCES from the SOURCES
  if(  SOURCES_MAIN_REMOVE STREQUAL "" )
  else()
    list(REMOVE_ITEM CPPSOURCES_ORIG ${SOURCES_MAIN_REMOVE})
  endif()
  if(  HEADERS_REMOVE STREQUAL "" )
  else()
    list(REMOVE_ITEM CPPHEADERS_ORIG  ${HEADERS_REMOVE})
  endif()


  #get the file names of them and change their paths

  foreach(fil ${CPPHEADERS_ORIG})
      get_filename_component(filFileName ${fil} NAME)
      set(CPPHEADERS ${CPPHEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/include/${MODULE_NAME}_rqt/${filFileName})
  endforeach()
  foreach(fil ${CPPSOURCES_ORIG})
      get_filename_component(filFileName ${fil} NAME)
      set(CPPSOURCES ${CPPSOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/${filFileName})
  endforeach()

  message("CPPSOURCES1 4444444444444444444444444 ${CPPSOURCES}")
  message("CPPHEADERS1 4444444444444444444444444 ${CPPHEADERS}")
endmacro()

#******************************************************************************************************************************************************************
# this will create a library target of name ${MODULE_NAME}_ROSlib by default
# by default there can only exist one of these ROSlibrary targets.
# I could change it so that the project library name can be whichever I want passed in,
# but I think just having strictly one library per project will keep things simple.
macro(QR_CreateTarget_ROS2Library)



    IsATarget(
        NAME_OF_TARGET ${MODULE_NAME}_ROSlib
        TARGET_TYPE ROSLibrary
        MAY_CREATE_MORE_THAN_ONE FALSE)

    set(CPPHEADERS)
    set(CPPSOURCES)

    #grab all the source files associated with the _cp project
    if(DEFINED COPY_PASTE_STYLE_LINKING)
        _QR_grab_all_cpp_files()
    endif()


  file(GLOB SOURCES_MAIN_REMOVE
       "${CMAKE_CURRENT_SOURCE_DIR}/src/*_QRmain.cpp"
    )
  if(  SOURCES_MAIN_REMOVE STREQUAL "" )
  else()
    list(REMOVE_ITEM SOURCES ${SOURCES_MAIN_REMOVE})
  endif()


  #iterate through all AO_TO_SET and create a ros library for each case where that AO was set to real.
  #append that name to the library. also make the case where If no AO was set on the AO_TO_SET list. Make this
  #be called "AllSurrogates"
  #dont add this feature
  # set(AOS_TOITERATE  ${AO_TO_SET})
    # foreach(AO_TO_SET_l ${AOS_TOITERATE})

#    ament_auto_
    add_library(${MODULE_NAME}_ROSlib  SHARED #_${AO_TO_SET_l}
            ${SOURCES}
            ${HEADERS}
                ${CPPSOURCES}   #dont do it this way!!! you'll get weird errors again with the whole src file not being called!
                ${CPPHEADERS}

            ${QtHEADERS}
            ${QT_HEADERS}
            ${QtSOURCES}
            ${QT_RESOURCES}
            ${QT_UIS}
        )

    set(ALL_ROS_LIBRARIES ${ALL_ROS_LIBRARIES} ${MODULE_NAME}_ROSlib)#_${AO_TO_SET_l} dont add this feature

    source_group(DontTouch FILES ${CPPHEADERS} ${CPPSOURCES})

    # dont add this feature
    # _SET_AO_COMPILE_DEF(
    #     TARGET_NAME ${MODULE_NAME}_ROSlib#_${AO_TO_SET_l}
    # AO_NAME ${AO_TO_SET_l} )


#    message("11111111111111 \n ${MODULE_NAME}_ROSlib_${AO_TO_SET_l} has been given ${AO_TO_SET_l}Real  \n 111111111111111111111111111")

    target_compile_definitions(${MODULE_NAME}_ROSlib PRIVATE "COMPOSITION_BUILDING_DLL")#_${AO_TO_SET_l} dont add this feature

    target_include_directories(${MODULE_NAME}_ROSlib #_${AO_TO_SET_l} dont add this feature
      PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
    )

    ament_target_dependencies(${MODULE_NAME}_ROSlib ${ALL_DEPENDS}) #_${AO_TO_SET_l} dont add this feature

    # endforeach()




endmacro()

#******************************************************************************************************************************************************************
# set AO ConFIgUratIon to a target
macro(_SET_AO_COMPILE_DEF)
    set(options )
    set(oneValueArgs TARGET_NAME AO_NAME)
    set(multiValueArgs  )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # if no surrogate, dont make this multiapp
    if(${_arg_AO_NAME} STREQUAL "AllSurrogates")
#        message("23232323232323232323")
        target_compile_definitions(${_arg_TARGET_NAME} PRIVATE AllSurrogates)
        target_compile_definitions(${_arg_TARGET_NAME} PRIVATE MULTIAPP)
    elseif(${_arg_AO_NAME} STREQUAL "AllRealAO")
        target_compile_definitions(${_arg_TARGET_NAME} PRIVATE AllRealAO)
    elseif(${_arg_AO_NAME} STREQUAL "NoAODesignPattern")
        target_compile_definitions(${_arg_TARGET_NAME} PRIVATE NoAODesignPattern)
    else()
        target_compile_definitions(${_arg_TARGET_NAME} PRIVATE MULTIAPP)
    endif()

    target_compile_definitions(${_arg_TARGET_NAME} PRIVATE ${_arg_AO_NAME}Real)

endmacro()



#******************************************************************************************************************************************************************
# compose a node into the exe target
macro(QR_Compose_Node)
    set(options )
    set(oneValueArgs FROM_MODULE NODE_NAME)
    set(multiValueArgs  )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    set(SINGLE_NODE_COMPOSED ${_arg_NODE_NAME})#for creating main.cpp for single nodes.
    list(APPEND NODES_TO_COMPOSE ${_arg_NODE_NAME})
    list(APPEND FROM_MODULE_NODES_TO_COMPOSE ${_arg_FROM_MODULE}_rqt)

#    list(LENGTH NODES_TO_COMPOSE list_len)
    MATH(EXPR list_len "${list_len}+1")





endmacro()


#******************************************************************************************************************************************************************
# this will create a executable target of name ${PROJECT_NAME} by default
#IS_FOR_COMPOSABLES: Is the executable for composable nodes or just a singla app. If it is for composable node, than you may need to
        #set compile definitions AOREAL to real manually based on the nodes(AOs) being composed.
#FOR_REAL_AO: which AO is set as real here?
macro(QR_CreateTarget_ROS2IntegrationEXE)
    set(options )
    set(oneValueArgs NAME_OF_TARGET IS_FOR_COMPOSABLES FOR_REAL_AO WantToGenerateMain)
    set(multiValueArgs FOR_NODES LINK_ADDITIONAL_TARGETS)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(FOR_REAL_AO ${_arg_FOR_REAL_AO})
    if(${_arg_WantToGenerateMain} STREQUAL "")
        set(WantToGenerateMain TRUE)
    else()
        set(WantToGenerateMain ${_arg_WantToGenerateMain})
    endif()

    IsATarget(
        NAME_OF_TARGET ${_arg_NAME_OF_TARGET}
        TARGET_TYPE ROSIntegration
        MAY_CREATE_MORE_THAN_ONE TRUE)

    if(NOT DEFINED _arg_NAME_OF_TARGET)
        set(_arg_NAME_OF_TARGET ${PROJECT_NAME})
    endif()




    #reset variables
    set(NODES_TO_COMPOSE)
    set(FROM_MODULE_NODES_TO_COMPOSE)
    set(IS_FOR_COMPOSABLES ${_arg_IS_FOR_COMPOSABLES})
    set(list_len 0)



    #ament_auto_
    add_executable(${_arg_NAME_OF_TARGET}
         ${CMAKE_CURRENT_SOURCE_DIR}/src/${_arg_NAME_OF_TARGET}_QRmain.cpp

         ${QtHEADERS}
         ${QT_HEADERS}
         ${QtSOURCES}
         ${QT_RESOURCES}
         ${QT_UIS}
      )
    #I dont know why/if this is needed but I saw smirk guy do it.
    target_compile_definitions(${_arg_NAME_OF_TARGET} PRIVATE "COMPOSITION_BUILDING_DLL")


    ## Install executable
    install(TARGETS ${_arg_NAME_OF_TARGET} DESTINATION lib/${PROJECT_NAME})#${_arg_NAME_OF_TARGET})

    #have the target dependencies for the exe project  be the same as the ros2 dependencies
    # you can add more on your own?
    ament_target_dependencies(${_arg_NAME_OF_TARGET} ${ALL_DEPENDS})


    #add the compile definition for the real AO selected
    _SET_AO_COMPILE_DEF(
        TARGET_NAME ${_arg_NAME_OF_TARGET}
    AO_NAME ${_arg_FOR_REAL_AO})
    #target_compile_definitions(${_arg_NAME_OF_TARGET} PRIVATE ${_arg_FOR_REAL_AO}Real)

    #link the library target for this project along with any additional targets the user set.
#    target_link_libraries(${_arg_NAME_OF_TARGET}  ${MODULE_NAME}_ROSlib)
#    foreach(ADDITIONAL_TARGETS IN LISTS _arg_LINK_ADDITIONAL_TARGETS)
#        target_link_libraries(${_arg_NAME_OF_TARGET}  ${ADDITIONAL_TARGETS})
#    endforeach()


#       message("SOURCES -------- ${SOURCES}")
#       message("HEADERS -------- ${HEADERS}")

endmacro()












##############################################################################################################################
#linking targets for Ros project targets
##############################################################################################################################



#use this to link ros project targets to roslibrary targets
macro(QR_target_link_to_CPPLibrary )
        set(options)
        set(oneValueArgs MODULE_NAME)
        set(multiValueArgs)
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


        if(${TARGET_TYPE} STREQUAL "ROSIntegration")
            QR_target_link_from_ROSIntegrationEXE_to_CPPLibrary(MODULE_NAME ${_arg_MODULE_NAME})
        elseif(${TARGET_TYPE} STREQUAL "ROSLibrary")
            QR_target_link_from_ROSLibrary_to_CPPLibrary(MODULE_NAME ${_arg_MODULE_NAME})
        endif()

endmacro()


#use this to link ros project targets to roslibrary targets
macro(QR_target_link_to_ROSLibrary )
        set(options)
        set(oneValueArgs MODULE_NAME)
        set(multiValueArgs)
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


        if(${TARGET_TYPE} STREQUAL "ROSIntegration")
            QR_target_link_from_ROSIntegrationEXE_to_ROSLibrary(MODULE_NAME ${_arg_MODULE_NAME})
        elseif(${TARGET_TYPE} STREQUAL "ROSLibrary")
            #cant do it
#            message(FATAL_ERROR "HADI: cant link from ROSlibrary to a ROSLibrary target")
            QR_target_link_from_ROSLibrary_to_ROSLibrary(MODULE_NAME ${_arg_MODULE_NAME})
        endif()

endmacro()

#use this to link ros project targets to Interface  targets
macro(QR_target_link_to_Interface )
        set(options)
        set(oneValueArgs MODULE_NAME)
        set(multiValueArgs)
        cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


        if(${TARGET_TYPE} STREQUAL "ROSIntegration")
            QR_target_link_from_ROSIntegrationEXE_to_Interface(MODULE_NAME ${_arg_MODULE_NAME})
        elseif(${TARGET_TYPE} STREQUAL "ROSLibrary")
            QR_target_link_from_ROSLibrary_to_Interface(MODULE_NAME ${_arg_MODULE_NAME})
        endif()

endmacro()




#******************************************************************************************************************************************************************
# This will link from a ros library to a cpp library
macro(QR_target_link_from_ROSLibrary_to_CPPLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    IsALINK(
         TARGET_NAME_FROM ${MODULE_NAME}_ROSlib
         TARGET_NAME_TO ${_arg_MODULE_NAME}_CPPlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSLibrary
         TO_TYPE  CPPLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

endmacro()



#******************************************************************************************************************************************************************
# This will link from a ros library to an interface target
macro(QR_target_link_from_ROSLibrary_to_Interface)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    IsALINK(
         TARGET_NAME_FROM ${MODULE_NAME}_ROSlib
         TARGET_NAME_TO ${_arg_MODULE_NAME}_i
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSLibrary
         TO_TYPE  Interface
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

endmacro()




#******************************************************************************************************************************************************************
# This will link from a ros integration target  to a cpp library
macro(QR_target_link_from_ROSIntegrationEXE_to_CPPLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



    IsALINK(
         TARGET_NAME_FROM ${NAME_OF_TARGET}
         TARGET_NAME_TO ${_arg_MODULE_NAME}_CPPlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSIntegration
         TO_TYPE  CPPLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )


endmacro()


#******************************************************************************************************************************************************************
# This will link from a ros integration target  to a ROS library
macro(QR_target_link_from_ROSIntegrationEXE_to_ROSLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    IsALINK(
         TARGET_NAME_FROM ${NAME_OF_TARGET}
         TARGET_NAME_TO ${_arg_MODULE_NAME}_ROSlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSIntegration
         TO_TYPE  ROSLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK FALSE
         MAY_LINK_TO_EXTERNAL FALSE
         )

endmacro()


#******************************************************************************************************************************************************************
# This will link from a ros library target  to a ROS library
macro(QR_target_link_from_ROSLibrary_to_ROSLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    IsALINK(
         TARGET_NAME_FROM ${NAME_OF_TARGET}
         TARGET_NAME_TO ${_arg_MODULE_NAME}_ROSlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSLibrary
         TO_TYPE  ROSLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

endmacro()


#******************************************************************************************************************************************************************
# This will link from a ros integration target to an interface target
macro(QR_target_link_from_ROSIntegrationEXE_to_Interface)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    IsALINK(
         TARGET_NAME_FROM ${NAME_OF_TARGET}
         TARGET_NAME_TO ${_arg_MODULE_NAME}_i
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE ROSIntegration
         TO_TYPE  Interface
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

endmacro()
