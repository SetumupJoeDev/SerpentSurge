#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
private:

public:
	//Integers
	int m_posX;
	int m_posY;
	//Constructor
	Vector2( );
	Vector2( int newX, int newY );
	void setPosition( int newX, int newY ){ m_posX = newX, m_posY = newY; }
};

#endif // !VECTOR2_H
