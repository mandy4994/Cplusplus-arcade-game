
#include "WinCanvas.h"
#include "WinTexture.h"
#include"DerivedClasses.h"
#include "BaseClasses.h"

class Bullet : public Block,public GameEntity {


private:
	// Implement inherited private implementation
	virtual void draw_impl(Canvas & c);
	virtual void update_impl(float const & dt);

public:

	Bullet(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });

	void setDirection(int direction);
	int state;
	int bulletDirection;
	int bulletX =0;
	int bulletY = 0;
	TEXTURE_PTR pBulletTexture;
	std::shared_ptr<TexturedSprite> pBulletTextureSprite;




}; 
