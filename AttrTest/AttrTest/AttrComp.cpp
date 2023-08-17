#include "AttrComp.h"
#include "Attr.h"
#include "AttrModify.h"

int AttrComp::GetAttrVal(EAttr ty)
{
    auto attr = GetAttr(ty);
    if (attr)
        return attr->GetVal();
    else
        return 0;
}

void AttrComp::AddBinder(EAttr ty, SP(AttrBinder) binder)
{
    auto attr = GetAttr(ty);
    if (attr)
        attr->AddBinder(binder);
}

void AttrComp::RemBinder(EAttr ty, SP(AttrBinder) binder)
{
    auto attr = GetAttr(ty);
    if (attr)
        attr->RemBinder(binder);
}

void AttrComp::AddMod(SP(AttrModify) mod)
{
    EAttr ty = mod->GetTargetAttr();
    auto attr = GetAttr(ty);
    if (attr)
    {
        attr->AddMod(mod);
    }
}

void AttrComp::RemMod(SP(AttrModify) mod)
{
    EAttr ty = mod->GetTargetAttr();
    auto attr = GetAttr(ty);
    if (attr)
    {
        attr->RemMod(mod);
    }
}

void AttrComp::UpdMod(EAttr ty)
{
    auto attr = GetAttr(ty);
    if (attr)
    {
        attr->UpdMod();
    }
}

EComp AttrComp::GetTy()
{
    return EComp::Attr;
}

void AttrComp::Init()
{
    auto attr_vec =
    {
        EAttr::STR,
        EAttr::INT,
        EAttr::AGI,

        EAttr::ATK,
        EAttr::DEF,
        EAttr::AGI,
        EAttr::HP,
        EAttr::MP,
    };

    for (const auto& ty : attr_vec)
    {
        attrs[ty] = std::make_shared<Attr>();
    }
}

SP(Attr) AttrComp::GetAttr(EAttr ty)
{
    auto it = attrs.find(ty);
    if (it != attrs.end())
        return it->second;

    return nullptr;
}
