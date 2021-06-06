
#include <iostream>
#include <Windows.h>

#include "Helpers.h"
#include "Vector2.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: Helpers.cpp					||
//  Purpose: Contains various useful	||
//  functions used in the game without	||
//  being confined to a class.			||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

void GoToXY( Vector2 vector2 )
{
	HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
	COORD position = { ( SHORT ) vector2.m_posX, ( SHORT ) vector2.m_posY };
	//Sets the position of the cursor in the console to the x and y values passed through in the method's arguments
	SetConsoleCursorPosition( hStdout, position );
}

void ChangeHandleColour( int colourInt )
{
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( handle, colourInt );
}

void DrawChar( char c, Vector2 vector2, int colourInt )
{
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	//Sets the colour of the text to that passed through in the parameters
	SetConsoleTextAttribute( handle, colourInt );
	//Moves the cursor to the x and y coordinates passed through in the method's arguments
	GoToXY( vector2 );
	//Draws the character defined in the method's arguments at the X and Y coordinates defined in the method's arguments
	std::cout << c;
}

void DrawString( std::string textToRender, Vector2 vector2, int colourInt )
{
	HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
	//Sets the colour of the text that will be rendered
	SetConsoleTextAttribute( handle, colourInt );
	//Moves the cursor to the position of the vector2
	GoToXY( vector2 );
	//Renders the text on screen
	std::cout << textToRender;
}
