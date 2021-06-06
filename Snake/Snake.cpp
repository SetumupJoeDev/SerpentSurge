
#include <conio.h>
#include <iostream>

#include "Helpers.h"
#include "Settings.h"
#include "Snake.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: Snake.cpp						||
//  Purpose: A container for all of the \\
||  snake segments. Handles updating,	||
//	rendering and unrendering all snake \\
||	segments.							||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

Snake::Snake( ) 
: m_snakeHead( m_bodySegments[0] )
{
	//Constructor
	for ( int i = 0; i < m_maxSnakeLength; i++ )
	{
		if ( i & 1 )
		{
			m_bodySegments[i].setColour( Settings::Snake::g_snakeColourOne );
		}
		else
		{
			m_bodySegments[i].setColour( Settings::Snake::g_snakeColourTwo );
		}
	}
	m_lengthIncrease = Settings::Snake::g_snakeLengthModifier;
	resetSnake( );
}

void Snake::checkForCollisions( )
{
	//Checks to see if the snake has hit the outer bounding box of the level. If it has, it is set to be dead.
	if ( m_snakeHead.getVector().m_posX <= m_leftBoundary || m_snakeHead.getVector().m_posX >= m_rightBoundary || m_snakeHead.getVector( ).m_posY <= m_topBoundary || m_snakeHead.getVector().m_posY >= m_bottomBoundary )
	{
		m_isDead = true;
	}
	//Checks to see if the snake head has hit any of the active tail segments. If it has, it is set to dead. 
	for ( int i = 1; i <= m_numSegments; i++ )
	{
		SnakeSegment& currentSegment = m_bodySegments[i];
		if ( m_snakeHead.getVector().m_posX == currentSegment.getVector().m_posX && m_snakeHead.getVector().m_posY == currentSegment.getVector().m_posY )
		{
			m_isDead = true;
		}
	}
	//Checks to see if the snake head has hit the fruit. If it has, the tail length is increased and the snake is set to have collected fruit.
	if ( m_snakeHead.getVector( ).m_posX == m_fruitPosition.m_posX && m_snakeHead.getVector( ).m_posY == m_fruitPosition.m_posY )
	{
		m_numSegments += m_lengthIncrease;
		m_hasCollectedFruit = true;
	}
}

void Snake::checkForInput( )
{
	char m_keyPressed = _getch( );
	//Reads the ascii value of the key pressed and saves it to a local variable
	switch ( m_keyPressed )
	{
	case 'w':
	{
		if ( m_snakeHead.getYVelocity( ) != 1 )
		{
			m_snakeHead.setXVelocity( 0 );						//If the key pressed was UP, the snake's x coordinate increase is set to 0 so that it will only move
			m_snakeHead.setYVelocity( -1 );						//vertically, and its y coordinate increase is set to -1 so that it will move upwards.
			m_isMoving = true;
		}
		break;
	}
	case 's':
	{
		if ( m_snakeHead.getYVelocity( ) != -1 && m_isMoving )
		{
			m_snakeHead.setXVelocity( 0 );						//If the key pressed was DOWN, the snake's x coordinate increase is set to 0 so that it will only move
			m_snakeHead.setYVelocity( 1 );						//vertically, and its y coordinate increase is set to 1 so that it will move downwards.
		}
		break;
	}
	case 'a':
	{
		if ( m_snakeHead.getXVelocity( ) != 1 )
		{
			m_snakeHead.setXVelocity( -1 );						//If the key pressed was LEFT, the snake's y coordinate increase is set to 0 so that it will only move
			m_snakeHead.setYVelocity( 0 );						//horizontally, and its x coordinate increase is set to -1 so that it will move left.
			m_isMoving = true;
		}
		break;
	}
	case 'd':
	{
		if ( m_snakeHead.getXVelocity( ) != -1 )
		{
			m_snakeHead.setXVelocity( 1 );						//If the key pressed was RIGHT, the snake's x coordinate increase is set to 0 so that it will only move
			m_snakeHead.setYVelocity( 0 );						//vertically, and its y coordinate increase is set to -1 so that it will move upwards.
			m_isMoving = true;
		}
		break;
	}
	case 27:
	{
		m_isDead = true;                                       //If the player presses the ESCAPE button, they die so they can return to the main menu
		break;
	}
	}
}

void Snake::unrenderSegments( )
{
	//Un-renders the last segment in the array to avoid leaving a trail
	m_bodySegments[m_numSegments - 1].unrenderChar( );
}

void Snake::renderSegments( )
{
	//Loops through all of the active snake segments and renders them
	for ( int i = 0; i < m_numSegments; i++ )
	{
		m_bodySegments[i].renderChar( );
	}
}

void Snake::resetSnake( )
{
	//Resets the snake's booleans so the game doesn't register them as dead or having collected fruit on loading
	m_isDead = false;
	m_hasCollectedFruit = false;
	//Resets the snake's length to the value assigned in the settings
	m_numSegments = Settings::Snake::g_snakeStartLength;
	//Resets the bool to false so that the tail segments don't move before the snake does
	m_isMoving = false;
	resetPositionAndVelocity( );
}

void Snake::resetPositionAndVelocity( )
{
	//Resets the snake's movement speeds to the base value assigned in the settings
	m_snakeHead.setXVelocity( Settings::Snake::g_snakeStartSpeedX );
	m_snakeHead.setYVelocity( Settings::Snake::g_snakeStartSpeedY );
	m_isMoving = false;
	//Loops through the array and sets each segment's position back to the values assigned in the settings
	for ( int i = 0; i < m_maxSnakeLength; i++ )
	{
		m_bodySegments[i].setPosition( Settings::Snake::g_snakeStartPosX, Settings::Snake::g_snakeStartPosY );
	}
	//Offsets the Y position of each active snake segment by the previous segment's position +1 to prevent all segments from being at the same position
	for ( int i = 0; i < m_numSegments; i++ )
	{
		int newYOffset = i + 1;
		SnakeSegment& currentSegment = m_bodySegments[i];
		currentSegment.setPosition( currentSegment.getVector( ).m_posX, currentSegment.getVector( ).m_posY + newYOffset );
	}
}

void Snake::updateTailSegmentPositions( )
{
	//Loops through all of the snake segments to update their positions
	for ( int i = m_numSegments; i > 0; i-- )
	{
		//Creates a reference to the next segment in the array to get its position more easily
		SnakeSegment& nextSegment = m_bodySegments[i - 1];
		m_bodySegments[i].setVector( nextSegment.getVector( ));
	}
	for ( int i = m_numSegments; i < m_maxSnakeLength; i++ )
	{
		//Sets the position of the remaining segments in the array to that of the last rendered segment, so that when the player collects another
		//fruit, the newly rendered segments are rendered at the end of the snake and not at their spawn point
		if ( m_numSegments > 0 )
		{
			m_bodySegments[i].setVector( m_bodySegments[m_numSegments - 1].getVector( ) );
		}
	}
}

void Snake::update( )
{
	//If the keyboard receives input, the game checks to see if it should have impact on the game
	if ( _kbhit( ) )
	{
		checkForInput( );
	}
	checkForCollisions( );
	if ( m_isMoving )
	{
		updateTailSegmentPositions( );
	}
	m_snakeHead.update( );
	if ( m_numSegments > m_maxSnakeLength )
	{
		m_numSegments = m_maxSnakeLength;
	}
}
