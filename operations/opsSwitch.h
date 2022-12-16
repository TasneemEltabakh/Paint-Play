#pragma once
#include "operation.h"
class opsSwitch:
	public operation
{
public:
	opsSwitch(controller* pCont);
	virtual ~opsSwitch();
	virtual void Execute();

};

