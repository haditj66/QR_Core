// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qr_core:srv/VoidInt64.idl
// generated code does not contain a copyright notice

#ifndef QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_HPP_
#define QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__VoidInt64_Request __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__VoidInt64_Request __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VoidInt64_Request_
{
  using Type = VoidInt64_Request_<ContainerAllocator>;

  explicit VoidInt64_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ull;
      this->arg1 = 0ll;
    }
  }

  explicit VoidInt64_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ull;
      this->arg1 = 0ll;
    }
  }

  // field types and members
  using _id_type =
    uint64_t;
  _id_type id;
  using _arg1_type =
    int64_t;
  _arg1_type arg1;

  // setters for named parameter idiom
  Type & set__id(
    const uint64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__arg1(
    const int64_t & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::VoidInt64_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::VoidInt64_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::VoidInt64_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::VoidInt64_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__VoidInt64_Request
    std::shared_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__VoidInt64_Request
    std::shared_ptr<qr_core::srv::VoidInt64_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VoidInt64_Request_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->arg1 != other.arg1) {
      return false;
    }
    return true;
  }
  bool operator!=(const VoidInt64_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VoidInt64_Request_

// alias to use template instance with default allocator
using VoidInt64_Request =
  qr_core::srv::VoidInt64_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__VoidInt64_Response __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__VoidInt64_Response __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VoidInt64_Response_
{
  using Type = VoidInt64_Response_<ContainerAllocator>;

  explicit VoidInt64_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit VoidInt64_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::VoidInt64_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::VoidInt64_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::VoidInt64_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::VoidInt64_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__VoidInt64_Response
    std::shared_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__VoidInt64_Response
    std::shared_ptr<qr_core::srv::VoidInt64_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VoidInt64_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const VoidInt64_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VoidInt64_Response_

// alias to use template instance with default allocator
using VoidInt64_Response =
  qr_core::srv::VoidInt64_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core

namespace qr_core
{

namespace srv
{

struct VoidInt64
{
  using Request = qr_core::srv::VoidInt64_Request;
  using Response = qr_core::srv::VoidInt64_Response;
};

}  // namespace srv

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__VOID_INT64__STRUCT_HPP_
