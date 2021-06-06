#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <string.h>

#include "Vector2.h"

namespace Settings
{
	namespace Snake
	{
		//Length Settings
		const int g_snakeStartLength = 4;
		const int g_snakeLengthModifier = 4;
		const int g_maxLength = 100;
		//Speed Settings
		const int g_snakeStartSpeedX = 0;
		const int g_snakeStartSpeedY = 0;
		//Position Settings
		const int g_snakeStartPosX = 12;
		const int g_snakeStartPosY = 12;
		//Colour Settings
		const int g_snakeColourOne = 2;
		const int g_snakeColourTwo = 10;
		//Character Settings
		const char g_snakeChar = ( char ) 178;
	}

	namespace Enemies
	{
		const Vector2 g_enemyPositions[10] 
		{	
			Vector2( 5, 15 ), Vector2( 95, 15 ), Vector2( 45, 5 ), Vector2( 45, 21 ), Vector2( 49, 12 ),
			Vector2( 49, 15), Vector2( 25, 25 ), Vector2( 75, 25 ),  Vector2( 15, 15 ),  Vector2( 85, 15 )
		};
		const Vector2 g_firstenemyTargets[10]
		{
			Vector2( 5, 5 ), Vector2( 95, 5 ), Vector2( 10, 5 ),  Vector2( 10, 21 ), Vector2( 15, 12 ),
			Vector2( 15, 15 ), Vector2( 25, 5 ), Vector2( 75, 5 ), Vector2( 25, 25 ), Vector2( 75, 25 )
		};
		const Vector2 g_secondEnemyTargets[10]
		{
			Vector2( 5, 25 ), Vector2( 95, 25 ), Vector2( 80, 5 ), Vector2( 80, 21 ), Vector2( 85, 12 ),
			Vector2( 85, 15 ), Vector2( 25, 25 ), Vector2( 75, 25 ), Vector2( 15, 15 ), Vector2( 85, 15 )
		};
	}

	namespace Fruit
	{
		const int g_yLimit = 24;
		const int g_xLimit = 99;
		const char g_fruitChar = ( char ) 64;
		const int g_fruitColour = 4;
	}

	namespace Game
	{
		const int g_sleepTimer = 100;
		const int g_fruitScoreIncrease = 10;
		const int g_backgroundColour = 0;
	}

	namespace Boundaries
	{
		//Boundary Chars
		const char g_bottomLeftCorner = static_cast < char >( 200 );
		const char g_bottomRightCorner = static_cast < char >( 188 );
		const char g_sideWall = static_cast < char >( 186 );
		const char g_topLeftCorner = static_cast < char >( 201 );
		const char g_topRightCorner = static_cast < char >( 187 );
		const char g_topWall = static_cast < char >( 205 );
		//Boundary Positions
		const int g_topBoundary = 1;
		const int g_bottomBoundary = 26;
		const int g_leftBoundary = 1;
		const int g_rightBoundary = 101;
		const int g_wallColour = 1;
	}

	namespace Menu
	{
		namespace Titles
		{
			//Title Positions
			const int g_titleX = 16;
			const int g_deathTitleX = 30;
			//Title Ascii Art
			const std::string g_mainTitleAscii[6] = {	" _____ _________________ _____ _   _ _____   _____ _   _______ _____  _____ ", 
													"/  ___|  ___| ___ \\ ___ \\  ___| \\ | |_   _| /  ___| | | | ___ \\  __ \\|  ___|", 
													"\\ `--.| |__ | |_/ / |_/ / |__ |  \\| | | |   \\ `--.| | | | |_/ / |  \\/| |__  ",
													" `--. \\  __||    /|  __/|  __|| . ` | | |    `--. \\ | | |    /| | __ |  __| ",
													"/\\__/ / |___| |\\ \\| |   | |___| |\\  | | |   /\\__/ / |_| | |\\ \\| |_\\ \\| |___ ",
													"\\____/\\____/\\_| \\_\\_|   \\____/\\_| \\_/ \\_/   \\____/ \\___/\\_| \\_|\\____/\\____/ " };
			const std::string g_deathTitleAscii[6] = { "__   _______ _   _  ______ _____ ___________ _ ",
														"\\ \\ / /  _  | | | | |  _  \\_   _|  ___|  _  \\ |",
														" \\ V /| | | | | | | | | | | | | | |__ | | | | |",
														"  \\ / | | | | | | | | | | | | | |  __|| | | | |",
														"  | | \\ \\_/ / |_| | | |/ / _| |_| |___| |/ /|_|",
														"  \\_/  \\___/ \\___/  |___/  \\___/\\____/|___/ (_)"};
			const std::string g_levelCompleteAscii[8] = {	"  _                    _    _____                      _      _       _ ",
															" | |                  | |  / ____|                    | |    | |     | |",
															" | |     _____   _____| | | |     ___  _ __ ___  _ __ | | ___| |_ ___| |",
															" | |    / _ \\ \\ / / _ \\ | | |    / _ \\| '_ ` _ \\| '_ \\| |/ _ \\ __/ _ \\ |",
															" | |___|  __/\\ V /  __/ | | |___| (_) | | | | | | |_) | |  __/ ||  __/_|",
															" |______\\___| \\_/ \\___|_|  \\_____\\___/|_| |_| |_| .__/|_|\\___|\\__\\___(_)",
															"                                                | |                     ",
															"                                                |_|                     "};
			const std::string g_winTitle[6] = { "__   _______ _   _   _    _ _____ _   _ _ ",
												"\\ \\ / /  _  | | | | | |  | |_   _| \\ | | |",
												" \\ V /| | | | | | | | |  | | | | |  \\| | |",
												"  \\ / | | | | | | | | |/\\| | | | | . ` | |",
												"  | | \\ \\_/ / |_| | \\  /\\  /_| |_| |\\  |_|",
												"  \\_/  \\___/ \\___/   \\/  \\/ \\___/\\_| \\_(_)"};
		}
		namespace TextPositions
		{
			//Title Text Position
			const int g_titleX = 40;
			const int g_titleY = 1;
			//Welcome Text Position
			const int g_welcomeX = 39;
			const int g_welcomeY = 10;
			//High Score position
			const int g_highScoreX = 45;
			const int g_highScoreY = 12;
			//Menu Option One position
			const int g_optionOneX = 43;
			const int g_optionOneY = 14;
			//Menu Option Two Position
			const int g_optionTwoX = 42;
			const int g_optionTwoY = 16;
			//Menu Option Three Position
			const int g_optionThreeX = 44;
			const int g_optionThreeY = 18;
			//Menu Option Four Position
			const int g_optionFourX = 47;
			const int g_optionFourY = 20;
		}
		namespace TextToDisplay
		{
			//Game Title Text
			const std::string g_titleText		= "Welcome to SERPENT SURGE!";
			//Welcome Text
			const std::string g_welcomeText		= "Select any option to begin!";
			//Option One Text
			const std::string g_optionOneText	= "1. Play Classic Mode";
			//Option Two Text
			const std::string g_optionTwoText	= "2. Play Adventure Mode";
			//Option Three Text
			const std::string g_optionThreeText = "3. Clear High Score";
			//Option Four Text
			const std::string g_optionFourText	= "4. Quit Game";
		}
		namespace TextColours
		{
			//Default Text Colour
			const int g_defaultColour = 15;
			//Highlighted Text Colour
			const int g_highlightedColour = 23;
		}
	}

	namespace Levels
	{
		const int g_levelFruitCounts[5] = { 5, 8, 12, 17, 23 };
	}
}

#endif // !SETTINGS_H
