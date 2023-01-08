#pragma once
#include "operation.h"
#include "..//Shapes/Shape.h"
#include <vector> 

class UnHide : public operation
{
public:

	UnHide(controller* pCont);
	virtual ~UnHide();
	virtual void Execute();

};