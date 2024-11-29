// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from qr_core:srv/SyncInt64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/sync_int64.h"


#ifndef QR_CORE__SRV__DETAIL__SYNC_INT64__FUNCTIONS_H_
#define QR_CORE__SRV__DETAIL__SYNC_INT64__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "qr_core/msg/rosidl_generator_c__visibility_control.h"

#include "qr_core/srv/detail/sync_int64__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__SyncInt64__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__SyncInt64__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__SyncInt64__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__SyncInt64__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/SyncInt64 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__srv__SyncInt64_Request
 * )) before or use
 * qr_core__srv__SyncInt64_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__init(qr_core__srv__SyncInt64_Request * msg);

/// Finalize srv/SyncInt64 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Request__fini(qr_core__srv__SyncInt64_Request * msg);

/// Create srv/SyncInt64 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__srv__SyncInt64_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Request *
qr_core__srv__SyncInt64_Request__create(void);

/// Destroy srv/SyncInt64 message.
/**
 * It calls
 * qr_core__srv__SyncInt64_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Request__destroy(qr_core__srv__SyncInt64_Request * msg);

/// Check for srv/SyncInt64 message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__are_equal(const qr_core__srv__SyncInt64_Request * lhs, const qr_core__srv__SyncInt64_Request * rhs);

/// Copy a srv/SyncInt64 message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__copy(
  const qr_core__srv__SyncInt64_Request * input,
  qr_core__srv__SyncInt64_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__SyncInt64_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__SyncInt64_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__SyncInt64_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__SyncInt64_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__srv__SyncInt64_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__Sequence__init(qr_core__srv__SyncInt64_Request__Sequence * array, size_t size);

/// Finalize array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Request__Sequence__fini(qr_core__srv__SyncInt64_Request__Sequence * array);

/// Create array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__srv__SyncInt64_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Request__Sequence *
qr_core__srv__SyncInt64_Request__Sequence__create(size_t size);

/// Destroy array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Request__Sequence__destroy(qr_core__srv__SyncInt64_Request__Sequence * array);

/// Check for srv/SyncInt64 message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__Sequence__are_equal(const qr_core__srv__SyncInt64_Request__Sequence * lhs, const qr_core__srv__SyncInt64_Request__Sequence * rhs);

/// Copy an array of srv/SyncInt64 messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Request__Sequence__copy(
  const qr_core__srv__SyncInt64_Request__Sequence * input,
  qr_core__srv__SyncInt64_Request__Sequence * output);

/// Initialize srv/SyncInt64 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__srv__SyncInt64_Response
 * )) before or use
 * qr_core__srv__SyncInt64_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__init(qr_core__srv__SyncInt64_Response * msg);

/// Finalize srv/SyncInt64 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Response__fini(qr_core__srv__SyncInt64_Response * msg);

/// Create srv/SyncInt64 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__srv__SyncInt64_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Response *
qr_core__srv__SyncInt64_Response__create(void);

/// Destroy srv/SyncInt64 message.
/**
 * It calls
 * qr_core__srv__SyncInt64_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Response__destroy(qr_core__srv__SyncInt64_Response * msg);

/// Check for srv/SyncInt64 message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__are_equal(const qr_core__srv__SyncInt64_Response * lhs, const qr_core__srv__SyncInt64_Response * rhs);

/// Copy a srv/SyncInt64 message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__copy(
  const qr_core__srv__SyncInt64_Response * input,
  qr_core__srv__SyncInt64_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__SyncInt64_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__SyncInt64_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__SyncInt64_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__SyncInt64_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__srv__SyncInt64_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__Sequence__init(qr_core__srv__SyncInt64_Response__Sequence * array, size_t size);

/// Finalize array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Response__Sequence__fini(qr_core__srv__SyncInt64_Response__Sequence * array);

/// Create array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__srv__SyncInt64_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Response__Sequence *
qr_core__srv__SyncInt64_Response__Sequence__create(size_t size);

/// Destroy array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Response__Sequence__destroy(qr_core__srv__SyncInt64_Response__Sequence * array);

/// Check for srv/SyncInt64 message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__Sequence__are_equal(const qr_core__srv__SyncInt64_Response__Sequence * lhs, const qr_core__srv__SyncInt64_Response__Sequence * rhs);

/// Copy an array of srv/SyncInt64 messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Response__Sequence__copy(
  const qr_core__srv__SyncInt64_Response__Sequence * input,
  qr_core__srv__SyncInt64_Response__Sequence * output);

/// Initialize srv/SyncInt64 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__srv__SyncInt64_Event
 * )) before or use
 * qr_core__srv__SyncInt64_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__init(qr_core__srv__SyncInt64_Event * msg);

/// Finalize srv/SyncInt64 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Event__fini(qr_core__srv__SyncInt64_Event * msg);

/// Create srv/SyncInt64 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__srv__SyncInt64_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Event *
qr_core__srv__SyncInt64_Event__create(void);

/// Destroy srv/SyncInt64 message.
/**
 * It calls
 * qr_core__srv__SyncInt64_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Event__destroy(qr_core__srv__SyncInt64_Event * msg);

/// Check for srv/SyncInt64 message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__are_equal(const qr_core__srv__SyncInt64_Event * lhs, const qr_core__srv__SyncInt64_Event * rhs);

/// Copy a srv/SyncInt64 message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__copy(
  const qr_core__srv__SyncInt64_Event * input,
  qr_core__srv__SyncInt64_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__SyncInt64_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__SyncInt64_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__SyncInt64_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__SyncInt64_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__srv__SyncInt64_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__Sequence__init(qr_core__srv__SyncInt64_Event__Sequence * array, size_t size);

/// Finalize array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Event__Sequence__fini(qr_core__srv__SyncInt64_Event__Sequence * array);

/// Create array of srv/SyncInt64 messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__srv__SyncInt64_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__SyncInt64_Event__Sequence *
qr_core__srv__SyncInt64_Event__Sequence__create(size_t size);

/// Destroy array of srv/SyncInt64 messages.
/**
 * It calls
 * qr_core__srv__SyncInt64_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__SyncInt64_Event__Sequence__destroy(qr_core__srv__SyncInt64_Event__Sequence * array);

/// Check for srv/SyncInt64 message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__Sequence__are_equal(const qr_core__srv__SyncInt64_Event__Sequence * lhs, const qr_core__srv__SyncInt64_Event__Sequence * rhs);

/// Copy an array of srv/SyncInt64 messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__SyncInt64_Event__Sequence__copy(
  const qr_core__srv__SyncInt64_Event__Sequence * input,
  qr_core__srv__SyncInt64_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__SRV__DETAIL__SYNC_INT64__FUNCTIONS_H_
