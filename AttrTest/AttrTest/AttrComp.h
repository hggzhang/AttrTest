#pragma once
#include "Comp.h"
#include "SmartPointerHeader.h"
#include "define.h"
#include <map>
#include <vector>

class Attr;

class AttrBinder;

class AttrModify;

class AttrComp :
    public Comp
{
public:
	AttrComp() 
	{
		Init();
	}

	int GetAttrVal(EAttr ty);
	void AddBinder(EAttr ty, SP(AttrBinder) binder);
	void RemBinder(EAttr ty, SP(AttrBinder) binder);

	void AddMod(SP(AttrModify) mod);
	void RemMod(SP(AttrModify) mod);
	void UpdMod(EAttr ty);

	virtual EComp GetTy() override;


private:
	void Init();
	std::map<EAttr, SP(Attr)> attrs;
	SP(Attr) GetAttr(EAttr ty);
};

