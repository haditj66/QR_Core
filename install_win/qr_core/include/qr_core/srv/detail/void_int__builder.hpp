// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:srv\VoidInt.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__VOID_INT__BUILDER_HPP_
#define QR_CORE__SRV__DETAIL__VOID_INT__BUILDER_HPP_

#include "qr_core/srv/detail/void_int__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_VoidInt_Request_arg1
{
public:
  Init_VoidInt_Request_arg1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qr_core::srv::VoidInt_Request arg1(::qr_core::srv::VoidInt_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::VoidInt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::VoidInt_Request>()
{
  return qr_core::srv::builder::Init_VoidInt_Request_arg1();
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
auto build<::qr_core::srv::VoidInt_Response>()
{
  return ::qr_core::srv::VoidInt_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__VOID_INT__BUILDER_HPP_
