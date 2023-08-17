#include "Affix.h"
#include "Modify.h"
#include "Entity.h"
#include "AttrComp.h"
#include "AttrModify.h"

void Affix::Apply(const SP(Entity)& in_ent)
{
	for (auto& mod : mods)
	{
		auto comp_ty = mod->GetCompTy();
		mod->Apply(in_ent);
		if (in_ent)
		{
			switch (comp_ty)
			{
			case EComp::Attr:
			{
				auto comp = in_ent->GetComp<AttrComp>(comp_ty);
				if (comp)
				{
					comp->AddMod(std::dynamic_pointer_cast<AttrModify>(mod));
				}
			}
			default:
				break;
			}
		}
		else
		{
			if (auto lock = ent.lock())
			{
				switch (comp_ty)
				{
				case EComp::Attr:
				{
					auto comp = lock->GetComp<AttrComp>(comp_ty);
					if (comp)
					{
						comp->RemMod(std::dynamic_pointer_cast<AttrModify>(mod));
					}
				}
				default:
					break;
				}
			}
		}

		ent = in_ent;
	}
}
