// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#include "qr_core/msg/detail/void_int64_changed__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__msg__VoidInt64Changed__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x61, 0x97, 0x13, 0x36, 0x7c, 0x20, 0x63, 0x18,
      0x3f, 0xab, 0x73, 0x42, 0x5b, 0x7e, 0x8a, 0x98,
      0xa4, 0xf3, 0x18, 0x1d, 0x1b, 0xc4, 0x22, 0xb2,
      0x1b, 0x07, 0x88, 0x80, 0x82, 0x6e, 0x55, 0x83,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char qr_core__msg__VoidInt64Changed__TYPE_NAME[] = "qr_core/msg/VoidInt64Changed";

// Define type names, field names, and default values
static char qr_core__msg__VoidInt64Changed__FIELD_NAME__id[] = "id";
static char qr_core__msg__VoidInt64Changed__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field qr_core__msg__VoidInt64Changed__FIELDS[] = {
  {
    {qr_core__msg__VoidInt64Changed__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__msg__VoidInt64Changed__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__msg__VoidInt64Changed__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__msg__VoidInt64Changed__TYPE_NAME, 28, 28},
      {qr_core__msg__VoidInt64Changed__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 id\n"
  "int64 data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qr_core__msg__VoidInt64Changed__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__msg__VoidInt64Changed__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 21, 21},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__msg__VoidInt64Changed__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__msg__VoidInt64Changed__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
