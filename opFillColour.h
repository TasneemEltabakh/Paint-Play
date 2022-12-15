#pragma once
#pragma once
#include "../Paint-Play/operations/operation.h"
class opFillColour : public operation
{
public:
	opFillColour(controller* pCont);
	virtual ~opFillColour();
	virtual void Execute();
};
