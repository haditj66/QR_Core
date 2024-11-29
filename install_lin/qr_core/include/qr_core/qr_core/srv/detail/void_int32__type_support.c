// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qr_core:srv/VoidInt32.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qr_core/srv/detail/void_int32__rosidl_typesupport_introspection_c.h"
#include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qr_core/srv/detail/void_int32__functions.h"
#include "qr_core/srv/detail/void_int32__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__srv__VoidInt32_Request__init(message_memory);
}

void qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_fini_function(void * message_memory)
{
  qr_core__srv__VoidInt32_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_member_array[1] = {
  {
    "arg1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__srv__VoidInt32_Request, arg1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_members = {
  "qr_core__srv",  // message namespace
  "VoidInt32_Request",  // message name
  1,  // number of fields
  sizeof(qr_core__srv__VoidInt32_Request),
  false,  // has_any_key_member_
  qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_member_array,  // message members
  qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle = {
  0,
  &qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_members,
  get_message_typesupport_handle_function,
  &qr_core__srv__VoidInt32_Request__get_type_hash,
  &qr_core__srv__VoidInt32_Request__get_type_description,
  &qr_core__srv__VoidInt32_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Request)() {
  if (!qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle.typesupport_identifier) {
    qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qr_core/srv/detail/void_int32__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qr_core/srv/detail/void_int32__functions.h"
// already included above
// #include "qr_core/srv/detail/void_int32__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__srv__VoidInt32_Response__init(message_memory);
}

void qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_fini_function(void * message_memory)
{
  qr_core__srv__VoidInt32_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__srv__VoidInt32_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_members = {
  "qr_core__srv",  // message namespace
  "VoidInt32_Response",  // message name
  1,  // number of fields
  sizeof(qr_core__srv__VoidInt32_Response),
  false,  // has_any_key_member_
  qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_member_array,  // message members
  qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle = {
  0,
  &qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_members,
  get_message_typesupport_handle_function,
  &qr_core__srv__VoidInt32_Response__get_type_hash,
  &qr_core__srv__VoidInt32_Response__get_type_description,
  &qr_core__srv__VoidInt32_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Response)() {
  if (!qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle.typesupport_identifier) {
    qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qr_core/srv/detail/void_int32__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qr_core/srv/detail/void_int32__functions.h"
// already included above
// #include "qr_core/srv/detail/void_int32__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "qr_core/srv/void_int32.h"
// Member `request`
// Member `response`
// already included above
// #include "qr_core/srv/detail/void_int32__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__srv__VoidInt32_Event__init(message_memory);
}

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_fini_function(void * message_memory)
{
  qr_core__srv__VoidInt32_Event__fini(message_memory);
}

size_t qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__size_function__VoidInt32_Event__request(
  const void * untyped_member)
{
  const qr_core__srv__VoidInt32_Request__Sequence * member =
    (const qr_core__srv__VoidInt32_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__request(
  const void * untyped_member, size_t index)
{
  const qr_core__srv__VoidInt32_Request__Sequence * member =
    (const qr_core__srv__VoidInt32_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__request(
  void * untyped_member, size_t index)
{
  qr_core__srv__VoidInt32_Request__Sequence * member =
    (qr_core__srv__VoidInt32_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__fetch_function__VoidInt32_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const qr_core__srv__VoidInt32_Request * item =
    ((const qr_core__srv__VoidInt32_Request *)
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__request(untyped_member, index));
  qr_core__srv__VoidInt32_Request * value =
    (qr_core__srv__VoidInt32_Request *)(untyped_value);
  *value = *item;
}

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__assign_function__VoidInt32_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  qr_core__srv__VoidInt32_Request * item =
    ((qr_core__srv__VoidInt32_Request *)
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__request(untyped_member, index));
  const qr_core__srv__VoidInt32_Request * value =
    (const qr_core__srv__VoidInt32_Request *)(untyped_value);
  *item = *value;
}

bool qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__resize_function__VoidInt32_Event__request(
  void * untyped_member, size_t size)
{
  qr_core__srv__VoidInt32_Request__Sequence * member =
    (qr_core__srv__VoidInt32_Request__Sequence *)(untyped_member);
  qr_core__srv__VoidInt32_Request__Sequence__fini(member);
  return qr_core__srv__VoidInt32_Request__Sequence__init(member, size);
}

size_t qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__size_function__VoidInt32_Event__response(
  const void * untyped_member)
{
  const qr_core__srv__VoidInt32_Response__Sequence * member =
    (const qr_core__srv__VoidInt32_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__response(
  const void * untyped_member, size_t index)
{
  const qr_core__srv__VoidInt32_Response__Sequence * member =
    (const qr_core__srv__VoidInt32_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__response(
  void * untyped_member, size_t index)
{
  qr_core__srv__VoidInt32_Response__Sequence * member =
    (qr_core__srv__VoidInt32_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__fetch_function__VoidInt32_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const qr_core__srv__VoidInt32_Response * item =
    ((const qr_core__srv__VoidInt32_Response *)
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__response(untyped_member, index));
  qr_core__srv__VoidInt32_Response * value =
    (qr_core__srv__VoidInt32_Response *)(untyped_value);
  *value = *item;
}

void qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__assign_function__VoidInt32_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  qr_core__srv__VoidInt32_Response * item =
    ((qr_core__srv__VoidInt32_Response *)
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__response(untyped_member, index));
  const qr_core__srv__VoidInt32_Response * value =
    (const qr_core__srv__VoidInt32_Response *)(untyped_value);
  *item = *value;
}

bool qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__resize_function__VoidInt32_Event__response(
  void * untyped_member, size_t size)
{
  qr_core__srv__VoidInt32_Response__Sequence * member =
    (qr_core__srv__VoidInt32_Response__Sequence *)(untyped_member);
  qr_core__srv__VoidInt32_Response__Sequence__fini(member);
  return qr_core__srv__VoidInt32_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__srv__VoidInt32_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(qr_core__srv__VoidInt32_Event, request),  // bytes offset in struct
    NULL,  // default value
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__size_function__VoidInt32_Event__request,  // size() function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__request,  // get_const(index) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__request,  // get(index) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__fetch_function__VoidInt32_Event__request,  // fetch(index, &value) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__assign_function__VoidInt32_Event__request,  // assign(index, value) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__resize_function__VoidInt32_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(qr_core__srv__VoidInt32_Event, response),  // bytes offset in struct
    NULL,  // default value
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__size_function__VoidInt32_Event__response,  // size() function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_const_function__VoidInt32_Event__response,  // get_const(index) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__get_function__VoidInt32_Event__response,  // get(index) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__fetch_function__VoidInt32_Event__response,  // fetch(index, &value) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__assign_function__VoidInt32_Event__response,  // assign(index, value) function pointer
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__resize_function__VoidInt32_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_members = {
  "qr_core__srv",  // message namespace
  "VoidInt32_Event",  // message name
  3,  // number of fields
  sizeof(qr_core__srv__VoidInt32_Event),
  false,  // has_any_key_member_
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_member_array,  // message members
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_type_support_handle = {
  0,
  &qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_members,
  get_message_typesupport_handle_function,
  &qr_core__srv__VoidInt32_Event__get_type_hash,
  &qr_core__srv__VoidInt32_Event__get_type_description,
  &qr_core__srv__VoidInt32_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Event)() {
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Request)();
  qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Response)();
  if (!qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_type_support_handle.typesupport_identifier) {
    qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "qr_core/srv/detail/void_int32__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_members = {
  "qr_core__srv",  // service namespace
  "VoidInt32",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle,
  NULL,  // response message
  // qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle
  NULL  // event_message
  // qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle
};


static rosidl_service_type_support_t qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_type_support_handle = {
  0,
  &qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_members,
  get_service_typesupport_handle_function,
  &qr_core__srv__VoidInt32_Request__rosidl_typesupport_introspection_c__VoidInt32_Request_message_type_support_handle,
  &qr_core__srv__VoidInt32_Response__rosidl_typesupport_introspection_c__VoidInt32_Response_message_type_support_handle,
  &qr_core__srv__VoidInt32_Event__rosidl_typesupport_introspection_c__VoidInt32_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    qr_core,
    srv,
    VoidInt32
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    qr_core,
    srv,
    VoidInt32
  ),
  &qr_core__srv__VoidInt32__get_type_hash,
  &qr_core__srv__VoidInt32__get_type_description,
  &qr_core__srv__VoidInt32__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32)(void) {
  if (!qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_type_support_handle.typesupport_identifier) {
    qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, VoidInt32_Event)()->data;
  }

  return &qr_core__srv__detail__void_int32__rosidl_typesupport_introspection_c__VoidInt32_service_type_support_handle;
}
