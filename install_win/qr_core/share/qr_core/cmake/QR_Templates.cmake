include(${QR_CORE_DIR}/cmake/MultiParameterTemplate.cmake)

include(${QR_CORE_DIR}/cmake/QR_Core.cmake)


#=====================================================================================
#create a node template that you can add publishers and subscribers to.
#=====================================================================================

#******************************************************************************************************************************************************************
# Initialize the capability to use composable node tempaltes. call this at least once.
macro(QR_composable_node_init)



    MP_intitialize(DESTINATION_OF_INTERMEDIARYFILES ${CMAKE_CURRENT_SOURCE_DIR}/GeneratedFiles )

endmacro()




#******************************************************************************************************************************************************************
# This will create template files for a publisher node.
#NAME_OF_NODE: name of your node
#TYPE_OF_EVENT_TO_PUB: events have types.
#TOPIC_NAME_OF_EVENT: events are further defined by a type of namespace called topics.
macro(QR_create_composable_node)
    set(options)
    set(oneValueArgs FOR_TARGET NAME_OF_NODE  IS_THIS_USING_CGEN)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(NAME_OF_NODE ${_arg_NAME_OF_NODE})


    #if this is not on windows, make sure it cant use cgen
    if(NOT WIN32)
        message("DESTINATION_OF_INTERMEDIARYFILES  999999999999999999999999  ${DESTINATION_OF_INTERMEDIARYFILES}")
        set(_arg_IS_THIS_USING_CGEN FALSE)
    endif()

#       set(LIST_OF_ALL_TEMPLATE_VARIABLES
#           PUBLISHER
#           PUBLISHER_CONSTRUCTOR
#           SUBSCRIBER )

#       #initialize multi-parameter template abilities -----------------------------------------

#       set(GROUPS_OF_MULTIPARAMS PUBLISHERS SUBSCRIBERS)


    MP_create_instance_of_multiparameter_template(
        LIST_OF_ALL_TEMPLATE_VARIABLES
                   PUBLISHER
                   PUBLISHER_HEADER
                   PUBLISHER_CONSTRUCTOR
                   SUBSCRIBER
                   SUBSCRIBER_CONSTRUCTOR
                   SUBSCRIBER_CALLBACK_DECLARATION
                   SUBSCRIBER_CALLBACK_DEFINITION
                   SUBSCRIBER_TYPE_HEADER

        GROUPS_OF_MULTIPARAMS PUBLISHERS SUBSCRIBERS

        NAMEOFTEMPLATE ${NAME_OF_NODE}
        WORKINGDIRECTORYOFINPUTFILE "${QR_CORE_DIR}/GeneratedFiles"
        INPUT_FILE_NAMES     Composable_Node_cpp Composable_Node_hpp
        OUTPUT_FILE_NAMES    ${NAME_OF_NODE} ${NAME_OF_NODE}
        OUTPUT_FILE_EXTENSIONS cpp hpp
        IS_THIS_USING_CGEN ${_arg_IS_THIS_USING_CGEN})



    #source_group("Include files" FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/${_arg_NAME_OF_NODE}.hpp)

endmacro()






#call this when you are done with a node instance
#NAMEOFTEMPLATE: name of this template
macro(QR_done_with_instance_of_node)
    set(options)
    set(oneValueArgs NAMEOFTEMPLATE)
    set(multiValueArgs )
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



    if(${_arg_NAMEOFTEMPLATE}_IS_THIS_USING_CGEN STREQUAL "FALSE" )

        MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE ${_arg_NAMEOFTEMPLATE} )
    else()
        MP_done_with_instance_of_multiparameter_template(NAMEOFTEMPLATE ${_arg_NAMEOFTEMPLATE}

            ADDITIONAL_GENERATED_FILE_LOCATION
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})
    endif()



endmacro()




#=====================================================================================
#add publishers, subscribers, actions, and services to an already created node template
#=====================================================================================




#******************************************************************************************************************************************************************
# This will create a pulisher for the already created node.
#FOR_PACKAGE: need which package this publisher is for because I'll need the headers which will have the package as first name
#FOR_TYPE_MSG_FILE_NAME: events have types.
#TOPIC_NAME_OF_EVENT: events are further defined by a type of namespace called topics.
macro(QR_add_publisher_to_node)
    set(options)
    set(oneValueArgs   FOR_TYPE_MSG_FILE_NAME FOR_PACKAGE TOPIC_NAME_OF_EVENT)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



    set(TYPE_OF_EVENT "${_arg_FOR_PACKAGE}::msg::${_arg_FOR_TYPE_MSG_FILE_NAME}")
    set(TOPIC_NAME_OF_EVENT ${_arg_TOPIC_NAME_OF_EVENT})


    to_lowercase_with_underscore(INPUT_STRING ${_arg_FOR_TYPE_MSG_FILE_NAME})
    set(MSG_NAME_AS_AS_LOWER ${OUTPUT_STRING})

    MP_define_group_of_multiparams_for_template_instance(
        FORTHISGROUP PUBLISHERS
        NAME_OF_TEMPLATE ${NAME_OF_NODE})

    MP_define_multiparameter(
        FOR_PARAMETER PUBLISHER_HEADER
        WITH_VALUE "#include \"${_arg_FOR_PACKAGE}/msg/${MSG_NAME_AS_AS_LOWER}.hpp\" \n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER PUBLISHER
        WITH_VALUE "rclcpp::Publisher<${TYPE_OF_EVENT}>::SharedPtr pub${THIS_SO_FAR}_;\n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER PUBLISHER_CONSTRUCTOR
        WITH_VALUE "pub${THIS_SO_FAR}_ = this->create_publisher<${TYPE_OF_EVENT}>(\"~/${TOPIC_NAME_OF_EVENT}\",100);\n"
        )

    MP_done_defining_group(  )


