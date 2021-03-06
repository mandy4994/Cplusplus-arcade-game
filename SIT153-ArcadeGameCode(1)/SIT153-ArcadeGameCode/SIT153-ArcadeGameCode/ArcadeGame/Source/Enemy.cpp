#include "Enemy.h"
#include "DerivedClasses.h"

#include <iostream>
#include <fstream>
#include <math.h>


unsigned int microseconds;

using std::cout;
using std::cin;
using std::endl;

int left = 0;
int right = 1;
int direction = right;





void Enemy::draw_impl(Canvas & c)
{

	
}

void Enemy::update_impl(float const & dt)
{	
		VECTOR2f v = GetVelocity();
		POINT2f p = GetPosition();
	// moves the enemy left and right. TODO: need to fix the velocity because it going to fast.

	if (yellowEnemyX < 0)
		direction = right;
	if (yellowEnemyX > 600)
		direction = left;

	if (direction == left) 
		yellowEnemyX--;

	if (direction == right)
		yellowEnemyX++;
	
	
	pEnemyYellowTextureSprite->SetPosition(POINT2f(yellowEnemyX, yellowEnemyY));
	SetPosition(POINT2f(yellowEnemyX,yellowEnemyY));
}



Enemy::Enemy(unsigned int w, unsigned int h, POINT2f const & p) :
	Block(w, h, p),GameEntity(ID_ENEMY)
{
	//load texture and set it to the same location as the enemy.
	pEnemyYellowTexture = std::make_shared<WinTexture>("resource//yellow_enemy.bmp", RGB(255, 0, 255));
	pEnemyYellowTextureSprite = std::make_shared<TexturedSprite>(pEnemyYellowTexture);
	pEnemyYellowTextureSprite->SetPosition(POINT2f(yellowEnemyX, yellowEnemyY));
	SetPosition(POINT2f(yellowEnemyX, yellowEnemyY));
	SetVelocity(VECTOR2f(0.5f,0.5f));
}
