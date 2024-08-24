/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/my_composable_node/MyNode.hpp"



/*****************************************************************************
** Namespaces
*****************************************************************************/
//QT stuff
#ifdef ISForQT__ON
#include "../include/MyQtHeaders/main_window.hpp"
#endif


namespace PROJECT_NAME {
  using namespace std::chrono_literals;


  /*****************************************************************************
  ** Implementation
  *****************************************************************************/

  MyNode::MyNode(const rclcpp::NodeOptions & options)
      : Node("MyNode", options)
  {
      #ifdef ISForQT__ON
      //MainWindow::UIStatic->SomeLabel->text("node has started");
      #endif

      pub_ = this->create_publisher<std_msgs::msg::String>("~/some_topic",100);
      //sim_velocity = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel",100);
      //subscription_ = this->create_subscription<sensor_msgs::msg::Image>("cam_sync/image_raw", 10, std::bind(&joystick::topic_callback, this,_1));

      timer_ = this->create_wall_timer(
            500ms, std::bind(&MyNode::timer_callback, this));

  }




  MyNode::~MyNode()
  {
    rclcpp::shutdown();
  }




  //void joystick::topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const {
      //RCLCPP_INFO(rclcpp::get_logger("JOYSTICK"),"event recieved");
   //}






}

//this is needed for a composable node
#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(PROJECT_NAME::MyNode)

