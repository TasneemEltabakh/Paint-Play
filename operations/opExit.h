#pragma once
#include "operation.h"
class opExit :
    public operation
{
public:

 	opExit(controller* pCont);
	virtual ~opExit();
	virtual window CreateWind(GUI* pUI) const;
	virtual void Execute();

};

