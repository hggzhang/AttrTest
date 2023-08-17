#include "AffixFactory.h"
#include <vector>
#include "AttrModifyFix.h"
#include "AttrModifyIncByAttr.h"
#include "AttrModifyOverride.h"
#include "define.h"
#include "Modify.h"
#include "Affix.h"

SP(Affix) AffixFactory::GenAffix(int ID)
{
	SP(Affix) ret;

	switch (ID)
	{
		case 1:
		{
			auto fixmod = MK_SP(AttrModifyFix, EAttr::DEF, 40);
			auto vec = std::vector<SP(Modify)>{ fixmod };
			ret = MK_SP(Affix, vec);
			break;
		}
		default:
		{
			
			auto incmod = MK_SP(AttrModifyIncByAttr, EAttr::ATK, EAttr::DEF, 150);
			auto ormod = MK_SP(AttrModifyOverride, EAttr::DEF, 0);
			auto vec = std::vector<SP(Modify)>{ incmod, ormod };
			ret = MK_SP(Affix, vec);
			break;
		}
	}

	return ret;
}
