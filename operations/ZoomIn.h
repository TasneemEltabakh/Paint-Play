#pragma once
#include "operation.h"

class ZoomIn : public operation
{
public:

	ZoomIn(controller* pCont);
	virtual ~ZoomIn();
	virtual void Execute();


};