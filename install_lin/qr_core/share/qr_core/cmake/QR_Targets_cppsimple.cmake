##############################################################################################################################
#target creation functions meant for SIMPLECPP_PROJECT types
##############################################################################################################################







#******************************************************************************************************************************************************************
# create a unit test target
macro(QR_CreateTarget_UnitTests)
    #only do this when colcon is not building! colcon does not like building google unit tests

    IsATarget(
        NAME_OF_TARGET ${PROJECT_NAME}_unit_tests
        TARGET_TYPE UnitTest
        MAY_CREATE_MORE_THAN_ONE FALSE)

    if(NOT DEFINED USING_COLCON)


        #generate the cmake file that will create the unit test target
        QR_Generate_File(
            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests
            INPUT_FILE_NAME unit_test_cmakelists
            OUTPUT_FILE_NAME CMakeLists
            OUTPUT_FILE_EXTENSION txt
            IF_FILE_DOESNT_EXIST FALSE
        )



        #generate the main exe file that will run all the tests
        Generate_File_Using_Cgen(
            INPUT_DIRECTORY ${QR_CORE_DIR}/GeneratedFiles
            OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/src
            INPUT_FILE_NAME unit_test_main
            OUTPUT_FILE_NAME main
            OUTPUT_FILE_EXTENSION .cpp
        )


endif()
endmacro()


#******************************************************************************************************************************************************************
# this will create a library target of name ${MODULE_NAME}_CPPlib by default
# by default there can only exist one of these ROSlibrary targets.
# I could change it so that the project library name can be whichever I want passed in,
# but I think just having strictly one library per project will keep things simple.
macro(QR_CreateTarget_CPPLibrary)



    IsATarget(
        NAME_OF_TARGET ${MODULE_NAME}_CPPlib
        TARGET_TYPE CPPLibrary
        MAY_CREATE_MORE_THAN_ONE FALSE)

#    ament_auto_
    add_library(${MODULE_NAME}_CPPlib STATIC #SHARED
        ${SOURCES}
        ${HEADERS}

#        ${QtHEADERS}
#        ${QT_HEADERS}
        ${QtSOURCES}
        ${QT_RESOURCES}
        ${QT_UIS}
    )




    target_compile_definitions(${MODULE_NAME}_CPPlib PRIVATE "COMPOSITION_BUILDING_DLL")

    message("world_CPPlib_INTERFACE_INCLUDE_DIRECTORIES 8888888888888888888  ${world_CPPlib_INTERFACE_INCLUDE_DIRECTORIES}")

    # I have no idea why this is needed but leaving it here for now as is.
    target_include_directories(${MODULE_NAME}_CPPlib
      PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
    )


#I dont know if this is needed for cpp libraries using colcon but for now just keep it here.
ament_target_dependencies(${MODULE_NAME}_CPPlib ${ALL_DEPENDS})


