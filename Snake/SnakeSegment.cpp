
#include "SnakeSegment.h"
#include "Settings.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: SnakeSegment.cpp				||
//  Purpose: A segment of the player's  \\
||	snake. Hold positional data, as well||
//	as a character avatar and colour.	\\
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

SnakeSegment::SnakeSegment( )
{
	m_characterAvatar = Settings::Snake::g_snakeChar;
	m_characterVector.setPosition( Settings::Snake::g_snakeStartPosX, Settings::Snake::g_snakeStartPosY );
	m_textColour = Settings::Snake::g_snakeColourOne;
	m_xVelocity = 0;
	m_yVelocity = 0;
}

void SnakeSegment::update( )
{
	//Moves the segment by increasing its X or Y position by the value of xVelocity and yVelocity
	m_characterVector.setPosition( m_characterVector.m_posX + m_xVelocity, m_characterVector.m_posY + m_yVelocity );
}
