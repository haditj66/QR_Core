
include(${QR_CORE_DIR}/cmake/QR_Core.cmake)




#******************************************************************************************************************************************************************
#this function is to be called before using MP.
#DESTINATION_OF_INTERMEDIARYFILES: where to put intermediary files
macro(MP_intitialize)
    set(options DEBUG_MP)
    set(oneValueArgs  )
    set(multiValueArgs  DESTINATION_OF_INTERMEDIARYFILES)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #default value for _arg_DEBUG_MP
    if(NOT DEFINED _arg_DEBUG_MP)
        set(_arg_DEBUG_MP FALSE)
    endif()
    set(DEBUG_MP ${_arg_DEBUG_MP})


set(DESTINATION_OF_INTERMEDIARYFILES ${_arg_DESTINATION_OF_INTERMEDIARYFILES} )

endmacro()






#******************************************************************************************************************************************************************
#this will create an instance of a template
#NAMEOFTEMPLATE: name of this template
#WORKINGDIRECTORYOFINPUTFILE the directory of the input template file
#INPUT_FILE_NAMES: name of ALL the input template files. (there can be multiple. make sure files input match with output files by index)
#OUTPUT_FILE_NAMES: name of ALL the output file generated (there can be multiple. make sure files input match with output files by index)
#OUTPUT_FILE_EXTENSIONS: ALL extensions of all files. Again, make sure they mach the input and output files by index.
# GROUPS_OF_MULTIPARAMS: define your multi-parameter groups. groups of parameters are basically multiple areas in the template that
       # have a multi-parameter corresponding to one group. For example a variable that needs to be declared in one
       # place but defined in another. Also there could be multiple of that variable with different names.
#LIST_OF_ALL_TEMPLATE_VARIABLES: list all variables that will show  up in the tempalte. remmeber that when wrinting that.
macro(MP_create_instance_of_multiparameter_template)
    set(options)
    set(oneValueArgs WORKINGDIRECTORYOFINPUTFILE NAMEOFTEMPLATE IS_THIS_USING_CGEN)
    set(multiValueArgs GROUPS_OF_MULTIPARAMS LIST_OF_ALL_TEMPLATE_VARIABLES INPUT_FILE_NAMES OUTPUT_FILE_NAMES OUTPUT_FILE_EXTENSIONS)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    set(INC_prev -1)


