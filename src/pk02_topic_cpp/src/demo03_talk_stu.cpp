/*  
  需求：以某个固定频率发送文本“hello world!”，文本后缀编号，每发送一条消息，编号递增1。
  步骤：
    1.包含头文件；
    2.初始化 ROS2 客户端；
    3.定义节点类；
      3-1.创建发布方；
      3-2.创建定时器；
      3-3.组织消息并发布。
    4.调用spin函数，并传入节点对象指针；
    5.释放资源。
*/

//1. Include header files
#include "rclcpp/rclcpp.hpp"
#include "base_interface_demo/msg/student.hpp"

using namespace std::chrono_literals;   //chrono_literals provides us with easy access to common time units
using base_interface_demo::msg::Student;

//2. Define node class
class TalkStu : public rclcpp::Node    
//point that the TalkStu class inherits from the  base class rclcpp::Node,pbulic is the access specifier,the rclcpp is the namespace, Node is the class name
{
    public:
        TalkStu() : Node("Student_talker"),count_(0)    
        //constructor of the class, it takes a name as an argument and initializes the count_ variable to 0
        {
            //3.1 Create publisher
            publisher_ = this->create_publisher<Student>("topic_stu", 10);
            //use the create_publisher() function to create a publisher on the topic "topic" with a queue size of 10
            //publiser_ is a member variable of the class that is used to publish messages on the topic
            //this pointer is used to refer to the node object that is currently being created
            //<Student> is a type token that specifies the type of message to be published on the topic
            //std_msgs is the namespace, msg is the message type, String is the message name

            //3.2 Create timer
            timer_ = this->create_wall_timer(500ms,std::bind(&TalkStu::timer_callback,this));
            //create_wall_timer() function is used to create a timer that will call the timer_callback() function every 500ms
            //std::bind() function is used to bind the timer_callback() function to the current object of the class
            //the timer_callback() function will be called every 500ms and will publish a message on the topic
            //this pointer is used to refer to the current object of the class
        }
    private:
        void timer_callback()
        {
            //3.3 Organize message and publish
            auto stu = Student();
            stu.name = "LWX";
            stu.age = count_++;
            stu.height = 164.0;
            stu.weight = 50.65;
            RCLCPP_INFO(this->get_logger(), "学生信息：%s, 年龄：%d, 身高：%.2f, 体重：%.2f", stu.name.c_str(), stu.age, stu.height, stu.weight);
            publisher_->publish(stu);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<Student>::SharedPtr publisher_;
        size_t count_;
        //SharedPtr is used to create a shared pointer to the timer and publisher objects,
        //this is necessary because the objects are created in the constructor and need to be accessed by the timer_callback() function
        //count_ is a member variable that is used to keep track of the number of messages published on the topic
        //the second sentence is a detailed description of the member variables
        //the third sentence is a brief description of the member functions, 
};

int main(int argc, char * argv[])
{
    //2. initialize the ROS2 client
    rclcpp::init(argc, argv);
    //create a node object of the TalkStu class

    //4. transfer spin function,and use node pointer as argument
    rclcpp::spin(std::make_shared<TalkStu>());

    //5.release the ROS2 resources
    rclcpp::shutdown();
    return 0;
}