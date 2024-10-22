cmake_minimum_required(VERSION 3.8)
project(pk04_action_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(base_interface_demo REQUIRED)
#find_package(rosidl_default_generators REQUIRED)
#由于使用的base_interface_demo软件包，他的CMakeLists.txt文件中已经包含了rosidl_default_generators的依赖，所以这里不需要再次添加依赖。

add_executable(demo01_action_server src/demo01_action_server.cpp)
ament_target_dependencies(
  demo01_action_server
  "rclcpp"
  "rclcpp_action"
  "base_interface_demo"
)

add_executable(demo02_action_client src/demo02_action_client.cpp)
ament_target_dependencies(
  demo02_action_client
  "rclcpp"
  "rclcpp_action"
  "base_interface_demo"
)

install(TARGETS 
  demo01_action_server
  demo02_action_client
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
