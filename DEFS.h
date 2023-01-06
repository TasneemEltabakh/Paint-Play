#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_regularPOLY,      //Draw polygon
	DRAW_IRREPoly,       //draw a irr
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a shape(s)
	MOVE,			//Move a shape(s)
	RESIZE,			//Resize a shape(s)
	ROTATE,	//Rotate a shape(s)
	ZOOMIN,
	ZOOMOUT,
	RESIZEBYDRAG,
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	SELECT,
	selsectcol,
	selectwid,
	selectfill,//Select spacific shape  //Rghda added 
	LOAD,			//Load a graph from a file
	EXIT, //Exit the application	
	GROUP,
	Colour_Palleteop,
	colours,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	DRAW_SQ,
	DRAWOV,
	bord,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,
	TO_Pallete, //Switch interface to Play mode
	FILL_COLOUR,
	BACK,
	SWITCH,
	ADD_IMG,
	///TODO: Add more operation types (if needed)
};

#endif