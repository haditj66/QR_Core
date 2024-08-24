/*****************************************************************************
** Includes
*****************************************************************************/

#ifdef ISForQT__ON
#include <QApplication>
#include "../include/MyQtHeaders/main_window.hpp"
#endif


#include "rclcpp/rclcpp.hpp"
#include "./include/my_composable_node/MyNode.hpp"
#include "./include/my_composable_node/Config.hpp"

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {

    int result = 1;

#ifdef ISForQT__ON
    /*********************
    ** Qt
    **********************/

    QApplication app(argc, argv);
    QTStuff::MainWindow w(argc,argv);
    w.setWindowTitle("name window here");
    w.show();
    result = app.exec();

#else

//    rclcpp::init(argc, argv);
//    std::shared_ptr<MyQtRosProject::MyNode> myNodeobj = std::make_shared<MyQtRosProject::MyNode>();
//    rclcpp::spin(myNodeobj);
//    rclcpp::shutdown();

    rclcpp::init(argc, argv);
    auto node =
      std::make_shared<my_composable_node::MyNode>(rclcpp::NodeOptions());

    RCLCPP_INFO(node->get_logger(), "MyNode started up!");
    rclcpp::spin(node);  // should not return
    rclcpp::shutdown();

//    rclcpp::executors::SingleThreadedExecutor exec;
//    exec.add_node(node);
//    exec.spin();
#endif



    return result;

}
