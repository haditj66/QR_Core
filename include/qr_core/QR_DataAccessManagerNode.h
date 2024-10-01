#pragma once

#ifdef ROS2_PROJECT

//ROS2
#include "rclcpp/rclcpp.hpp"
#include "visibility_control.h"

#include "QR_Utils.h"

extern std::string AO_NAME;

//CPP
//#include <chrono>
//#include <memory>
//#include <functional>
//#include <string>





///DataAccessManagerNode. This node will be used to manage data property calls by using service callbacks for things like get and set.
///This node will basically create service clients for AO surrogates to call get and sets of their data.
  class DataAccessManagerNode : public rclcpp::Node
  {
  public:


      COMPOSITION_PUBLIC
      explicit DataAccessManagerNode (const rclcpp::NodeOptions & options)
          //: Node(QR_stringify(DataNodeName), options)
          : Node(QR_stringify(MODULE_NAME) + AO_NAME+ "DAMN", options)
      {
          //TheDataAccessManagerNode = (rclcpp::Node*)this;

      }



      //MyNode();
      virtual ~DataAccessManagerNode ()      {
          rclcpp::shutdown();
        }



  private:

  };







#endif
