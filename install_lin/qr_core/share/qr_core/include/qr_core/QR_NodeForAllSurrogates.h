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





///DataAccessManagerNode. This node will be used to manage dataaccess calls like service callbacks for Setposx
///for the REAL AO. and also surrogate changes like subscribtion to Rock1/posxChanged
  class NodeForAllSurrogates : public rclcpp::Node
  {
  public:


      COMPOSITION_PUBLIC
      explicit NodeForAllSurrogates (const rclcpp::NodeOptions & options)
          //: Node(QR_stringify(DataNodeName), options)
          : Node(QR_stringify(MODULE_NAME) + AO_NAME+ "NFAS", options)
      {
          //TheDataAccessManagerNode = (rclcpp::Node*)this;

      }



      //MyNode();
      virtual ~NodeForAllSurrogates ()      {
          rclcpp::shutdown();
        }



  private:

  };







#endif
