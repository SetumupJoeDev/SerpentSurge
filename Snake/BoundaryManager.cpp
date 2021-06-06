#include "Helpers.h"
#include "BoundaryManager.h"
#include "Settings.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: BoundaryManager.cpp			||
//  Purpose: Handles the drawing of the	||
//  boundary walls of the game.			||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

BoundaryManager::BoundaryManager( )
{
	//Wall Characters
	m_bottomLeftCorner  = Settings::Boundaries::g_bottomLeftCorner;
	m_bottomRightCorner = Settings::Boundaries::g_bottomRightCorner;
	m_sideWall			= Settings::Boundaries::g_sideWall;
	m_topLeftCorner		= Settings::Boundaries::g_topLeftCorner;
	m_topRightCorner	= Settings::Boundaries::g_topRightCorner;
	m_topWall			= Settings::Boundaries::g_topWall;
	//Level Boundaries
	m_topBoundary		= Settings::Boundaries::g_topBoundary;
	m_bottomBoundary	= Settings::Boundaries::g_bottomBoundary;
	m_leftBoundary		= Settings::Boundaries::g_leftBoundary;
	m_rightBoundary		= Settings::Boundaries::g_rightBoundary;
	//Wall Colours
	m_wallColour		= Settings::Boundaries::g_wallColour;
	//Position of the current wall being drawn
	m_wallPosition.setPosition( 0, 0 );
}

void BoundaryManager::renderCorners( )
{
	//Renders the corners of the wall
	m_wallPosition.setPosition( m_leftBoundary, m_topBoundary );
	DrawChar( m_topLeftCorner, m_wallPosition, m_wallColour );
	m_wallPosition.setPosition( m_rightBoundary, m_topBoundary );
	DrawChar( m_topRightCorner, m_wallPosition, m_wallColour );
	m_wallPosition.setPosition( m_leftBoundary, m_bottomBoundary );
	DrawChar( m_bottomLeftCorner, m_wallPosition, m_wallColour );
	m_wallPosition.setPosition( m_rightBoundary, m_bottomBoundary );
	DrawChar( m_bottomRightCorner, m_wallPosition, m_wallColour );
}
 
void BoundaryManager::renderFloorAndCeiling( )
{
	//Loops through for all of the coordinates along the X axis for the wall boundaries
	for ( int i = m_leftBoundary + 1; i < m_rightBoundary; i++ )
	{
		//Sets the position of the wall based on the value of i and the top and bottom boundaries, and renders a wall at that position
		m_wallPosition.setPosition( i, m_topBoundary );
		DrawChar( m_topWall, m_wallPosition, m_wallColour );
		m_wallPosition.setPosition( i, m_bottomBoundary );
		DrawChar( m_topWall, m_wallPosition, m_wallColour );
	}
}

void BoundaryManager::renderSides( )
{
	//Loops through all the positions in between the top and bottom boundary, starting one down from the top as the ceiling is already drawn elsewhere
	//and stopping short of the floor for the same reason
	for ( int i = m_topBoundary + 1; i < m_bottomBoundary; i++ )
	{
		m_wallPosition.setPosition( m_leftBoundary, i );
		DrawChar( m_sideWall, m_wallPosition, m_wallColour );
		m_wallPosition.setPosition( m_rightBoundary, i );
		DrawChar( m_sideWall, m_wallPosition, m_wallColour );
	}
}

void BoundaryManager::renderBasicWalls( )
{
	renderCorners( );
	renderFloorAndCeiling( );
	renderSides( );
}
