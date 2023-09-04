#pragma once
#include "Modify.h"
#include "SmartPointerHeader.h"
#include "define.h"

struct AttrData;

class Attr;
class Entity;

class AttrModify :
    public Modify
{
protected:
    int v = 0;
    EAttr target;

public:
    virtual EComp GetCompTy() override { return EComp::Attr; }
    AttrModify(EAttr in_target, int in_v = 0) : target(in_target), v(in_v) {}

    void SetVal(int in) 
    { 
        if (v == in)
            return;
        v = in; 
        Upd();
    }

    virtual void Apply(const SP(Entity)& in_ent) override;
    

    EAttr GetTargetAttr()
    {
        return target;
    }

    void Upd();

    virtual void Modify(AttrData& info) = 0;
};

