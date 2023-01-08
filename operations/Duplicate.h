#pragma once
#include "operation.h"
#include "..//controller.h"

class Duplicate : public operation
{
private:

public:
	Duplicate (controller* pCont);
	virtual ~Duplicate();
	virtual void Execute();
};

