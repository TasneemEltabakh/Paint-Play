#pragma once
#include "operation.h"

class ZoomOut : public operation
{
public:

	ZoomOut(controller* pCont);
	virtual ~ZoomOut();
	virtual void Execute();


};