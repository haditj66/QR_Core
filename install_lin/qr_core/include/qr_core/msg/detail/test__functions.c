// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qr_core:msg/Test.idl
// generated code does not contain a copyright notice
#include "qr_core/msg/detail/test__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `blablas`
#include "rosidl_runtime_c/string_functions.h"

bool
qr_core__msg__Test__init(qr_core__msg__Test * msg)
{
  if (!msg) {
    return false;
  }
  // blablas
  if (!rosidl_runtime_c__String__init(&msg->blablas)) {
    qr_core__msg__Test__fini(msg);
    return false;
  }
  return true;
}

void
qr_core__msg__Test__fini(qr_core__msg__Test * msg)
{
  if (!msg) {
    return;
  }
  // blablas
  rosidl_runtime_c__String__fini(&msg->blablas);
}

qr_core__msg__Test *
qr_core__msg__Test__create()
{
  qr_core__msg__Test * msg = (qr_core__msg__Test *)malloc(sizeof(qr_core__msg__Test));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__msg__Test));
  bool success = qr_core__msg__Test__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
qr_core__msg__Test__destroy(qr_core__msg__Test * msg)
{
  if (msg) {
    qr_core__msg__Test__fini(msg);
  }
  free(msg);
}


bool
qr_core__msg__Test__Sequence__init(qr_core__msg__Test__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  qr_core__msg__Test * data = NULL;
  if (size) {
    data = (qr_core__msg__Test *)calloc(size, sizeof(qr_core__msg__Test));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qr_core__msg__Test__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qr_core__msg__Test__fini(&data[i - 1]);
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
qr_core__msg__Test__Sequence__fini(qr_core__msg__Test__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qr_core__msg__Test__fini(&array->data[i]);
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

qr_core__msg__Test__Sequence *
qr_core__msg__Test__Sequence__create(size_t size)
{
  qr_core__msg__Test__Sequence * array = (qr_core__msg__Test__Sequence *)malloc(sizeof(qr_core__msg__Test__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = qr_core__msg__Test__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
qr_core__msg__Test__Sequence__destroy(qr_core__msg__Test__Sequence * array)
{
  if (array) {
    qr_core__msg__Test__Sequence__fini(array);
  }
  free(array);
}
