#include "Groupshape.h"

groupshape::groupshape(vector<shape*> selec, GfxInfo Groupinfo, int number) : shape(Groupinfo)
{
	
	for (int i = 0; i < number; i++)
	{
		group.push_back(selec[i]);
	}
}
groupshape:: ~groupshape()
{}



void groupshape::Resize(double n)
{
	
}
void groupshape::Rotate()
{}
void groupshape::zoom(double s, int x, int y)
{
	

}
void groupshape::ResizeThisbydrag(Point corner, int  xto, int yto)
{



}
void groupshape::Move(int x, int y) {   //Rghda Salah

}
void groupshape::Draw(GUI* pUI) const
{

}
void groupshape::Save(ofstream& outfile) {  //Rghda added
}
string groupshape::PrintOnTool()
{
	return " ";
}

bool groupshape::IsShapeExisting(int x, int y)
{
	
	
		return true;
	
}