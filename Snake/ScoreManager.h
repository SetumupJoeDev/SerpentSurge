#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <fstream>

#include "Vector2.h"

class ScoreManager
{
private:
	//Integers
	int m_currentScore;
	int m_classicModeHighScore;
	int m_adventureModeHighScore;
	int m_textColour;
	//Resources
	std::ifstream m_highScoreFileRead;
	std::ofstream m_highScoreFileWrite;
	//Strings
	std::string m_classicModeScoreFile;
	std::string m_adventureModeScoreFile;
	//Vectors
	Vector2 m_scorePosition;
	Vector2 m_highScorePosition;
public:
	//Constructor
	ScoreManager( );
	//Setters and Getters
	//Current Score
	void setCurrentScore( int newScore ){ m_currentScore = newScore; }
	int  getCurrentScore( ){ return m_currentScore; }
	//High Score
	//Classic
	void setClassicHighScore( int newHighScore ){ m_classicModeHighScore = newHighScore; }
	int  getClassicHighScore( ){ return m_classicModeHighScore; }
	//Adventure
	void setAdventureHighScore( int newHighScore ){ m_adventureModeHighScore = newHighScore; }
	int  getAdventureHighScore( ){ return m_adventureModeHighScore; }
	//Methods
	void readHighScore( );
	void writeHighScore( bool isClassicMode, int newHighScore );
	void displayScores( );
	void compareScores( bool isClassicMode );
};

#endif // !SCOREMANAGER_H
