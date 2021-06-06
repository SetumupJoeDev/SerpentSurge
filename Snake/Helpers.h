#ifndef HELPERS_H
#define HELPERS_H

#include <fstream>
#include <string.h>

#include "Vector2.h"

void DrawChar( char c, Vector2 vector2, int colourInt );

void DrawString( std::string textToRender, Vector2 vector2, int colourInt = 15 );

void ChangeHandleColour( int colourInt = 15 );

#endif // !HELPERS_H