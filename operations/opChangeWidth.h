#pragma once
#include "operation.h"
//Add pen width operation class
class opChangeWidth : public operation
{
public:
	string wchoice;
	//operationType return_;
	opChangeWidth(controller* pCont);
	virtual ~opChangeWidth();

	//Add color palette to the controller
	virtual void Execute();

};