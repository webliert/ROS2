/*  
    需求：订阅发布方发布的消息，并输出到终端。
    步骤：
        1.包含头文件；
        2.初始化 ROS2 客户端；
        3.定义节点类；
            3-1.创建订阅方；
            3-2.处理订阅到的消息。
        4.调用spin函数，并传入节点对象指针；
        5.释放资源。
*/

//1.include header files
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

//3.initialize node class
class MinialSubscriber : public rclcpp::Node
{
    public: 
        MinialSubscriber() : Node("minimal_subscriber")
        // construct and initialize subscriber,the node name is "minimal_subscriber"
        {
            subscription_ = this->create_subscription<std_msgs::msg::String>("topic",10,std::bind(&MinialSubscriber::topic_callback, this, std::placeholders::_1));\
            // create a subscription to the topic "topic" with a queue size of 10, and bind the topic_callback function to it.
            //std::bind is used to bind the topic_callback function to the object of the class MinialSubscriber.
        }
        private:
        //3-2 handle the subscribed message
        void topic_callback(const std_msgs::msg::String & msg)const
        {
            RCLCPP_INFO(this->get_logger(), "Received message: %s", msg.data.c_str()); 
            //the statement function is used to print the received message to the terminal.
            //RCLCPP_INFO is a macro defined in the rclcpp library, which prints the message to the terminal with the node name as prefix.
        }
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
        //SharedPtr is used to create a shared pointer to the subscription object, which is used to release the resources when the node is shut down.
};

int main(int argc, char * argv[])
{
    //2.initialize ROS2 client
    rclcpp::init(argc, argv);
    //4.call spin function and pass the node object pointer
    rclcpp::spin(std::make_shared<MinialSubscriber>());
    //5.release resources
    rclcpp::shutdown();
    return 0;
}