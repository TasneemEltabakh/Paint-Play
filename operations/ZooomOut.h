#pragma once
#include "operation.h"
class ZooomOut : public operation
{
public:

	ZooomOut(controller* pCont);
	virtual ~ZooomOut();
	virtual void Execute();


};