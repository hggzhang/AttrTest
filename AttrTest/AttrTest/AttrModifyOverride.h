#pragma once
#include "AttrModify.h"
class AttrModifyOverride :
    public AttrModify
{
public:
    AttrModifyOverride(EAttr in_target, int in_v = 0) : AttrModify(in_target, in_v) {}
    // ͨ�� AttrModify �̳�
    virtual void Modify(AttrData& info) override;
};

