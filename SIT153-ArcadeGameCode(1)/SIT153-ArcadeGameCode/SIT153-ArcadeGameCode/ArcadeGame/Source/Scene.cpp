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

#include "Scene.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Scene::Scene(POINT2 const & s, POINT2 const & e)
	: m_ul(s),
	  m_br(e),
	  m_game_entities(),
	  m_drawable_objects(),
	  m_dynamic_objects(),
	  m_controlled_objects()
{}

Scene::~Scene()
{
	Clear();
}

void Scene::OnInput()
{
	for (auto c : m_controlled_objects)
		c->OnInput();
}

void Scene::OnUpdate(float const & dt)
{
	// Update any sprite object that requires it
	for (auto d : m_dynamic_objects)
		d->OnUpdate(dt);

	// resolve collisions
	RunCollisionTests();

	// do any other update actions (such as remove dead sprites)
}

void Scene::OnDraw(Canvas & c)
{
	for (auto s : m_drawable_objects)
		s->OnDraw(c);
}

bool Scene::Load(std::string const & filename)
{
	/*
	 * Add functionality here to load a set of sprites from the given file
	 */


	return false; // if failed to load
}
void Scene::AddEntity(ENTITY_PTR pEntity)
{
	m_game_entities.insert( std::make_pair(pEntity->GetUID(), pEntity) );
}

void Scene::AddSprite(SPRITE_PTR pSprite)
{
	m_drawable_objects.push_back(pSprite);
}

void Scene::AddDynamic(DYNAMIC_PTR pDynamic)
{
	m_dynamic_objects.push_back(pDynamic);
}


ENTITY_PTR Scene::RemoveEntity(UID_TYPE const & uid)
{
	ENTITY_PTR p = nullptr;
	auto iter = m_game_entities.find(uid);
	if (iter != m_game_entities.end())
	{
		p = Find(uid);
		m_game_entities.erase(iter);
	}
	return p;
}

void Scene::RemoveSprite(SPRITE_PTR pSprite)
{
	m_drawable_objects.remove(pSprite);
}
void Scene::RemoveDynamic(DYNAMIC_PTR pDynamic)
{
	m_dynamic_objects.remove(pDynamic);
}


ENTITY_PTR Scene::Find(UID_TYPE const & uid)
{
	auto iter = m_game_entities.find(uid);
	if (iter != m_game_entities.end())
		return iter->second;
	else
		return nullptr;
}



void Scene::Clear()
{
	m_game_entities.clear();
	m_drawable_objects.clear();
	m_dynamic_objects.clear();
	m_controlled_objects.clear();
}

void Scene::RunCollisionTests()
{
	
	for (auto e_i : m_game_entities)
	{
		/*
		 * Test for a collision between this Sprite and boundary
		 */
		

		/*
		 * Test for a collision between this Sprite and each other Sprite
		 */

		for (auto e_j : m_game_entities)
		{
			if (e_i.first == e_j.first) // don't test a Sprite against itself
				continue;
			
				if (e_i.second == e_j.second)
					cout << "collistion" << endl;
			/*
			 * Add code here to test for a collision between Sprites s_i and s_j
			 * You may need to apply some mathematics and/or geometric analysis
			 * This may also require you to augment the Sprite class, or the derived
			 * classes, to be able to identify the 'type' of Sprite it is (e.g., is
			 * it a box, or perhaps a circle?). The collision test will depend on
			 * its shape and size (and where it is, of course).
			 *
			 * If a collision occurs, reflect the velocity of each Sprite appropriately
			 */
		
			

		}
	}
}

