#pragma once
#include "operation.h"
class opSetPen :
    public operation
{
public:
	opSetPen(controller* pCont);
	virtual ~opSetPen();
	virtual void Execute();
};