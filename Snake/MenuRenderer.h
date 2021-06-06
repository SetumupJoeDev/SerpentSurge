#ifndef MENURENDERER_H
#define MENURENDERER_H

#include <iostream>
#include <string.h>

#include "Vector2.h"
#include "Settings.h"

class MenuRenderer
{
private:
	//Chars
	const char m_bottomLeftCorner = Settings::Boundaries::g_bottomLeftCorner;
	const char m_bottomRightCorner = Settings::Boundaries::g_bottomRightCorner;
	const char m_sideWall = Settings::Boundaries::g_sideWall;
	const char m_topLeftCorner = Settings::Boundaries::g_topLeftCorner;
	const char m_topRightCorner = Settings::Boundaries::g_topRightCorner;
	const char m_topWall = Settings::Boundaries::g_topWall;
	//Enums
	enum class menuOptions{ playClassic, playAdventure, clearScore, quitGame };
	menuOptions m_currentMenuOption;
	//Integers
	int m_highlightedTextColour;
	//Strings
	std::string m_titleText;
	std::string m_welcomeText;
	std::string m_optionOneText;
	std::string m_optionTwoText;
	std::string m_optionThreeText;
	std::string m_optionFourText;
	//Vectors
	Vector2 m_menuTitlePosition;
	Vector2 m_welcomeTextPosition;
	Vector2 m_highScorePosition;
	Vector2 m_menuOptionOnePosition;
	Vector2 m_menuOptionTwoPosition;
	Vector2 m_menuOptionThreePosition;
	Vector2 m_menuOptionFourPosition;
	//Methods
	void renderDeathTitle( );
	void renderDeathInfo( int playerScore );
	void renderMenuTitle( );
	void renderLevelCompleteTitle( );
	void renderAdventureCompleteTitle( );
	void renderAdventureCompleteInfo( int playerScore );
	void renderLevelCompleteInfo( int playerScore );
	void renderMenuOptions( );
	void renderMenuBox( );
public:
	//Constructor
	MenuRenderer( );
	//Setters and Getters
	//Current Menu Option
	void setCurrentOption( int newOption ){ m_currentMenuOption = (menuOptions )newOption; }
	menuOptions getCurrentOption( ){ return m_currentMenuOption; }
	//Methods
	void renderMainMenu( );
	void renderGameOver( int playerScore );
	void renderLevelComplete( int playerScore );
	void renderAdventureComplete( int playerScore );
};

#endif