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


#include "DerivedClasses.h"
#include "WinCanvas.h"


Block::Block(unsigned int w, unsigned int h, POINT2f const & p)
: Sprite(p), Dynamic(), Rect(p, POINT2f(p.x+w,p.y+h))
	{}

Block::~Block()
{}

/*
 *		Implementation of Block update, invoked
 *		through base class (Sprite) update method.
 */
void Block::update_impl(float const & dt)
{
	VECTOR2f d = br - ul;
	ul = m_position;
	br.y = m_position.y + d.y;
	y--;
	SetPosition(POINT2f(x,y));
}

/*
*		The Block implementaiton method for draw, which is called
*		from the base object (Shape) draw method.
*/
void Block::draw_impl(Canvas & c)
{
	// Use the GraphicsCanvas API to draw a solid Block in 'RED'
	c.DrawSolidRect(*this, RGB(0, 255, 0));
}



int Block::GetWidth()
{

	return (int)(br.x - ul.x);
}
int Block::GetHeight()
{
	return (int)(br.y - ul.y);
}

void Block::SetWidth(int w)
{
	br.x = ul.x + w;
}
void Block::SetHeight(int h)
{
	br.y = ul.y + h;
}



TexturedSprite::TexturedSprite(TEXTURE_PTR pt, POINT2f pos)
: Sprite(pos),
  m_pTexture(pt)  
{}

void TexturedSprite::draw_impl(Canvas & c)
{
	c.DrawTexture(*m_pTexture, m_position);
}
void TexturedSprite::SetTexture(TEXTURE_PTR pt)
{
	m_pTexture = pt;
}
