
#include "MusicManager.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: MusicManager.cpp				||
//  Purpose: Handles the different music||
//  tracks played throughout the game.	||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

MusicManager::MusicManager()
{
	m_mainMenuMusic = TEXT( "MainMenuTheme.wav" );
	m_classicModeMusic = TEXT( "ClassicModeTheme.wav" );
	m_adventureModeMusic = TEXT( "AdventureModeTheme.wav" );
	m_deathMusic = TEXT( "DeathSound.wav" );
}

void MusicManager::playMainMenuMusic( )
{
	PlaySound( m_mainMenuMusic, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP );
}

void MusicManager::playGameMusic( bool isClassic )
{
	if ( isClassic )
	{
		PlaySound( m_classicModeMusic, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP );
	}
	else
	{
		PlaySound( m_adventureModeMusic, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP );
	}
}

void MusicManager::playDeathMusic( )
{
	PlaySound( m_deathMusic, NULL, SND_ASYNC | SND_FILENAME );
}
