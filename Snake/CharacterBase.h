#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H

#include "Vector2.h"

class CharacterBase
{
	//Variables
protected:
	//Characters
	char m_characterAvatar;
	//Integers
	int m_textColour;
	int m_backgroundColour;
	//Vector2
	Vector2 m_characterVector;
public:
	//Constructor
	CharacterBase();
	//Setters and Getters
	//Character Avatar
	void setCharacterAvatar( char newAvatar ){ m_characterAvatar = newAvatar; }
	char getCharacterAvatar( ){ return m_characterAvatar; }
	//Colour
	void setColour( int newColour ){ m_textColour = newColour; }
	//Vector2
	void setVector( Vector2 newVector ){ m_characterVector = newVector; }
	void setPosition( int newX, int newY ){ m_characterVector.setPosition(newX, newY); }
	Vector2 getVector( ){ return m_characterVector; }
	//Methods
	virtual void update( );
	virtual void unrenderChar( );
	virtual void renderChar( );
};

#endif