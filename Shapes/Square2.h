
#include "..//Shapes/Shape.h"
#include "../GUI/GUI.h"

class Square2 : public shape
{
private:
	Point Corner1;
	Point Corner2;
	int side; 
public:
	Square2(Point p1 , Point p2 , GfxInfo shapeGfxInfo);
	virtual ~Square2();
	virtual void Draw(GUI* pUI) const;

	void Save(ofstream& outfile); //Rghda added
	string PrintOnTool();  //Rghda added
	bool IsShapeExisting(int x, int y);  //Rghda added
};

