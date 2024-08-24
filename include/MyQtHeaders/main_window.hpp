#ifndef demo_joystick_MAIN_WINDOW_H
#define demo_joystick_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/
//QT
#include <QMainWindow>

//CPP
#include <chrono>
#include <memory>

//ROS2
#include "rclcpp/rclcpp.hpp"

//ros2_joystick files
#include "../my_composable_node/MyNode.hpp"
#include "ui_main_window.h"


//#include "./../../../../../Documents/../ros2_flir/src/flir_my_ros2_sub/include/flir_my_ros2_sub/MyFlirSub.h"



/*****************************************************************************
** Namespace
*****************************************************************************/
namespace Ui {class MainWindow;}
namespace QTStuff {


  /*****************************************************************************
  ** CLASSES | Mainwindow
  *****************************************************************************/
  class MainWindow : public QMainWindow {
  Q_OBJECT

  public:

          static Ui::MainWindowDesign* UIStatic;

    MainWindow(int argc, char** argv, QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event); // Overloaded function


  private:
    Ui::MainWindowDesign *ui;
    int argc_;
    char** argv_;


    /*********************
    ** node stuff
    **********************/
    std::shared_ptr<my_composable_node::MyNode> Qjoystick;
    std::thread ros_spin_thread_;
    void rosSpinThread();

  };
}

#endif
