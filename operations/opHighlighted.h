#pragma once
#pragma once
#include "..//operations/operation.h"

class opHighlighted : public operation
{
public:
	opHighlighted(controller* pCont);
	virtual ~opHighlighted();
	virtual void Execute();
};
