#pragma once

#include <string>

class QR_AO
{

    bool GetIsAOReal() const {return _isReal;}

    virtual std::string Getid() const =0;


protected:
    virtual void Setid(std::string id) =0;

protected:


    bool _isReal;

};
