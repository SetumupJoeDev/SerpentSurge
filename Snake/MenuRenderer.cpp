
#include <string>

#include "MenuRenderer.h"

#include "Helpers.h"
#include "Settings.h"
#include "Vector2.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: MenuRenderer.cpp				||
//  Purpose: Renders all of the menu	||
//  elements in the game.				||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

MenuRenderer::MenuRenderer( )
{
	//Text Colours
	m_highlightedTextColour = Settings::Menu::TextColours::g_highlightedColour;
	//Text Contents
	m_titleText = Settings::Menu::TextToDisplay::g_titleText;
	m_welcomeText = Settings::Menu::TextToDisplay::g_welcomeText;
	m_optionOneText = Settings::Menu::TextToDisplay::g_optionOneText;
	m_optionTwoText = Settings::Menu::TextToDisplay::g_optionTwoText;
	m_optionThreeText = Settings::Menu::TextToDisplay::g_optionThreeText;
	m_optionFourText = Settings::Menu::TextToDisplay::g_optionFourText;
	//Text Positions
	m_menuTitlePosition.setPosition( Settings::Menu::TextPositions::g_titleX, Settings::Menu::TextPositions::g_titleY );
	m_welcomeTextPosition.setPosition( Settings::Menu::TextPositions::g_welcomeX, Settings::Menu::TextPositions::g_welcomeY );
	m_menuOptionOnePosition.setPosition( Settings::Menu::TextPositions::g_optionOneX, Settings::Menu::TextPositions::g_optionOneY );
	m_menuOptionTwoPosition.setPosition( Settings::Menu::TextPositions::g_optionTwoX, Settings::Menu::TextPositions::g_optionTwoY );
	m_menuOptionThreePosition.setPosition( Settings::Menu::TextPositions::g_optionThreeX, Settings::Menu::TextPositions::g_optionThreeY );
	m_menuOptionFourPosition.setPosition( Settings::Menu::TextPositions::g_optionFourX, Settings::Menu::TextPositions::g_optionFourY );
}

void MenuRenderer::renderDeathTitle( )
{
	//Renders the ascii art for the death title on the screen by iterating through the array of strings in the settings namespace
	for ( int i = 0; i < 6; ++i )
	{
		int j = i + 1;
		DrawString( Settings::Menu::Titles::g_deathTitleAscii[i], Vector2( Settings::Menu::Titles::g_deathTitleX, j ), 12 );
	}
}

void MenuRenderer::renderDeathInfo( int playerScore )
{
	//Renders the player's score on screen as well as instructions to continue
	DrawString( "You died! Press any key to continue.", Vector2( 35, 9 ) );
	DrawString( "Your score was: " + std::to_string( playerScore ), Vector2( 45, 11 ) );
}

void MenuRenderer::renderMenuTitle( )
{
	//Draws the game's title and welcome text in their positions on screen
	for ( int i = 0; i < 6; ++i )
	{
		int j = i + 1;
		DrawString( Settings::Menu::Titles::g_mainTitleAscii[i], Vector2( Settings::Menu::Titles::g_titleX, j ), 2 );
	}
	DrawString( m_welcomeText, m_welcomeTextPosition );
}

void MenuRenderer::renderLevelCompleteTitle( )
{
	//Renders the ascii art for the level complete title on the screen by iterating through the array of strings in the settings namespace
	for ( int i = 0; i < 8; ++i )
	{
		int j = i + 1;
		DrawString( Settings::Menu::Titles::g_levelCompleteAscii[i], Vector2( Settings::Menu::Titles::g_titleX, j ), 12 );
	}
}

void MenuRenderer::renderAdventureCompleteTitle( )
{
	//Renders the ascii art for the adventure complete title on the screen by iterating through the array of strings in the settings namespace
	for ( int i = 0; i < 6; ++i )
	{
		int j = i + 1;
		DrawString( Settings::Menu::Titles::g_winTitle[i], Vector2( Settings::Menu::Titles::g_deathTitleX, j ) );
	}
}

void MenuRenderer::renderAdventureCompleteInfo( int playerScore )
{
	DrawString( "Your score was: " + std::to_string( playerScore ), Vector2( 35, 13 ) );
	DrawString( "You have completed adventure mode! ", Vector2( 20, 11 ) );
}

void MenuRenderer::renderLevelCompleteInfo( int playerScore )
{
	//Draws the score and length increase info on the screen for the player
	DrawString( "Your current score is: " + std::to_string( playerScore ), Vector2( 37, 13 ) );
	DrawString( "Your length has changed by: +2", Vector2( 35, 15 ) );
	DrawString( "You beat this level! ", Vector2( 30, 11 ) );
}

void MenuRenderer::renderMenuOptions( )
{
	switch ( m_currentMenuOption )
	{
	case MenuRenderer::menuOptions::playClassic:
	{
		//Draws the menu options, with option one highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::playAdventure:
	{
		//Draws the menu options, with option two highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::clearScore:
	{
		//Draws the menu options, with option three highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition, m_highlightedTextColour );
		ChangeHandleColour( );
		DrawString( m_optionFourText, m_menuOptionFourPosition );
		break;
	}
	case MenuRenderer::menuOptions::quitGame:
	{
		//Draws the menu options, with option four highlighted
		DrawString( m_optionOneText, m_menuOptionOnePosition );
		DrawString( m_optionTwoText, m_menuOptionTwoPosition );
		DrawString( m_optionThreeText, m_menuOptionThreePosition );
		DrawString( m_optionFourText, m_menuOptionFourPosition, m_highlightedTextColour );
		ChangeHandleColour( );
		break;
	}
	default:
	{
		//Prints an error message if none of the previous conditions are met
		std::cout << "Something has gone wrong. Please contact your nearest programmer.";
		break;
	}
	}
}

void MenuRenderer::renderMenuBox( )
{
	//Draws all four corners of the menu box
	DrawChar( m_topLeftCorner, Vector2( 13, 0 ), 12 );
	DrawChar( m_topRightCorner, Vector2( 93, 0 ), 12 );
	DrawChar( m_bottomLeftCorner, Vector2( 13, 22 ), 12 );
	DrawChar( m_bottomRightCorner, Vector2( 93, 22 ), 12 );
	//Iterates through Y positions 1-14, drawing the sides of the menu box
	for ( int i = 1; i < 22; i++ )
	{
		DrawChar( m_sideWall, Vector2( 13, i ), 12 );
		DrawChar( m_sideWall, Vector2( 93, i ), 12 );
	}
	//Iterates through X positions 38 - 66, drawing top and bottom walls for the menu box
	for ( int i = 14; i < 93; i++ )
	{
		DrawChar( m_topWall, Vector2( i, 0 ), 12 );
		DrawChar( m_topWall, Vector2( i, 22 ), 12 );
	}
}

void MenuRenderer::renderMainMenu( )
{
	renderMenuTitle( );
	renderMenuOptions( );
	renderMenuBox( );
}

void MenuRenderer::renderGameOver( int playerScore )
{
	renderMenuBox( );
	renderDeathTitle( );
	renderDeathInfo( playerScore );
}

void MenuRenderer::renderLevelComplete( int playerScore )
{
	system( "cls" );
	renderMenuBox( );
	renderLevelCompleteTitle( );
	renderLevelCompleteInfo( playerScore );
}

void MenuRenderer::renderAdventureComplete( int playerScore )
{
	system( "cls" );
	renderMenuBox( );
	renderAdventureCompleteTitle( );
	renderAdventureCompleteInfo( playerScore );
}
