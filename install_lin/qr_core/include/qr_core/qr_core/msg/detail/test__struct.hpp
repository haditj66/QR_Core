// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qr_core:msg/Test.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/msg/test.hpp"


#ifndef QR_CORE__MSG__DETAIL__TEST__STRUCT_HPP_
#define QR_CORE__MSG__DETAIL__TEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qr_core__msg__Test __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__msg__Test __declspec(deprecated)
#endif

namespace qr_core
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Test_
{
  using Type = Test_<ContainerAllocator>;

  explicit Test_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blablas = "";
    }
  }

  explicit Test_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : blablas(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blablas = "";
    }
  }

  // field types and members
  using _blablas_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _blablas_type blablas;

  // setters for named parameter idiom
  Type & set__blablas(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->blablas = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::msg::Test_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::msg::Test_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::msg::Test_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::msg::Test_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::msg::Test_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::msg::Test_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::msg::Test_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::msg::Test_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::msg::Test_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::msg::Test_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__msg__Test
    std::shared_ptr<qr_core::msg::Test_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__msg__Test
    std::shared_ptr<qr_core::msg::Test_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Test_ & other) const
  {
    if (this->blablas != other.blablas) {
      return false;
    }
    return true;
  }
  bool operator!=(const Test_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Test_

// alias to use template instance with default allocator
using Test =
  qr_core::msg::Test_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qr_core

#endif  // QR_CORE__MSG__DETAIL__TEST__STRUCT_HPP_
