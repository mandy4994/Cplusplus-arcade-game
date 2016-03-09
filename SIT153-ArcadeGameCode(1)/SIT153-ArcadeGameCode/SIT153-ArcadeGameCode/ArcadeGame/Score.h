
#include "WinCanvas.h"
#include "WinTexture.h"
#include"DerivedClasses.h"

class Score : public Block {


private:
	// Implement inherited private implementation
	virtual void draw_impl(Canvas & c);
	virtual void update_impl(float const & dt);

public:

	Score(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });

	void setDirection(int direction);
	int state;
	int directionPressed;
	int x = 20;
	int y = 10;
	TEXTURE_PTR pScoreTexture;
	std::shared_ptr<TexturedSprite> pScoreTextureSprite;



};
