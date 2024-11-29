// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice
#include "qr_core/msg/detail/void_int64_changed__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
qr_core__msg__VoidInt64Changed__init(qr_core__msg__VoidInt64Changed * msg)
{
  if (!msg) {
    return false;
  }
  // id1
  // id2
  // data
  return true;
}

void
qr_core__msg__VoidInt64Changed__fini(qr_core__msg__VoidInt64Changed * msg)
{
  if (!msg) {
    return;
  }
  // id1
  // id2
  // data
}

bool
qr_core__msg__VoidInt64Changed__are_equal(const qr_core__msg__VoidInt64Changed * lhs, const qr_core__msg__VoidInt64Changed * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id1
  if (lhs->id1 != rhs->id1) {
    return false;
  }
  // id2
  if (lhs->id2 != rhs->id2) {
    return false;
  }
  // data
  if (lhs->data != rhs->data) {
    return false;
  }
  return true;
}

bool
qr_core__msg__VoidInt64Changed__copy(
  const qr_core__msg__VoidInt64Changed * input,
  qr_core__msg__VoidInt64Changed * output)
{
  if (!input || !output) {
    return false;
  }
  // id1
  output->id1 = input->id1;
  // id2
  output->id2 = input->id2;
  // data
  output->data = input->data;
  return true;
}

qr_core__msg__VoidInt64Changed *
qr_core__msg__VoidInt64Changed__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__msg__VoidInt64Changed * msg = (qr_core__msg__VoidInt64Changed *)allocator.allocate(sizeof(qr_core__msg__VoidInt64Changed), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__msg__VoidInt64Changed));
  bool success = qr_core__msg__VoidInt64Changed__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qr_core__msg__VoidInt64Changed__destroy(qr_core__msg__VoidInt64Changed * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qr_core__msg__VoidInt64Changed__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qr_core__msg__VoidInt64Changed__Sequence__init(qr_core__msg__VoidInt64Changed__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__msg__VoidInt64Changed * data = NULL;

  if (size) {
    data = (qr_core__msg__VoidInt64Changed *)allocator.zero_allocate(size, sizeof(qr_core__msg__VoidInt64Changed), allocator.state);
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
      allocator.deallocate(data, allocator.state);
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
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qr_core__msg__VoidInt64Changed__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
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
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__msg__VoidInt64Changed__Sequence * array = (qr_core__msg__VoidInt64Changed__Sequence *)allocator.allocate(sizeof(qr_core__msg__VoidInt64Changed__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qr_core__msg__VoidInt64Changed__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qr_core__msg__VoidInt64Changed__Sequence__destroy(qr_core__msg__VoidInt64Changed__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qr_core__msg__VoidInt64Changed__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qr_core__msg__VoidInt64Changed__Sequence__are_equal(const qr_core__msg__VoidInt64Changed__Sequence * lhs, const qr_core__msg__VoidInt64Changed__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qr_core__msg__VoidInt64Changed__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qr_core__msg__VoidInt64Changed__Sequence__copy(
  const qr_core__msg__VoidInt64Changed__Sequence * input,
  qr_core__msg__VoidInt64Changed__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qr_core__msg__VoidInt64Changed);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qr_core__msg__VoidInt64Changed * data =
      (qr_core__msg__VoidInt64Changed *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qr_core__msg__VoidInt64Changed__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qr_core__msg__VoidInt64Changed__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qr_core__msg__VoidInt64Changed__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
