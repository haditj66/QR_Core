#pragma once

#include <mutex>
#include <future>
#include "QR_Print.h"



///this is the base abstract class all tickets derive from.
template<typename TReturnDataType>
class Ticket
{
public:

    virtual TReturnDataType AwaitRequestUntilFinished() =0;

    virtual bool IsReady() = 0;

    uint64_t getid() const {return id;}
    void setid(uint64_t ID){this->id = ID;}


protected:

    uint64_t id;

};


//typedef typename rclcpp::Subscription<TDataChangedSub>::SharedPtr DataChangedSub;
//typedef typename TDataChangedSub::SharedPtr DataChangedCall;
//typedef typename rclcpp::Client<TDataChanged>::SharedResponse Trcl;
//typedef typename std::shared_future<Trcl> DataChanged;

//typedef  Ticket<std::shared_future<rclcpp::Client<world_i::srv::AddObjectToWorld>::SharedResponse>, world_i::srv::AddObjectToWorld_Response::_result_type> AddobjectToWorldTicket_t;// TicketFor_AddObjectToWorld;
//typedef  Ticket<std::shared_future<rclcpp::Client<world_i::srv::MoveObject>::SharedResponse>, world_i::srv::MoveObject_Response::_result_type> MoveObjectTicket_t;//TicketFor_MoveObject;


//template <class TReturnDataType>//


// go here for an explanation of furture vs shared futue
//https://stackoverflow.com/questions/16005655/what-is-the-difference-between-future-and-shared-future
///ticket base implementation for ros tickets that will use Futures for their await function.
template<typename TFuture, typename TReturnDataType>
class TicketFutureBase : public Ticket<TReturnDataType>
{

        //    typedef typename rclcpp::Client<TReturnDataType> TClient1;
        //    typedef typename TClient1::SharedResponse TClient;
        //    typedef typename  std::shared_future<TClient> TFutureType;


public:


    std::mutex MutexForTicket;


    TicketFutureBase(TFuture future) : resultTaskToAwait(future) {
            //this->id = id;
            //generate a new id
            //id = getRandom();
        };




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
                return _GetFinalReturnFromFuture();
                //
            }
            else
            {
                TReturnDataType returnValue = _AwaitRequestUntilFinished();
                return returnValue;
            }


        }
    }





protected:

    TicketFutureBase(){

    }

    //this is needed because some futures like the one for services will return a different type then the TReturnDataType
    // and because of that will need an extra step to get the final return type
    virtual TReturnDataType _GetFinalReturnFromFuture() = 0;

    virtual TReturnDataType _AwaitRequestUntilFinished() = 0;


    //TTaskType
    TFuture resultTaskToAwait;
    //wtf resultTaskToAwait;
    //std::shared_future<rclcpp::Client<TReturnDataType>::SharedResponse>* resultTaskToAwait;

};




///this is meant to be used for futures. They have mutex to await the ticket.
template<typename TFuture, typename TReturnDataType>
//class Ticket : public TicketFutureBase<TReturnDataType>
class TicketFuture  : public TicketFutureBase<TFuture, TReturnDataType>
{

        //    typedef typename rclcpp::Client<TReturnDataType> TClient1;
        //    typedef typename TClient1::SharedResponse TClient;
        //    typedef typename  std::shared_future<TClient> TFutureType;

public:
    TicketFuture(TFuture future ) : TicketFutureBase<TFuture, TReturnDataType>(future)//TicketFutureBase<TReturnDataType>(future)
    {

    }

protected:
    TReturnDataType _AwaitRequestUntilFinished() override
    {
        //success so return the result
        return _GetFinalReturnFromFuture();

    }

    TReturnDataType _GetFinalReturnFromFuture() override
    {
        return this->resultTaskToAwait.get();
    }

};

///function specialization workaround for TicketFutureBase if the return value is void
template<typename TFuture>
class TicketFuture<TFuture, void>  : public TicketFutureBase<TFuture, void>
{

        //    typedef typename rclcpp::Client<TReturnDataType> TClient1;
        //    typedef typename TClient1::SharedResponse TClient;
        //    typedef typename  std::shared_future<TClient> TFutureType;

public:
    TicketFuture(TFuture future ) : TicketFutureBase<TFuture, void>(future)//TicketFutureBase<TReturnDataType>(future)
    {

    }

protected:
    void _AwaitRequestUntilFinished() override
    {
        //success so return the result
        return _GetFinalReturnFromFuture();

    }

    void _GetFinalReturnFromFuture() override
    {
        this->resultTaskToAwait.get();
    }

};


#ifdef ROS2_PROJECT



///this is meant to be used for ros tickets that come from services. They have mutex to await the ticket.
template<typename TFuture, typename TReturnDataType,typename TInterfaceType >
class TicketFuture_RosService_NONQR : public TicketFutureBase<TFuture, TReturnDataType>
{
    //rclcpp::Client<world_i::srv::AddObjectToWorld>::SharedFuture
    //    typedef typename rclcpp::Client<TInterfaceType>::SharedFuture TClient1;
    typedef typename rclcpp::Client<TInterfaceType>::SharedFuture TSharedFuture;
    // typedef typename TInterfaceType::Response::_result_type TReturnResultType;
    //    typedef typename TClient1::SharedFuture TSharedFuture;
    //typedef typename TReturnDataType::_result_type TResponseResult;

    //    typedef typename TClient1::SharedResponse TClient;
    //    typedef typename  std::shared_future<TClient> TFutureType;

public:
    //    std::function<void(TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>*, TSharedFuture)> CallbackToServiceVar =
    //            std::bind
    //            (&TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>::CallbackToService,this);

