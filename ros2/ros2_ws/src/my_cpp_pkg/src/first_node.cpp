#include "rclcpp/rclcpp.hpp"

using namespace std;

class MyCustomNode : public rclcpp::Node{ //rclcpp is the namespace (package name)

    public:
        MyCustomNode():Node("new_node"), counter(0){
            timer = this->create_wall_timer(chrono::seconds(5), bind(&MyCustomNode::print_hello, this));
        }

        void print_hello(){
            RCLCPP_INFO(this->get_logger(), "hello %d", counter);
            counter++;
        }

        

    private:
        int counter;
        rclcpp::TimerBase::SharedPtr timer;//type alias for std::shared_ptr<rclcpp::TimerBase> timer;
        
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto node = make_shared<MyCustomNode>(); //shared pointer
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

