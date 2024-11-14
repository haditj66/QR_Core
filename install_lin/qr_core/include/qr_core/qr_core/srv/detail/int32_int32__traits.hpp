// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:srv/Int32Int32.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/int32_int32.hpp"


#ifndef QR_CORE__SRV__DETAIL__INT32_INT32__TRAITS_HPP_
#define QR_CORE__SRV__DETAIL__INT32_INT32__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qr_core/srv/detail/int32_int32__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qr_core
{

namespace srv
{

inline void to_flow_style_yaml(
  const Int32Int32_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: arg1
  {
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Int32Int32_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arg1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arg1: ";
    rosidl_generator_traits::value_to_yaml(msg.arg1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Int32Int32_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qr_core

namespace rosidl_generator_traits
{

[[deprecated("use qr_core::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qr_core::srv::Int32Int32_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  qr_core::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qr_core::srv::to_yaml() instead")]]
inline std::string to_yaml(const qr_core::srv::Int32Int32_Request & msg)
{
  return qr_core::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qr_core::srv::Int32Int32_Request>()
{
  return "qr_core::srv::Int32Int32_Request";
}

template<>
inline const char * name<qr_core::srv::Int32Int32_Request>()
{
  return "qr_core/srv/Int32Int32_Request";
}

template<>
struct has_fixed_size<qr_core::srv::Int32Int32_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qr_core::srv::Int32Int32_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qr_core::srv::Int32Int32_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace qr_core
{

namespace srv
{

inline void to_flow_style_yaml(
  const Int32Int32_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Int32Int32_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Int32Int32_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qr_core

namespace rosidl_generator_traits
{

[[deprecated("use qr_core::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qr_core::srv::Int32Int32_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  qr_core::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qr_core::srv::to_yaml() instead")]]
inline std::string to_yaml(const qr_core::srv::Int32Int32_Response & msg)
{
  return qr_core::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qr_core::srv::Int32Int32_Response>()
{
  return "qr_core::srv::Int32Int32_Response";
}

template<>
inline const char * name<qr_core::srv::Int32Int32_Response>()
{
  return "qr_core/srv/Int32Int32_Response";
}

template<>
struct has_fixed_size<qr_core::srv::Int32Int32_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qr_core::srv::Int32Int32_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qr_core::srv::Int32Int32_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace qr_core
{

namespace srv
{

inline void to_flow_style_yaml(
  const Int32Int32_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Int32Int32_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Int32Int32_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qr_core

namespace rosidl_generator_traits
{

[[deprecated("use qr_core::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qr_core::srv::Int32Int32_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  qr_core::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qr_core::srv::to_yaml() instead")]]
inline std::string to_yaml(const qr_core::srv::Int32Int32_Event & msg)
{
  return qr_core::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qr_core::srv::Int32Int32_Event>()
{
  return "qr_core::srv::Int32Int32_Event";
}

template<>
inline const char * name<qr_core::srv::Int32Int32_Event>()
{
  return "qr_core/srv/Int32Int32_Event";
}

template<>
struct has_fixed_size<qr_core::srv::Int32Int32_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qr_core::srv::Int32Int32_Event>
  : std::integral_constant<bool, has_bounded_size<qr_core::srv::Int32Int32_Request>::value && has_bounded_size<qr_core::srv::Int32Int32_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<qr_core::srv::Int32Int32_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qr_core::srv::Int32Int32>()
{
  return "qr_core::srv::Int32Int32";
}

template<>
inline const char * name<qr_core::srv::Int32Int32>()
{
  return "qr_core/srv/Int32Int32";
}

template<>
struct has_fixed_size<qr_core::srv::Int32Int32>
  : std::integral_constant<
    bool,
    has_fixed_size<qr_core::srv::Int32Int32_Request>::value &&
    has_fixed_size<qr_core::srv::Int32Int32_Response>::value
  >
{
};

template<>
struct has_bounded_size<qr_core::srv::Int32Int32>
  : std::integral_constant<
    bool,
    has_bounded_size<qr_core::srv::Int32Int32_Request>::value &&
    has_bounded_size<qr_core::srv::Int32Int32_Response>::value
  >
{
};

template<>
struct is_service<qr_core::srv::Int32Int32>
  : std::true_type
{
};

template<>
struct is_service_request<qr_core::srv::Int32Int32_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qr_core::srv::Int32Int32_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QR_CORE__SRV__DETAIL__INT32_INT32__TRAITS_HPP_
