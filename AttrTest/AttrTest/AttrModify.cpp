#include "AttrModify.h"
#include "Attr.h"
#include "AttrComp.h"
#include "Entity.h"

void AttrModify::Apply(const SP(Entity)& in_ent)
{
	Modify::Apply(in_ent);
}

void AttrModify::Upd()
{
	if (auto lock = ent.lock())
	{
		auto comp = lock->GetComp<AttrComp>(GetCompTy());
		if (comp)
		{
			comp->UpdMod(target);
		}
	}
}
