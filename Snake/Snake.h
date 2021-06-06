#ifndef SNAKE_H
#define SNAKE_H

#include "Settings.h"
#include "SnakeSegment.h"

class Snake
{
private:
	//Booleans
	bool m_isDead;
	bool m_hasCollectedFruit;
	bool m_isMoving;
	//Integers
	int m_numSegments;                       //The number of body segments to render
	int m_lengthIncrease;
	const int m_maxSnakeLength = Settings::Snake::g_maxLength;
	//Constants
	const int m_topBoundary = Settings::Boundaries::g_topBoundary;
	const int m_bottomBoundary = Settings::Boundaries::g_bottomBoundary;
	const int m_leftBoundary = Settings::Boundaries::g_leftBoundary;
	const int m_rightBoundary = Settings::Boundaries::g_rightBoundary;
	//Objects
	SnakeSegment m_bodySegments[Settings::Snake::g_maxLength];
	SnakeSegment& m_snakeHead;
	//Vector2
	Vector2 m_fruitPosition;
public:
	//Constructor
	Snake( );
	//Setters and Getters

	//Methods
	void checkForCollisions( );
	void checkForInput( );
	//Setters and Getters
	//fruitPos
	void setFruitPos( Vector2 fruitPosition ){ m_fruitPosition.setPosition( fruitPosition.m_posX, fruitPosition.m_posY ); }
	Vector2  getFruitPos( ){ return m_fruitPosition; }
	//Segment Array
	SnakeSegment getBodySegments( int segmentIndex ){ return m_bodySegments[segmentIndex]; }
	//Length Increase
	void setLengthIncrease( int newIncrease ){ m_lengthIncrease = newIncrease; }
	int  getLengthIncrease( ){ return m_lengthIncrease; }
	//NumSegments
	void setNumSegments( int newNumSegments ){ m_numSegments = newNumSegments; }
	int getNumSegments( ){ return m_numSegments; }
	//IsDead
	void setIsDead( bool shouldBeDead ){ m_isDead = shouldBeDead; }
	bool getIsDead( ){ return m_isDead; }
	//hasCollectedFruit
	void setCollectedFruit( bool collectedFruit ){ m_hasCollectedFruit = collectedFruit; }
	bool getCollectedFruit( ){ return m_hasCollectedFruit; }
	//Methods
	void unrenderSegments( );
	void renderSegments( );
	void resetSnake( ); 
	void resetPositionAndVelocity( );
	void update( );
	void updateTailSegmentPositions( );
};

#endif // !SNAKE_H
