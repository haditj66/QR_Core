// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:msg/Test.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__TEST__STRUCT_H_
#define QR_CORE__MSG__DETAIL__TEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'blablas'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Test in the package qr_core.
typedef struct qr_core__msg__Test
{
  rosidl_runtime_c__String blablas;
} qr_core__msg__Test;

// Struct for a sequence of qr_core__msg__Test.
typedef struct qr_core__msg__Test__Sequence
{
  qr_core__msg__Test * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__msg__Test__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__TEST__STRUCT_H_
