// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:msg\Test.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__MSG__DETAIL__TEST__BUILDER_HPP_
#define QR_CORE__MSG__DETAIL__TEST__BUILDER_HPP_

#include "qr_core/msg/detail/test__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace qr_core
{

namespace msg
{

namespace builder
{

class Init_Test_blablas
{
public:
  Init_Test_blablas()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qr_core::msg::Test blablas(::qr_core::msg::Test::_blablas_type arg)
  {
    msg_.blablas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::msg::Test msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::msg::Test>()
{
  return qr_core::msg::builder::Init_Test_blablas();
}

}  // namespace qr_core

#endif  // QR_CORE__MSG__DETAIL__TEST__BUILDER_HPP_
