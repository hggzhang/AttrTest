#include <iostream>
#include "AttrComp.h"
#include "SmartPointerHeader.h"
#include "AttrModifyFix.h"
#include "define.h"
#include "AttrBinderLambda.h"
#include "AttrModifyIncByAttr.h"
#include "EntityFactory.h"
#include "AffixFactory.h"
#include "Entity.h"
#include "Attr.h"
#include "Affix.h"

void main()
{
	auto ent = EntityFactory::GenEntity();
	auto comp = std::static_pointer_cast<AttrComp>(ent->GetComp(EComp::Attr));
	auto bind_atk = std::make_shared<AttrBinderLambda>([](const AttrData& data) {std::cout << "attr atk = " << data.final << std::endl; });
	auto bind_def = std::make_shared<AttrBinderLambda>([](const AttrData& data) {std::cout << "attr def = " << data.final << std::endl; });

	comp->AddBinder(EAttr::ATK, bind_atk);
	comp->AddBinder(EAttr::DEF, bind_def);

	// 40�������
	auto affix1 = AffixFactory::GenAffix(1);
	affix1->Apply(ent);

	/*
	* ��׺���Թ����أ��Ի���Χ��
	* -- ��ĵ������Ϊ0����Ĺ���������ԭ����������1.5��
	*/
	auto affix2 = AffixFactory::GenAffix(2);
	affix2->Apply(ent);
}