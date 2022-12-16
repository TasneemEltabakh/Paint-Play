
#include "operation.h"
class opChangeFill: public operation
{
public:
	string fillchoice;
	opChangeFill(controller* pCont);
	virtual ~opChangeFill();
	virtual void Execute();

};