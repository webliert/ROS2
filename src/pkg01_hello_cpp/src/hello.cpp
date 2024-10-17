#include <cstdio>
#include<rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
  //初始化 ROS2
  rclcpp::init(argc, argv);

  //创建节点
  auto node = rclcpp::Node::make_shared("hello_node");

  //输出文本
  RCLCPP_INFO(node->get_logger(), "Hello ROS2!,test my ROS2 print");

  //释放资源
  rclcpp::shutdown();

  return 0;
}
