#pragma once
#include "SmartPointerHeader.h"
#include <map>
#include "define.h"

class Comp;

class Entity
{
public:
	void AddComp(SP(Comp) comp);
	void RemComp(SP(Comp) comp);
	SP(Comp) GetComp(EComp Ty);

	template<class T> 
	std::shared_ptr<T> GetComp(EComp Ty);
private:
	std::map<EComp, SP(Comp)> comps;
};

template<class T>
inline std::shared_ptr<T> Entity::GetComp(EComp Ty)
{
	auto comp = GetComp(Ty);
	return std::dynamic_pointer_cast<T>(comp);
}
