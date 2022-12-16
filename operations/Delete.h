
#pragma once
#ifndef ADD_DELETE_ACTION_H
#define ADD_DELETE_ACTION_H

#include "operation.h"

class Delete : public operation
{
public:
	Delete(controller* pCont);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif


