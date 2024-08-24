#pragma once

#include <vector>
#include <mutex>
#include <cstdint>

class QR_PoolObject
{
    template<class TObject>
    friend class QR_PoolManager;

public:
    QR_PoolObject(){
        isActive = false;
        //dont generate the Id here as it will be calling a virtual function from a constructor which can lead to undefined behaviour.
    };

    bool GetisActive() const {return isActive;}
    uint64_t GetPoolObjID() const {return ID;}

protected:
    //ID is generated here. I could just have a counter that counts up to generate a unique id. However this would not be thread safe as incrementing the counter and setting it to ID is not automic.
    virtual  uint64_t GenerateRandomId() = 0;

private:
    //ID is generated via the QR random int
    uint64_t ID;
    bool isActive;
};

template<class TObject>
class QR_PoolManager
{
public:

    void AddObjectToPool(QR_PoolObject* objToAdd)
    {
        //add the object to the pool by creating an id for it, setting it to active, and adding it to vector.
        objToAdd->ID = objToAdd->GenerateRandomId();
        objToAdd->isActive = true;

        //this vector can be added to or removed asynchronously making it non-threadsafe.
        mutexForGettingAndSettingPoolObjs.lock();
        ObjectPool.push_back(objToAdd);
        mutexForGettingAndSettingPoolObjs.unlock();
    }

    void RemoveObjectFromPool(QR_PoolObject* objToAdd)
    {
        //get the object placement in the list
        int objIndex = 0;
        mutexForGettingAndSettingPoolObjs.lock();
        for(int i; i < ObjectPool.size(); i++)
        {
            if (objToAdd->ID == ObjectPool[i]->ID) {
                objIndex = i;
                break;
            }
        }
        ObjectPool.erase(ObjectPool.begin() + objIndex);
        objToAdd->isActive = false;
        mutexForGettingAndSettingPoolObjs.unlock();
    }

    QR_PoolObject* GetObjectFromPool(uint64_t id)
    {
        QR_PoolObject* ret = nullptr;
        for(int i; i < ObjectPool.size(); i++)
        {
            if (id == ObjectPool[i]->ID) {
                ret = ObjectPool[i];
                break;
            }
        }
        return ret;
    }

private:
    std::mutex mutexForGettingAndSettingPoolObjs;

    std::vector<QR_PoolObject*> ObjectPool;
};
