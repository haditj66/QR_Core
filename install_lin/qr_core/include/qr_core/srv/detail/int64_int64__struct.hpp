// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qr_core:srv/Int64Int64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_HPP_
#define QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__Int64Int64_Request __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__Int64Int64_Request __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Int64Int64_Request_
{
  using Type = Int64Int64_Request_<ContainerAllocator>;

  explicit Int64Int64_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arg1 = 0ll;
    }
  }

  explicit Int64Int64_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arg1 = 0ll;
    }
  }

  // field types and members
  using _arg1_type =
    int64_t;
  _arg1_type arg1;

  // setters for named parameter idiom
  Type & set__arg1(
    const int64_t & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::Int64Int64_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::Int64Int64_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::Int64Int64_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::Int64Int64_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__Int64Int64_Request
    std::shared_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__Int64Int64_Request
    std::shared_ptr<qr_core::srv::Int64Int64_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Int64Int64_Request_ & other) const
  {
    if (this->arg1 != other.arg1) {
      return false;
    }
    return true;
  }
  bool operator!=(const Int64Int64_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Int64Int64_Request_

// alias to use template instance with default allocator
using Int64Int64_Request =
  qr_core::srv::Int64Int64_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__Int64Int64_Response __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__Int64Int64_Response __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Int64Int64_Response_
{
  using Type = Int64Int64_Response_<ContainerAllocator>;

  explicit Int64Int64_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0ll;
    }
  }

  explicit Int64Int64_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0ll;
    }
  }

  // field types and members
  using _result_type =
    int64_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const int64_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::Int64Int64_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::Int64Int64_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::Int64Int64_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::Int64Int64_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__Int64Int64_Response
    std::shared_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__Int64Int64_Response
    std::shared_ptr<qr_core::srv::Int64Int64_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Int64Int64_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Int64Int64_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Int64Int64_Response_

// alias to use template instance with default allocator
using Int64Int64_Response =
  qr_core::srv::Int64Int64_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core

namespace qr_core
{

namespace srv
{

struct Int64Int64
{
  using Request = qr_core::srv::Int64Int64_Request;
  using Response = qr_core::srv::Int64Int64_Response;
};

}  // namespace srv

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__INT64_INT64__STRUCT_HPP_
