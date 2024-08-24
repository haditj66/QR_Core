// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "qr_core/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "qr_core/msg/detail/void_int64_changed__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace qr_core
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qr_core
cdr_serialize(
  const qr_core::msg::VoidInt64Changed & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qr_core
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  qr_core::msg::VoidInt64Changed & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qr_core
get_serialized_size(
  const qr_core::msg::VoidInt64Changed & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qr_core
max_serialized_size_VoidInt64Changed(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace qr_core

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qr_core
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qr_core, msg, VoidInt64Changed)();

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
