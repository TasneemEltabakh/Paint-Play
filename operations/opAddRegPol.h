#pragma once
#include "operation.h"
class opAddRegPol :  public operation
{
public:
	opAddRegPol(controller* pCont);
	virtual ~opAddRegPol();

	//Add rectangle to the controller
	virtual void Execute();

};