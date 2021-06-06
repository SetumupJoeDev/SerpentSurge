

#include "CharacterBase.h"
#include "Helpers.h"
#include "Settings.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
||	Name: CharacterBase.cpp				||
//  Purpose: The base class for any		||
//  single-character rendered in game.	||
//	Author: James Smale					\\
//	Project: SERPENT SURGE				\\
||	Language: C++						||
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

CharacterBase::CharacterBase()
{
	m_characterAvatar = 'c';
	m_backgroundColour = Settings::Game::g_backgroundColour;
	m_textColour = 15;
}

void CharacterBase::update( )
{

}

void CharacterBase::unrenderChar( )
{
	//Renders a single blank space over the char
	DrawChar( ' ', m_characterVector, m_backgroundColour );
}

void CharacterBase::renderChar( )
{
	//Renders the char in its current location
	DrawChar( m_characterAvatar, m_characterVector, m_textColour );
}