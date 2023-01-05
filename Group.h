#pragma once
#include "operation.h"
class Group : operation
{
public:

	Group(controller* pCont);
	virtual ~Group();
	virtual void Execute();

};