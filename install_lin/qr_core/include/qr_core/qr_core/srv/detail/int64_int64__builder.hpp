// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/int64_int64.hpp"


#ifndef QR_CORE__SRV__DETAIL__INT64_INT64__BUILDER_HPP_
#define QR_CORE__SRV__DETAIL__INT64_INT64__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qr_core/srv/detail/int64_int64__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_Int64Int64_Request_arg1
{
public:
  Init_Int64Int64_Request_arg1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qr_core::srv::Int64Int64_Request arg1(::qr_core::srv::Int64Int64_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::Int64Int64_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::Int64Int64_Request>()
{
  return qr_core::srv::builder::Init_Int64Int64_Request_arg1();
}

}  // namespace qr_core


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_Int64Int64_Response_result
{
public:
  Init_Int64Int64_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qr_core::srv::Int64Int64_Response result(::qr_core::srv::Int64Int64_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::Int64Int64_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::Int64Int64_Response>()
{
  return qr_core::srv::builder::Init_Int64Int64_Response_result();
}

}  // namespace qr_core


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_Int64Int64_Event_response
{
public:
  explicit Init_Int64Int64_Event_response(::qr_core::srv::Int64Int64_Event & msg)
  : msg_(msg)
  {}
  ::qr_core::srv::Int64Int64_Event response(::qr_core::srv::Int64Int64_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::Int64Int64_Event msg_;
};

class Init_Int64Int64_Event_request
{
public:
  explicit Init_Int64Int64_Event_request(::qr_core::srv::Int64Int64_Event & msg)
  : msg_(msg)
  {}
  Init_Int64Int64_Event_response request(::qr_core::srv::Int64Int64_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Int64Int64_Event_response(msg_);
  }

private:
  ::qr_core::srv::Int64Int64_Event msg_;
};

class Init_Int64Int64_Event_info
{
public:
  Init_Int64Int64_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Int64Int64_Event_request info(::qr_core::srv::Int64Int64_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Int64Int64_Event_request(msg_);
  }

private:
  ::qr_core::srv::Int64Int64_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::Int64Int64_Event>()
{
  return qr_core::srv::builder::Init_Int64Int64_Event_info();
}

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__INT64_INT64__BUILDER_HPP_
