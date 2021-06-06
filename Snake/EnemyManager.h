#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "EnemyBase.h"

class EnemyManager
{
private:
	//Integers
	int m_activeEnemies;
	//Objects
	EnemyBase m_enemyArray[10];
public:
	//Constructor
	EnemyManager( );
	//Setters and Getters
	void setActiveEnemies( int activeEnemies){ m_activeEnemies = activeEnemies; }
	int  getActiveEnemies( ){ return m_activeEnemies; }
	//Methods
	void assignEnemyVectors( );
	void unrenderEnemies( );
	void updateEnemies( Snake& snake );
	void renderEnemies( );
};

#endif // !ENEMYMANAGER_H
