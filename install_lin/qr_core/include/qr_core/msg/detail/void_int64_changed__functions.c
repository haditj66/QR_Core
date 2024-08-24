// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice
#include "qr_core/msg/detail/void_int64_changed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
qr_core__msg__VoidInt64Changed__init(qr_core__msg__VoidInt64Changed * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // data
  return true;
}

void
qr_core__msg__VoidInt64Changed__fini(qr_core__msg__VoidInt64Changed * msg)
{
  if (!msg) {
    return;
  }
  // id
  // data
}

qr_core__msg__VoidInt64Changed *
qr_core__msg__VoidInt64Changed__create()
{
  qr_core__msg__VoidInt64Changed * msg = (qr_core__msg__VoidInt64Changed *)malloc(sizeof(qr_core__msg__VoidInt64Changed));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__msg__VoidInt64Changed));
  bool success = qr_core__msg__VoidInt64Changed__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
qr_core__msg__VoidInt64Changed__destroy(qr_core__msg__VoidInt64Changed * msg)
{
  if (msg) {
    qr_core__msg__VoidInt64Changed__fini(msg);
  }
  free(msg);
}


bool
qr_core__msg__VoidInt64Changed__Sequence__init(qr_core__msg__VoidInt64Changed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  qr_core__msg__VoidInt64Changed * data = NULL;
  if (size) {
    data = (qr_core__msg__VoidInt64Changed *)calloc(size, sizeof(qr_core__msg__VoidInt64Changed));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qr_core__msg__VoidInt64Changed__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qr_core__msg__VoidInt64Changed__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
qr_core__msg__VoidInt64Changed__Sequence__fini(qr_core__msg__VoidInt64Changed__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qr_core__msg__VoidInt64Changed__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

qr_core__msg__VoidInt64Changed__Sequence *
qr_core__msg__VoidInt64Changed__Sequence__create(size_t size)
{
  qr_core__msg__VoidInt64Changed__Sequence * array = (qr_core__msg__VoidInt64Changed__Sequence *)malloc(sizeof(qr_core__msg__VoidInt64Changed__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = qr_core__msg__VoidInt64Changed__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
qr_core__msg__VoidInt64Changed__Sequence__destroy(qr_core__msg__VoidInt64Changed__Sequence * array)
{
  if (array) {
    qr_core__msg__VoidInt64Changed__Sequence__fini(array);
  }
  free(array);
}