#include generated files in the library target
file(GLOB GEN_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles/*.in"
  )
file(GLOB CMAKE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/*.cmake"
  )

#TODO: this is not working. why?
#message("GEN_FILES===========************************======${GEN_FILES}")
source_group("Generated Files" FILES  ${GEN_FILES})

source_group("cmake Files" FILES  ${CMAKE_FILES})

#target_sources(${MODULE_NAME}_CPPlib PUBLIC ${CMAKE_FILES})
#target_include_directories(${MODULE_NAME}_CPPlib cmake)

#this probably shouldnt be possible to have qt for simple cpp libraries but Im keeping it here for now.
if(${ISForQT} STREQUAL "ON" )
    #En caso de QML, substituir Widgets por Quick
    target_link_libraries(${MODULE_NAME}_CPPlib
      Qt5::Widgets
      Qt5::Core
      Qt5::Gui
      )
endif()

endmacro()



#******************************************************************************************************************************************************************
# this will create a executable target of name ${PROJECT_NAME} by default
#LINK_ADDITIONAL_TARGETS: link additional targets other than the library for the project.
macro(QR_CreateTarget_CPPIntegrationEXE)
    set(options )
    set(oneValueArgs NAME_OF_TARGET)
    set(multiValueArgs  )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #Target member variable
    IsATarget(
        NAME_OF_TARGET ${_arg_NAME_OF_TARGET}
        TARGET_TYPE CPPIntegration
        MAY_CREATE_MORE_THAN_ONE TRUE)


 



    #create the exe target and installation paths. "_QRmain" is needed to be appended because when library targets are
    #created, it will ignore files with this appended
    add_executable(${_arg_NAME_OF_TARGET}
         ${CMAKE_CURRENT_SOURCE_DIR}/src/${_arg_NAME_OF_TARGET}_QRmain.cpp
      )
    #I dont know why/if this is needed but I saw smirk guy do it.
    target_compile_definitions(${_arg_NAME_OF_TARGET} PRIVATE "COMPOSITION_BUILDING_DLL")


    ## Install executable
    install(TARGETS ${_arg_NAME_OF_TARGET} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/${PROJECT_NAME})#${_arg_NAME_OF_TARGET})

    #have the target dependencies for the exe project  be the same as the ros2 dependencies
    # you can add more on your own?
    ament_target_dependencies(${_arg_NAME_OF_TARGET} ${ALL_DEPENDS})


 

endmacro()




# do this when you are done creating a target
macro(QR_target_done)
    set(options)
    set(oneValueArgs)#IS_EXTERNAL_MODULE
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # finish doing things such as generating files or whatever based on the type of target it was 
    if(TARGET_TYPE STREQUAL "CPPLibrary")
        #I dunno what files are needed to be generated based on the targets it linked to. Probably none
         
        # export the library for colcon by default
        QR_export_library_for_colcon()
        
    elseif(TARGET_TYPE STREQUAL "CPPIntegration")
        #generating a main file. This wont ovewrite if a main of that name already exists though
        QR_Generate_File(
            WORKINGDIRECTORYOFINPUTFILE ${QR_CORE_DIR}
            WORKINGDIRECTORYOFOUTPUTFILE ${CMAKE_CURRENT_SOURCE_DIR}/src
            INPUT_FILE_NAME main_simplecpp
            OUTPUT_FILE_NAME ${_arg_NAME_OF_TARGET}_QRmain
            OUTPUT_FILE_EXTENSION cpp
            IF_FILE_DOESNT_EXIST TRUE
        )

    elseif(TARGET_TYPE STREQUAL "UnitTest")
        if(NOT DEFINED USING_COLCON)
            add_subdirectory(unit_tests)
        endif()
    endif()
    
    
endmacro()



##############################################################################################################################
#linking targets for simple cpp targets
##############################################################################################################################




# general function that will direct to the correct on based on from target type
macro(QR_target_link_to_CPPLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(TARGET_TYPE STREQUAL "CPPIntegration")
        QR_target_link_from_IntegrationEXE_to_CPPLibrary(MODULE_NAME ${_arg_MODULE_NAME})
        #message(FATAL_ERROR "HADI: cant link integrationlibrary to cpplibrary target")
    endif()
    if(TARGET_TYPE STREQUAL "CPPLibrary")
        QR_target_link_from_CPPLibrary_to_CPPLibrary(MODULE_NAME ${_arg_MODULE_NAME})
    endif()

endmacro()




#******************************************************************************************************************************************************************
# This will link the curren  a cpp library to an interface from a specified module.
#MODULE_NAME: name of the module the target exists in.
macro(QR_target_link_from_CPPLibrary_to_Interface)
    set(options)
    set(oneValueArgs MODULE_NAME)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #TODO
    #do a check that the name of the module was provided as one of the depending modules.

    #link libraries
    IsALINK(
         TARGET_NAME_FROM ${_arg_MODULE_NAME}_CPPlib
         TARGET_NAME_TO ${_arg_MODULE_NAME}_i
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE CPPLibrary
         TO_TYPE  Interface
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

    #for cpp simple libraries, the target is always such that ${_arg_MODULE_NAME}_CPPlib
    #target_link_libraries(${PROJECT_NAME}  ${_arg_MODULE_NAME}::${_arg_MODULE_NAME}_CPPlib)



    #link libraries
    #target_link_libraries(${MODULE_NAME}_CPPlib  ${_arg_MODULE_NAME}::${_arg_MODULE_NAME}_CPPlibrary)

endmacro()




#******************************************************************************************************************************************************************
# This will link the current cpp simple library with another cpp library from a different module.
#currently the module must be external. (cant have two different cpp library targets within the same module.)
macro(QR_target_link_from_CPPLibrary_to_CPPLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)#IS_EXTERNAL_MODULE
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #TODO
    #do a check that the name of the module was provided as one of the depending modules.


    #steps for linking and creating targets.

    #step 1. user calls the cmake functions for creating targets and linking them. This is written in a config file
    #called targets_and_links.cmake .

    #step 2. when the CMakeLists.txt file runs, it will include this targets_and_links file at the beginning. example it will
    #look like the bottom. The functions at the bottom will only set the variables such as MODULE_NAME_DEPENDS and TARGET_TYPE_DEPEND.

#    QR_CreateTarget_CPPLibrary()
#    QR_target_done()

#    QR_CreateTarget_CPPIntegrationEXE(NAME_OF_TARGET someexe)
#    QR_target_link_from_IntegrationEXE_to_CPPLibrary(MODULE_NAME ${PROJECT_NAME}) # sets MODULE_NAME_DEPENDS and TARGET_TYPE_DEPEND (interface, cpplibrary, roslibrary)
#    QR_target_done()

#    #create a unit test target
#    QR_CreateTarget_UnitTests()
#    QR_target_done()

    #step 3. after the file runs, it will write those two variables into some intermediary file config/generated/all_depends.cmake .
    #(the bash scripts generated for building the project will need to read from this file). Also, the find_package() command
    #for finding those projects will read from this file.

    #step 4. the CMakeLists.txt will now read include(all_depends.cmake) . it will generate the full project name of a depend.
    # for example
    #if MODULE_NAME_DEPENDS = some_module and TARGET_TYPE_DEPEND = SIMPLECPP_PROJECT
    #then FULL_PROJECT_DEPEND_NAME = somemodule_cp
    #now remove duplicates found in FULL_PROJECT_DEPEND_NAME
    # remember that ros interfaces projects need to be in their own list because they get processed differently in the package.xml
    # so if TARGET_TYPE_DEPEND = SIMPLECPP_PROJECT  set FULL_PROJECT_DEPEND_NAME_I = somemodule_i


    #step 5. call QR cmake function
#    QR_Find_List_Of_Ros_Packages(
#        PACKAGES_LIST ${FULL_PROJECT_DEPEND_NAME}
#        PACKAGES_INTERFACE_LIST ${FULL_PROJECT_DEPEND_NAME_I}
#        )

    #step 6. set a variable indicating that the QR functions called in step 2 should change to their 2nd implementation
    # set(DEPENDS_PHASE2)

    #step 7. mid way through the CMakeLists.txt , call the step 2 functions again. this time they will simply target_link_libraries
    #as usual.

    #step 8. when QR_done is called, I will need to read from all_depends.cmake  again. Now that I have those variables, I will
    #need to generate the bash file SourceAllDepends.bash .
        #step a. I need to go through all directories for all QR modules and, using the
        #algorithm written with jamie, find the module that matches the name in the MODULE_NAME_DEPENDS.

        #step b. the previous step would have gotten me a list of directories corresponding to the MODULE_NAME_DEPENDS . This
        #list is called MODULE_NAME_DEPENDS_BASE_DIRECTORY

        #step c. iterate through MODULE_NAME_DEPENDS_BASE_DIRECTORY and, depending on the TARGET_TYPE_DEPEND, append the directory to that project
        #for that type to the base directory. For example
        #if TARGET_TYPE_DEPEND = INTERFACE
        # PROJECT_DEPEND_FULLPATH = ${MODULE_NAME_DEPENDS_BASE_DIRECTORY}/rosqt/IF

        #step d. now that you have the list  PROJECT_DEPEND_FULLPATH , you can use a MP template to generate the
        # SourceAllDepends.bash file



    #link libraries
    IsALINK(
         TARGET_NAME_FROM ${MODULE_NAME}_CPPlib
         TARGET_NAME_TO ${_arg_MODULE_NAME}_CPPlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE CPPLibrary
         TO_TYPE  CPPLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )


    #target_link_libraries(${MODULE_NAME}_CPPlib  ${_arg_MODULE_NAME}::${_arg_MODULE_NAME}_CPPlibrary)

endmacro()



#******************************************************************************************************************************************************************
# This will link the current cpp integration exe with a cpp library from a specified module.
#MODULE_NAME: name of the module the target exists in.
#Amount of targets allowed: many
#amount of linkable targetes: many
#InternalExternalModules: either
macro(QR_target_link_from_IntegrationEXE_to_CPPLibrary)
    set(options)
    set(oneValueArgs MODULE_NAME)#IS_EXTERNAL_MODULE
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #TODO
    #do a check that the name of the module was provided as one of the depending modules.


    #link libraries
    IsALINK(
         TARGET_NAME_FROM ${NAME_OF_TARGET}
         TARGET_NAME_TO ${_arg_MODULE_NAME}_CPPlib
         TO_MODULE ${_arg_MODULE_NAME}
         FROM_TYPE CPPIntegration
         TO_TYPE  CPPLibrary
         MAY_CREATE_MORE_THAN_ONE_LINK TRUE
         MAY_LINK_TO_EXTERNAL TRUE
         )

    #for cpp simple libraries, the target is always such that ${_arg_MODULE_NAME}_CPPlib
    #target_link_libraries(${PROJECT_NAME}  ${_arg_MODULE_NAME}::${_arg_MODULE_NAME}_CPPlib)



    #link libraries
    #target_link_libraries(${MODULE_NAME}_CPPlib  ${_arg_MODULE_NAME}::${_arg_MODULE_NAME}_CPPlibrary)

endmacro()
