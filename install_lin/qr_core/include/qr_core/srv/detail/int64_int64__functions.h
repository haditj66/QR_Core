// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__INT64_INT64__FUNCTIONS_H_
#define QR_CORE__SRV__DETAIL__INT64_INT64__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "qr_core/msg/rosidl_generator_c__visibility_control.h"

#include "qr_core/srv/detail/int64_int64__struct.h"

/// Initialize srv/Int64Int64 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__srv__Int64Int64_Request
 * )) before or use
 * qr_core__srv__Int64Int64_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__Int64Int64_Request__init(qr_core__srv__Int64Int64_Request * msg);

/// Finalize srv/Int64Int64 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Request__fini(qr_core__srv__Int64Int64_Request * msg);

/// Create srv/Int64Int64 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__srv__Int64Int64_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__Int64Int64_Request *
qr_core__srv__Int64Int64_Request__create();

/// Destroy srv/Int64Int64 message.
/**
 * It calls
 * qr_core__srv__Int64Int64_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Request__destroy(qr_core__srv__Int64Int64_Request * msg);


/// Initialize array of srv/Int64Int64 messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__srv__Int64Int64_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__Int64Int64_Request__Sequence__init(qr_core__srv__Int64Int64_Request__Sequence * array, size_t size);

/// Finalize array of srv/Int64Int64 messages.
/**
 * It calls
 * qr_core__srv__Int64Int64_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Request__Sequence__fini(qr_core__srv__Int64Int64_Request__Sequence * array);

/// Create array of srv/Int64Int64 messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__srv__Int64Int64_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__Int64Int64_Request__Sequence *
qr_core__srv__Int64Int64_Request__Sequence__create(size_t size);

/// Destroy array of srv/Int64Int64 messages.
/**
 * It calls
 * qr_core__srv__Int64Int64_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Request__Sequence__destroy(qr_core__srv__Int64Int64_Request__Sequence * array);

/// Initialize srv/Int64Int64 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__srv__Int64Int64_Response
 * )) before or use
 * qr_core__srv__Int64Int64_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__Int64Int64_Response__init(qr_core__srv__Int64Int64_Response * msg);

/// Finalize srv/Int64Int64 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Response__fini(qr_core__srv__Int64Int64_Response * msg);

/// Create srv/Int64Int64 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__srv__Int64Int64_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__Int64Int64_Response *
qr_core__srv__Int64Int64_Response__create();

/// Destroy srv/Int64Int64 message.
/**
 * It calls
 * qr_core__srv__Int64Int64_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Response__destroy(qr_core__srv__Int64Int64_Response * msg);


/// Initialize array of srv/Int64Int64 messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__srv__Int64Int64_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__srv__Int64Int64_Response__Sequence__init(qr_core__srv__Int64Int64_Response__Sequence * array, size_t size);

/// Finalize array of srv/Int64Int64 messages.
/**
 * It calls
 * qr_core__srv__Int64Int64_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Response__Sequence__fini(qr_core__srv__Int64Int64_Response__Sequence * array);

/// Create array of srv/Int64Int64 messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__srv__Int64Int64_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__srv__Int64Int64_Response__Sequence *
qr_core__srv__Int64Int64_Response__Sequence__create(size_t size);

/// Destroy array of srv/Int64Int64 messages.
/**
 * It calls
 * qr_core__srv__Int64Int64_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__srv__Int64Int64_Response__Sequence__destroy(qr_core__srv__Int64Int64_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__SRV__DETAIL__INT64_INT64__FUNCTIONS_H_
