// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:msg/Test.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__TEST__TRAITS_HPP_
#define QR_CORE__MSG__DETAIL__TEST__TRAITS_HPP_

#include "qr_core/msg/detail/test__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

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
