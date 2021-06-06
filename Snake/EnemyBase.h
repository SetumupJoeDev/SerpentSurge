#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include "CharacterBase.h"
#include "Snake.h"

class EnemyBase : public CharacterBase
{
private:
	//Integers
	static const int m_numTargets = 2;
	int m_targetIndex;
	//Vectors
	Vector2 m_currentTarget;
	Vector2 m_targetLocations[m_numTargets];
public:
	//Constructor
	EnemyBase( );
	//Setters and Getters
	//Target Location
	void setTargetLocation( int arrayIndex, Vector2 newVector ){ m_targetLocations[arrayIndex] = newVector; }
	Vector2 getTargetLocations( int arrayIndex ){ return m_targetLocations[arrayIndex]; }
	//Current Target
	void setCurrentTarget( int arrayIndex ){ m_currentTarget = m_targetLocations[arrayIndex]; }
	Vector2 getCurrentTarget( ){ return m_currentTarget; }

	void detectCollisions( Snake& snake );

	virtual void update( ) override;
};

#endif