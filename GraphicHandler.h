#pragma once
#include <iostream>
#include "Squarelib.h"
#include "Game.h"
#include "Mainloop.h"
#include <raylib.h>
#define incr 300




struct Myship
{
	int x;
	int y;
};

class graphichandler
{
public:
	graphichandler();
    ~graphichandler();
	void StartingScreen(Texture2D texture, Texture2D texture2, Texture2D texture3, Texture2D Logo, int buttonsize , Vector2 *buttonppos);
	void mainscreenbutton(float *buttonsize, Vector2* buttonppos);
	void GamePlayScreen(Texture2D texture ,Texture2D texture2, Font font1);
	void selectsquare(Texture2D texture);
	void DrawShip(player* player1, Texture2D texture, Texture2D texture2);
	void EndingScreen(player* player1, player* ai1 , Font font1);
	void Options();
	void shipshot(ship* ship1,Texture2D crosstexture);
	void drawwhitecross(Texture2D whitecross, int whitex[], int whitey[], square* current_square);
	void drawscores(player* player1, int posx, int posy);
	void ashanimation(Texture2D ash , int amountofash);
	void Createwave();
	void shipanimator(int *pos);
	void readimagefromheader(Texture2D* targettex, Image* targetim, static unsigned char* data, int format, int height, int width);
	void thropyAnimator(Texture2D texture1);


};






