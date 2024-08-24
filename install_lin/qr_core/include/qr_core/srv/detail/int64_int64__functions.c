// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice
#include "qr_core/srv/detail/int64_int64__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
qr_core__srv__Int64Int64_Request__init(qr_core__srv__Int64Int64_Request * msg)
{
  if (!msg) {
    return false;
  }
  // arg1
  return true;
}

void
qr_core__srv__Int64Int64_Request__fini(qr_core__srv__Int64Int64_Request * msg)
{
  if (!msg) {
    return;
  }
  // arg1
}

qr_core__srv__Int64Int64_Request *
qr_core__srv__Int64Int64_Request__create()
{
  qr_core__srv__Int64Int64_Request * msg = (qr_core__srv__Int64Int64_Request *)malloc(sizeof(qr_core__srv__Int64Int64_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__srv__Int64Int64_Request));
  bool success = qr_core__srv__Int64Int64_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
qr_core__srv__Int64Int64_Request__destroy(qr_core__srv__Int64Int64_Request * msg)
{
  if (msg) {
    qr_core__srv__Int64Int64_Request__fini(msg);
  }
  free(msg);
}


bool
qr_core__srv__Int64Int64_Request__Sequence__init(qr_core__srv__Int64Int64_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  qr_core__srv__Int64Int64_Request * data = NULL;
  if (size) {
    data = (qr_core__srv__Int64Int64_Request *)calloc(size, sizeof(qr_core__srv__Int64Int64_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qr_core__srv__Int64Int64_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qr_core__srv__Int64Int64_Request__fini(&data[i - 1]);
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
qr_core__srv__Int64Int64_Request__Sequence__fini(qr_core__srv__Int64Int64_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qr_core__srv__Int64Int64_Request__fini(&array->data[i]);
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

qr_core__srv__Int64Int64_Request__Sequence *
qr_core__srv__Int64Int64_Request__Sequence__create(size_t size)
{
  qr_core__srv__Int64Int64_Request__Sequence * array = (qr_core__srv__Int64Int64_Request__Sequence *)malloc(sizeof(qr_core__srv__Int64Int64_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = qr_core__srv__Int64Int64_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
qr_core__srv__Int64Int64_Request__Sequence__destroy(qr_core__srv__Int64Int64_Request__Sequence * array)
{
  if (array) {
    qr_core__srv__Int64Int64_Request__Sequence__fini(array);
  }
  free(array);
}


bool
qr_core__srv__Int64Int64_Response__init(qr_core__srv__Int64Int64_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
qr_core__srv__Int64Int64_Response__fini(qr_core__srv__Int64Int64_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

qr_core__srv__Int64Int64_Response *
qr_core__srv__Int64Int64_Response__create()
{
  qr_core__srv__Int64Int64_Response * msg = (qr_core__srv__Int64Int64_Response *)malloc(sizeof(qr_core__srv__Int64Int64_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__srv__Int64Int64_Response));
  bool success = qr_core__srv__Int64Int64_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
qr_core__srv__Int64Int64_Response__destroy(qr_core__srv__Int64Int64_Response * msg)
{
  if (msg) {
    qr_core__srv__Int64Int64_Response__fini(msg);
  }
  free(msg);
}


bool
qr_core__srv__Int64Int64_Response__Sequence__init(qr_core__srv__Int64Int64_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  qr_core__srv__Int64Int64_Response * data = NULL;
  if (size) {
    data = (qr_core__srv__Int64Int64_Response *)calloc(size, sizeof(qr_core__srv__Int64Int64_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qr_core__srv__Int64Int64_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qr_core__srv__Int64Int64_Response__fini(&data[i - 1]);
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
qr_core__srv__Int64Int64_Response__Sequence__fini(qr_core__srv__Int64Int64_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qr_core__srv__Int64Int64_Response__fini(&array->data[i]);
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

qr_core__srv__Int64Int64_Response__Sequence *
qr_core__srv__Int64Int64_Response__Sequence__create(size_t size)
{
  qr_core__srv__Int64Int64_Response__Sequence * array = (qr_core__srv__Int64Int64_Response__Sequence *)malloc(sizeof(qr_core__srv__Int64Int64_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = qr_core__srv__Int64Int64_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
qr_core__srv__Int64Int64_Response__Sequence__destroy(qr_core__srv__Int64Int64_Response__Sequence * array)
{
  if (array) {
    qr_core__srv__Int64Int64_Response__Sequence__fini(array);
  }
  free(array);
}
