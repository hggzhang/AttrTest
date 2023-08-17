#pragma once
#include "SmartPointerHeader.h"
#include "define.h"

class Entity;

class Modify
{
protected:
	WP(Entity) ent;

public:
	virtual EComp GetCompTy() = 0;
	void SetEntity(const SP(Entity)& in) { ent = in; }
	virtual void Apply(const SP(Entity)& in);
};

