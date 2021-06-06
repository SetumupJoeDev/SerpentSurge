#ifndef FRUIT_H
#define FRUIT_H

#include "CharacterBase.h"
#include "Settings.h"
#include "Snake.h"

class Fruit : public CharacterBase
{
private:
	//Integers
	const int m_topBoundary		= Settings::Boundaries::g_topBoundary;
	const int m_bottomBoundary	= Settings::Fruit::g_yLimit;
	const int m_leftBoundary	= Settings::Boundaries::g_leftBoundary;
	const int m_rightBoundary	= Settings::Fruit::g_yLimit;
	//Objects
	Snake* m_snake;
public:
	//Constructor
	Fruit( );
	//Setters and Getters
	void setSnake( Snake* newSnake ){ m_snake = newSnake; }
	Snake* getSnake(){ return m_snake; }
	//Methods
	void generateNewPosition( );
};

#endif // !FRUIT_H
