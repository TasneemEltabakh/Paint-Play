#pragma once
#include "operation.h"

class ZooomIn : public operation
{
public:

	ZooomIn(controller* pCont);
	virtual ~ZooomIn();
	virtual void Execute();


};