#pragma once
#include "operation.h"

class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();

	//Add Triangle to the controller
	virtual void Execute();

};

