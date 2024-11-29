// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from qr_core:msg/VoidInt32Changed.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "qr_core/msg/detail/void_int32_changed__functions.h"
#include "qr_core/msg/detail/void_int32_changed__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace qr_core
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void VoidInt32Changed_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) qr_core::msg::VoidInt32Changed(_init);
}

void VoidInt32Changed_fini_function(void * message_memory)
{
  auto typed_message = static_cast<qr_core::msg::VoidInt32Changed *>(message_memory);
  typed_message->~VoidInt32Changed();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VoidInt32Changed_message_member_array[3] = {
  {
    "id1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core::msg::VoidInt32Changed, id1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "id2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core::msg::VoidInt32Changed, id2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qr_core::msg::VoidInt32Changed, data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VoidInt32Changed_message_members = {
  "qr_core::msg",  // message namespace
  "VoidInt32Changed",  // message name
  3,  // number of fields
  sizeof(qr_core::msg::VoidInt32Changed),
  false,  // has_any_key_member_
  VoidInt32Changed_message_member_array,  // message members
  VoidInt32Changed_init_function,  // function to initialize message memory (memory has to be allocated)
  VoidInt32Changed_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VoidInt32Changed_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VoidInt32Changed_message_members,
  get_message_typesupport_handle_function,
  &qr_core__msg__VoidInt32Changed__get_type_hash,
  &qr_core__msg__VoidInt32Changed__get_type_description,
  &qr_core__msg__VoidInt32Changed__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace qr_core


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qr_core::msg::VoidInt32Changed>()
{
  return &::qr_core::msg::rosidl_typesupport_introspection_cpp::VoidInt32Changed_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qr_core, msg, VoidInt32Changed)() {
  return &::qr_core::msg::rosidl_typesupport_introspection_cpp::VoidInt32Changed_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
