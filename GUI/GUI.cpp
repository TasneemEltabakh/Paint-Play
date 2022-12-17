#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 55;
	MenuIconWidth = 60;

	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames
	IsFilled=false;
	isChanged = false;

	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}



//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;

	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_EXIT: return EXIT;
			case ICON_TRI: return DRAW_TRI;
			case ICON_REG: return DRAW_regularPOLY;
			case ICON_COLORS :return TO_Pallete;
			case ICON_FILL: return FILL_COLOUR;
			case ICON_IRREG: return DRAW_IRREPoly;
			case ICON_LINE: return DRAW_LINE;
			case ICON_OVAL: return DRAWOV;
			case ICON_SQU: return DRAW_SQ;
			case ICON_SAVE: return SAVE;  //Rghda added
			case ICON_SELECT: return SELECT;  //Rghda added
			case ICON_DEL: return DEL;  //Rghda added
			case ICON_LOAD:return LOAD;
			case ICON_ADDIMG: return ADD_IMG;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

	if (InterfaceMode == MODE_COLOURS)	//GUI in the colouroallete mode
		{
			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < ToolBarHeight)
			{

				int ClickedIconOrder = (x / MenuIconWidth);


				switch (ClickedIconOrder)
				{
				case ICON_COLOURPallet: return colours;
				case ICON_BACK: return BACK;
				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}
		//[2] User clicks on the drawing area
		if (y >= 0 && y < ToolBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		return TO_PLAY;	//just for now. This should be updated
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{

	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar()
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\rectangle.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\circle.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\line.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\triangle.jpg";
	MenuIconImages[ICON_SQU] = "images\\MenuIcons\\square.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\oval.jpg";
	MenuIconImages[ICON_REG] = "images\\MenuIcons\\hexagon.jpg";
	MenuIconImages[ICON_IRREG] = "images\\MenuIcons\\irregular.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\exit.jpg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\cut.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\copy.jpg";
	MenuIconImages[ICON_DRAG] = "images\\MenuIcons\\drag.jpg";
	MenuIconImages[ICON_ADDIMG] = "images\\MenuIcons\\image.jpg";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\delete.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\fill.jpg";
	MenuIconImages[ICON_COLORS] = "images\\MenuIcons\\pencil.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\save.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\select.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\load.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\switch.jpg";
	
	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i <( DRAW_ICON_COUNT); i++)
		pWind->DrawImage(MenuIconImages[i], i * (MenuIconWidth), 7, MenuIconWidth, ToolBarHeight);
	



	//Draw a line under the toolbar
	pWind->SetPen(PLUM, 2);
	pWind->DrawLine(0, ToolBarHeight + 14, width, ToolBarHeight + 14);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void  GUI::CreateColourToolBar()
{
	InterfaceMode = MODE_COLOURS;
	ClearStatusBar();	//First clear the status bar
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_COLOURPallet] = "images\\MenuIcons\\drawtoolbar.jpg";
	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawImage(MenuIconImages[ICON_COLOURPallet], 1 , height - (int)(1.25* StatusBarHeight), 1285,100) ;

}

void  GUI::back()
{
	InterfaceMode =MODE_DRAW;
	CreateDrawToolBar();

}
void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::AddImg(string s) {

	int MenuIconWidthpallete = 100;
	int drawheight = 100;
	int MenuIconW = 80;

	pWind->DrawImage("images\\MenuIcons\\" + s + ".jpg", 10, 30, 100, 900);
	pWind->SetPen(RED, 3);
}

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const
{
	color DrawingClr;
	if (TriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

} 
void GUI:: DrawPol(const int PointertoarryOFX[], const int PointertoarryOFy[], const int Numberofsides, GfxInfo shapeGfxInfo) const
{
	
	color DrawingClr;
	if (shapeGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = shapeGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, shapeGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (shapeGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(shapeGfxInfo.FillClr);
	}
	else

		style = FRAME;
	pWind->DrawPolygon(PointertoarryOFX,PointertoarryOFy, Numberofsides ,style);

}
// Circle //

void GUI::DrawCircle(Point P1, int radious, GfxInfo CircleGfxInfo) const
{
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, radious, style);


}
// square 
void GUI:: DrawSquare(const int array1[], const int array2[], GfxInfo SquareGfxInfo) const //Draw a Square 
{
	
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(array1,array2,4,style);

}

// Oval
void GUI::DrawEllipse(Point P1, Point	P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x,P2.y, style);


}
// line 
void GUI::DrawLine(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);


}



color GUI::GetColour(const int X, const int Y)
{
	DrawColor= pWind->GetColor(X, Y);
	return DrawColor;
}
bool GUI::checkfill()
{
	return IsFilled;
}
bool GUI::checkborder()
{
	
	return isChanged;
}

bool GUI::GetIsFilled() 
{

	IsFilled = true;
	return IsFilled;
}
bool GUI::GetIsChanged()
{
	isChanged = true;
	return isChanged;
}

color GUI::FillColour(const int X, const int Y)
{
	FillColor = pWind->GetColor(X, Y);
	return FillColor;
}


// a trial to make  coleur 

int GUI:: setPenWidth(int wchoice) 		//set current pen width
{
	
	if (wchoice == 1)
	{
		PenWidth=1;
	}
	else if (wchoice == 2)
	{
		PenWidth = 4;
	}
	else if (wchoice == 3)
	{
		PenWidth = 7;
	}
	else if (wchoice == 4)
	{
		PenWidth = 10;
	}

	else if (wchoice == 5)
	{
		PenWidth = 13;
	}
	else if (wchoice == 6)
	{
		PenWidth = 18;
	}
	else if (wchoice == 7)
	{
		PenWidth = 25;
	}
	else
	{
		PrintMessage("Unsupported Operation");
	}
	return PenWidth;
}




//////////////////////////////////////////////////////////////////////////////////////////
GUI :: ~GUI()
{
	delete pWind;
}


