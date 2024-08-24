// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_H_
#define QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Int64Int64 in the package qr_core.
typedef struct qr_core__srv__Int64Int64_Request
{
  int64_t arg1;
} qr_core__srv__Int64Int64_Request;

// Struct for a sequence of qr_core__srv__Int64Int64_Request.
typedef struct qr_core__srv__Int64Int64_Request__Sequence
{
  qr_core__srv__Int64Int64_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__Int64Int64_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Int64Int64 in the package qr_core.
typedef struct qr_core__srv__Int64Int64_Response
{
  int64_t result;
} qr_core__srv__Int64Int64_Response;

// Struct for a sequence of qr_core__srv__Int64Int64_Response.
typedef struct qr_core__srv__Int64Int64_Response__Sequence
{
  qr_core__srv__Int64Int64_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__Int64Int64_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_H_
