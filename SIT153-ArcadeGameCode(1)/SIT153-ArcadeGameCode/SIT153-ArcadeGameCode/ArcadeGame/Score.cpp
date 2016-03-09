
#include "..\Include\Score.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;



void Score::draw_impl(Canvas & c)
{

	// Use the GraphicsCanvas API to draw a solid Block in 'RED'
	//c.DrawSolidRect(*this, RGB(0, 255, 0));
}

void Score::update_impl(float const & dt)
{

	// Initialise its position and velocity
	SetPosition(POINT2f(x, y));
	SetVelocity(VECTOR2f(0, 0));

	pScoreTextureSprite->SetPosition(POINT2f(0, 0));

	if (directionPressed == LEFT && playerX > 0) {

		playerX--;
		SetPosition(POINT2f(playerX, playerY));
		starship->SetPosition(POINT2f(playerX, playerY));
		directionPressed = NONE;

	}

	if (directionPressed == RIGHT && playerX < WINDOW_WIDTH - 90) {

		playerX++;
		SetPosition(POINT2f(playerX, playerY));
		starship->SetPosition(POINT2f(playerX, playerY));
		directionPressed = NONE;

	}
}

Score::Score(unsigned int w, unsigned int h, POINT2f const & p) :
	Block(w, h, p) {

	pScoreTexture = std::make_shared<WinTexture>("resource//starship.bmp", RGB(255, 0, 255));
	starship = std::make_shared<TexturedSprite>(pStarship);
	starship->SetPosition(POINT2f(playerX, playerY));
	directionPressed = NONE;


}


void Player::setDirection(int direction)
{
	directionPressed = direction;
}
;

