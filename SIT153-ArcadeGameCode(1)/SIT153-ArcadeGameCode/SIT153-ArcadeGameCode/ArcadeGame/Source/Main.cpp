/* ********************************************************************************* *
 * *                  SIT153 - Introduction to Game Development                    * *
 * *                Assignment #2 - Develop a Classic Arcade Game                  * *
 * *                                                                               * *
 * *  This code is provided to students as a basic framework for the purposes of   * *
 * *  developing a game that meets the requirements of the assessment guidelines.  * *
 * *  This code base does not provide all features necessary to implement such a   * *
 * *  game. Students must modify and extend this framework to achieve the          * *
 * *  specific functionality required of their game.                               * *
 * *                                                                               * *
 * *  The code is provided as-is and while significant efforts have been made to   * *
 * *  ensure that it is bug-free, this is not a guarantee. It is each student's    * *
 * *  responsibility to ensure that their final submission compiles and executes   * *
 * *  without error.                                                               * *
 * *                                                                               * *
 * *  COPYRIGHT NOTICE                                                             * *
 * *  ----------------                                                             * *
 * *  (C) [2012] - [2015] Deakin University                                        * *
 * *  All rights reserved.                                                         * *
 * *  All information contained herein is, and remains the property of Deakin      * *
 * *  University and the authors (Tim Wilkin, Michael Hobbs and Shaun Bangay).     * *
 * *  Dissemination of this information or reproduction of this material is        * *
 * *  strictly forbidden unless prior written permission is obtained from Deakin   * *
 * *  University. The right to create derivative works from this material is       * *
 * *  hereby granted to students enrolled in SIT153, but only for the purposes of  * *
 * *  assessment while an enrolled student at Deakin University.                   * *
 * *                                                                               * *
 * *  Please complete the following information as acknowledgement of the          * *
 * *  above conditions regarding the use of this code. Failure to complete this    * *
 * *  acknowledgement will mean that your assignment submission will not be marked * *
 * *                                                                               * *
 * ********************************************************************************* *
 * *  STUDENT ID:		213347007                                                                  * *
 * *  STUDENT NAME:  Mandeep Singh                                                              * *
 * *  DATE:            9/10/2015                                                            * *
 * ********************************************************************************* *
 */

