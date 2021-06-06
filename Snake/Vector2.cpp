
#include "Vector2.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: Vector2.cpp					||
//  Purpose: A container for the X and Y||
//  positions of various objects in the ||
//  game.								||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

Vector2::Vector2( )
{
	m_posX = 0;
	m_posY = 0;
}

Vector2::Vector2( int newX, int newY )
{
	m_posX = newX;
	m_posY = newY;
}
