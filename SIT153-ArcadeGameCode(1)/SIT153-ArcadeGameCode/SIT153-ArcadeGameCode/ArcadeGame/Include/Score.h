
#include "WinCanvas.h"
#include "WinTexture.h"
#include"DerivedClasses.h"
#include "BaseClasses.h"

class Score : public Block {


private:
	// Implement inherited private implementation
	virtual void draw_impl(Canvas & c);
	virtual void update_impl(float const & dt);

public:

	Score(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });

	
	int scoreX = 10;
	int scoreY = 0;
	TEXTURE_PTR pScoreTexture;
	std::shared_ptr<TexturedSprite> pScoreTextureSprite;




};