    std::function<void(TSharedFuture)> CallbackToServiceVar;
    //            std::bind
    //            (&TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>::CallbackToService,this);

    TicketFuture_RosService_NONQR( ) : TicketFutureBase<TFuture, TReturnDataType>()//TicketFutureBase<TReturnDataType>(future)
    {
        CallbackToServiceVar = [&,this](TSharedFuture inner_future)
        {
            //QR_Print("callback for addobjectToWorld recieved");
            // auto res = inner_future.get()->result;
            auto res = inner_future.get();
            this->MutexForTicket.unlock();
        };

    }

    void SetNewFuture(TFuture future )
    {
        this->resultTaskToAwait = future;
    }

protected:


    TReturnDataType _AwaitRequestUntilFinished() override
    {

            //lock it here. if it passes this, it means the callback for the service unlocked it and the service is complete.
        QR_Print("locking mutex");
        this->MutexForTicket.lock();
        this->MutexForTicket.unlock();
        QR_Print("unlocking mutex");
        //{
        //success so return the result
        return this->_GetFinalReturnFromFuture();



    }

    TReturnDataType _GetFinalReturnFromFuture() override
    {
        auto df = this->resultTaskToAwait.get();
        return df;
    }

};








///this is meant to be used for ros tickets that come from services. They have mutex to await the ticket.
template<typename TFuture, typename TReturnDataType,typename TInterfaceType >
//class Ticket : public TicketFutureBase<TReturnDataType>
class TicketFuture_RosService : public TicketFutureBase<TFuture, TReturnDataType>
{
    //rclcpp::Client<world_i::srv::AddObjectToWorld>::SharedFuture
    //    typedef typename rclcpp::Client<TInterfaceType>::SharedFuture TClient1;
    typedef typename rclcpp::Client<TInterfaceType>::SharedFuture TSharedFuture;
    typedef typename TInterfaceType::Response::_result_type TReturnResultType;
    //    typedef typename TClient1::SharedFuture TSharedFuture;
    //typedef typename TReturnDataType::_result_type TResponseResult;

    //    typedef typename TClient1::SharedResponse TClient;
    //    typedef typename  std::shared_future<TClient> TFutureType;

public:
    //    std::function<void(TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>*, TSharedFuture)> CallbackToServiceVar =
    //            std::bind
    //            (&TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>::CallbackToService,this);

    std::function<void(TSharedFuture)> CallbackToServiceVar;
    //            std::bind
    //            (&TicketFuture_RosService<TFuture, TReturnDataType, TInterfaceType>::CallbackToService,this);

    TicketFuture_RosService( ) : TicketFutureBase<TFuture, TReturnResultType>()//TicketFutureBase<TReturnDataType>(future)
    {
        CallbackToServiceVar = [&,this](TSharedFuture inner_future)
        {
            //QR_Print("callback for addobjectToWorld recieved");
            auto res = inner_future.get()->result;
            this->MutexForTicket.unlock();
        };

    }

    void SetNewFuture(TFuture future )
    {
        this->resultTaskToAwait = future;
    }


    //    void CallbackToService(int inner_future)
    //    {
    //        QR_Print("callback for addobjectToWorld recieved");
    ////        auto res = inner_future.get()->result;
    ////        this->MutexForTicket.unlock();
    //    }
protected:




    TReturnResultType _AwaitRequestUntilFinished() override
    {

            //lock it here. if it passes this, it means the callback for the service unlocked it and the service is complete.
        QR_Print("locking mutex");
        this->MutexForTicket.lock();
        this->MutexForTicket.unlock();
        QR_Print("unlocking mutex");
        //{
        //success so return the result
        return this->_GetFinalReturnFromFuture();


        //}
        //        else //TODO: log the error
        //        {
        //            //there was a failure in the request call so log the error
        //
        //        }

    }

    TReturnResultType _GetFinalReturnFromFuture() override
    {
        auto df = this->resultTaskToAwait.get();
        return df->result;
    }

};


///function specialization workaround for TicketFutureBase if the return value is void
template<typename TFuture,typename TInterfaceType>
class TicketFuture_RosService<TFuture, void, TInterfaceType> : public TicketFutureBase<TFuture, void>
{

    //    typedef typename rclcpp::Client<void> TClient1;
    //    typedef typename TClient1::SharedResponse TClient;
    //    typedef typename  std::shared_future<TClient> TFutureType;
    typedef typename rclcpp::Client<TInterfaceType>::SharedFuture TSharedFuture;

public:

    std::function<void(TSharedFuture)> CallbackToServiceVar;

    //Ticket(std::shared_future<rclcpp::Client<int>::SharedResponse> future) : TicketFutureBase<int>(future)
    TicketFuture_RosService( ) : TicketFutureBase<TFuture, void>( )
    {
        CallbackToServiceVar = [&,this](TSharedFuture inner_future)
        {
            //QR_Print("callback for addobjectToWorld recieved");
            // auto res = inner_future.get()->result;
            this->MutexForTicket.unlock();
        };

    }
    void SetNewFuture(TFuture future )
    {
        this->resultTaskToAwait = future;
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
        _GetFinalReturnFromFuture();
        //return df->result;

        //}
        //        else
        //        {
        //            //there was a failure in the request call so log the error
        //            //TODO: log the error
        //        }

    }

    void _GetFinalReturnFromFuture() override
    {
        this->resultTaskToAwait.get();
    }

};
#endif
