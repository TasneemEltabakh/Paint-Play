#pragma once
#include "operation.h"
#include "..//controller.h"

class opAddImg : public operation
{
private:
	string name;

public:
	opAddImg(controller* pCont);
	virtual ~opAddImg();
	virtual void Execute();
};

