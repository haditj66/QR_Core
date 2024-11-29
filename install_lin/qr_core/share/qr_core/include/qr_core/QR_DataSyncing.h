#pragma once


#ifdef ROS2_PROJECT

#include <functional>
#include "QR_Ticket.h"
#include "rclcpp/rclcpp.hpp"

#include <list>
#include <random>

extern rclcpp::Node* AOGlobalNode;
extern rclcpp::Node* TheDataAccessManagerNode;




class DataSyncSession {
private:
    int64_t arg1_;
    int64_t arg2_;

    // Helper function to generate a random int64
    int64_t generateRandomInt64() {
        std::random_device rd;              // Seed generator
        std::mt19937_64 gen(rd());          // 64-bit Mersenne Twister engine
        std::uniform_int_distribution<int64_t> dist(INT64_MIN, INT64_MAX);
        return dist(gen);
    }

public:
    // Constructor: Generates two random int64 numbers
    DataSyncSession()
        : arg1_(generateRandomInt64()), arg2_(generateRandomInt64()) {

    }

    // Function to check if the given arguments match the session
    bool IsSameSession(int64_t arg1, int64_t arg2) const {
        return (arg1_ == arg1 && arg2_ == arg2);
    }

    //  Accessor functions for arg1_ and arg2_
    int64_t getArg1() const { return arg1_; }
    int64_t getArg2() const { return arg2_; }
};





using std::placeholders::_1;
using std::placeholders::_2;

template<typename TData, typename TDataChanged, typename TDataChangedSub>
class DataSyncing
{

    typedef typename rclcpp::Subscription<TDataChangedSub>::SharedPtr DataChangedSub;
    typedef typename TDataChangedSub::SharedPtr DataChangedCall;
    typedef typename rclcpp::Client<TDataChanged>::SharedResponse Trcl;
    typedef typename std::shared_future<Trcl> DataChanged;

    //qr_core::srv::VoidInt, //rclcpp::Subscription<qr_core::msg::VoidIntChanged>::SharedPtr

public:

    //This class will subscribe to the "Rock1/changedposx" event.
    //When such an event happens, it will check the id of that event. If
    //the id matches the Ticket used to send that request, it will set the
    //HasBeenRefreshedSinceSet to true. This means that surrogate data is synced with the
    //AO and any subsequent Set or Get to that data may go through.
    //rclcpp::Subscription<TDataChanged>::SharedPtr
    DataChangedSub subscription_datachanged;
    rclcpp::CallbackGroup::SharedPtr Datasync_cb_group;


    //pass in the subscription callback group because it will be specific to every surrogate. As in, a surrogate will have one callback
    //group for all datasync objects in it.
    DataSyncing(std::string id,std::string nameOfData, TData* dataToChange, rclcpp::CallbackGroup::SharedPtr callbackGroupForSurrogate) : DataToChange(dataToChange){

        //        subscription_datachanged = AOGlobalNode->create_subscription<TDataChanged>
        //                        (id + "/"+ nameOfData + "DataChanged", 10, std::bind(&DataSyncing<TData,  TDataChanged, TDataChangedSub>::datachanged_Callback, this,_1));
        //        subscriptionInitialized = AOGlobalNode->create_subscription<world_i::msg::GameobjectData>
        //                ("/GameobjectInitialized", 10, std::bind(&GameobjectInit::GameobjectInitialized_Callback,this, _1));

        this->Id = id;

        Datasync_cb_group = callbackGroupForSurrogate;//AOGlobalNode->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        rclcpp::SubscriptionOptions options;
        options.callback_group = Datasync_cb_group;
        subscription_datachanged = TheDataAccessManagerNode->create_subscription<TDataChangedSub>
                                   (id + "/"+ nameOfData + "DataChanged", 10,
                                    std::bind(&DataSyncing<TData,  TDataChanged, TDataChangedSub>::datachanged_Callback, this,_1), options);

        TicketForData = nullptr;
    }

    void datachanged_Callback(const DataChangedCall msg)//(const DataChangedCall msg)
    {
        //I need to make sure the requesting surrogate of this data set is not this surrogate as data is already updated for it upont request.
        //do this by looking through the DataSyncSession. if the id matches, it should be removed from the list and this function should exit.
        bool isSameSurrogate = CheckIfSessionIsTheSame(msg->id1, msg->id2);
        if (isSameSurrogate == true) {
            return;
        }

        //if the id here is the same as the ticket id, I can say that this callback was from my request to change this data. This means that
        // //the data has now been changed based on the ticket request.
        // if(this->TicketForData != nullptr)
        // {
        //     if(msg->id == this->TicketForData->getid())
        //     {
        //         SetHasBeenRefreshedSinceSet(true);
        //     }
        // }

        QR_Print(" %s  onchanged event callback recieved. value changed to: %d", this->Id.c_str(), msg->data);

        //regardless on whether the data change was from the ticket request, I still need to change the surrogate's internal data.
        //This is the ONLY place where this can happen, so no need for a mutex.
        *DataToChange = msg->data;
        //      int64_t s = msg->data;
    }



    TicketFuture<DataChanged, void>*
        //Ticket<std::shared_future<rclcpp::Client<qr_core::srv::Int64Int64>::SharedResponse>, void>*
        TicketForData;


    std::mutex MutexForData;
    void SetHasBeenRefreshedSinceSet(bool value)
    {
        MutexForData.lock();
        _HasBeenRefreshedSinceSet = value;
        MutexForData.unlock();
    }
    bool HasBeenRefreshedSinceSet(){return _HasBeenRefreshedSinceSet;}

    DataSyncSession* GenerateSession()
    {
        DataSyncSession* s = new DataSyncSession();
        myList.push_back(s);
        return s;
    }

private:
    std::string Id;
    bool _HasBeenRefreshedSinceSet;
    TData* DataToChange;

    std::list<DataSyncSession*> myList;


    bool CheckIfSessionIsTheSame(int64_t id1, int64_t id2)
    {

        for (auto it = myList.begin(); it != myList.end(); ++it)
        {
            DataSyncSession* session = *it;

            // Check if the session's ID matches the requesting ID
            if (session->IsSameSession(id1, id2))
            {
                // Remove the session from the list
                myList.erase(it);
                return true;
            }
        }
        return false;
    }
};


#endif
