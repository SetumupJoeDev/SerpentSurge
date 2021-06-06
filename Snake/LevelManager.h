#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "EnemyManager.h"
#include "MenuRenderer.h"
#include "ScoreManager.h"
#include "Snake.h"
#include "Vector2.h"

class LevelManager
{

private:
	//Booleans
	bool m_isLevelComplete;
	//Integers
	int m_currentLevel;
	int m_fruitInLevel;
	int m_fruitCollected;
	//Objects
	EnemyManager* m_enemyManager;
	MenuRenderer* m_menuRenderer;
	ScoreManager* m_scoreManager;
	Snake* m_snake;
	//Vectors
	Vector2 m_fruitCountPosition;
public:
	//Constructor
	LevelManager( );
	//Setters and Getters
	//Is level completed
	void setLevelCompleted( bool isCompleted){ m_isLevelComplete = isCompleted; }
	bool getLevelCompleted( ){ return m_isLevelComplete; }
	//Fruit in level
	void setFruitInLevel( int levelFruit){ m_fruitInLevel = levelFruit; }
	int  getFruitInLevel( ){ return m_fruitInLevel; }
	//Fruit Collected
	void setFruitCollected( ){ ++m_fruitCollected; }
	int  getFruitCollected(){ return m_fruitCollected; }
	//Enemy Manager
	void setEnemyManager( EnemyManager* enemyManager ){ m_enemyManager = enemyManager; }
	EnemyManager* getEnemyManager( ){ return m_enemyManager; }
	//Menu Renderer
	void setMenuRenderer( MenuRenderer* menuRenderer ){ m_menuRenderer = menuRenderer; }
	MenuRenderer* getMenuRenderer( ){ return m_menuRenderer; }
	//Score Manager
	void setScoreManager( ScoreManager* scoreManager ){ m_scoreManager = scoreManager; }
	ScoreManager* getScoreManager( ){ return m_scoreManager; }
	//Snake
	void setSnake( Snake* snake ){ m_snake = snake; }
	Snake* getSnake( ){ return m_snake; }
	//Methods
	void renderFruitCounts( );
	void resetLevels( );
	void update( );
};

#endif