#pragma once
#include "SmartPointerHeader.h"
#include <vector>

class Modify;
class Entity;
class Affix
{
public:
	void Apply(const SP(Entity)& in_ent);
	Affix(std::vector<SP(Modify)>& in) { mods = in; }
protected:
	std::vector<SP(Modify)> mods;
	WP(Entity) ent;
};

