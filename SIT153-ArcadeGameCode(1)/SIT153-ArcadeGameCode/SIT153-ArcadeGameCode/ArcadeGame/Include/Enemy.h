
#include "WinCanvas.h"
#include "WinTexture.h"
#include"DerivedClasses.h"


class Enemy : public Block, public GameEntity {


private:
	// Implement inherited private implementation
	virtual void draw_impl(Canvas & c);
	virtual void update_impl(float const & dt);

public:

	Enemy(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });

	int state;
	int yellowEnemyX = 0;
	int yellowEnemyY = 0;
	TEXTURE_PTR pEnemyYellowTexture;
	std::shared_ptr<TexturedSprite> pEnemyYellowTextureSprite;



};
