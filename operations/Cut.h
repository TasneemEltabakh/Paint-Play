#pragma once
#include "operation.h"
#include "..//controller.h"

class Cut : public operation
{
private:

public:
	Cut(controller* pCont);
	virtual ~Cut();
	virtual void Execute();
};