// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:srv/VoidInt64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__VOID_INT64__BUILDER_HPP_
#define QR_CORE__SRV__DETAIL__VOID_INT64__BUILDER_HPP_

#include "qr_core/srv/detail/void_int64__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_VoidInt64_Request_arg1
{
public:
  explicit Init_VoidInt64_Request_arg1(::qr_core::srv::VoidInt64_Request & msg)
  : msg_(msg)
  {}
  ::qr_core::srv::VoidInt64_Request arg1(::qr_core::srv::VoidInt64_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::VoidInt64_Request msg_;
};

class Init_VoidInt64_Request_id
{
public:
  Init_VoidInt64_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VoidInt64_Request_arg1 id(::qr_core::srv::VoidInt64_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_VoidInt64_Request_arg1(msg_);
  }

private:
  ::qr_core::srv::VoidInt64_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::VoidInt64_Request>()
{
  return qr_core::srv::builder::Init_VoidInt64_Request_id();
}

}  // namespace qr_core


namespace qr_core
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::VoidInt64_Response>()
{
  return ::qr_core::srv::VoidInt64_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__VOID_INT64__BUILDER_HPP_
