#include "AttrModifyIncByAttr.h"
#include "AttrBinderLambda.h"
#include "Entity.h"
#include "AttrComp.h"
#include "Attr.h"

void AttrModifyIncByAttr::Modify(AttrData& data)
{
	data.fix += v;
}

void AttrModifyIncByAttr::Init()
{
	auto func = [this](const AttrData& data)
	{
		if (target == from)
			return;
		int tmp = data.raw * (pct / 100.f);
		SetVal(tmp);
	};

	bind = std::make_shared<AttrBinderLambda>(func);
}

void AttrModifyIncByAttr::Apply(const SP(Entity)& in_ent)
{
	if (in_ent)
	{
		auto comp = in_ent->GetComp<AttrComp>(EComp::Attr);
		if (comp)
		{
			comp->AddBinder(from, bind);
		}
	}
	else
	{
		if (auto lock = ent.lock())
		{
			auto comp = lock->GetComp<AttrComp>(EComp::Attr);
			if (comp)
			{
				comp->RemBinder(from, bind);
			}
		}
	}
	AttrModify::Apply(in_ent);
}
