// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/void_int64_changed.h"


#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__STRUCT_H_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/VoidInt64Changed in the package qr_core.
typedef struct qr_core__msg__VoidInt64Changed
{
  uint64_t id;
  int64_t data;
} qr_core__msg__VoidInt64Changed;

// Struct for a sequence of qr_core__msg__VoidInt64Changed.
typedef struct qr_core__msg__VoidInt64Changed__Sequence
{
  qr_core__msg__VoidInt64Changed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__msg__VoidInt64Changed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__STRUCT_H_
