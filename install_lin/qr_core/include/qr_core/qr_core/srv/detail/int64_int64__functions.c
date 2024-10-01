// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice
#include "qr_core/srv/detail/int64_int64__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

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

bool
qr_core__srv__Int64Int64_Request__are_equal(const qr_core__srv__Int64Int64_Request * lhs, const qr_core__srv__Int64Int64_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arg1
  if (lhs->arg1 != rhs->arg1) {
    return false;
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Request__copy(
  const qr_core__srv__Int64Int64_Request * input,
  qr_core__srv__Int64Int64_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // arg1
  output->arg1 = input->arg1;
  return true;
}

qr_core__srv__Int64Int64_Request *
qr_core__srv__Int64Int64_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Request * msg = (qr_core__srv__Int64Int64_Request *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__srv__Int64Int64_Request));
  bool success = qr_core__srv__Int64Int64_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qr_core__srv__Int64Int64_Request__destroy(qr_core__srv__Int64Int64_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qr_core__srv__Int64Int64_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qr_core__srv__Int64Int64_Request__Sequence__init(qr_core__srv__Int64Int64_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Request * data = NULL;

  if (size) {
    data = (qr_core__srv__Int64Int64_Request *)allocator.zero_allocate(size, sizeof(qr_core__srv__Int64Int64_Request), allocator.state);
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
qr_core__srv__Int64Int64_Request__Sequence__fini(qr_core__srv__Int64Int64_Request__Sequence * array)
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
      qr_core__srv__Int64Int64_Request__fini(&array->data[i]);
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

qr_core__srv__Int64Int64_Request__Sequence *
qr_core__srv__Int64Int64_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Request__Sequence * array = (qr_core__srv__Int64Int64_Request__Sequence *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qr_core__srv__Int64Int64_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qr_core__srv__Int64Int64_Request__Sequence__destroy(qr_core__srv__Int64Int64_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qr_core__srv__Int64Int64_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qr_core__srv__Int64Int64_Request__Sequence__are_equal(const qr_core__srv__Int64Int64_Request__Sequence * lhs, const qr_core__srv__Int64Int64_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qr_core__srv__Int64Int64_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Request__Sequence__copy(
  const qr_core__srv__Int64Int64_Request__Sequence * input,
  qr_core__srv__Int64Int64_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qr_core__srv__Int64Int64_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qr_core__srv__Int64Int64_Request * data =
      (qr_core__srv__Int64Int64_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qr_core__srv__Int64Int64_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qr_core__srv__Int64Int64_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qr_core__srv__Int64Int64_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
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

bool
qr_core__srv__Int64Int64_Response__are_equal(const qr_core__srv__Int64Int64_Response * lhs, const qr_core__srv__Int64Int64_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Response__copy(
  const qr_core__srv__Int64Int64_Response * input,
  qr_core__srv__Int64Int64_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

qr_core__srv__Int64Int64_Response *
qr_core__srv__Int64Int64_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Response * msg = (qr_core__srv__Int64Int64_Response *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__srv__Int64Int64_Response));
  bool success = qr_core__srv__Int64Int64_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qr_core__srv__Int64Int64_Response__destroy(qr_core__srv__Int64Int64_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qr_core__srv__Int64Int64_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qr_core__srv__Int64Int64_Response__Sequence__init(qr_core__srv__Int64Int64_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Response * data = NULL;

  if (size) {
    data = (qr_core__srv__Int64Int64_Response *)allocator.zero_allocate(size, sizeof(qr_core__srv__Int64Int64_Response), allocator.state);
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
qr_core__srv__Int64Int64_Response__Sequence__fini(qr_core__srv__Int64Int64_Response__Sequence * array)
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
      qr_core__srv__Int64Int64_Response__fini(&array->data[i]);
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

qr_core__srv__Int64Int64_Response__Sequence *
qr_core__srv__Int64Int64_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Response__Sequence * array = (qr_core__srv__Int64Int64_Response__Sequence *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qr_core__srv__Int64Int64_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qr_core__srv__Int64Int64_Response__Sequence__destroy(qr_core__srv__Int64Int64_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qr_core__srv__Int64Int64_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qr_core__srv__Int64Int64_Response__Sequence__are_equal(const qr_core__srv__Int64Int64_Response__Sequence * lhs, const qr_core__srv__Int64Int64_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qr_core__srv__Int64Int64_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Response__Sequence__copy(
  const qr_core__srv__Int64Int64_Response__Sequence * input,
  qr_core__srv__Int64Int64_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qr_core__srv__Int64Int64_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qr_core__srv__Int64Int64_Response * data =
      (qr_core__srv__Int64Int64_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qr_core__srv__Int64Int64_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qr_core__srv__Int64Int64_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qr_core__srv__Int64Int64_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "qr_core/srv/detail/int64_int64__functions.h"

bool
qr_core__srv__Int64Int64_Event__init(qr_core__srv__Int64Int64_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    qr_core__srv__Int64Int64_Event__fini(msg);
    return false;
  }
  // request
  if (!qr_core__srv__Int64Int64_Request__Sequence__init(&msg->request, 0)) {
    qr_core__srv__Int64Int64_Event__fini(msg);
    return false;
  }
  // response
  if (!qr_core__srv__Int64Int64_Response__Sequence__init(&msg->response, 0)) {
    qr_core__srv__Int64Int64_Event__fini(msg);
    return false;
  }
  return true;
}

void
qr_core__srv__Int64Int64_Event__fini(qr_core__srv__Int64Int64_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  qr_core__srv__Int64Int64_Request__Sequence__fini(&msg->request);
  // response
  qr_core__srv__Int64Int64_Response__Sequence__fini(&msg->response);
}

bool
qr_core__srv__Int64Int64_Event__are_equal(const qr_core__srv__Int64Int64_Event * lhs, const qr_core__srv__Int64Int64_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!qr_core__srv__Int64Int64_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!qr_core__srv__Int64Int64_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Event__copy(
  const qr_core__srv__Int64Int64_Event * input,
  qr_core__srv__Int64Int64_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!qr_core__srv__Int64Int64_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!qr_core__srv__Int64Int64_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

qr_core__srv__Int64Int64_Event *
qr_core__srv__Int64Int64_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Event * msg = (qr_core__srv__Int64Int64_Event *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qr_core__srv__Int64Int64_Event));
  bool success = qr_core__srv__Int64Int64_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qr_core__srv__Int64Int64_Event__destroy(qr_core__srv__Int64Int64_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qr_core__srv__Int64Int64_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qr_core__srv__Int64Int64_Event__Sequence__init(qr_core__srv__Int64Int64_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Event * data = NULL;

  if (size) {
    data = (qr_core__srv__Int64Int64_Event *)allocator.zero_allocate(size, sizeof(qr_core__srv__Int64Int64_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qr_core__srv__Int64Int64_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qr_core__srv__Int64Int64_Event__fini(&data[i - 1]);
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
qr_core__srv__Int64Int64_Event__Sequence__fini(qr_core__srv__Int64Int64_Event__Sequence * array)
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
      qr_core__srv__Int64Int64_Event__fini(&array->data[i]);
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

qr_core__srv__Int64Int64_Event__Sequence *
qr_core__srv__Int64Int64_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qr_core__srv__Int64Int64_Event__Sequence * array = (qr_core__srv__Int64Int64_Event__Sequence *)allocator.allocate(sizeof(qr_core__srv__Int64Int64_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qr_core__srv__Int64Int64_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qr_core__srv__Int64Int64_Event__Sequence__destroy(qr_core__srv__Int64Int64_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qr_core__srv__Int64Int64_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qr_core__srv__Int64Int64_Event__Sequence__are_equal(const qr_core__srv__Int64Int64_Event__Sequence * lhs, const qr_core__srv__Int64Int64_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qr_core__srv__Int64Int64_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qr_core__srv__Int64Int64_Event__Sequence__copy(
  const qr_core__srv__Int64Int64_Event__Sequence * input,
  qr_core__srv__Int64Int64_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qr_core__srv__Int64Int64_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qr_core__srv__Int64Int64_Event * data =
      (qr_core__srv__Int64Int64_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qr_core__srv__Int64Int64_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qr_core__srv__Int64Int64_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qr_core__srv__Int64Int64_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
