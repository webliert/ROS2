// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from base_interface_demo:msg/Student.idl
// generated code does not contain a copyright notice

#ifndef BASE_INTERFACE_DEMO__MSG__DETAIL__STUDENT__STRUCT_HPP_
#define BASE_INTERFACE_DEMO__MSG__DETAIL__STUDENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__base_interface_demo__msg__Student __attribute__((deprecated))
#else
# define DEPRECATED__base_interface_demo__msg__Student __declspec(deprecated)
#endif

namespace base_interface_demo
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Student_
{
  using Type = Student_<ContainerAllocator>;

  explicit Student_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->age = 0l;
      this->height = 0.0f;
      this->weight = 0.0f;
    }
  }

  explicit Student_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->age = 0l;
      this->height = 0.0f;
      this->weight = 0.0f;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _age_type =
    int32_t;
  _age_type age;
  using _height_type =
    float;
  _height_type height;
  using _weight_type =
    float;
  _weight_type weight;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__age(
    const int32_t & _arg)
  {
    this->age = _arg;
    return *this;
  }
  Type & set__height(
    const float & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__weight(
    const float & _arg)
  {
    this->weight = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    base_interface_demo::msg::Student_<ContainerAllocator> *;
  using ConstRawPtr =
    const base_interface_demo::msg::Student_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<base_interface_demo::msg::Student_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<base_interface_demo::msg::Student_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      base_interface_demo::msg::Student_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<base_interface_demo::msg::Student_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      base_interface_demo::msg::Student_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<base_interface_demo::msg::Student_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<base_interface_demo::msg::Student_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<base_interface_demo::msg::Student_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__base_interface_demo__msg__Student
    std::shared_ptr<base_interface_demo::msg::Student_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__base_interface_demo__msg__Student
    std::shared_ptr<base_interface_demo::msg::Student_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Student_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    return true;
  }
  bool operator!=(const Student_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Student_

// alias to use template instance with default allocator
using Student =
  base_interface_demo::msg::Student_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace base_interface_demo

#endif  // BASE_INTERFACE_DEMO__MSG__DETAIL__STUDENT__STRUCT_HPP_
