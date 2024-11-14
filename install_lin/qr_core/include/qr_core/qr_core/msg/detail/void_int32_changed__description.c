// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qr_core:msg/VoidInt32Changed.idl
// generated code does not contain a copyright notice

#include "qr_core/msg/detail/void_int32_changed__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__msg__VoidInt32Changed__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0f, 0x38, 0x31, 0xed, 0xff, 0xd4, 0x59, 0x62,
      0xa0, 0xb0, 0xe9, 0x65, 0x46, 0xcf, 0xea, 0xa4,
      0x90, 0x36, 0xc0, 0xf9, 0x0c, 0x5b, 0xd6, 0xcf,
      0x13, 0x54, 0xe8, 0x5b, 0x4a, 0xff, 0x7b, 0xa9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char qr_core__msg__VoidInt32Changed__TYPE_NAME[] = "qr_core/msg/VoidInt32Changed";

// Define type names, field names, and default values
static char qr_core__msg__VoidInt32Changed__FIELD_NAME__id[] = "id";
static char qr_core__msg__VoidInt32Changed__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field qr_core__msg__VoidInt32Changed__FIELDS[] = {
  {
    {qr_core__msg__VoidInt32Changed__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__msg__VoidInt32Changed__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__msg__VoidInt32Changed__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__msg__VoidInt32Changed__TYPE_NAME, 28, 28},
      {qr_core__msg__VoidInt32Changed__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint32 id\n"
  "int32 data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qr_core__msg__VoidInt32Changed__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__msg__VoidInt32Changed__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 21, 21},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__msg__VoidInt32Changed__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__msg__VoidInt32Changed__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
