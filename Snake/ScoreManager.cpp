
#include <string>

#include "Helpers.h"
#include "ScoreManager.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: ScoreManager.cpp				||
//  Purpose: Handles all of the reading	||
//  , writing and assignment of player	||
//  scores during gameplay.				||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

ScoreManager::ScoreManager( )
{
	m_currentScore = 0;
	m_classicModeHighScore = 0;
	m_adventureModeHighScore = 0;
	m_classicModeScoreFile = "HighScoreClassic.txt";
	m_adventureModeScoreFile = "HighScoreAdventure.txt";
	readHighScore( );
	m_scorePosition.setPosition( 35, 0 );
	m_highScorePosition.setPosition( 50, 0 );
}

void ScoreManager::readHighScore( )
{
	//Reads the contents of the high score file and assigns its value to m_highScore
	m_highScoreFileRead.open( m_classicModeScoreFile );
	m_highScoreFileRead >> m_classicModeHighScore;
	m_highScoreFileRead.close( );
	m_highScoreFileRead.open( m_adventureModeScoreFile );
	m_highScoreFileRead >> m_adventureModeHighScore;
	m_highScoreFileRead.close( );
}

void ScoreManager::writeHighScore( bool isClassicMode, int newHighScore )
{
	//Writes the value of newHighScore to the high score file
	if ( isClassicMode )
	{
		m_highScoreFileWrite.open( m_classicModeScoreFile );
	}
	else
	{
		m_highScoreFileWrite.open( m_adventureModeScoreFile );

	}
	m_highScoreFileWrite << newHighScore;
	m_highScoreFileWrite.close( );
}

void ScoreManager::displayScores( )
{
	//Displays the score and high score on screen
	DrawString( "Score: " + std::to_string( m_currentScore ), m_scorePosition );
	DrawString( "High Score: " + std::to_string( m_classicModeHighScore ), m_highScorePosition );
}

void ScoreManager::compareScores( bool isClassicMode )
{
	//Compares the current score to the high score of the current game mode. If it is higher, it overwrites the old high score
	if ( isClassicMode )
	{
		if ( m_currentScore > m_classicModeHighScore )
		{
			writeHighScore( true, m_currentScore );
			readHighScore( );
		}
	}
	else
	{
		if ( m_currentScore > m_adventureModeHighScore )
		{
			writeHighScore( false, m_currentScore );
			readHighScore( );
		}
	}
}
