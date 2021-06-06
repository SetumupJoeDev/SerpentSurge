#ifndef GAME_H
#define GAME_H

#include <fstream>

#include "BoundaryManager.h"
#include "EnemyManager.h"
#include "Fruit.h"
#include "LevelManager.h"
#include "MenuRenderer.h"
#include "MusicManager.h"
#include "ScoreManager.h"
#include "Snake.h"
#include "Vector2.h"

class Game
{
	//Variables
private:
	//Booleans
	bool m_hasRenderedWalls;
	bool m_stillPlaying;
	//Enums
	enum class GameStates{mainMenu, playingClassic, playingAdventure, deathScreen };
	enum class MenuOptions{playClassic, playAdventure, clearHighScore, quitGame };
	enum GameStates m_currentGameState;
	enum MenuOptions m_currentMenuOption;
	//Integers
	int m_fruitScoreIncrease;
	int m_sleepTimer;
	//Objects
	BoundaryManager m_boundaryManager;
	EnemyManager m_enemyManager;
	Fruit m_fruit;
	LevelManager m_levelManager;
	ScoreManager m_scoreManager;
	Snake m_snake;
	MenuRenderer m_menuRenderer;
	MusicManager m_musicManager;
	//Vectors
	Vector2 m_currentScorePosition;
	Vector2 m_currentTextPosition;
	//Methods
public:
	//Constructor
	Game( );
	//Setters and getters

	//Methods
	void checkHasCollectedFruit( );
	void checkHasDied( );
	void checkHasCompletedLevel( );
	void mainLoop( );
	void renderMainMenu( );
	void runAdventureMode( );
	void runClassicMode( );
	void renderGameOver( );
	void renderScore( );
	void renderHighScore( MenuOptions currentOption );
};

#endif
