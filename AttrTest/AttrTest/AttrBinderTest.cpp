#include "AttrBinderLambda.h"
#include <iostream>
void AttrBinderLambda::Notify(const AttrData& data)
{
	lambda(data);
}
