#include "Bullet.h"
#include "DerivedClasses.h"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;



void Bullet::draw_impl(Canvas & c)
{


}

void Bullet::update_impl(float const & dt)
{

	SetVelocity(VECTOR2f(5, 5));
	bulletY--;
	SetPosition(POINT2f(bulletX, bulletY));
	pBulletTextureSprite->SetPosition(POINT2f(bulletX, bulletY));
		
	
	
}



Bullet::Bullet(unsigned int w, unsigned int h, POINT2f const & p) :
	Block(w, h, p),GameEntity(ID_BULLET)
{
	// loads the texture for the bullet.
	pBulletTexture = std::make_shared<WinTexture>("resource//bullet.bmp", RGB(255, 0, 255));
	pBulletTextureSprite = std::make_shared<TexturedSprite>(pBulletTexture);
	SetPosition(POINT2f(bulletX, bulletY));
	pBulletTextureSprite->SetPosition(POINT2f(bulletX, bulletY));
}

void Bullet::setDirection(int direction)
{

	bulletDirection = direction;

}
