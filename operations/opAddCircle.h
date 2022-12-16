#pragma once


#include "..//operations/operation.h"

//Add Circle operation class
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add rectangle to the controller
	virtual void Execute();

};

