#pragma once

#include <mutex>
#include <future>
#include "QR_Print.h"


//typedef typename rclcpp::Subscription<TDataChangedSub>::SharedPtr DataChangedSub;
//typedef typename TDataChangedSub::SharedPtr DataChangedCall;
//typedef typename rclcpp::Client<TDataChanged>::SharedResponse Trcl;
//typedef typename std::shared_future<Trcl> DataChanged;

//typedef  Ticket<std::shared_future<rclcpp::Client<world_i::srv::AddObjectToWorld>::SharedResponse>, world_i::srv::AddObjectToWorld_Response::_result_type> AddobjectToWorldTicket_t;// TicketFor_AddObjectToWorld;
//typedef  Ticket<std::shared_future<rclcpp::Client<world_i::srv::MoveObject>::SharedResponse>, world_i::srv::MoveObject_Response::_result_type> MoveObjectTicket_t;//TicketFor_MoveObject;


//template <class TReturnDataType>//
template<typename TFuture, typename TReturnDataType>
class TicketBase
{

//    typedef typename rclcpp::Client<TReturnDataType> TClient1;
//    typedef typename TClient1::SharedResponse TClient;
//    typedef typename  std::shared_future<TClient> TFutureType;



public:


    std::mutex MutexForTicket;


    TicketBase(TFuture future) : resultTaskToAwait(future), _IsReady(false){
        //this->id = id;
        //generate a new id
        //id = getRandom();
    };




    bool _IsReady;
    bool IsReady()
    {
        //check the status of the future. look here for the workaround on how to do this
        //https://stackoverflow.com/questions/10890242/get-the-status-of-a-stdfuture
        return resultTaskToAwait.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
    }

    //trick to allow void template arg given by
    //https://stackoverflow.com/questions/44598222/void-or-any-type-as-a-template-parameter
    TReturnDataType AwaitRequestUntilFinished()
    {
        if constexpr (std::is_same<TReturnDataType, void>::value)
                //     ^^^^^^^^^
        {
            //check if it's ready. if it is, no need to await anything.
            if (this->IsReady())
            {
                return ;
            }
            else
            {
                return _AwaitRequestUntilFinished();
            }


        } else {

            //check if it's ready. if it is, no need to await anything.
            if (this->IsReady())
            {
                auto df = this->resultTaskToAwait.get();
                return df->result;
            }
            else
            {
                TReturnDataType returnValue = _AwaitRequestUntilFinished();
                return returnValue;
            }


        }
    }


    uint64_t getid(){return id;}
    void setid(uint64_t ID){this->id = ID;}


protected:

    uint64_t id;

    virtual TReturnDataType _AwaitRequestUntilFinished() = 0;


    //TTaskType
    TFuture resultTaskToAwait;
    //wtf resultTaskToAwait;
    //std::shared_future<rclcpp::Client<TReturnDataType>::SharedResponse>* resultTaskToAwait;

};






//function specialization workaround for Ticketbase if the return value is NOT void
//template<typename TReturnDataType>
template<typename TFuture, typename TReturnDataType>
//class Ticket : public TicketBase<TReturnDataType>
class Ticket : public TicketBase<TFuture, TReturnDataType>
{

//    typedef typename rclcpp::Client<TReturnDataType> TClient1;
//    typedef typename TClient1::SharedResponse TClient;
//    typedef typename  std::shared_future<TClient> TFutureType;

public:
    Ticket(TFuture future ) : TicketBase<TFuture, TReturnDataType>(future)//TicketBase<TReturnDataType>(future)
    {

    }

protected:
    TReturnDataType _AwaitRequestUntilFinished() override
    {


        //if ( rclcpp::spin_until_future_complete((std::shared_ptr<rclcpp::Node>)AOGlobalNode, this->resultTaskToAwait) == rclcpp::FutureReturnCode::SUCCESS)

        //lock it here. if it passes this, it means the callback for the service unlocked it and the service is complete.
         QR_Print("locking mutex");
        this->MutexForTicket.lock();
        this->MutexForTicket.unlock();
          QR_Print("unlocking mutex");
        //{
            //success so return the result
            auto df = this->resultTaskToAwait.get();
            return df->result;

        //}
//        else
//        {
//            //there was a failure in the request call so log the error
//            //TODO: log the error
//        }

    }

};


//function specialization workaround for Ticketbase if the return value is null
//template <>
//class Ticket<void> : public  TicketBase<void>
template<typename TFuture>
class Ticket<TFuture, void> : public TicketBase<TFuture, void>
{

//    typedef typename rclcpp::Client<void> TClient1;
//    typedef typename TClient1::SharedResponse TClient;
//    typedef typename  std::shared_future<TClient> TFutureType;


public:
    //Ticket(std::shared_future<rclcpp::Client<int>::SharedResponse> future) : TicketBase<int>(future)
    Ticket(TFuture future) : TicketBase<TFuture, void>(future)
    {
    }

protected:
    void _AwaitRequestUntilFinished() override
    {

        //I cant figure out how to do a simple non-polling waite for future complete!
        //I cant do rclcpp::spin_until_future_complete because that would be spinning within an executor which is not allowed.
        //https://answers.ros.org/question/302037/ros2-how-to-call-a-service-from-the-callback-function-of-a-subscriber/
//        while(this->resultTaskToAwait.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
//        {
//             std::this_thread::sleep_for(std::chrono::milliseconds(10));
//            //rclcpp::sleep_for(std::chrono::nanoseconds(1000));
//        }


        //lock it here. if it passes this, it means the callback for the service unlocked it and the service is complete.
        QR_Print("locking mutex");
       this->MutexForTicket.lock();
       this->MutexForTicket.unlock();
         QR_Print("unlocking mutex");

        //if //( rclcpp::spin_until_future_complete(rclcpp::executors::spin_node_until_future_complete, this->resultTaskToAwait)== rclcpp::FutureReturnCode::SUCCESS)
                //( rclcpp::spin_until_future_complete(AOGlobalNode->get_node_base_interface(), this->resultTaskToAwait)== rclcpp::FutureReturnCode::SUCCESS)
        //( rclcpp::spin_until_future_complete((std::shared_ptr<rclcpp::Node>)AOGlobalNode, this->resultTaskToAwait) == rclcpp::FutureReturnCode::SUCCESS)
             //(false)//
        //{
            //success so return the result
            auto df = this->resultTaskToAwait.get();
            //return df->result;

        //}
//        else
//        {
//            //there was a failure in the request call so log the error
//            //TODO: log the error
//        }

    }

};
