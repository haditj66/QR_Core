// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qr_core:srv/VoidInt64.idl
// generated code does not contain a copyright notice

#include "qr_core/srv/detail/void_int64__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__VoidInt64__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x19, 0x0c, 0x20, 0xfd, 0x53, 0xc0, 0x23, 0x1c,
      0xa5, 0x2e, 0x85, 0xea, 0xfd, 0x21, 0x81, 0x0f,
      0x3c, 0x66, 0xe6, 0x13, 0xb9, 0xa7, 0xc6, 0x5c,
      0xb0, 0x19, 0x71, 0xa4, 0x2c, 0xca, 0x08, 0x16,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__VoidInt64_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc0, 0xa3, 0x21, 0xd4, 0x23, 0xad, 0xb3, 0x09,
      0xbf, 0x12, 0x2d, 0xfc, 0x2e, 0x37, 0x88, 0xae,
      0xfb, 0xd5, 0xba, 0xe8, 0xd5, 0x39, 0x52, 0xd4,
      0x54, 0xca, 0x8f, 0xff, 0x9a, 0xa8, 0xde, 0xc0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__VoidInt64_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe9, 0xeb, 0x1a, 0x53, 0x3d, 0x2d, 0xa6, 0xd6,
      0x28, 0xc0, 0xa9, 0xba, 0x2f, 0xfc, 0x96, 0xec,
      0xe5, 0x6a, 0x04, 0xf9, 0xce, 0x97, 0x5e, 0xed,
      0xbc, 0x00, 0x0a, 0xba, 0xce, 0xf3, 0x7d, 0x2b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qr_core
const rosidl_type_hash_t *
qr_core__srv__VoidInt64_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x70, 0x66, 0x44, 0x91, 0x00, 0x93, 0x49, 0xed,
      0xd0, 0xd0, 0xc7, 0x02, 0x03, 0x64, 0xb0, 0xef,
      0xbd, 0x19, 0x94, 0x4d, 0x5f, 0xd0, 0x3a, 0x9c,
      0xe0, 0xe5, 0x41, 0xee, 0x95, 0xbb, 0x52, 0x51,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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

static char qr_core__srv__VoidInt64__TYPE_NAME[] = "qr_core/srv/VoidInt64";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char qr_core__srv__VoidInt64_Event__TYPE_NAME[] = "qr_core/srv/VoidInt64_Event";
static char qr_core__srv__VoidInt64_Request__TYPE_NAME[] = "qr_core/srv/VoidInt64_Request";
static char qr_core__srv__VoidInt64_Response__TYPE_NAME[] = "qr_core/srv/VoidInt64_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char qr_core__srv__VoidInt64__FIELD_NAME__request_message[] = "request_message";
static char qr_core__srv__VoidInt64__FIELD_NAME__response_message[] = "response_message";
static char qr_core__srv__VoidInt64__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field qr_core__srv__VoidInt64__FIELDS[] = {
  {
    {qr_core__srv__VoidInt64__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qr_core__srv__VoidInt64_Event__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qr_core__srv__VoidInt64__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Event__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__VoidInt64__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__VoidInt64__TYPE_NAME, 21, 21},
      {qr_core__srv__VoidInt64__FIELDS, 3, 3},
    },
    {qr_core__srv__VoidInt64__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qr_core__srv__VoidInt64_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qr_core__srv__VoidInt64_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = qr_core__srv__VoidInt64_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__VoidInt64_Request__FIELD_NAME__id[] = "id";
static char qr_core__srv__VoidInt64_Request__FIELD_NAME__arg1[] = "arg1";

static rosidl_runtime_c__type_description__Field qr_core__srv__VoidInt64_Request__FIELDS[] = {
  {
    {qr_core__srv__VoidInt64_Request__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Request__FIELD_NAME__arg1, 4, 4},
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
qr_core__srv__VoidInt64_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
      {qr_core__srv__VoidInt64_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__VoidInt64_Response__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field qr_core__srv__VoidInt64_Response__FIELDS[] = {
  {
    {qr_core__srv__VoidInt64_Response__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__VoidInt64_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
      {qr_core__srv__VoidInt64_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qr_core__srv__VoidInt64_Event__FIELD_NAME__info[] = "info";
static char qr_core__srv__VoidInt64_Event__FIELD_NAME__request[] = "request";
static char qr_core__srv__VoidInt64_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field qr_core__srv__VoidInt64_Event__FIELDS[] = {
  {
    {qr_core__srv__VoidInt64_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qr_core__srv__VoidInt64_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qr_core__srv__VoidInt64_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qr_core__srv__VoidInt64_Event__TYPE_NAME, 27, 27},
      {qr_core__srv__VoidInt64_Event__FIELDS, 3, 3},
    },
    {qr_core__srv__VoidInt64_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qr_core__srv__VoidInt64_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qr_core__srv__VoidInt64_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 id\n"
  "int64 arg1\n"
  "---\n"
  "";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__VoidInt64__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__VoidInt64__TYPE_NAME, 21, 21},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 26, 26},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__VoidInt64_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__VoidInt64_Request__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__VoidInt64_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__VoidInt64_Response__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qr_core__srv__VoidInt64_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qr_core__srv__VoidInt64_Event__TYPE_NAME, 27, 27},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__VoidInt64__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__VoidInt64__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qr_core__srv__VoidInt64_Event__get_individual_type_description_source(NULL);
    sources[3] = *qr_core__srv__VoidInt64_Request__get_individual_type_description_source(NULL);
    sources[4] = *qr_core__srv__VoidInt64_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__VoidInt64_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__VoidInt64_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__VoidInt64_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__VoidInt64_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qr_core__srv__VoidInt64_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qr_core__srv__VoidInt64_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qr_core__srv__VoidInt64_Request__get_individual_type_description_source(NULL);
    sources[3] = *qr_core__srv__VoidInt64_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
