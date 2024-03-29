#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <time.h>
#include <cstdlib>

//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	int groupID;
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	virtual bool isHidden() = 0;
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	void setCrntPenWidth(int);
	Point ChangeSize(Point);
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	

	
	virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double n) = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape
	virtual void zoom(double , int, int) = 0;
	virtual void Save(ofstream & outfile) = 0;	//Save the shape parameters to the file //Rghda edit (I remove the comment here)(GUIFile instead of OutFile)
	virtual void Move(int x, int y)=0;  //Rghda added
	virtual void ResizeThisbydrag(Point corner, int  xto,int yto) = 0;
	virtual Point getCenter()=0;
	virtual void setID(int* ) = 0;
	virtual shape* Copy() = 0;
	virtual int* GetID()= 0;
	virtual void SetgroupCenter(Point)=0;
	virtual void scramble(Point p) = 0;
	virtual void hide() = 0;
	virtual void unhide() = 0;
	virtual int returnId() = 0;  //for match
	virtual void setId(int newid)=0;  //for match
	//virtual void unhide() = 0;
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar

	
	virtual string PrintOnTool()=0; //Rghda added
	virtual bool IsShapeExisting(int x, int y) = 0;  //Rghda added

	virtual Point firstxofshape() = 0;  //Rghda added
	virtual shape* GDuplicateShape() = 0;  //Rghda added

	
};

