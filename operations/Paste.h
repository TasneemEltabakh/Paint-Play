#include "operation.h"
#include "..//controller.h"
#include <iostream>
using namespace std;

class Paste : public operation
{
private:

public:
	Paste(controller* pCont);
	virtual ~Paste();
	virtual void Execute();
};
