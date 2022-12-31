#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	 //Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY, //Playing mode
		MODE_COLOURS
	};


	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu
		ICON_TRI,
		ICON_SQU,
		ICON_OVAL,
		ICON_REG,
		// nada wed 
		ICON_IRREG,
		ICON_LINE,


		ICON_FILL,
		//TODO: Add more icons names here
		ICON_COLORS,
		ICON_BORD,
		ICON_CUT,
		ICON_COPY,
		ICON_DRAG,
		ICON_ADDIMG,
		ICON_DEL,  //Rghda
		ICON_SELECT,  //Rghda
		ICON_SELECTEDCOL,
		ICON_SELECTEDBOL,
		ICON_SELECTEDFILL,
		ICON_SAVE,
		ICON_LOAD,
		ICON_SWITCH,
		ICON_EXIT,		//Exit icon
		
		DRAW_ICON_COUNT	,	//no. of menu icons ==> This should be the last line in this enum

	};


	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{

		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		ICON_HIDE,
		ICON_UNHIDE,
		ICON_START,
		ICON_REST,
		ICON_Switch,
		PLAY_ICON_COUNT,	//no. of menu icons ==> This should be the last line in this enum

	};
	enum ColourPalette
	{
		ICON_COLOURPallet,
		ICON_BACK
	};

	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu
    	bool IsFilled;
		bool isChanged;
		bool isBorderChanged;
		bool isResized;
		bool isZoomedin;
		bool isZoomedOut;
		bool isshapezoom;
		
		color col;
		
	



	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color OldDrawColor;		//Drawing color
	color OLDFillColor;		//Filling color
	color OLdHighlightColor;
	int OLdwidth;
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;	
	
	Point Origin;
	double scale;
	int* count;//width of the pen that draws shapes
	int* count2;
	int* count3;
	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateColourToolBar();
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo) const;
	void DrawPol( int PointertoarryOFX[],  int PointertoarryOFy[], const int Numberofsides, GfxInfo shapeGfxInfo) const;
	void DrawCircle(Point P1, int radious, GfxInfo CircleGfxInfo) const;  //Draw a Circle
	void DrawSquare(Point P1, Point P2,GfxInfo SquareGfxInfo) const;  //Draw a Square 
	void DrawEllipse(Point P1, Point P2, GfxInfo OvalGfxInfo) const;  //Draw an Oval
	void DrawLine(Point P1, Point P2, GfxInfo OvalGfxInfo) const;  //Draw a line 
	void back();
	void switchtoplay ();
	bool checkfill();
	bool checkborder();
	bool GetIsFilled() ;
	bool GetIsChanged();
	bool Checkresize();
	bool CheckIsResized();
	void AddImg(string name);
	bool DoZoomin();
	bool DoZoomOut();
	bool UnZoomi();
	bool UnZoomo();
	void Zoom(int, int);
	double getLastScale();
	bool checkZoomin();
	bool checkZoomOut();
	bool GetIsFilled() const;
	Point GetOrigin() const;
	///Make similar functions for drawing all other shapes.
    void PrintMessage(string msg) const;	//Print a message on Status bar
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	color GetColour(const int X, const int Y); //choose colour from colour pallete
	
	color getoldDrawColor() const;
	color GetSelectedColour(const int X, const int Y);	//get current drwawing color
	color getoldFillColor() const;	//get current filling color
	int getoldPenWidth() const;
	color FillColour(const int X, const int Y); // fill color 
	color FillselectedColour(const int X, const int Y);
	int setPenWidth(int);
	int setselectedWidth(int wchoice);
	bool checkcol();
	bool GetIscol();
	bool isThisShapezoomed();
	~GUI();
};

