// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__TRAITS_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__TRAITS_HPP_

#include "qr_core/msg/detail/void_int64_changed__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

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
