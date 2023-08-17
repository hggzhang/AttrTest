#include "EntityFactory.h"
#include "Entity.h"
#include "AttrComp.h"
#include "Comp.h"


SP(Entity) EntityFactory::GenEntity()
{
    auto ent = std::make_shared<Entity>();

    auto comps =
    {
        std::make_shared<AttrComp>(),
    };

    for (const auto& comp : comps)
    {
        ent->AddComp(comp);
        comp->SetEntity(ent);
    }

    return ent;
}
