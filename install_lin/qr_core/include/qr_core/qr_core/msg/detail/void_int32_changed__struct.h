// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:msg/VoidInt32Changed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/void_int32_changed.h"


#ifndef QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_H_
#define QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/VoidInt32Changed in the package qr_core.
typedef struct qr_core__msg__VoidInt32Changed
{
  uint32_t id;
  int32_t data;
} qr_core__msg__VoidInt32Changed;

// Struct for a sequence of qr_core__msg__VoidInt32Changed.
typedef struct qr_core__msg__VoidInt32Changed__Sequence
{
  qr_core__msg__VoidInt32Changed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__msg__VoidInt32Changed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_H_
