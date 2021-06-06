#ifndef SNAKESEGMENT_H
#define SNAKESEGMENT_H

#include "CharacterBase.h"

class SnakeSegment : public CharacterBase
{
private:
	//Integers
	int m_xVelocity;
	int m_yVelocity;
public:
	//Constructor
	SnakeSegment( );
	//Setters and Getters
	//X Velocity
	void setXVelocity( int newXVelocity ){ m_xVelocity = newXVelocity; }
	int getXVelocity( ){ return m_xVelocity; }
	//Y Velocity
	void setYVelocity( int newYVelocity ){ m_yVelocity = newYVelocity; }
	int getYVelocity( ){ return m_yVelocity; }
	//Methods
	void updatePosition( int newX, int newY );
	void saveCurrentPosition( );
	virtual void update( ) override;
};

#endif // !SNAKESEGMENT_H
