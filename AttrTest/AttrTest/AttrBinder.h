#pragma once
#include "Binder.h"

struct AttrData;
class AttrBinder :
    public Binder
{
public: 
    virtual void Notify(const AttrData& data) = 0;
};

