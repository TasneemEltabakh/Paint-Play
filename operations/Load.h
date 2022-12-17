#pragma once
#include "operation.h"
#include "..//controller.h"

class opLoad : public operation
{
private:
	string name;
	ifstream inputfile;

public:
	opLoad(controller* pCont);
	virtual ~opLoad();
	virtual void Execute();
};
