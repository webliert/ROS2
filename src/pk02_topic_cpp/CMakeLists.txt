cmake_minimum_required(VERSION 3.8)
project(pk02_topic_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(base_interface_demo REQUIRED)

add_executable(demo01_talk_str src/demo01_talk_str.cpp)
add_executable(demo02_listen_str src/demo02_listen_str.cpp)
add_executable(demo03_talker_stu src/demo03_talk_stu.cpp)
add_executable(demo04_listen_stu src/demo04_listen_stu.cpp)

ament_target_dependencies(
  demo01_talk_str
  "rclcpp"
  "std_msgs"
 "base_interface_demo"
)


ament_target_dependencies(
  demo02_listen_str
  "rclcpp"
  "std_msgs"
  "base_interface_demo"
)

ament_target_dependencies(
  demo03_talker_stu
  "rclcpp"
  "std_msgs"
  "base_interface_demo"
)

ament_target_dependencies(
  demo04_listen_stu
  "rclcpp"
  "std_msgs"
  "base_interface_demo"
)

install(TARGETS 
  demo01_talk_str
  demo02_listen_str
  demo03_talker_stu
  demo04_listen_stu
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
