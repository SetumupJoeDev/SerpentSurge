
#include "EnemyManager.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: EnemyManager.cpp				||
//  Purpose: A container for all of the \\
||  enemies in the game. Handles the	||
//  updating and rendering of them.		||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

EnemyManager::EnemyManager( )
{
	m_activeEnemies = 2;
}

void EnemyManager::assignEnemyVectors( )
{
	for ( int i = 0; i < 10; ++i )
	{
		m_enemyArray[i].setVector( Settings::Enemies::g_enemyPositions[i] );
		m_enemyArray[i].setTargetLocation( 0, Settings::Enemies::g_firstenemyTargets[i] );
		m_enemyArray[i].setTargetLocation( 1, Settings::Enemies::g_secondEnemyTargets[i] );
		m_enemyArray[i].setCurrentTarget( 0 );
	}
}

void EnemyManager::unrenderEnemies( )
{
	//Loops through the array of enemies and un-renders them
	for ( int i = 0; i < m_activeEnemies; ++i )
	{
		m_enemyArray[i].unrenderChar( );
	}
}

void EnemyManager::updateEnemies( Snake& snake )
{
	//Loops through the array of enemies and runs the collision detection and update functions
	for ( int i = 0; i < m_activeEnemies; ++i )
	{
		m_enemyArray[i].detectCollisions( snake );
		m_enemyArray[i].update( );
	}
}

void EnemyManager::renderEnemies( )
{
	//Loops through the array of enemies and renders them in their positions
	for ( int i = 0; i < m_activeEnemies; ++i )
	{
		m_enemyArray[i].renderChar( );
	}
}
