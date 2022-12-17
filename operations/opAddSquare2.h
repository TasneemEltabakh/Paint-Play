#pragma once




#include "..//operations/operation.h"


//Add Square operation class
class opAddSquare2 : public operation
{
public:
	opAddSquare2(controller* pCont);
	virtual ~opAddSquare2();

	//Add Square to the controller
	virtual void Execute();

};


