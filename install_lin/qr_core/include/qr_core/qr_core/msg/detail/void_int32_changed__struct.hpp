// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qr_core:msg/VoidInt32Changed.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/void_int32_changed.hpp"


#ifndef QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_HPP_
#define QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qr_core__msg__VoidInt32Changed __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__msg__VoidInt32Changed __declspec(deprecated)
#endif

namespace qr_core
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VoidInt32Changed_
{
  using Type = VoidInt32Changed_<ContainerAllocator>;

  explicit VoidInt32Changed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id1 = 0ll;
      this->id2 = 0ll;
      this->data = 0l;
    }
  }

  explicit VoidInt32Changed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id1 = 0ll;
      this->id2 = 0ll;
      this->data = 0l;
    }
  }

  // field types and members
  using _id1_type =
    int64_t;
  _id1_type id1;
  using _id2_type =
    int64_t;
  _id2_type id2;
  using _data_type =
    int32_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__id1(
    const int64_t & _arg)
  {
    this->id1 = _arg;
    return *this;
  }
  Type & set__id2(
    const int64_t & _arg)
  {
    this->id2 = _arg;
    return *this;
  }
  Type & set__data(
    const int32_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::msg::VoidInt32Changed_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::msg::VoidInt32Changed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::msg::VoidInt32Changed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::msg::VoidInt32Changed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__msg__VoidInt32Changed
    std::shared_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__msg__VoidInt32Changed
    std::shared_ptr<qr_core::msg::VoidInt32Changed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VoidInt32Changed_ & other) const
  {
    if (this->id1 != other.id1) {
      return false;
    }
    if (this->id2 != other.id2) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const VoidInt32Changed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VoidInt32Changed_

// alias to use template instance with default allocator
using VoidInt32Changed =
  qr_core::msg::VoidInt32Changed_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qr_core

#endif  // QR_CORE__MSG__DETAIL__VOID_INT32_CHANGED__STRUCT_HPP_
