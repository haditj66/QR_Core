// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:msg/VoidInt64Changed.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__BUILDER_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__BUILDER_HPP_

#include "qr_core/msg/detail/void_int64_changed__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace qr_core
{

namespace msg
{

namespace builder
{

class Init_VoidInt64Changed_data
{
public:
  explicit Init_VoidInt64Changed_data(::qr_core::msg::VoidInt64Changed & msg)
  : msg_(msg)
  {}
  ::qr_core::msg::VoidInt64Changed data(::qr_core::msg::VoidInt64Changed::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::msg::VoidInt64Changed msg_;
};

class Init_VoidInt64Changed_id
{
public:
  Init_VoidInt64Changed_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VoidInt64Changed_data id(::qr_core::msg::VoidInt64Changed::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_VoidInt64Changed_data(msg_);
  }

private:
  ::qr_core::msg::VoidInt64Changed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::msg::VoidInt64Changed>()
{
  return qr_core::msg::builder::Init_VoidInt64Changed_id();
}

}  // namespace qr_core

#endif  // QR_CORE__MSG__DETAIL__VOID_INT64_CHANGED__BUILDER_HPP_
