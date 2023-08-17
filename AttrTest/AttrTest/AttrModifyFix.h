#include "AttrModify.h"

class AttrModifyFix : public AttrModify
{
public:
	virtual void Modify(AttrData& info) override;

	AttrModifyFix(EAttr in_target, int v = 0) : AttrModify(in_target, v) {}
};