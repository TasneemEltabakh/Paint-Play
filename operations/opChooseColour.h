#pragma once
#include "operation.h"
class opChooseColour : public operation
{
public:
	opChooseColour(controller* pCont);
	virtual ~opChooseColour();
	virtual void Execute();
};