#pragma once
#include "AttrModify.h"
#include "define.h"
#include "memory"

class AttrBinderLambda;
class AttrModifyIncByAttr :
    public AttrModify
{
public:
    virtual void Modify(AttrData& info) override;
    AttrModifyIncByAttr(EAttr target, EAttr from, int pct) : AttrModify(target), from(from), pct(pct) { Init(); }
private:
    void Init();
    int pct;
    EAttr from;
    std::shared_ptr<AttrBinderLambda> bind;
public:
    virtual void Apply(const SP(Entity)& in_ent) override;
};

