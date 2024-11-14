// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qr_core:srv/Int32Int32.idl
// generated code does not contain a copyright notice

#include "qr_core/srv/detail/int32_int32__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__Int32Int32__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x00, 0x61, 0x6c, 0x04, 0x4a, 0x33, 0xe5, 0xe6,
      0x12, 0xf7, 0xcd, 0x43, 0x56, 0x6b, 0x3c, 0xf3,
      0x6a, 0x0e, 0x5f, 0x59, 0xd4, 0x2c, 0x2f, 0xed,
      0xe4, 0x06, 0xdc, 0xda, 0xc3, 0x22, 0xae, 0x64,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__Int32Int32_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x0b, 0x48, 0x41, 0xf8, 0x96, 0xf2, 0xe6,
      0x81, 0xbb, 0xa2, 0x10, 0x26, 0x35, 0x8c, 0xf8,
      0x51, 0x10, 0xf2, 0x51, 0x8c, 0x7a, 0x82, 0x4c,
      0x6c, 0xa4, 0x51, 0x15, 0x47, 0xe5, 0x37, 0x2f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__Int32Int32_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x40, 0xe3, 0xd6, 0xa0, 0x59, 0x27, 0xf9, 0x59,
      0x0e, 0x1c, 0x0c, 0x6f, 0x5c, 0xca, 0xa6, 0x3c,
      0x6e, 0x16, 0xe4, 0x74, 0x7b, 0x6f, 0xf1, 0x78,
      0x4d, 0x1e, 0xcb, 0x42, 0x44, 0x7d, 0x56, 0xe8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__Int32Int32_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd0, 0xe9, 0x5b, 0x96, 0x50, 0x70, 0x0c, 0xf1,
      0x51, 0x40, 0xb7, 0x21, 0x52, 0xbd, 0x93, 0xb2,
      0x19, 0xa8, 0x32, 0x3f, 0x0c, 0xae, 0x64, 0x11,
      0x61, 0x7a, 0x94, 0x92, 0xc6, 0xa1, 0x65, 0x63,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char qr_core__srv__Int32Int32__TYPE_NAME[] = "qr_core/srv/Int32Int32";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char qr_core__srv__Int32Int32_Event__TYPE_NAME[] = "qr_core/srv/Int32Int32_Event";
static char qr_core__srv__Int32Int32_Request__TYPE_NAME[] = "qr_core/srv/Int32Int32_Request";
static char qr_core__srv__Int32Int32_Response__TYPE_NAME[] = "qr_core/srv/Int32Int32_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char qr_core__srv__Int32Int32__FIELD_NAME__request_message[] = "request_message";
static char qr_core__srv__Int32Int32__FIELD_NAME__response_message[] = "response_message";
static char qr_core__srv__Int32Int32__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field qr_core__srv__Int32Int32__FIELDS[] = {
  {
    {qr_core__srv__Int32Int32__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__Int32Int32_Event__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qr_core__srv__Int32Int32__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Event__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__Int32Int32__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__Int32Int32__TYPE_NAME, 22, 22},
      {qr_core__srv__Int32Int32__FIELDS, 3, 3},
    },
    {qr_core__srv__Int32Int32__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qr_core__srv__Int32Int32_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qr_core__srv__Int32Int32_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = qr_core__srv__Int32Int32_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__Int32Int32_Request__FIELD_NAME__arg1[] = "arg1";

static rosidl_runtime_c__type_description__Field qr_core__srv__Int32Int32_Request__FIELDS[] = {
  {
    {qr_core__srv__Int32Int32_Request__FIELD_NAME__arg1, 4, 4},
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
qr_core__srv__Int32Int32_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
      {qr_core__srv__Int32Int32_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__Int32Int32_Response__FIELD_NAME__result[] = "result";

static rosidl_runtime_c__type_description__Field qr_core__srv__Int32Int32_Response__FIELDS[] = {
  {
    {qr_core__srv__Int32Int32_Response__FIELD_NAME__result, 6, 6},
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
qr_core__srv__Int32Int32_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
      {qr_core__srv__Int32Int32_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__Int32Int32_Event__FIELD_NAME__info[] = "info";
static char qr_core__srv__Int32Int32_Event__FIELD_NAME__request[] = "request";
static char qr_core__srv__Int32Int32_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field qr_core__srv__Int32Int32_Event__FIELDS[] = {
  {
    {qr_core__srv__Int32Int32_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qr_core__srv__Int32Int32_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__Int32Int32_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__Int32Int32_Event__TYPE_NAME, 28, 28},
      {qr_core__srv__Int32Int32_Event__FIELDS, 3, 3},
    },
    {qr_core__srv__Int32Int32_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qr_core__srv__Int32Int32_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qr_core__srv__Int32Int32_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 arg1\n"
  "---\n"
  "int32 result\n"
  "";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__Int32Int32__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__Int32Int32__TYPE_NAME, 22, 22},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__Int32Int32_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__Int32Int32_Request__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__Int32Int32_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__Int32Int32_Response__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__Int32Int32_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__Int32Int32_Event__TYPE_NAME, 28, 28},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__Int32Int32__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__Int32Int32__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qr_core__srv__Int32Int32_Event__get_individual_type_description_source(NULL);
    sources[3] = *qr_core__srv__Int32Int32_Request__get_individual_type_description_source(NULL);
    sources[4] = *qr_core__srv__Int32Int32_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__Int32Int32_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__Int32Int32_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__Int32Int32_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__Int32Int32_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__Int32Int32_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__Int32Int32_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qr_core__srv__Int32Int32_Request__get_individual_type_description_source(NULL);
    sources[3] = *qr_core__srv__Int32Int32_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
