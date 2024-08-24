// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qr_core/srv/detail/int64_int64__rosidl_typesupport_introspection_c.h"
#include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qr_core/srv/detail/int64_int64__functions.h"
#include "qr_core/srv/detail/int64_int64__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__srv__Int64Int64_Request__init(message_memory);
}

void Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_fini_function(void * message_memory)
{
  qr_core__srv__Int64Int64_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_member_array[1] = {
  {
    "arg1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__srv__Int64Int64_Request, arg1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_members = {
  "qr_core__srv",  // message namespace
  "Int64Int64_Request",  // message name
  1,  // number of fields
  sizeof(qr_core__srv__Int64Int64_Request),
  Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_member_array,  // message members
  Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_type_support_handle = {
  0,
  &Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Request)() {
  if (!Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_type_support_handle.typesupport_identifier) {
    Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Int64Int64_Request__rosidl_typesupport_introspection_c__Int64Int64_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qr_core/srv/detail/int64_int64__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qr_core/srv/detail/int64_int64__functions.h"
// already included above
// #include "qr_core/srv/detail/int64_int64__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__srv__Int64Int64_Response__init(message_memory);
}

void Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_fini_function(void * message_memory)
{
  qr_core__srv__Int64Int64_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__srv__Int64Int64_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_members = {
  "qr_core__srv",  // message namespace
  "Int64Int64_Response",  // message name
  1,  // number of fields
  sizeof(qr_core__srv__Int64Int64_Response),
  Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_member_array,  // message members
  Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_type_support_handle = {
  0,
  &Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Response)() {
  if (!Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_type_support_handle.typesupport_identifier) {
    Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Int64Int64_Response__rosidl_typesupport_introspection_c__Int64Int64_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "qr_core/srv/detail/int64_int64__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_members = {
  "qr_core__srv",  // service namespace
  "Int64Int64",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_Request_message_type_support_handle,
  NULL  // response message
  // qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_Response_message_type_support_handle
};

static rosidl_service_type_support_t qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_type_support_handle = {
  0,
  &qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64)() {
  if (!qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_type_support_handle.typesupport_identifier) {
    qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, srv, Int64Int64_Response)()->data;
  }

  return &qr_core__srv__detail__int64_int64__rosidl_typesupport_introspection_c__Int64Int64_service_type_support_handle;
}
