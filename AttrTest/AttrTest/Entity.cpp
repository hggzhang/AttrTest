#include "Entity.h"
#include "Comp.h"

void Entity::AddComp(SP(Comp) comp)
{
	auto ty = comp->GetTy();
	comps[ty] = comp;
}

void Entity::RemComp(SP(Comp) comp)
{
	auto ty = comp->GetTy();
	comps.erase(ty);
}

SP(Comp) Entity::GetComp(EComp ty)
{
	auto it = comps.find(ty);
	if (it == comps.end())
		return nullptr;
	else
		return it->second;
}


