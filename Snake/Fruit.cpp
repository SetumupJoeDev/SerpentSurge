
#include <stdlib.h>

#include "Fruit.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: Fruit.cpp						||
//  Purpose: Holds all of the data for 	||
//  the game's fruit. Can generate a new||
//	position for the fruit.				\\
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

Fruit::Fruit( )
{
	m_characterAvatar = Settings::Fruit::g_fruitChar;
	m_textColour	  = Settings::Fruit::g_fruitColour;
	m_snake = nullptr;
}

void Fruit::generateNewPosition( )
{
	//Generates a new set of coordinates for the fruit, within the walled area
	int newX = ( rand( ) % m_rightBoundary ) + 2;
	int newY = ( rand( ) % m_bottomBoundary) + 2;
	m_characterVector.setPosition( newX, newY );
	//Loops through all of the snake segments after the head to check if it has moved onto the snake. Generates new positions until it is no longer on a segment.
	for ( int i = 1; i < m_snake->getNumSegments( ); ++i )
	{
		if ( m_characterVector.m_posX == m_snake->getBodySegments( i ).getVector( ).m_posX && m_characterVector.m_posY == m_snake->getBodySegments( i ).getVector( ).m_posY )
		{
			generateNewPosition( );
		}
	}
}