/*****************************************************************************************
 * Demonstration of usage of the WinCanvas class for a Windows console application - to  *
 * support basic '2D graphics' through simplified API surrounding the Windows GDI system.*
 *                                                                                       *
 * This code is based on the code developed by Shaun Bangay (2012) & Tim Wilkin (2013).  *
 * Extended by Michael Hobbs and Tim Wilkin (2014) and re-written by Tim Wilkin (2015).  *
 *                                                                                       *
 *****************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>

#include <time.h>
#include <vector>

#include "WinCanvas.h"
#include "WinTexture.h"
#include "DerivedClasses.h"
#include "InputState.h"
#include "Scene.h"
#include "Main.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Score.h"

 // Declare which object from <iostream> and <string> the program will use
using std::cout;
using std::cin;
using std::endl;
using std::string;

int gameStatus;//used to see if all lives are use or the game is won.

const unsigned int GAMEOVER = 0;
const unsigned int WON = 1;
const unsigned int DEAD = 2;

int lives = 3; // start with 3 lives.
int scoreCount = 0;


static void initSprites();
void checkForCollisions();
void winGame();
void loseGame();
// The flag that the game loop uses to see if the game has finished
bool gamefinished = false;

TEXTURE_PTR pBackgroundBM;
std::shared_ptr<TexturedSprite> pBackground;

std::shared_ptr<Player> player;
std::vector<std::shared_ptr<Enemy>> enemies;

std::shared_ptr<Score> score;
std::shared_ptr<Score> scoreWord;
std::shared_ptr<Bullet> pBullet;

float bulletx = 0;
float bullety = 0;

int enemyCount = 31;
bool shooting = false;


Scene demo(
	POINT2(0, 0),							// Upper left corner coordinate
	POINT2(WINDOW_WIDTH, WINDOW_HEIGHT)		// lower right corner coordinate
	);






// The main function of the program
int main()
{
	
	

	/********************  DO NOT EDIT THIS CODE *****************************
     *
	 *	Declare a WinCanvas object. We wouldn't normally create an object this way as
	 *  it is non-portable, but this is a very simple 'graphics canvas' interface to
	 *  the Windows Graphical Device Interface (GDI) API.
	 */

	WinCanvas wc(WINDOW_WIDTH, WINDOW_HEIGHT, L"Class Arcade Game");

	/*
	 *  An InputState object provides an interface to the Keyboard and Mouse devices. 
	 */
	
	InputState	  ui;
	OpenUIHandler(ui);	// Initialise the input interface

	/*********************END RESTRICTED CODE *********************************
	 **************************************************************************/

	/*
	 *  Console Splash Screen
	 */

	cout << "  SIT153 Project - 2D Game Framework" << endl;
	cout << "=======================================" << endl;
	
	/*
	 *   Demonstration of game initialisation - You can and should
	 *   modify this code in line with your software design, to
	 *   provide the necessary runtime functionality.
	 */

	// Create a scene object - a container and manager for our sprites
     demo = Scene(
		     POINT2(0,0),							// Upper left corner coordinate
			 POINT2(WINDOW_WIDTH,WINDOW_HEIGHT)		// lower right corner coordinate
				);
	
	 //std::shared_ptr<Player>player = std::make_shared<Player>(79, 79);
	 initSprites();
	
	/*
	 * Execute the game loop
	 */

	

	// The main game loop
	while (!gamefinished)
	{
		// ****************************************************************		
		// *** STAGE 1: Check InputState										***
		// ****************************************************************		
	
		if (ui.isActive(VK_ESCAPE))		// Check to see if the Game Loop should terminated
		{
			gamefinished = true;	// Break out of this game loop
			wc.Terminate();			// Force a quite message to be passed to the 
									// message handler, which will close that thread
			continue;
		}
		

		if (ui.isActive(VK_RIGHT)) {
			player->setDirection(RIGHT);

		}

		if (ui.isActive(VK_LEFT) ) {

			player->setDirection(LEFT);
		}

		if (ui.isActive(VK_UP)&&!shooting) {

			
			//if the player presses up, a bullet is shot at the enemy if a bullet is not being fired.
			pBullet->bulletX = player->playerX + 16;
			pBullet->bulletY = player->playerY;
			cout << pBullet->y << endl;
		    pBullet->SetPosition(POINT2f(pBullet->bulletX, pBullet->bulletY));
			pBullet->pBulletTextureSprite->SetPosition(POINT2f(pBullet->x, pBullet->y));
			pBullet->SetVelocity(VECTOR2f(20, 20));
			demo.AddSprite(pBullet->pBulletTextureSprite);
			demo.AddSprite(pBullet);
			demo.AddDynamic(pBullet);
			demo.AddEntity(pBullet);
			pBullet->bulletDirection = UP;

			//bullets.push_back(pBullet);
			
			shooting = true;
		
		}


		demo.OnInput();
		
		

		// ******************************************************************************		
		// *** STAGE 2: Update the state of the scene objects based on the user input ***
		// ******************************************************************************
		//checks if bullet hits end of screen, and removes the bullet from the screen
		if (pBullet->bulletY < 0) {
			shooting = false;
			demo.RemoveSprite(pBullet->pBulletTextureSprite);
			demo.RemoveSprite(pBullet);
			demo.RemoveDynamic(pBullet);
		}

		if (enemyCount <= 0)
			winGame();


		checkForCollisions();
		demo.OnUpdate(0.01f);
		// ******************************************************************		
		// *** STAGE 3: Draw the shapes & text to the screen			  ***
		// ******************************************************************		
		wc.Clear(255, 255, 255);		// Need to clear the old screen before drawing new updated screen!
		demo.OnDraw(wc);				// Call the scene object's draw handler

		
		wc.Display();					// Last step is to actually 'display' the elements to the screen
	}

	// Finished the game. 
	cout << "Game finished. Now exiting...." << endl;

	return 0;
}


    static void initSprites() {



		//create player.
		player = std::make_shared<Player>(32,32);
		//player->SetPosition(POINT2f(player->playerX, player->playerY));
		// Add it to our scene
		demo.AddSprite(player->starship);
		demo.AddSprite(player);
		demo.AddDynamic(player);


		//Create enemies///////////////////////////////////////////////////////////////////////
		std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
		yellowEnemy->yellowEnemyX = WINDOW_WIDTH/2-10;
		yellowEnemy->yellowEnemyY = 34-27;
		yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
		enemies.push_back(yellowEnemy);

		// Add it to our scene
		demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
		demo.AddSprite(yellowEnemy);
		demo.AddDynamic(yellowEnemy);
		demo.AddEntity(yellowEnemy);

		for (int i = 0; i < 2; i++) {

			std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
			yellowEnemy->yellowEnemyX = (i * 30) + 240+35;
			yellowEnemy->yellowEnemyY = 63-27;
			yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
			enemies.push_back(yellowEnemy);

			// Add it to our scene
			demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
			demo.AddSprite(yellowEnemy);
			demo.AddDynamic(yellowEnemy);
			demo.AddEntity(yellowEnemy);

		}


		for (int i = 0; i < 4; i++) {

			std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
			yellowEnemy->yellowEnemyX = (i * 30) + 210+35;
			yellowEnemy->yellowEnemyY = 92-27;
			yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
			enemies.push_back(yellowEnemy);

			// Add it to our scene
			demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
			demo.AddSprite(yellowEnemy);
			demo.AddDynamic(yellowEnemy);
			demo.AddEntity(yellowEnemy);

		}


		for (int i = 0; i < 6; i++) {

			std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
			yellowEnemy->yellowEnemyX = (i * 30) + 180+35;
			yellowEnemy->yellowEnemyY = 121-27;
			yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
			enemies.push_back(yellowEnemy);

			// Add it to our scene
			demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
			demo.AddSprite(yellowEnemy);
			demo.AddDynamic(yellowEnemy);
			demo.AddEntity(yellowEnemy);
		}

		//create yellowEnemys.
		for (int i = 0; i < 8;i++) {
			
			std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
			yellowEnemy->yellowEnemyX = (i * 30)+150+35;
			yellowEnemy->yellowEnemyY = 150-27;
			yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
			enemies.push_back(yellowEnemy);
			
			// Add it to our scene
			demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
			demo.AddSprite(yellowEnemy);
			demo.AddDynamic(yellowEnemy);
			demo.AddEntity(yellowEnemy);
		
		}

		//create yellowEnemys.
		for (int i = 0; i < 10; i++) {

			std::shared_ptr<Enemy> yellowEnemy = std::make_shared<Enemy>(19, 27);
			yellowEnemy->yellowEnemyX = (i * 30) + 120 + 35;
			yellowEnemy->yellowEnemyY = 179 - 27;
			yellowEnemy->SetPosition(POINT2f(yellowEnemy->yellowEnemyX, yellowEnemy->yellowEnemyY));
			enemies.push_back(yellowEnemy);

			// Add it to our scene
			demo.AddSprite(yellowEnemy->pEnemyYellowTextureSprite);
			demo.AddSprite(yellowEnemy);
			demo.AddDynamic(yellowEnemy);
			demo.AddEntity(yellowEnemy);
		// end of creating enemies////////////////////////////////////////////////
		}
		
		

		scoreWord = std::make_shared<Score>(71, 61);
		scoreWord->SetPosition(POINT2f(0, 0));
		scoreWord->SetVelocity(VECTOR2f(0, 0));
		scoreWord->pScoreTexture = std::make_shared<WinTexture>("resource//score.bmp", RGB(255, 0, 255));
		scoreWord->pScoreTextureSprite = std::make_shared<TexturedSprite>(scoreWord->pScoreTexture);

		// Add it to our scene
		demo.AddSprite(scoreWord->pScoreTextureSprite);
		demo.AddSprite(scoreWord);
		demo.AddDynamic(scoreWord);

		//create Score board..
		score = std::make_shared<Score>(71, 61);
		score->scoreX = 10;
		score->scoreY = 68;
		score->SetPosition(POINT2f(score->x, score->y));
		score->SetVelocity(VECTOR2f(0, 0));

		// Add it to our scene
		demo.AddSprite(score->pScoreTextureSprite);
		demo.AddSprite(score);
		demo.AddDynamic(score);

		pBullet = std::make_shared<Bullet>(5, 5);
		
}
	// this functions is used to see enemies got hit with bullets.
	 void checkForCollisions() {

		for (int i = 0; i < enemies.size();i++) {
			int x = enemies[i]->yellowEnemyX;
			int y = enemies[i]->yellowEnemyY;

			int bx = pBullet->bulletX;
			int by = pBullet->bulletY;
			// check and see if player bullet hits an enemy.
			if(bx<(x+19)&&bx>x&&by<(y+27)&&by>y){
			
				//remove bullet from Scene.
				demo.RemoveSprite(pBullet->pBulletTextureSprite);
				demo.RemoveSprite(pBullet);
				demo.RemoveDynamic(pBullet);
				shooting = false;

				//remove enemy from Scene.
				demo.RemoveSprite(enemies[i]->pEnemyYellowTextureSprite);
				demo.RemoveSprite(enemies[i]);
				demo.RemoveDynamic(enemies[i]);
				enemies[i]->yellowEnemyX = -100;
				enemies[i]->yellowEnemyY = -100;

				enemyCount--;
				
				//update score
				scoreCount++;
				// sets appropriate image for the score.
				string result = "resource//"+std::to_string(scoreCount)+".bmp";
				cout << result << endl;
				score->pScoreTexture = std::make_shared<WinTexture>(result, RGB(255, 0, 255));
				score->pScoreTextureSprite = std::make_shared<TexturedSprite>(score->pScoreTexture);
				demo.AddSprite(score->pScoreTextureSprite);
			}
		
		}
	}

	 // this gets called when the player kills all the enemies. 
	 void winGame() {
		

		 std::shared_ptr<Score> winnerLabel = std::make_shared<Score>(71, 61);
		 winnerLabel->SetPosition(POINT2f(300, 200));
		 winnerLabel->SetVelocity(VECTOR2f(0, 0));
		 winnerLabel->pScoreTexture = std::make_shared<WinTexture>("resource//winner.bmp", RGB(255, 0, 255));
		 winnerLabel->pScoreTextureSprite = std::make_shared<TexturedSprite>(winnerLabel->pScoreTexture);

		 // Add it to our scene
		 demo.AddSprite(winnerLabel ->pScoreTextureSprite);
		 demo.AddSprite(winnerLabel);
		 demo.AddDynamic(winnerLabel);
		 
	 
	 
	 }

	 void loseGame() {
	 
		 std::shared_ptr<Score> winnerLabel = std::make_shared<Score>(71, 61);
		 winnerLabel->SetPosition(POINT2f(300, 200));
		 winnerLabel->SetVelocity(VECTOR2f(0, 0));
		 winnerLabel->pScoreTexture = std::make_shared<WinTexture>("resource//gameover.bmp", RGB(255, 0, 255));
		 winnerLabel->pScoreTextureSprite = std::make_shared<TexturedSprite>(winnerLabel->pScoreTexture);

		 // Add it to our scene
		 demo.AddSprite(winnerLabel->pScoreTextureSprite);
		 demo.AddSprite(winnerLabel);
		 demo.AddDynamic(winnerLabel);
	 
	 
	 
	 
	 
	 }