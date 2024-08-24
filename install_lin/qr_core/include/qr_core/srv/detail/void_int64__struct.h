// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:srv/VoidInt64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_H_
#define QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/VoidInt64 in the package qr_core.
typedef struct qr_core__srv__VoidInt64_Request
{
  uint64_t id;
  int64_t arg1;
} qr_core__srv__VoidInt64_Request;

// Struct for a sequence of qr_core__srv__VoidInt64_Request.
typedef struct qr_core__srv__VoidInt64_Request__Sequence
{
  qr_core__srv__VoidInt64_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__VoidInt64_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/VoidInt64 in the package qr_core.
typedef struct qr_core__srv__VoidInt64_Response
{
  uint8_t structure_needs_at_least_one_member;
} qr_core__srv__VoidInt64_Response;

// Struct for a sequence of qr_core__srv__VoidInt64_Response.
typedef struct qr_core__srv__VoidInt64_Response__Sequence
{
  qr_core__srv__VoidInt64_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__VoidInt64_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_H_
