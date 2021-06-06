
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Game.h"
#include "Helpers.h"
#include "Settings.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: Game.cpp						||
//  Purpose: Runs all of the basic game	||
//  logic.								||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

Game::Game( )
{
	m_currentGameState = GameStates::mainMenu;
	m_currentMenuOption = MenuOptions::playClassic;
	m_fruitScoreIncrease = Settings::Game::g_fruitScoreIncrease;
	m_sleepTimer = Settings::Game::g_sleepTimer;
	//Sets this boolean to false so that the walls will be rendered
	m_hasRenderedWalls = false;
	//Sets the position of the score text
	m_currentScorePosition.setPosition( 25, 0 );
	//Plays the main menu music
	m_musicManager.playMainMenuMusic( );
	//Sets this boolean to true so that the game will continue to run until the player quits
	m_stillPlaying = true;
	m_enemyManager.assignEnemyVectors( );
	m_levelManager.setMenuRenderer( &m_menuRenderer );
	m_levelManager.setSnake( &m_snake );
	m_levelManager.setEnemyManager( &m_enemyManager );
	m_levelManager.setScoreManager( &m_scoreManager );
	m_fruit.setSnake( &m_snake );
	m_fruit.generateNewPosition( );
	//Passes the position of the fruit into the Snake so it can detect collisions
	m_snake.setFruitPos( m_fruit.getVector( ) );
}

