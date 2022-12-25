#pragma once
#include "operation.h"
class opStick :
	public operation
{
public:

	opStick(controller* pCont);
	virtual ~opStick();
	virtual void Execute();

};