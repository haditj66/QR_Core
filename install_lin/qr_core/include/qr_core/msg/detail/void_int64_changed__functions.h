// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__FUNCTIONS_H_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "qr_core/msg/rosidl_generator_c__visibility_control.h"

#include "qr_core/msg/detail/void_int64_changed__struct.h"

/// Initialize msg/VoidInt64Changed message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * qr_core__msg__VoidInt64Changed
 * )) before or use
 * qr_core__msg__VoidInt64Changed__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__msg__VoidInt64Changed__init(qr_core__msg__VoidInt64Changed * msg);

/// Finalize msg/VoidInt64Changed message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__msg__VoidInt64Changed__fini(qr_core__msg__VoidInt64Changed * msg);

/// Create msg/VoidInt64Changed message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * qr_core__msg__VoidInt64Changed__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__msg__VoidInt64Changed *
qr_core__msg__VoidInt64Changed__create();

/// Destroy msg/VoidInt64Changed message.
/**
 * It calls
 * qr_core__msg__VoidInt64Changed__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__msg__VoidInt64Changed__destroy(qr_core__msg__VoidInt64Changed * msg);


/// Initialize array of msg/VoidInt64Changed messages.
/**
 * It allocates the memory for the number of elements and calls
 * qr_core__msg__VoidInt64Changed__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
bool
qr_core__msg__VoidInt64Changed__Sequence__init(qr_core__msg__VoidInt64Changed__Sequence * array, size_t size);

/// Finalize array of msg/VoidInt64Changed messages.
/**
 * It calls
 * qr_core__msg__VoidInt64Changed__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__msg__VoidInt64Changed__Sequence__fini(qr_core__msg__VoidInt64Changed__Sequence * array);

/// Create array of msg/VoidInt64Changed messages.
/**
 * It allocates the memory for the array and calls
 * qr_core__msg__VoidInt64Changed__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
qr_core__msg__VoidInt64Changed__Sequence *
qr_core__msg__VoidInt64Changed__Sequence__create(size_t size);

/// Destroy array of msg/VoidInt64Changed messages.
/**
 * It calls
 * qr_core__msg__VoidInt64Changed__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_qr_core
void
qr_core__msg__VoidInt64Changed__Sequence__destroy(qr_core__msg__VoidInt64Changed__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__FUNCTIONS_H_
