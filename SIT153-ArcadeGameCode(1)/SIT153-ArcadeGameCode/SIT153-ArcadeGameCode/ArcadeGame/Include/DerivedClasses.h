/* ********************************************************************************* *
* *  COPYRIGHT NOTICE                                                             * *
* *  ----------------                                                             * *
* *  (C)[2012] - [2015] Deakin University                                         * *
* *  All rights reserved.                                                         * *
* *  All information contained herein is, and remains the property of Deakin      * *
* *  University and the authors(Tim Wilkin, Michael Hobbs and Shaun Bangay).      * *
* *  Dissemination of this information or reproduction of this material is        * *
* *  strictly forbidden unless prior written permission is obtained from Deakin   * *
* *  University.The right to create derivative works from this material is        * *
* *  hereby granted to students enrolled in SIT153, but only for the purposes of  * *
* *  assessment while an enrolled student at Deakin University.                   * *
* *                                                                               * *
* ********************************************************************************* */

#ifndef DERIVED_CLASS_H
#define DERIVED_CLASS_H

#include "BaseClasses.h"

const unsigned int	NONE = 0;
const unsigned int	RIGHT = 1;
const unsigned int	LEFT = 2;
const unsigned int	UP = 3;
const unsigned int	DOWN = 4;


// Constant values used in the code - this is the whole window size including
// menu buttons and border - actual graphics canvas size is smaller!
const unsigned int	WINDOW_WIDTH = 600;
const unsigned int	WINDOW_HEIGHT = 400;

class Block : public Sprite, public Dynamic, public Rect
{
	private:
		// Implement inherited private implementation
		virtual void draw_impl(Canvas & c);
		virtual void update_impl(float const & dt);

	public:
		Block(unsigned int w, unsigned int h, POINT2f const & p = { 0, 0 });
		~Block();

		int GetWidth();
		int GetHeight();

		void SetWidth(int w);
		void SetHeight(int h);
		int x, y;

};

class TexturedSprite : public Sprite
{
	private:
		TEXTURE_PTR  m_pTexture;

		virtual void draw_impl(Canvas & c);

	protected:

	public:
		explicit TexturedSprite(TEXTURE_PTR pt = nullptr, POINT2f pos = { 0, 0 });

		virtual ~TexturedSprite(){}

		void SetTexture(TEXTURE_PTR pt);
};

#endif