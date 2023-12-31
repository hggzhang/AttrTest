#include "Attr.h"
#include "AttrModify.h"
#include "AttrBinder.h"
#include "AttrUtil.h"

void Attr::AddBinder(SP(AttrBinder) binder)
{
	binders.push_back(binder);
    binder->Notify(data);
}

void Attr::RemBinder(SP(AttrBinder) binder)
{
    auto it = std::find(binders.begin(), binders.end(), binder);
    if (it != binders.end()) {
        binders.erase(it);
    }
}

void Attr::AddMod(SP(AttrModify) mod)
{
    mods.push_back(mod);
    UpdMod();
}

void Attr::RemMod(SP(AttrModify) mod)
{
    auto it = std::find(mods.begin(), mods.end(), mod);
    if (it != mods.end()) {
        mods.erase(it);
        UpdMod();
    }
}

void Attr::UpdMod()
{
    data.fix = 0;
    data.pct = 0;
    data.more = 0;
    data.override = 0;
    data.bOverride = false;
    data.final = 0;

    for (const auto& mod : mods)
    {
        mod->Modify(data);
    }

    data.final = AttrUtil::GetFinal(data);

    OnUpdMod();
}

void Attr::OnUpdMod()
{
    for (const auto& binder : binders)
    {
        binder->Notify(data);
    }
}
