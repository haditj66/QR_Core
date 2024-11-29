// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qr_core:srv/SyncInt64.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qr_core/srv/sync_int64.hpp"


#ifndef QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_HPP_
#define QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__SyncInt64_Request __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__SyncInt64_Request __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SyncInt64_Request_
{
  using Type = SyncInt64_Request_<ContainerAllocator>;

  explicit SyncInt64_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id1 = 0ll;
      this->id2 = 0ll;
      this->arg1 = 0ll;
    }
  }

  explicit SyncInt64_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id1 = 0ll;
      this->id2 = 0ll;
      this->arg1 = 0ll;
    }
  }

  // field types and members
  using _id1_type =
    int64_t;
  _id1_type id1;
  using _id2_type =
    int64_t;
  _id2_type id2;
  using _arg1_type =
    int64_t;
  _arg1_type arg1;

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
  Type & set__arg1(
    const int64_t & _arg)
  {
    this->arg1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::SyncInt64_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::SyncInt64_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__SyncInt64_Request
    std::shared_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__SyncInt64_Request
    std::shared_ptr<qr_core::srv::SyncInt64_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SyncInt64_Request_ & other) const
  {
    if (this->id1 != other.id1) {
      return false;
    }
    if (this->id2 != other.id2) {
      return false;
    }
    if (this->arg1 != other.arg1) {
      return false;
    }
    return true;
  }
  bool operator!=(const SyncInt64_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SyncInt64_Request_

// alias to use template instance with default allocator
using SyncInt64_Request =
  qr_core::srv::SyncInt64_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core


#ifndef _WIN32
# define DEPRECATED__qr_core__srv__SyncInt64_Response __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__SyncInt64_Response __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SyncInt64_Response_
{
  using Type = SyncInt64_Response_<ContainerAllocator>;

  explicit SyncInt64_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SyncInt64_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    qr_core::srv::SyncInt64_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::SyncInt64_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__SyncInt64_Response
    std::shared_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__SyncInt64_Response
    std::shared_ptr<qr_core::srv::SyncInt64_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SyncInt64_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SyncInt64_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SyncInt64_Response_

// alias to use template instance with default allocator
using SyncInt64_Response =
  qr_core::srv::SyncInt64_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__qr_core__srv__SyncInt64_Event __attribute__((deprecated))
#else
# define DEPRECATED__qr_core__srv__SyncInt64_Event __declspec(deprecated)
#endif

namespace qr_core
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SyncInt64_Event_
{
  using Type = SyncInt64_Event_<ContainerAllocator>;

  explicit SyncInt64_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SyncInt64_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<qr_core::srv::SyncInt64_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qr_core::srv::SyncInt64_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<qr_core::srv::SyncInt64_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qr_core::srv::SyncInt64_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<qr_core::srv::SyncInt64_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qr_core::srv::SyncInt64_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<qr_core::srv::SyncInt64_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qr_core::srv::SyncInt64_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qr_core::srv::SyncInt64_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const qr_core::srv::SyncInt64_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qr_core::srv::SyncInt64_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qr_core__srv__SyncInt64_Event
    std::shared_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qr_core__srv__SyncInt64_Event
    std::shared_ptr<qr_core::srv::SyncInt64_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SyncInt64_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SyncInt64_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SyncInt64_Event_

// alias to use template instance with default allocator
using SyncInt64_Event =
  qr_core::srv::SyncInt64_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qr_core

namespace qr_core
{

namespace srv
{

struct SyncInt64
{
  using Request = qr_core::srv::SyncInt64_Request;
  using Response = qr_core::srv::SyncInt64_Response;
  using Event = qr_core::srv::SyncInt64_Event;
};

}  // namespace srv

}  // namespace qr_core

#endif  // QR_CORE__SRV__DETAIL__SYNC_INT64__STRUCT_HPP_
