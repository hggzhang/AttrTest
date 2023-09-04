#pragma once
#include "SmartPointerHeader.h"
#include <vector>
#include "define.h"

class AttrBinder;

class AttrModify;


struct AttrData
{
	int fix = 0;
	int more = 0;
	int total = 0;
	int pct = 0;
	int override = 0;
	bool bOverride = false;
	int final = 0;
};

class Attr
{
public:
	int GetVal() { return data.final; }

	void AddBinder(SP(AttrBinder) binder);
	void RemBinder(SP(AttrBinder) binder);

	void AddMod(SP(AttrModify) mod);
	void RemMod(SP(AttrModify) mod);
	void UpdMod();

	const AttrData& GetAttr()
	{
		return data;
	}
	
private:
	std::vector<SP(AttrBinder)> binders;
	std::vector<SP(AttrModify)> mods;
	AttrData data;
	void OnUpdMod();

};
