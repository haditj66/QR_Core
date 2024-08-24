/*****************************************************************************
** Includes
*****************************************************************************/
#include "../../include/MyQtHeaders/main_window.hpp"
#include "ui_main_window.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/
namespace QTStuff {

  /*****************************************************************************
  ** Implementation [MainWindow]
  *****************************************************************************/

Ui::MainWindowDesign* MainWindow::UIStatic = nullptr;

  MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindowDesign),
      argc_(argc),
      argv_(argv)
  {
    ui->setupUi(this);

#ifdef ISForQT__ON
    ros_spin_thread_ = std::thread{std::bind(&MainWindow::rosSpinThread, this)};
#endif



  }

  MainWindow::~MainWindow(){rclcpp::shutdown();}

  // Start ROS2 NODE
  void MainWindow::rosSpinThread()
  {

      rclcpp::init(argc_, argv_);
      Qjoystick =
        std::make_shared<my_composable_node::MyNode>(rclcpp::NodeOptions());

      RCLCPP_INFO(Qjoystick->get_logger(), "MyNode started up!");
      rclcpp::spin(Qjoystick);  // should not return
      rclcpp::shutdown();
  }



  void MainWindow::closeEvent(QCloseEvent *event)
  {
    QMainWindow::closeEvent(event);
  }

}










