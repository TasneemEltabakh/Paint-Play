#pragma once
#include "operation.h"
class Resize : public operation
{
public:

	Resize(controller* pCont);
	virtual ~Resize();
	virtual void Execute();

};