#     message("over here2222222222222@@@@@@@@@@@@@@@@@@@222222222222222   ${${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN}")

    if(NOT DEFINED _arg_IS_THIS_USING_CGEN)
        set(_arg_IS_THIS_USING_CGEN  FALSE)
    endif()

    set(${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN  ${_arg_IS_THIS_USING_CGEN})
#    message("over2 here2222222222222@@@@@@@@@@@@@@@@@@@222222222222222   ${${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN}")

    #set all global variables needed for this particular instance of a MP template
    set(GROUPS_OF_MULTIPARAMS ${_arg_GROUPS_OF_MULTIPARAMS})
    set(LIST_OF_ALL_TEMPLATE_VARIABLES ${_arg_LIST_OF_ALL_TEMPLATE_VARIABLES})





    #variable int he config file, append the variables with a _1_NAME_OF_NODE
#       set(LIST_OF_ALL_TEMPLATE_VARIABLES ${_arg_LIST_OF_ALL_TEMPLATE_VARIABLES} PARENT_SCOPE)
#       set(DESTINATION_OF_INTERMEDIARYFILES ${_arg_DESTINATION_OF_INTERMEDIARIES} PARENT_SCOPE)

    #set default values for all global group multi-parameters inrement values. these vairables keep track of how
    #many of that group has been created yet.
    set(${_arg_NAMEOFTEMPLATE}_ALL_SO_FAR 0  )
    foreach(GROUPParam IN LISTS GROUPS_OF_MULTIPARAMS )
        set(${GROUPParam}_SO_FAR_${_arg_NAMEOFTEMPLATE} 0  )
    endforeach()
#    message("_arg_NAMEOFTEMPLATE   333333333333333333333333333333   ${_arg_NAMEOFTEMPLATE}")


#    foreach(TEMPLATE_VARIABLES IN LISTS LIST_OF_ALL_TEMPLATE_VARIABLES)
#        give_range_of_ints(FROM 1 TO 10 )
#        foreach(INC IN LISTS RETURNEDLIST )
#            set(${TEMPLATE_VARIABLES}_${INC}_NAME_OF_NODE "@${TEMPLATE_VARIABLES}_${INC}_${_arg_NAMEOFTEMPLATE}@" )
#        endforeach()

#    endforeach()

    foreach(TEMPLATE_VARIABLES IN LISTS LIST_OF_ALL_TEMPLATE_VARIABLES)
        give_range_of_ints(FROM 1 TO 10 )
        foreach(INC IN LISTS RETURNEDLIST )
            set(${TEMPLATE_VARIABLES}_MP ${${TEMPLATE_VARIABLES}_MP} "@${TEMPLATE_VARIABLES}_${INC}_${_arg_NAMEOFTEMPLATE}@" )
            #remove semicolons
            string (REPLACE ";" " " ${TEMPLATE_VARIABLES}_MP "${${TEMPLATE_VARIABLES}_MP}")
        endforeach()

    endforeach()

    #----------------------------------------------------------------------------------




    #change output filenames to append extensions in the case that the user has same output file names, the intermediary files
    #will need unique names
    list(LENGTH _arg_INPUT_FILE_NAMES list_len)

    set(_arg_OUTPUT_FILE_NAMES___)
    math(EXPR list_len "${list_len} - 1")
    give_range_of_ints(FROM 0 TO ${list_len} )
    foreach(index_for_list IN LISTS RETURNEDLIST)
        list(GET _arg_OUTPUT_FILE_EXTENSIONS ${index_for_list} ToAppend)
        list(GET _arg_OUTPUT_FILE_NAMES ${index_for_list} OUTPUT_FILE_NAME)
        set(_arg_OUTPUT_FILE_NAMES___ ${_arg_OUTPUT_FILE_NAMES___}  ${OUTPUT_FILE_NAME}_${ToAppend})
    endforeach()

#    message("_arg_OUTPUT_FILE_NAMES 000000000000000000000000000000  ${_arg_OUTPUT_FILE_NAMES}")
    set(_arg_OUTPUT_FILE_NAMES ${_arg_OUTPUT_FILE_NAMES___})
#    message("_arg_OUTPUT_FILE_NAMES___ 000000000000000000000000000000  ${_arg_OUTPUT_FILE_NAMES___}")




    #set these "class member variables" variables to be used when a parameter is set.
    set(${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES  ${_arg_INPUT_FILE_NAMES} )
    set(${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_NAMES  ${_arg_OUTPUT_FILE_NAMES})
    set(${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_EXTENSIONS  ${_arg_OUTPUT_FILE_EXTENSIONS})

#       set(${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES  ${_arg_INPUT_FILE_NAMES} PARENT_SCOPE)
#       set(${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_NAMES  ${_arg_OUTPUT_FILE_NAMES} PARENT_SCOPE)
#       set(${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_EXTENSIONS  ${_arg_OUTPUT_FILE_EXTENSIONS} PARENT_SCOPE)
#    message("${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES 1111111111111111111111111111111   ${${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES}")



    list(LENGTH _arg_INPUT_FILE_NAMES list_len)

    give_range_of_ints(FROM 0 TO ${list_len} )
    foreach(index_for_list IN LISTS RETURNEDLIST)
        math(EXPR index_for_list "${index_for_list} - 1")

        list(GET _arg_INPUT_FILE_NAMES ${index_for_list} INPUT_FILE_NAME)
        list(GET _arg_OUTPUT_FILE_NAMES ${index_for_list} OUTPUT_FILE_NAME)
        list(GET _arg_OUTPUT_FILE_EXTENSIONS ${index_for_list} OUTPUT_FILE_EXTENSION)

#        message("PUBLISHER_1_NAME_OF_NODE 55555555555555555555  ${PUBLISHER_1_NAME_OF_NODE}")


        #create the first intermediate ".in" file for this node. Later the final code generated file will be created
        _MP_Generate_File(
                WORKINGDIRECTORYOFINPUTFILE ${_arg_WORKINGDIRECTORYOFINPUTFILE}
                WORKINGDIRECTORYOFOUTPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES}
                INPUT_FILE_NAME ${INPUT_FILE_NAME}
                OUTPUT_FILE_NAME ${OUTPUT_FILE_NAME}0
                OUTPUT_FILE_EXTENSION in
                IF_FILE_DOESNT_EXIST FALSE)#if this file already exists, dont generate it.

#              #target_sources(${_arg_FOR_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/${_arg_NAME_OF_NODE}.cpp)

           #target_sources(${_arg_FOR_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/${_arg_NAME_OF_NODE}.hpp)

    endforeach()



endmacro()








#******************************************************************************************************************************************************************
#call this when you are done with a template and want to create the final generated file.
#NAMEOFTEMPLATE: name of this template
#ADDITIONAL_GENERATED_FILE_LOCATION: this is a second location for the final created file other than the intermediary location.
macro(MP_done_with_instance_of_multiparameter_template)
    set(options)
    set(oneValueArgs NAMEOFTEMPLATE )
    set(multiValueArgs ADDITIONAL_GENERATED_FILE_LOCATION)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


    #if this is not using cgen, make sure that the ADDITIONAL_GENERATED_FILE_LOCATION was defined. if it was'nt throw an error.
    if(${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN STREQUAL "TRUE" )
        if(NOT DEFINED _arg_ADDITIONAL_GENERATED_FILE_LOCATION)
            message(FATAL_ERROR "HADI: for multiparameter template of name ${_arg_NAMEOFTEMPLATE} you said you wanted to use cgen by setting the IS_THIS_USING_CGEN to TRUE,
                however you never gave an ADDITIONAL_GENERATED_FILE_LOCATION when calling the function MP_done_with_instance_of_multiparameter_template()")

        endif()
    endif()

    #make sure the additional is the same list size as the input files
    list(LENGTH ${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES list_len)
    list(LENGTH _arg_ADDITIONAL_GENERATED_FILE_LOCATION list_len2)
    if(DEFINED _arg_ADDITIONAL_GENERATED_FILE_LOCATION)
        if(${list_len} STREQUAL ${list_len2})
        else()
            message(FATAL_ERROR "HADI: for multiparameter template of name ${_arg_NAMEOFTEMPLATE}, the ADDITIONAL_GENERATED_FILE_LOCATION you gave was not of the same size
                list of the number of INPUT_FILES for this template")
        endif()
    endif()

    #set all tempalte MP values to empty ---------------------------------------------
    _MP_set_template_variables_empty(NAME_OF_TEMPLATE ${_arg_NAME_OF_NODE})
    # ---------------------------------------------

    _MP_generate_file_from_intermediary(
    INC ${${_arg_NAMEOFTEMPLATE}_ALL_SO_FAR}
    INC_prev ${INC_prev}
    NAME_OF_NODE ${_arg_NAMEOFTEMPLATE}
    IS_FOR_FINAL_INTER ON
    ADDITIONAL_GENERATED_FILE_LOCATION ${_arg_ADDITIONAL_GENERATED_FILE_LOCATION})

    set(INC_prev -1)

endmacro()


#******************************************************************************************************************************************************************
#sets a multi-parameter for a template
#   FOR_PARAMETER
#   WITH_VALUE
macro(MP_define_multiparameter)
    set(options)
    set(oneValueArgs  FOR_PARAMETER  )
    set(multiValueArgs  WITH_VALUE)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    #check if there were any user sections in the WITH_VALUE variable. FOR NOW THIS WILL ONLY SUPPORT ONE USER_SECTION PER MULTIPARAMETER
    string(FIND "${_arg_WITH_VALUE}" "##UserCode" isFound)
        if(${isFound} STREQUAL "-1")

        else()
         #increment and unique name
         MATH(EXPR USER_SECTIONS_SO_FAR "${${NAME_OF_NODE}_ALL_SO_FAR}+1")
         list(GET USER_SECTIONS_POSSIBLE ${USER_SECTIONS_SO_FAR} APPENDCODE)
         set(NAME_FOR_USER_SECTION "${NAME_OF_THIS_MP_GROUP}${APPENDCODE}")
         string(REPLACE "##UserCode" "##UserCode_${NAME_FOR_USER_SECTION}" _arg_WITH_VALUE ${_arg_WITH_VALUE})
        endif()

    set(value_set_for_param   ${_arg_WITH_VALUE})
    set(${_arg_FOR_PARAMETER}_${THIS_SO_FAR}_${NAME_OF_NODE}
        ${value_set_for_param})

endmacro()


#******************************************************************************************************************************************************************
#sets a multi-parameter for a template
macro(_MP_get_unique_user_section_name)
    set(options)
    set(oneValueArgs  FOR_PARAMETER  )
    set(multiValueArgs  WITH_VALUE)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


endmacro()

#******************************************************************************************************************************************************************
macro(MP_done_defining_group)
    set(options)
    set(oneValueArg )
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})


     _MP_generate_file_from_intermediary(
     INC ${${NAME_OF_NODE}_ALL_SO_FAR}
     INC_prev ${INC_prev}
     NAME_OF_NODE ${NAME_OF_NODE} )

endmacro()




#******************************************************************************************************************************************************************
#this is the start of defining a template group's multiparameter
# the process goes to call these
#MP_define_group_of_multiparams_for_template_instance()
#MP_define_multiparameter()
#MP_define_multiparameter()
#MP_done_defining_group()
#FORTHISGROUP: name of group of multiparams
#NAME_OF_TEMPLATE: name of template
#NAME_OF_THIS_MP_GROUP: this is needed for creating a unique name for any user_sections used by cgen. if you dont have any user sections, this is not needed.
macro(MP_define_group_of_multiparams_for_template_instance)
    set(options)
    set(oneValueArgs FORTHISGROUP NAME_OF_TEMPLATE NAME_OF_THIS_MP_GROUP)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(NAME_OF_THIS_MP_GROUP ${_arg_NAME_OF_THIS_MP_GROUP})
    set(NAME_OF_NODE ${_arg_NAME_OF_TEMPLATE})

    #create a variable that will be incremented to keep track of the number of user sections created
    set(USER_SECTIONS_POSSIBLE
            za zb zc zd ze zf zg zh zi zj zk zl zm zn zo zp zq zr zs zt zu zv zw zx zy zz )
    set(USER_SECTIONS_SO_FAR 0)

    #increment the global variables ---------------------------------------------

    set(ForThisMechanism ${_arg_FORTHISGROUP})

    #${NAME_OF_NODE}_ALL_SO_FAR
    MATH(EXPR ${NAME_OF_NODE}_ALL_SO_FAR  "${${NAME_OF_NODE}_ALL_SO_FAR}+1")
    set(${NAME_OF_NODE}_ALL_SO_FAR ${${NAME_OF_NODE}_ALL_SO_FAR})

    # PUBLISHERS_SO_FAR_${NAME_OF_NODE}
    MATH(EXPR ${ForThisMechanism}_SO_FAR_${NAME_OF_NODE} "${${ForThisMechanism}_SO_FAR_${NAME_OF_NODE}}+1")
    set(${ForThisMechanism}_SO_FAR_${NAME_OF_NODE} ${${ForThisMechanism}_SO_FAR_${NAME_OF_NODE}})


    set(THIS_SO_FAR ${${ForThisMechanism}_SO_FAR_${NAME_OF_NODE}})
    set(INC_prev ${${ForThisMechanism}_SO_FAR_${NAME_OF_NODE}})
    MATH(EXPR INC_prev "${${NAME_OF_NODE}_ALL_SO_FAR}-1")

    #---------------------------------------------



    #set default values again   ---------------------------------------------
    _MP_set_template_variables_default(NAME_OF_TEMPLATE ${NAME_OF_NODE})
    # ---------------------------------------------


endmacro()






#******************************************************************************************************************************************************************
# set default values, not meant to be called from user. private function
#NAME_OF_NODE: name of your template
function(_MP_set_template_variables_default)
    set(options)
    set(oneValueArgs NAME_OF_TEMPLATE)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
#message("LIST_OF_ALL_TEMPLATE_VARIABLES -----------------------------------${LIST_OF_ALL_TEMPLATE_VARIABLES}")

foreach(TEMPLATE_VARIABLES IN LISTS LIST_OF_ALL_TEMPLATE_VARIABLES  )
    give_range_of_ints(FROM 0 TO 10 )
    foreach(INC IN LISTS RETURNEDLIST )
#        message("TEMPLATE_VARIABLES 5555555555555555555555555555  ${TEMPLATE_VARIABLES}")
#        message("NAME_OF_NODE --------------------5---------------${NAME_OF_NODE}"_arg_NAME_OF_TEMPLATE)

        set(${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE} "@${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE}@")
        set(${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE} ${${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE}} PARENT_SCOPE)
    endforeach()
endforeach()

endfunction()



#******************************************************************************************************************************************************************
# set template values to empty. usually done when about to finallize the template
#NAME_OF_TEMPLATE: name of your template
function(_MP_set_template_variables_empty)
    set(options)
    set(oneValueArgs NAME_OF_TEMPLATE)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
#message("LIST_OF_ALL_TEMPLATE_VARIABLES -----------------------------------${LIST_OF_ALL_TEMPLATE_VARIABLES}")

foreach(TEMPLATE_VARIABLES IN LISTS LIST_OF_ALL_TEMPLATE_VARIABLES  )
    give_range_of_ints(FROM 0 TO 10 )
    foreach(INC IN LISTS RETURNEDLIST )
#        message("TEMPLATE_VARIABLES 5555555555555555555555555555  ${TEMPLATE_VARIABLES}")
#        message("NAME_OF_NODE --------------------5---------------${NAME_OF_NODE}")

        set(${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE} "")
        set(${TEMPLATE_VARIABLES}_${INC}_${_arg_NAME_OF_TEMPLATE} "" PARENT_SCOPE)
    endforeach()
endforeach()

endfunction()







#******************************************************************************************************************************************************************
# PRIVATE
#this will generate files from an input file INPUT_FILE_NAME located at WORKINGDIRECTORYOFINPUTFILE
#over to output file OUTPUT_FILE_NAME located at WORKINGDIRECTORYOFOUTPUTFILE with extenstion OUTPUT_FILE_EXTENSION
#IF_FILE_DOESNT_EXIST: set to TRUE or ON if you only want to generate the file if it does NOT exist
function(_MP_Generate_File )
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

    if(NOT DEFINED _arg_WORKINGDIRECTORYOFINPUTFILE)
        #set(_arg_WORKINGDIRECTORYOFINPUTFILE ${CMAKE_SOURCE_DIR})
    endif()

    #first make sure the input file even exists. if not, dont do anything
    if (NOT EXISTS ${_arg_WORKINGDIRECTORYOFINPUTFILE}/${_arg_INPUT_FILE_NAME}.in)
        if(${DEBUG_MP} STREQUAL "TRUE" )
            message(WARNING "HADI: the input file ${_arg_WORKINGDIRECTORYOFINPUTFILE}/${_arg_INPUT_FILE_NAME}.in  did not exist when
                    attempting to cgen generate macro.")
        endif()
        return()
    endif ()

    #generate the file
    configure_file(${_arg_WORKINGDIRECTORYOFINPUTFILE}/${_arg_INPUT_FILE_NAME}.in
            ${_arg_WORKINGDIRECTORYOFOUTPUTFILE}/${_arg_OUTPUT_FILE_NAME}.${_arg_OUTPUT_FILE_EXTENSION} @ONLY)


 endfunction()







 #******************************************************************************************************************************************************************
 # PRIVATE
 #This will create a pulisher for the alcreaty created node.
 #NAME_OF_NODE: name of your node
 #TYPE_OF_EVENT_TO_PUB: events have types.
 #TOPIC_NAME_OF_EVENT: events are further defined by a type of namespace called topics.
 #ADDITIONAL_GENERATED_FILE_LOCATION: this is a second location for the final created file other than the intermediary location.
 macro(_MP_generate_file_from_intermediary)
     set(options IS_FOR_FINAL_INTER )
     set(oneValueArgs  INC INC_prev NAME_OF_NODE IS_FOR_FINAL )
     set(multiValueArgs ADDITIONAL_GENERATED_FILE_LOCATION)
     cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

     set(_arg_NAMEOFTEMPLATE ${_arg_NAME_OF_NODE})

#     message("${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES ---------------------------${${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES}")
#     message("${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_NAMES ---------------------------${${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_NAMES}")
#     message("${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_EXTENSIONS ---------------------------${${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_EXTENSIONS}")


    if(NOT DEFINED _arg_IS_FOR_FINAL_INTER  )
        set(_arg_IS_FOR_FINAL_INTER OFF)
    endif()

    if(${_arg_IS_FOR_FINAL_INTER} STREQUAL "TRUE" )
         #increment INC and INC_PREV one more time since it wasnt done by previous MP_define_group_of_multiparams_for_template_instance()
         MATH(EXPR _arg_INC_prev "${_arg_INC_prev}+1")
         set(  _arg_INC "FINAL")
    endif()

# message("_arg_INC ------------343434---------------${_arg_INC}")
# message("_arg_INC_prev ----------34343434-----------------${_arg_INC_prev}")




     list(LENGTH ${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES list_len)


     give_range_of_ints(FROM 0 TO ${list_len} )
     foreach(index_for_list IN LISTS RETURNEDLIST)
         math(EXPR index_for_list "${index_for_list} - 1")

         list(GET ${_arg_NAMEOFTEMPLATE}_INPUT_FILE_NAMES ${index_for_list} INPUT_FILE_NAME)
         list(GET ${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_NAMES ${index_for_list} OUTPUT_FILE_NAME)
         list(GET ${_arg_NAMEOFTEMPLATE}_OUTPUT_FILE_EXTENSIONS ${index_for_list} OUTPUT_FILE_EXTENSION)



         _MP_Generate_File(
             WORKINGDIRECTORYOFINPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES}
             WORKINGDIRECTORYOFOUTPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES} #${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
             INPUT_FILE_NAME ${OUTPUT_FILE_NAME}${_arg_INC_prev}
             OUTPUT_FILE_NAME ${OUTPUT_FILE_NAME}${_arg_INC}
             OUTPUT_FILE_EXTENSION in
             IF_FILE_DOESNT_EXIST FALSE)

         if(${_arg_IS_FOR_FINAL_INTER} STREQUAL "TRUE" )
             if(DEFINED _arg_ADDITIONAL_GENERATED_FILE_LOCATION)
                 list(GET _arg_ADDITIONAL_GENERATED_FILE_LOCATION ${index_for_list} _arg_ADDITIONAL_LOCATION)


                 #if this is not using cgen, just output the final file.
                 if(${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN STREQUAL "FALSE" )

                     # remove the the appended extension that was appended to the ouput file name
                     string(REGEX REPLACE "_${OUTPUT_FILE_EXTENSION}" "" OUTPUT_FILE_NAME_FINAL  ${OUTPUT_FILE_NAME})
                     message("OUTPUT_FILE_NAME_FINAL ------  ${OUTPUT_FILE_NAME_FINAL}")

                     _MP_Generate_File(
                         WORKINGDIRECTORYOFINPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES}
                         WORKINGDIRECTORYOFOUTPUTFILE ${_arg_ADDITIONAL_LOCATION} #${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
                         INPUT_FILE_NAME ${OUTPUT_FILE_NAME}${_arg_INC_prev}
                         OUTPUT_FILE_NAME ${OUTPUT_FILE_NAME_FINAL}
                         OUTPUT_FILE_EXTENSION ${OUTPUT_FILE_EXTENSION}
                         IF_FILE_DOESNT_EXIST FALSE)

                 #if this is using cgen, output another intermediary file of extension .cgenM.in finally, use cgen to generate the final file.
                 else()

                     _MP_Generate_File(
                         WORKINGDIRECTORYOFINPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES}
                         WORKINGDIRECTORYOFOUTPUTFILE ${DESTINATION_OF_INTERMEDIARYFILES} #${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
                         INPUT_FILE_NAME ${OUTPUT_FILE_NAME}${_arg_INC_prev}
                         OUTPUT_FILE_NAME ${OUTPUT_FILE_NAME}_FINAL
                         OUTPUT_FILE_EXTENSION in
                         IF_FILE_DOESNT_EXIST FALSE)

                     message("`````````````````````````\n
                           DESTINATION_OF_INTERMEDIARYFILES ----- ${DESTINATION_OF_INTERMEDIARYFILES} \n
                           _arg_ADDITIONAL_LOCATION ----- ${_arg_ADDITIONAL_LOCATION} \n
                           OUTPUT_FILE_NAME ----- ${OUTPUT_FILE_NAME} \n
                           OUTPUT_FILE_EXTENSION ----- ${OUTPUT_FILE_EXTENSION}
                           ")

                     # remove the the appended extension that was appended to the ouput file name
                     string(REGEX REPLACE "_${OUTPUT_FILE_EXTENSION}" "" OUTPUT_FILE_NAME_FINAL  ${OUTPUT_FILE_NAME})
                     message("OUTPUT_FILE_NAME_FINAL ------  ${OUTPUT_FILE_NAME_FINAL}")

                     #finally use cgen to create the final file.
                     Generate_File_Using_Cgen(
                             INPUT_DIRECTORY ${DESTINATION_OF_INTERMEDIARYFILES}
                             OUTPUT_DIRECTORY ${_arg_ADDITIONAL_LOCATION}
                             INPUT_FILE_NAME ${OUTPUT_FILE_NAME}_FINAL
                             OUTPUT_FILE_NAME ${OUTPUT_FILE_NAME_FINAL}
                             OUTPUT_FILE_EXTENSION .${OUTPUT_FILE_EXTENSION}
                     )

                 endif()

                 #if not debugging, remove the previous .in file.
                 if(${DEBUG_MP} STREQUAL "FALSE" )
                     file(REMOVE ${DESTINATION_OF_INTERMEDIARYFILES}/${OUTPUT_FILE_NAME}_FINAL.in )
                     file(REMOVE ${DESTINATION_OF_INTERMEDIARYFILES}/${OUTPUT_FILE_NAME}FINAL.in )
                     file(REMOVE ${DESTINATION_OF_INTERMEDIARYFILES}/${OUTPUT_FILE_NAME}_FINAL.cgenM.in )
                 endif()




             endif()
         endif()


         #if not debugging, remove the previous .in file.
         if(${DEBUG_MP} STREQUAL "FALSE" )
             file(REMOVE ${DESTINATION_OF_INTERMEDIARYFILES}/${OUTPUT_FILE_NAME}${_arg_INC_prev}.in )
         endif()



        endforeach()


 endmacro()

