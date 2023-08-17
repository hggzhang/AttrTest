#pragma once
#include "AttrBinder.h"
#include <functional>
class AttrBinderLambda :
    public AttrBinder
{
private:
    std::function<void(const AttrData& data)> lambda;
public:
    AttrBinderLambda(std::function<void(const AttrData& data)> lambda) : lambda(lambda) {};

    virtual void Notify(const AttrData& data) override;
};

