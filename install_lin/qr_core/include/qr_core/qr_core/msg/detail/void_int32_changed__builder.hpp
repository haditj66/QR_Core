// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:msg/VoidInt32Changed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/void_int32_changed.hpp"


#ifndef QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__BUILDER_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qr_core/msg/detail/void_int32_changed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qr_core
{

namespace msg
{

namespace builder
{

class Init_VoidInt32Changed_data
{
public:
  explicit Init_VoidInt32Changed_data(::qr_core::msg::VoidInt32Changed & msg)
  : msg_(msg)
  {}
  ::qr_core::msg::VoidInt32Changed data(::qr_core::msg::VoidInt32Changed::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::msg::VoidInt32Changed msg_;
};

class Init_VoidInt32Changed_id2
{
public:
  explicit Init_VoidInt32Changed_id2(::qr_core::msg::VoidInt32Changed & msg)
  : msg_(msg)
  {}
  Init_VoidInt32Changed_data id2(::qr_core::msg::VoidInt32Changed::_id2_type arg)
  {
    msg_.id2 = std::move(arg);
    return Init_VoidInt32Changed_data(msg_);
  }

private:
  ::qr_core::msg::VoidInt32Changed msg_;
};

class Init_VoidInt32Changed_id1
{
public:
  Init_VoidInt32Changed_id1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VoidInt32Changed_id2 id1(::qr_core::msg::VoidInt32Changed::_id1_type arg)
  {
    msg_.id1 = std::move(arg);
    return Init_VoidInt32Changed_id2(msg_);
  }

private:
  ::qr_core::msg::VoidInt32Changed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::msg::VoidInt32Changed>()
{
  return qr_core::msg::builder::Init_VoidInt32Changed_id1();
}

}  // namespace qr_core

#endif  // QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__BUILDER_HPP_
