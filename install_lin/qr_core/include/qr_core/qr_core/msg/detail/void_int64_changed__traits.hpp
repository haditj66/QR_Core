// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/void_int64_changed.hpp"


#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__TRAITS_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qr_core/msg/detail/void_int64_changed__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qr_core
{

namespace msg
{

inline void to_flow_style_yaml(
  const VoidInt64Changed & msg,
  std::ostream & out)
{
  out << "{";
  // member: id1
  {
    out << "id1: ";
    rosidl_generator_traits::value_to_yaml(msg.id1, out);
    out << ", ";
  }

  // member: id2
  {
    out << "id2: ";
    rosidl_generator_traits::value_to_yaml(msg.id2, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VoidInt64Changed & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id1: ";
    rosidl_generator_traits::value_to_yaml(msg.id1, out);
    out << "\n";
  }

  // member: id2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id2: ";
    rosidl_generator_traits::value_to_yaml(msg.id2, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VoidInt64Changed & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace qr_core

namespace rosidl_generator_traits
{

[[deprecated("use qr_core::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qr_core::msg::VoidInt64Changed & msg,
  std::ostream & out, size_t indentation = 0)
{
  qr_core::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qr_core::msg::to_yaml() instead")]]
inline std::string to_yaml(const qr_core::msg::VoidInt64Changed & msg)
{
  return qr_core::msg::to_yaml(msg);
}

template<>
inline const char * data_type<qr_core::msg::VoidInt64Changed>()
{
  return "qr_core::msg::VoidInt64Changed";
}

template<>
inline const char * name<qr_core::msg::VoidInt64Changed>()
{
  return "qr_core/msg/VoidInt64Changed";
}

template<>
struct has_fixed_size<qr_core::msg::VoidInt64Changed>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qr_core::msg::VoidInt64Changed>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qr_core::msg::VoidInt64Changed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__TRAITS_HPP_
