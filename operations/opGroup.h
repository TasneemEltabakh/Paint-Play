#pragma once
#include "operation.h"
#include "..//Shapes/Shape.h"
#include <vector> 
class opGroup : public operation
{
public:

	opGroup(controller* pCont);
	virtual ~opGroup();
	virtual void Execute();
	
};