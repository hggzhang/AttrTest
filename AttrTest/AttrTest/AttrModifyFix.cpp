#include "AttrModifyFix.h"
#include "Attr.h"

void AttrModifyFix::Modify(AttrData& data)
{
	data.fix += v;
}
