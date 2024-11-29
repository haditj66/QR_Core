// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qr_core:srv/SyncInt64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/sync_int64.h"


#ifndef QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_H_
#define QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SyncInt64 in the package qr_core.
typedef struct qr_core__srv__SyncInt64_Request
{
  int64_t id1;
  int64_t id2;
  int64_t arg1;
} qr_core__srv__SyncInt64_Request;

// Struct for a sequence of qr_core__srv__SyncInt64_Request.
typedef struct qr_core__srv__SyncInt64_Request__Sequence
{
  qr_core__srv__SyncInt64_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__SyncInt64_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SyncInt64 in the package qr_core.
typedef struct qr_core__srv__SyncInt64_Response
{
  uint8_t structure_needs_at_least_one_member;
} qr_core__srv__SyncInt64_Response;

// Struct for a sequence of qr_core__srv__SyncInt64_Response.
typedef struct qr_core__srv__SyncInt64_Response__Sequence
{
  qr_core__srv__SyncInt64_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__SyncInt64_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  qr_core__srv__SyncInt64_Event__request__MAX_SIZE = 1
};
// response
enum
{
  qr_core__srv__SyncInt64_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SyncInt64 in the package qr_core.
typedef struct qr_core__srv__SyncInt64_Event
{
  service_msgs__msg__ServiceEventInfo info;
  qr_core__srv__SyncInt64_Request__Sequence request;
  qr_core__srv__SyncInt64_Response__Sequence response;
} qr_core__srv__SyncInt64_Event;

// Struct for a sequence of qr_core__srv__SyncInt64_Event.
typedef struct qr_core__srv__SyncInt64_Event__Sequence
{
  qr_core__srv__SyncInt64_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qr_core__srv__SyncInt64_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_H_
