#pragma once
#include "operation.h"
class opSwitchTodraw2:
	public operation
{
public:
	opSwitchTodraw2(controller* pCont);
	virtual ~opSwitchTodraw2();
	virtual void Execute();

};