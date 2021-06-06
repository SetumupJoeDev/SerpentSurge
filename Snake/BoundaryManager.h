#ifndef BOUNDARYMANAGER_H
#define BOUNDARYMANAGER_H

#include "Vector2.h"

class BoundaryManager
{
private:
	//Chars
	char m_topLeftCorner;
	char m_topRightCorner;
	char m_bottomLeftCorner;
	char m_bottomRightCorner;
	char m_topWall;
	char m_sideWall;
	//Integers
	int m_topBoundary;
	int m_bottomBoundary;
	int m_leftBoundary;
	int m_rightBoundary;
	int m_wallColour;
	//Vectors
	Vector2 m_wallPosition;

	void renderCorners( );
	void renderFloorAndCeiling( );
	void renderSides( );

public:
	//Constructor
	BoundaryManager( );
	//Methods
	void renderBasicWalls( );
};

#endif // !BOUNDARYMANAGER_H
