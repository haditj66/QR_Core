// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qr_core:srv/VoidInt64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__VOID_INT64__TRAITS_HPP_
#define QR_CORE__SRV__DETAIL__VOID_INT64__TRAITS_HPP_

#include "qr_core/srv/detail/void_int64__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qr_core::srv::VoidInt64_Request>()
{
  return "qr_core::srv::VoidInt64_Request";
}

template<>
inline const char * name<qr_core::srv::VoidInt64_Request>()
{
  return "qr_core/srv/VoidInt64_Request";
}

template<>
struct has_fixed_size<qr_core::srv::VoidInt64_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qr_core::srv::VoidInt64_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qr_core::srv::VoidInt64_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qr_core::srv::VoidInt64_Response>()
{
  return "qr_core::srv::VoidInt64_Response";
}

template<>
inline const char * name<qr_core::srv::VoidInt64_Response>()
{
  return "qr_core/srv/VoidInt64_Response";
}

template<>
struct has_fixed_size<qr_core::srv::VoidInt64_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qr_core::srv::VoidInt64_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qr_core::srv::VoidInt64_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qr_core::srv::VoidInt64>()
{
  return "qr_core::srv::VoidInt64";
}

template<>
inline const char * name<qr_core::srv::VoidInt64>()
{
  return "qr_core/srv/VoidInt64";
}

template<>
struct has_fixed_size<qr_core::srv::VoidInt64>
  : std::integral_constant<
    bool,
    has_fixed_size<qr_core::srv::VoidInt64_Request>::value &&
    has_fixed_size<qr_core::srv::VoidInt64_Response>::value
  >
{
};

template<>
struct has_bounded_size<qr_core::srv::VoidInt64>
  : std::integral_constant<
    bool,
    has_bounded_size<qr_core::srv::VoidInt64_Request>::value &&
    has_bounded_size<qr_core::srv::VoidInt64_Response>::value
  >
{
};

template<>
struct is_service<qr_core::srv::VoidInt64>
  : std::true_type
{
};

template<>
struct is_service_request<qr_core::srv::VoidInt64_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qr_core::srv::VoidInt64_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QR_CORE__SRV__DETAIL__VOID_INT64__TRAITS_HPP_
