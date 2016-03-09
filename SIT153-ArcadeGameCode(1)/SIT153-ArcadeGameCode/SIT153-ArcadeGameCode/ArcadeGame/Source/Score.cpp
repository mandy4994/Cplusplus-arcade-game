#include "Score.h"
#include "DerivedClasses.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;



void Score::draw_impl(Canvas & c)
{

	
}

void Score::update_impl(float const & dt)
{

	
	SetVelocity(VECTOR2f(5, 5));
	
	SetPosition(POINT2f(scoreX, scoreY));
	pScoreTextureSprite->SetPosition(POINT2f(scoreX, scoreY));



}



Score::Score(unsigned int w, unsigned int h, POINT2f const & p) :
	Block(w, h, p)
{
	// loads texture for the score.
	pScoreTexture = std::make_shared<WinTexture>("resource//0.bmp", RGB(255, 0, 255));
	pScoreTextureSprite = std::make_shared<TexturedSprite>(pScoreTexture);
	SetPosition(POINT2f(scoreX, scoreY));
	pScoreTextureSprite->SetPosition(POINT2f(scoreX, scoreY));
}