void Game::renderMainMenu( )
{
	//Prints some welcome text to inform the player how to proceed
	m_menuRenderer.renderMainMenu( );
	renderHighScore( m_currentMenuOption );
	//If the game detects keyboard input, it checks what key was pressed
	if ( _kbhit( ) )
	{
		//Checks to see what key was pressed
		char inputChar = _getch( );
		int asciiCode = static_cast< int >( inputChar );
		switch ( asciiCode )
		{
		case 72:
		{
			//If the UP arrow was pressed, and the current menu option is not the top one, the menu selection moves up
			if ( ( int ) m_currentMenuOption > 0 )
			{
				int optionInt = static_cast< int >( m_currentMenuOption ) - 1;
				m_currentMenuOption = (MenuOptions)optionInt;
				m_menuRenderer.setCurrentOption( optionInt );
				m_menuRenderer.renderMainMenu( );
			}
			break;
		}
		case 80:
		{
			//If the DOWN arrow was pressed, and the current menu option is not the bottom one, the menu selection moves down
			if ( ( int ) m_currentMenuOption < 3 )
			{
				int optionInt = static_cast< int >( m_currentMenuOption ) + 1;
				m_currentMenuOption = ( MenuOptions ) optionInt;
				m_menuRenderer.setCurrentOption( optionInt );
				m_menuRenderer.renderMainMenu( );
			}
			break;
		}
		case 13:
		{
			//Checks to see which menu option is currently selected and acts accordingly
			switch ( m_currentMenuOption )
			{
			case Game::MenuOptions::playClassic:
			{
				//Sets the current game type to be classic mode
				m_currentGameState = GameStates::playingClassic;
				//Clears all text from the screen
				system( "cls" );
				//The game's background music is played
				m_musicManager.playGameMusic( true );
				m_snake.setLengthIncrease( Settings::Snake::g_snakeLengthModifier );

				break;
			}
			case Game::MenuOptions::playAdventure:
			{
				//Sets the current game type to be adventure mode
				m_currentGameState = GameStates::playingAdventure;
				//Clears all the text from the screen
				system( "cls" );
				//Plays the adventure mode theme music
				m_musicManager.playGameMusic( false );
				m_snake.setLengthIncrease( 0 );
				break;
			}
			case Game::MenuOptions::clearHighScore:
			{
				//Resets the saved high score to 0
				m_scoreManager.writeHighScore( true , 0 );
				m_scoreManager.writeHighScore( false, 0 );
				m_scoreManager.readHighScore( );
				renderHighScore( m_currentMenuOption );
				break;
			}
			case Game::MenuOptions::quitGame:
			{
				//Closes the game
				m_stillPlaying = false;
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
}

void Game::renderScore( )
{
	DrawString( "Score: " + std::to_string(m_scoreManager.getCurrentScore()), m_currentScorePosition, 15 );
}

void Game::renderHighScore( MenuOptions currentOption )
{
	//Renders the high score in the relevant position on screen
	m_currentTextPosition.setPosition( 45, 12 );
	//If the menu option is to play Classic Mode, the high score for Classic mode is displayed
	if ( currentOption == MenuOptions::playClassic )
	{
		DrawString( "High Score: " + std::to_string( m_scoreManager.getClassicHighScore( ) ), m_currentTextPosition );
	}
	//If the menu option is to play Adventure Mode, the high score for Adventure mode is displayed
	else if ( currentOption == MenuOptions::playAdventure )
	{
		DrawString( "High Score: " + std::to_string( m_scoreManager.getAdventureHighScore( ) ), m_currentTextPosition );
	}
}

void Game::runAdventureMode( )
{
	if ( !m_hasRenderedWalls )
	{
		m_boundaryManager.renderBasicWalls( );
		m_hasRenderedWalls = true;
	}
	//Unrenders the snake, before updating its position and rendering it again
	m_snake.unrenderSegments( );
	m_snake.update( );
	m_snake.renderSegments( );
	//Unrenders all of the active enemies, before updating them and rendering them again
	m_enemyManager.unrenderEnemies( );
	m_enemyManager.updateEnemies( m_snake );
	m_enemyManager.renderEnemies( );
	//Unrenders and then renders the fruit, so that any changes in its position are reflected when it renders
	m_fruit.unrenderChar( );
	m_fruit.renderChar( );
	//Displays the current fruit collected, and the total fruit in the level
	m_levelManager.update( );
	m_levelManager.renderFruitCounts( );
	checkHasCompletedLevel( );
}

void Game::runClassicMode( )
{
	if ( !m_hasRenderedWalls )
	{
		//Renders the walls
		m_boundaryManager.renderBasicWalls( );
		m_hasRenderedWalls = true;
	}
	//Un-renders the snake from the console
	m_snake.unrenderSegments( );
	//Runs the Snake's update function to move it around the play area, and update its tail segments
	m_snake.update( );
	//Renders the snake in the console
	m_snake.renderSegments( );
	//Draws the fruit in the console
	m_fruit.unrenderChar( );
	m_fruit.renderChar( );
	m_scoreManager.displayScores( );
}

void Game::renderGameOver( )
{
	int playerScore = m_scoreManager.getCurrentScore( );
	m_menuRenderer.renderGameOver( playerScore );
	//Displays text on the screen to inform the player of how to proceed
	//If the game detects keyboard input, the player is returned to the main menu
	if ( _kbhit( ) )
	{
		m_currentGameState = GameStates::mainMenu;
		m_musicManager.playMainMenuMusic( );
		m_scoreManager.setCurrentScore( 0 );
		//Discards the input from the buffer to prevent future input flags
		char dumpChar = _getch( );
		//Clears all text from the screen
		system( "cls" );
	}
}

void Game::checkHasCollectedFruit( )
{
	if ( m_snake.getCollectedFruit( ) )
	{
		switch ( m_currentGameState )
		{
		case GameStates::playingClassic:
		{
			m_scoreManager.setCurrentScore( m_scoreManager.getCurrentScore( ) + 10 );
			break;
		}
		case GameStates::playingAdventure:
		{
			m_levelManager.setFruitCollected( );
			m_scoreManager.setCurrentScore( m_scoreManager.getCurrentScore( ) + 15 );
			break;
		}
		default:
			std::cout << "Something has gone wrong. Please contact your nearest programmer.";
			break;
		}
		std::cout << '\a';
		m_fruit.generateNewPosition( );
		//Passes the new position of the fruit to the snake, so that it can detect when the snake head has collided with it
		m_snake.setFruitPos( m_fruit.getVector( ) );
		m_snake.setCollectedFruit( false );
	}
}

void Game::checkHasCompletedLevel( )
{
	if ( m_levelManager.getLevelCompleted( ) )
	{
		system( "cls" );
		m_hasRenderedWalls = false;
		m_levelManager.setLevelCompleted( false );
	}
}

void Game::checkHasDied( )
{
	//Checks to see if the snake has died. If it has, the following code is executed.
	if ( m_snake.getIsDead( ) )
	{
		//The game compares the player's score to the high score, dependent on the current game mode
		if ( m_currentGameState == GameStates::playingClassic )
		{
			m_scoreManager.compareScores( true );
		}
		else
		{
			m_scoreManager.compareScores( false );
			//Resets the positions of all of the enemies in the adventure mode
			m_enemyManager.assignEnemyVectors( );
		}
		//Sets the GameState to deathScreen, so that the game over screen is displayed
		m_currentGameState = GameStates::deathScreen;
		m_musicManager.playDeathMusic( );
		//Resets the handle colour to white to prevent strange colour bugs from occurring
		ChangeHandleColour( );
		//Resets all of the snake's attributes
		m_snake.resetSnake( );
		m_hasRenderedWalls = false;
		m_levelManager.resetLevels( );
	}
}

void Game::mainLoop( )
{
	while ( m_stillPlaying )
	{
		switch ( m_currentGameState )
		{
			case GameStates::mainMenu:
			{
				//Clears all text from the screen
				system( "cls" );
				renderMainMenu( );
				break;
			}
			case GameStates::playingClassic:
			{
				runClassicMode( );
				checkHasDied( );
				checkHasCollectedFruit( );
				break;
			}
			case GameStates::playingAdventure:
			{
				runAdventureMode( );
				checkHasDied( );
				checkHasCollectedFruit( );
				break;
			}
			case GameStates::deathScreen:
			{
				//Clears all text from the screen
				system( "cls" );
				renderGameOver( );
				break;
			}
		}
		Sleep( m_sleepTimer );
	}
}
