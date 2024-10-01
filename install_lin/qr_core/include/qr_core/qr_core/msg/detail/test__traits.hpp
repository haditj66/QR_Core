// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:msg/Test.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/test.hpp"


#ifndef QR_CORE__MSG__DETAIL__TEST__TRAITS_HPP_
#define QR_CORE__MSG__DETAIL__TEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qr_core/msg/detail/test__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qr_core
{

namespace msg
{

inline void to_flow_style_yaml(
  const Test & msg,
  std::ostream & out)
{
  out << "{";
  // member: blablas
  {
    out << "blablas: ";
    rosidl_generator_traits::value_to_yaml(msg.blablas, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Test & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: blablas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blablas: ";
    rosidl_generator_traits::value_to_yaml(msg.blablas, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Test & msg, bool use_flow_style = false)
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
  const qr_core::msg::Test & msg,
  std::ostream & out, size_t indentation = 0)
{
  qr_core::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qr_core::msg::to_yaml() instead")]]
inline std::string to_yaml(const qr_core::msg::Test & msg)
{
  return qr_core::msg::to_yaml(msg);
}

template<>
inline const char * data_type<qr_core::msg::Test>()
{
  return "qr_core::msg::Test";
}

template<>
inline const char * name<qr_core::msg::Test>()
{
  return "qr_core/msg/Test";
}

template<>
struct has_fixed_size<qr_core::msg::Test>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qr_core::msg::Test>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qr_core::msg::Test>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QR_CORE__MSG__DETAIL__TEST__TRAITS_HPP_
