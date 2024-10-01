// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qr_core/msg/detail/void_int64_changed__rosidl_typesupport_introspection_c.h"
#include "qr_core/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qr_core/msg/detail/void_int64_changed__functions.h"
#include "qr_core/msg/detail/void_int64_changed__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qr_core__msg__VoidInt64Changed__init(message_memory);
}

void qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_fini_function(void * message_memory)
{
  qr_core__msg__VoidInt64Changed__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_member_array[2] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__msg__VoidInt64Changed, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core__msg__VoidInt64Changed, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_members = {
  "qr_core__msg",  // message namespace
  "VoidInt64Changed",  // message name
  2,  // number of fields
  sizeof(qr_core__msg__VoidInt64Changed),
  false,  // has_any_key_member_
  qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_member_array,  // message members
  qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_init_function,  // function to initialize message memory (memory has to be allocated)
  qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_type_support_handle = {
  0,
  &qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_members,
  get_message_typesupport_handle_function,
  &qr_core__msg__VoidInt64Changed__get_type_hash,
  &qr_core__msg__VoidInt64Changed__get_type_description,
  &qr_core__msg__VoidInt64Changed__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qr_core, msg, VoidInt64Changed)() {
  if (!qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_type_support_handle.typesupport_identifier) {
    qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qr_core__msg__VoidInt64Changed__rosidl_typesupport_introspection_c__VoidInt64Changed_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
