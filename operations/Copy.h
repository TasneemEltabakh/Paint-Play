#pragma once
#include "operation.h"
#include "..//controller.h"

class Copy : public operation
{
private:

public:
	Copy(controller* pCont);
	virtual ~Copy();
	virtual void Execute();
};
