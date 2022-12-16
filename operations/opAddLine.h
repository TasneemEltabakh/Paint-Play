#pragma once



#include "..//operations/operation.h"

//Add Oval operation class
class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add Oval  to the controller
	virtual void Execute();

};

