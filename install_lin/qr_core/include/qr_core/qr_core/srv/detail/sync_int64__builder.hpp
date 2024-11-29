// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qr_core:srv/SyncInt64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/sync_int64.hpp"


#ifndef QR_CORE__SRV__DETAIL__SYNC_INT64__BUILDER_HPP_
#define QR_CORE__SRV__DETAIL__SYNC_INT64__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qr_core/srv/detail/sync_int64__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_SyncInt64_Request_arg1
{
public:
  explicit Init_SyncInt64_Request_arg1(::qr_core::srv::SyncInt64_Request & msg)
  : msg_(msg)
  {}
  ::qr_core::srv::SyncInt64_Request arg1(::qr_core::srv::SyncInt64_Request::_arg1_type arg)
  {
    msg_.arg1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Request msg_;
};

class Init_SyncInt64_Request_id2
{
public:
  explicit Init_SyncInt64_Request_id2(::qr_core::srv::SyncInt64_Request & msg)
  : msg_(msg)
  {}
  Init_SyncInt64_Request_arg1 id2(::qr_core::srv::SyncInt64_Request::_id2_type arg)
  {
    msg_.id2 = std::move(arg);
    return Init_SyncInt64_Request_arg1(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Request msg_;
};

class Init_SyncInt64_Request_id1
{
public:
  Init_SyncInt64_Request_id1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SyncInt64_Request_id2 id1(::qr_core::srv::SyncInt64_Request::_id1_type arg)
  {
    msg_.id1 = std::move(arg);
    return Init_SyncInt64_Request_id2(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::SyncInt64_Request>()
{
  return qr_core::srv::builder::Init_SyncInt64_Request_id1();
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
auto build<::qr_core::srv::SyncInt64_Response>()
{
  return ::qr_core::srv::SyncInt64_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace qr_core


namespace qr_core
{

namespace srv
{

namespace builder
{

class Init_SyncInt64_Event_response
{
public:
  explicit Init_SyncInt64_Event_response(::qr_core::srv::SyncInt64_Event & msg)
  : msg_(msg)
  {}
  ::qr_core::srv::SyncInt64_Event response(::qr_core::srv::SyncInt64_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Event msg_;
};

class Init_SyncInt64_Event_request
{
public:
  explicit Init_SyncInt64_Event_request(::qr_core::srv::SyncInt64_Event & msg)
  : msg_(msg)
  {}
  Init_SyncInt64_Event_response request(::qr_core::srv::SyncInt64_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SyncInt64_Event_response(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Event msg_;
};

class Init_SyncInt64_Event_info
{
public:
  Init_SyncInt64_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SyncInt64_Event_request info(::qr_core::srv::SyncInt64_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SyncInt64_Event_request(msg_);
  }

private:
  ::qr_core::srv::SyncInt64_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qr_core::srv::SyncInt64_Event>()
{
  return qr_core::srv::builder::Init_SyncInt64_Event_info();
}

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__SYNC_INT64__BUILDER_HPP_
