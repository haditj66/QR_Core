// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice
#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "qr_core/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "qr_core/msg/detail/void_int64_changed__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
bool cdr_serialize_qr_core__msg__VoidInt64Changed(
  const qr_core__msg__VoidInt64Changed * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
bool cdr_deserialize_qr_core__msg__VoidInt64Changed(
  eprosima::fastcdr::Cdr &,
  qr_core__msg__VoidInt64Changed * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
size_t get_serialized_size_qr_core__msg__VoidInt64Changed(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
size_t max_serialized_size_qr_core__msg__VoidInt64Changed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
bool cdr_serialize_key_qr_core__msg__VoidInt64Changed(
  const qr_core__msg__VoidInt64Changed * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
size_t get_serialized_size_key_qr_core__msg__VoidInt64Changed(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
size_t max_serialized_size_key_qr_core__msg__VoidInt64Changed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qr_core
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, qr_core, msg, VoidInt64Changed)();

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
