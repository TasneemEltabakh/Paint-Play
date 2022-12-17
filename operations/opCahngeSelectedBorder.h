#pragma once

#include "operation.h"

class opChangeBorderSelected : public operation
{
public:
	opChangeBorderSelected(controller* pCont);

	virtual void ReadActionParameters();
	virtual void Execute();

};




