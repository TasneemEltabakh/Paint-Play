
#include "operation.h"

class opChangeFillSelected : public operation
{
public:
	opChangeFillSelected(controller* pCont);

	//Do The copy command
	virtual void ReadActionParameters();
	virtual void Execute();

};




