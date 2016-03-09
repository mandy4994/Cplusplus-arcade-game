
#include "WinCanvas.h"
#include "WinTexture.h"
#include"DerivedClasses.h"

class Player : public Block{


	private:
		// Implement inherited private implementation
		virtual void draw_impl(Canvas & c);
		virtual void update_impl(float const & dt);

	public:

		Player(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });
		
		void setDirection(int direction);
		int state;
		int directionPressed;
		int playerX = (WINDOW_WIDTH/2)-40;
		int playerY = (320);
		TEXTURE_PTR pStarship;
		std::shared_ptr<TexturedSprite> starship;
		


};