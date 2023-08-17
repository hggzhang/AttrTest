#include "AttrModifyOverride.h"
#include "Attr.h"
void AttrModifyOverride::Modify(AttrData& info)
{
	info.bOverride = true;
	info.override = v;
}
