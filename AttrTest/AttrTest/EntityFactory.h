#pragma once
#include "SmartPointerHeader.h"

class Entity;

class EntityFactory
{
public:
	static SP(Entity) GenEntity();
};

