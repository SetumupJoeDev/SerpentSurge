
#include <iostream>

#include "EnemyBase.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: EnemyBase.cpp					 ||
//  Purpose: The base class of the game's||
//  enemies. Handles their movement and	 ||
//  rendering.							 ||
//	Author: James Smale					 \\
//	Project: SERPENT SURGE				 \\
||	Language: C++						 ||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

EnemyBase::EnemyBase( )
{
	m_characterAvatar = static_cast< char >( 177 );
	m_targetIndex = 0;
	m_currentTarget = m_targetLocations[m_targetIndex];
	m_textColour = 12;
}

void EnemyBase::detectCollisions( Snake& snake )
{
	//Loops through all of the active snake segments and checks to see if they are colliding with this object
	for ( int i = 0; i < snake.getNumSegments( ); i++ )
	{
		if ( m_characterVector.m_posX == snake.getBodySegments( i ).getVector( ).m_posX && m_characterVector.m_posY == snake.getBodySegments( i ).getVector( ).m_posY )
		{
			//If they are, the snake is killed
			snake.setIsDead( true );
		}
	}
}

void EnemyBase::update( )
{
	//If the enemy has reached its target vector, its target is changed to the next in the array
	if ( m_characterVector.m_posX == m_currentTarget.m_posX && m_characterVector.m_posY == m_currentTarget.m_posY )
	{
		++m_targetIndex;
		if ( m_targetIndex >= m_numTargets )
		{
			m_targetIndex = 0;
		}
		m_currentTarget = m_targetLocations[m_targetIndex];
	}
	//If the enemy is not at their destination, they move towards it by 1 position each update
	else
	{
		if ( m_characterVector.m_posX < m_currentTarget.m_posX )
		{
			++m_characterVector.m_posX;
		}
		else if ( m_characterVector.m_posX > m_currentTarget.m_posX )
		{
			--m_characterVector.m_posX;
		}
		if ( m_characterVector.m_posY < m_currentTarget.m_posY )
		{
			++m_characterVector.m_posY;
		}
		else if ( m_characterVector.m_posY > m_currentTarget.m_posY )
		{
			--m_characterVector.m_posY;
		}
	}
}