endmacro()








#******************************************************************************************************************************************************************
# This will create a subscriber for node.
#NAME_OF_SUBSCRIBER: the subscriber UNIQUE name. MUST NOT BE A DUPLICATE OF ANY PREVIOUSLY NAMED SUBSCRIBERS!!
#FOR_PACKAGE: need which package this publisher is for because I'll need the headers which will have the package as first name
#FOR_TYPE_MSG_FILE_NAME: events have types.
#TOPIC_NAME_OF_EVENT: events are further defined by a type of namespace called topics.
macro(QR_add_subscriber_to_node)
    set(options)
    set(oneValueArgs NAME_OF_SUBSCRIBER FOR_TYPE_MSG_FILE_NAME  FOR_PACKAGE TOPIC_NAME_OF_EVENT  )
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # because this is using cgen, you must provide name for the subscriber to give any user sections, unique names
    if( ${_arg_NAME_OF_SUBSCRIBER} STREQUAL "")
        message(FATAL_ERROR "HADI: you did not define the parameter NAME_OF_SUBSCRIBER, when calling the QR_add_subscriber_to_node function.")
    endif()

    string_has_any_digits(INPUT_STRING ${_arg_NAME_OF_SUBSCRIBER})
    if(${OUTPUT_BOOL} STREQUAL "TRUE")
        message(FATAL_ERROR "HADI:   NAME_OF_SUBSCRIBER has a name ${_arg_NAME_OF_SUBSCRIBER}. that has a number in it. Dont put numbers or underscores in the name.")
    endif()

    set(TYPE_OF_EVENT "${_arg_FOR_PACKAGE}::msg::${_arg_FOR_TYPE_MSG_FILE_NAME}")
    set(TOPIC_NAME_OF_EVENT ${_arg_TOPIC_NAME_OF_EVENT})
    set(NAME_OF_CALLBACK ${_arg_NAME_OF_SUBSCRIBER}_Callback)

    to_lowercase_with_underscore(INPUT_STRING ${_arg_FOR_TYPE_MSG_FILE_NAME})
    set(MSG_NAME_AS_AS_LOWER ${OUTPUT_STRING})

    MP_define_group_of_multiparams_for_template_instance(
        FORTHISGROUP SUBSCRIBERS
        NAME_OF_TEMPLATE ${NAME_OF_NODE}
        NAME_OF_THIS_MP_GROUP ${_arg_NAME_OF_SUBSCRIBER})

    MP_define_multiparameter(
        FOR_PARAMETER SUBSCRIBER
        WITH_VALUE "rclcpp::Subscription<${TYPE_OF_EVENT}>::SharedPtr subscription_${_arg_NAME_OF_SUBSCRIBER};\n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER SUBSCRIBER_TYPE_HEADER
        WITH_VALUE "#include \"${_arg_FOR_PACKAGE}/msg/${MSG_NAME_AS_AS_LOWER}.hpp\" \n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER SUBSCRIBER_CONSTRUCTOR
        WITH_VALUE "subscription_${_arg_NAME_OF_SUBSCRIBER} = this->create_subscription<${TYPE_OF_EVENT}>( \"${TOPIC_NAME_OF_EVENT}\", 10,
            std::bind(&${NAME_OF_NODE}::${NAME_OF_CALLBACK}, this, _1));\n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER SUBSCRIBER_CALLBACK_DECLARATION
        WITH_VALUE "void ${NAME_OF_CALLBACK}(const ${TYPE_OF_EVENT}::SharedPtr msg) const;\n"
        )

    MP_define_multiparameter(
        FOR_PARAMETER SUBSCRIBER_CALLBACK_DEFINITION
        WITH_VALUE "
//the callback for subscription to topic ${TOPIC_NAME_OF_EVENT}
void ${NAME_OF_NODE}::${NAME_OF_CALLBACK}(const ${TYPE_OF_EVENT}::SharedPtr msg) const
{
##UserCode
    //RCLCPP_INFO(this->get_logger(), "" ${NAME_OF_NODE} has received the ${TOPIC_NAME_OF_EVENT} published message: '%s'"", msg->data.c_str());
} \n\n"
        )


    MP_done_defining_group()


endmacro()
















#=====================================================================================
#templates for main composable and single node exe targets
#=====================================================================================



#******************************************************************************************************************************************************************
# This will create a pulisher for the already created node.
#NAME_OF_NODE: name of exe target
#NAME_OF_NODE: the name of the node this exe target is for.
macro(QR_create_single_node_exe_target)
    set(options)
    set(oneValueArgs NAME_OF_NODE TYPE_OF_EVENT TOPIC_NAME_OF_EVENT)
    set(multiValueArgs)
    cmake_parse_arguments(_arg "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT DEFINED _arg_DEBUG_MP)
        set(_arg_DEBUG_MP FALSE)
    endif()

endmacro()





