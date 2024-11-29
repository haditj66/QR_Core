#pragma once


#include "QR_Print.h"
#include "QR_rand.h"
 
#include "QR_Ticket.h" 
#include "QR_DataSyncing.h"
#include "QR_Utils.h"

#include "QR_AO.h"

#include "visibility_control.h"

#include "QR_DataAccessManagerNode.h"
#include "QR_NodeForAllSurrogates.h"

#include <sstream>
#include <fstream>
#include <cereal/archives/xml.hpp>

//some global variables

#ifdef ROS2_PROJECT
//This is the main REAL AO node.
extern rclcpp::Node* AOGlobalNode;
//this node is the DataAccessManagerNode meant to deal with all data modification related stuff.
extern rclcpp::Node* TheDataAccessManagerNode;
extern rclcpp::Node* TheNodeForAllSurrogates;
extern std::string AO_NAME;

static std::shared_ptr<DataAccessManagerNode> DAMN;
static std::shared_ptr<NodeForAllSurrogates> NFAS;

#endif

//
#define QR_INIT \
rclcpp::Node* TheDataAccessManagerNode = nullptr; \
rclcpp::Node* TheNodeForAllSurrogates = nullptr; \
rclcpp::Node* AOGlobalNode = nullptr;\
std::string AO_NAME;\
MODULE_NAMESPACE::QR_Settings MODULE_NAMESPACE::QRSettings;
//QR_Settings QRSettings;


//constexpr bool QR_HAS_BEEN_INITIALIZED = true;


//#include "cereal/archives/xml.hpp"
//class QR_Settings;
//extern QR_Settings QRSettings;



class QR_Core
{
public:
#ifdef ROS2_PROJECT
    #ifdef NoAODesignPattern
    template<class TQRSettings>
        static void Init_QR_Core(rclcpp::executors::MultiThreadedExecutor* exec)
    #elif defined(AllSurrogates)
    template<class TQRSettings>//template<class AONodeType, class TQRSettings>
        //static std::shared_ptr<AONodeType>
        static void Init_QR_Core(rclcpp::executors::MultiThreadedExecutor* exec, TQRSettings qRSettings, std::string& aoTheName, std::string theSettingFileSelection)
    #else
    template<class TQRSettings>
        //static std::shared_ptr<AONodeType>
        static void Init_QR_Core(rclcpp::executors::MultiThreadedExecutor* exec, TQRSettings qRSettings, std::string& aoTheName, std::string theSettingFileSelection)
    #endif
#else
    static void Init_QR_Core()
#endif
    {
        //static_assert(QR_HAS_BEEN_INITIALIZED, "not defined");
//        if constexpr (QR_HAS_BEEN_INITIALIZED == false)
//        {
//            throw ("you didnt put QR_INIT in the main includes area");
//        }


        //if the settings file /home/user/QR_Sync/World/rosqt/out.cereal is empty or not there, create the file instead and
        //dont load it.



		QR_rand::init_QRrand();



        #ifdef ROS2_PROJECT

        //####################################
        //Load the settings serialized object
        //####################################

        //if no theSettingFileSelection was passed in, than read it from the AOSelection.txt file
        std::string baseDir = QR_stringify(CMAKE_CURRENT_SOURCE_DIR);
        std::string FileSelection = "";
        if(theSettingFileSelection == "")
        {

            //grab the file that will select the settings file
            std::ifstream settingFileName(baseDir+"/config/AOSelection.txt", std::ios::binary);
            std::string FileSelection_( (std::istreambuf_iterator<char>(settingFileName) ),
                                          (std::istreambuf_iterator<char>()));
            FileSelection = FileSelection_;

            QR_Print("running setting file %s from AOSelection.txt", FileSelection);
        }
        else{
            FileSelection = theSettingFileSelection;

            QR_Print("running setting file %s from cli argument", FileSelection);
        }
        QR::trim(FileSelection);

        std::string pathToSettingsFile = baseDir+"/config/AllAOSettings/"+FileSelection+".cereal";

        std::ifstream so(pathToSettingsFile, std::ios::binary);

        // only if that file exists is empty, I need to write a default serialized object into settings file
    //    std::string content( (std::istreambuf_iterator<char>(so) ),
    //                          (std::istreambuf_iterator<char>()));
        if(so.peek() == std::ifstream::traits_type::eof())
        {
          std::ofstream ss(pathToSettingsFile, std::ios::binary);
          {
              cereal::XMLOutputArchive oarchive(ss); // Create an output archive

              qRSettings.id = "NotSet";
              oarchive(qRSettings); // Write the data to the archive

          }// archive goes out of scope, ensuring all contents are flushed
          ss.close();
          configASSERT((qRSettings.id != "NotSet"), "The settings chosen is NotSet and needs to be filled in." ) ;

        }
        //first load the serialized settings file
        {

            try {
                cereal::XMLInputArchive archive(so); //XMLInputArchive archive(so); // Create an input archive
                archive(qRSettings); // Read the data from the archive
            } catch (...) {
                QR_Print("loading the qRSettings file %s has failed. are you sure the setting file  located at \n %s \n matches the parameters in the QRsettings class?", FileSelection, pathToSettingsFile);
                throw ("qRSettings file not matching  cereal file");
            }

        }
        //close streams
        so.close();
        //if the settings file has a "NotSet" in the id arg, have a configasset fail
        configASSERT((qRSettings.id != "NotSet"), "The settings chosen is NotSet and needs to be filled in." ) ;

        //set the global variable for AOName
        aoTheName = qRSettings.id;

        //####################################





//        auto node =
//          std::make_shared<AONodeType>(rclcpp::NodeOptions());
//        exec->add_node(node);

#ifdef AllSurrogates
        NFAS =   std::make_shared<NodeForAllSurrogates>(rclcpp::NodeOptions());
              exec->add_node(NFAS);
        TheNodeForAllSurrogates = NFAS.get();
        auto node = NFAS;

#else
//        auto node =
//          std::make_shared<AONodeType>(rclcpp::NodeOptions());
//        exec->add_node(node);

         //AOGlobalNode = (rclcpp::Node*)node->ForNode;

#endif


            //#ifndef AllSurrogates
            #ifndef NoAODesignPattern


                    //create an instance of the DataAccessManagerNode. This node will be used to manage dataaccess calls like service callbacks for Setposx
                    //for the REAL AO. and also surrogate changes like subscribtion to Rock1/posxChanged
                    DAMN = std::make_shared<DataAccessManagerNode>(rclcpp::NodeOptions());
                    TheDataAccessManagerNode = DAMN.get();

                    //add the dataAccessNode
                    exec->add_node(DAMN);


             #endif
             //#endif
        //return node;

        #endif


	}

    #ifdef ROS2_PROJECT
    template<class AONodeType >
    static std::shared_ptr<AONodeType> CreateNode(rclcpp::executors::MultiThreadedExecutor* exec, std::string aoTheName)
    {
        AO_NAME = aoTheName;
        auto node =
          std::make_shared<AONodeType>(rclcpp::NodeOptions());
        exec->add_node(node);
        #ifndef AllSurrogates
                 AOGlobalNode = (rclcpp::Node*)node->ForNode;
        #endif



         return node;
    }
    #endif


private:

};
