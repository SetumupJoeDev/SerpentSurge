#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <Windows.h>

class MusicManager
{
private:
	LPCWSTR m_mainMenuMusic;
	LPCWSTR m_classicModeMusic;
	LPCWSTR m_adventureModeMusic;
	LPCWSTR m_deathMusic;
public:
	//Constructor
	MusicManager( );
	//Methods
	void playMainMenuMusic( );
	void playGameMusic( bool isClassic );
	void playDeathMusic( );
};

#endif // !SOUNDMANAGER_H
