#pragma once

/*****************************************************************************
** Includes
*****************************************************************************/


#ifdef ISForQT__ON
//*******DONT INCLUDE THIS!! this will cause some circular dependency with undefined behaviours and bugs
//#include "../include/MyQtHeaders/main_window.hpp"
#include "ui_main_window.h"
#include <QMainWindow>
#endif

#include "Config.hpp"

//ROS2
#include "rclcpp/rclcpp.hpp"
//#include "nav_msgs/msg/odometry.hpp"
//#include "image_transport/image_transport.hpp"
//#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/string.hpp"

//CPP
#include <chrono>
#include <memory>
#include <functional>
#include <string>


namespace PROJECT_NAME {
class SomeClass2{
public: int iii;

};
}


/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace PROJECT_NAME {
using std::placeholders::_1;


  /*****************************************************************************
  ** Class
  *****************************************************************************/
//#include<QDebug>
//namespace Ui {class MainWindow;}




  class MyNode : public rclcpp::Node
  {
  public:


      //COMPOSITION_PUBLIC
      explicit MyNode(const rclcpp::NodeOptions & options);

      //MyNode();
      virtual ~MyNode();


      //void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const;


  private:
      rclcpp::TimerBase::SharedPtr timer_;


      /*********************
      ** Subscriber y
      ** Publisher
      **********************/
      //rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
      rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
      //rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr sim_velocity;

      void timer_callback()
        {
          auto message = std_msgs::msg::String();
          message.data = "this is pulished by minimal publisher: " + std::to_string(5);
          RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

              //publish message
          pub_->publish(message);
        }
  };

} // namespace ros2joystick
/* ros2_joystick_QNODE_HPP_ */
