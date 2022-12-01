#pragma once
#include "operation.h"
class opAddirrPol :
    public operation
{

public:

	opAddirrPol(controller* pCont);
	virtual ~opAddirrPol();


	virtual void Execute();
};

