#pragma once
#include "SmartPointerHeader.h"
#include "define.h"

class Entity;

class Comp
{
public:
	void SetEntity(SP(Entity) in) { ent = in; }
	virtual EComp GetTy() = 0;
protected:
	WP(Entity) ent;
};

