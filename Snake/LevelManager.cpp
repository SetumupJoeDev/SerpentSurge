
#include <iostream>
#include <string>

#include "Helpers.h"
#include "LevelManager.h"
#include "Settings.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: LevelManager.cpp				||
//  Purpose: Handles all of the data	||
//  regarding the game's adventure mode	||
//  levels, as well as progression.		||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

LevelManager::LevelManager( )
{
	m_isLevelComplete = false;
	m_currentLevel = 0;
	m_fruitCollected = 0;
	m_fruitInLevel = Settings::Levels::g_levelFruitCounts[m_currentLevel];
	m_fruitCountPosition.setPosition( 35, 0 );
	m_snake = nullptr;
	m_menuRenderer = nullptr;
	m_scoreManager = nullptr;
	m_enemyManager = nullptr;
}

void LevelManager::renderFruitCounts( )
{
	//Displays the number of fruit the player has collected in the current level, compared to the number required to complete the level
	DrawString( "Fruit Collected: " + std::to_string( m_fruitCollected ) + "/" + std::to_string( m_fruitInLevel ), m_fruitCountPosition );
}

void LevelManager::resetLevels( )
{
	m_isLevelComplete = false;
	m_currentLevel = 0;
	m_fruitCollected = 0;
	m_fruitInLevel = Settings::Levels::g_levelFruitCounts[m_currentLevel];
	m_enemyManager->setActiveEnemies( 2 );
}

void LevelManager::update( )
{
	if ( m_fruitCollected == m_fruitInLevel )
	{
		//Increase the current level by one
		++m_currentLevel;
		m_scoreManager->setCurrentScore( m_scoreManager->getCurrentScore( ) + ( 5 * m_currentLevel ) );
		if ( m_currentLevel < 5 )
		{
			//Gets the number of fruit required to beat the new level from the settings namespace and assigns it as the value of m_fruitInLevel
			m_fruitInLevel = Settings::Levels::g_levelFruitCounts[m_currentLevel];
			//Renders the Level Complete UI
			m_menuRenderer->renderLevelComplete( m_scoreManager->getCurrentScore() );
			//Pauses the flow of the program to wait for player input before continuing to the next level
			system( "pause" );
			//Resets the snake to its origin and resets its velocity so it is not moving when the next level begins
			m_snake->setNumSegments( m_snake->getNumSegments( ) + 2 );
			m_snake->resetPositionAndVelocity( );
			m_enemyManager->setActiveEnemies( m_enemyManager->getActiveEnemies( ) + 2 );
		}
		else
		{
			//Renders the Adventure Complete UI
			m_menuRenderer->renderAdventureComplete( m_scoreManager->getCurrentScore() );
			system( "pause" );
			m_snake->resetSnake( );
			m_scoreManager->compareScores( false );
			m_scoreManager->setCurrentScore( 0 );
		}
		//Resets all of the necessary values to ensure the game can be replayed correctly
		m_isLevelComplete = true;
		m_fruitCollected = 0;
	}
}
