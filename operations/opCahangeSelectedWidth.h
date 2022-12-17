#pragma once

#include "operation.h"

class opChangeSelectedWidth : public operation
{
public:
	opChangeSelectedWidth(controller* pCont);
	virtual void ReadActionParameters();
	virtual void Execute();

};



