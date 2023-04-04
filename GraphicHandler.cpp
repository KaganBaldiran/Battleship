#include "GraphicHandler.h"
#include <raylib.h>
#include <math.h>

void graphichandler::GamePlayScreen(Texture2D texture , Texture2D texture2 , Font font1 )
{
	

	Vector2 squarespos = { squarepix_x , 2* squarepix_x };
	Vector2 line_init = { 0,squarepix_x };
	Vector2 line_end = { 11* squarepix_x,squarepix_x };
	Vector2 background = { -20,0 };
	Vector2 Letterspos = { 15 , 160 };
	
	Color darkred = { 199,77,72,200};
	DrawTextureEx(texture2, background, 0, 1, WHITE);
	DrawTextureEx(texture, squarespos, 0, 1.565, WHITE);

	char letters[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	
	DrawRectangle(0, 0, 11* squarepix_x, squarepix_x, darkred);
	DrawLineEx(line_init, line_end, 5,RED);
	
	DrawTextEx(font1, "1 2 3 4 5 6 7 8 9 10", { (squarepix_x + (squarepix_x / 2) - 10), (squarepix_x + (squarepix_x / 2) - 30) }, 80,3.5, LIGHTGRAY);
	
	for (size_t i = 0; i < 10; i++)
	{
		
		DrawTextEx(font1, TextFormat("%c", letters[i]), Letterspos , 80, 0 ,  LIGHTGRAY);
		Letterspos.y += squarepix_y;
		

	}

}

graphichandler::graphichandler()
{
}

graphichandler::~graphichandler()
{
	
}

void graphichandler::StartingScreen(Texture2D texture , Texture2D texture2 , Texture2D texture3, Texture2D Logo ,int buttonsize , Vector2 *buttonppos)
{

	static Vector2 logopos = { squarepix_x - 15, squarepix_y -20 };
	int *arraytoadd = new(int[50]);
	static int h = 0;
	static bool allowtosub = false;
	
	
	for (size_t j = 50; j != 0; j--)
	{
			arraytoadd[j-1] = j + 1;
	}
			
	if (!allowtosub)
	{
	   logopos.y += (float)arraytoadd[h]/75;
			
		h++;
				
		if (h == 50)
		{
			h = 0;
			allowtosub = true;
		}
			
	}
	if (allowtosub)
	{
		logopos.y -= (float)arraytoadd[h]/75;
			
		h++;
				
			
		if (h == 50)
		{
			h = 0;
			allowtosub = false;;
		}
			
	}

	DrawTextureEx(Logo,logopos, 0, 0.8, WHITE);
	
	if ((300 <= GetMousePosition().x) && (GetMousePosition().x <= 650) && (400 <= GetMousePosition().y) && (GetMousePosition().y <= 550))
	{
		

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			DrawTextureEx(texture, *buttonppos, 0, (float)buttonsize / 1000, LIGHTGRAY);
		}
		else
		{
			DrawTextureEx(texture3, *buttonppos, 0, (float)buttonsize / 1000, WHITE);
		}

	}
	else
	{
		DrawTextureEx(texture, *buttonppos, 0, (float)buttonsize/1000, WHITE);
	}


	
	delete[] arraytoadd;
	
}

void graphichandler::mainscreenbutton(float *buttonsize, Vector2* buttonppos)
{
	static bool buttonpressed = false;
	static bool buttonreleased = false;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{

		if ((300 <= GetMousePosition().x) && (GetMousePosition().x <= 650) && (400 <= GetMousePosition().y) && (GetMousePosition().y <= 550))
		{


			buttonpressed = true;


		}
		
	}

	if (buttonpressed)
	{

		if (*buttonsize > 800)
		{
			*buttonsize -= 50;
			buttonppos->x += 14;
			buttonppos->y += 14;

		}
		if (*buttonsize == 800)
		{
			buttonreleased = true;
			buttonpressed = false;

		}


	}
	if (buttonreleased && !buttonpressed)
	{
		if (*buttonsize >= 800)
		{
			*buttonsize += 50;
			buttonppos->x -= 14;
			buttonppos->y -= 14;
		}
		if (*buttonsize == 1000)
		{
			buttonreleased = false;

		}
	}
	

}



void graphichandler::DrawShip(player* player1, Texture2D texture, Texture2D texture2)
{
	Myship myship1 = { player1->firstship_player.getfirstsquare().getsquareposX()  , (player1->firstship_player.getfirstsquare().getsquareposY())};
	Myship myship2 = { player1->secondship_player.getfirstsquare().getsquareposX()  , (player1->secondship_player.getfirstsquare().getsquareposY())};
	Myship myship3 ={ (player1->thirdship_player.getfirstsquare().getsquareposX())  , player1->thirdship_player.getfirstsquare().getsquareposY() };

	float shipsize = 0.289f;

	//first
	if (player1->firstship_player.getshipangle() == 90) {

		shipanimator(&myship1.x);
			 
			
		if ((player1->firstship_player.getfirstsquare().getsquareposY() >= (9 * squarepix_y)))
		{
			DrawTextureEx(texture2, { (float)myship1.x+ squarepix_y-20,(float)myship1.y + 20 - 2*squarepix_y }, player1->firstship_player.getshipangle(), shipsize, WHITE);
		}
		else
		{
			DrawTextureEx(texture, { (float)myship1.x + squarepix_y - 20 ,(float)myship1.y +15}, player1->firstship_player.getshipangle(), shipsize, WHITE);
		}
	}
	if (player1->firstship_player.getshipangle() == 0)
	{
		shipanimator(&myship1.y);

		if ((player1->firstship_player.getfirstsquare().getsquareposX() >= (9 * squarepix_x)))
		{
			DrawTextureEx(texture2, { (float)myship1.x - 2*squarepix_x + 15,(float)myship1.y + 20}, player1->firstship_player.getshipangle(), shipsize, WHITE);

		}
		else
		{
			DrawTextureEx(texture, { (float)myship1.x + 15,(float)myship1.y + 20 }, player1->firstship_player.getshipangle(), shipsize, WHITE);
		}
	}
//second
	if (player1->secondship_player.getshipangle() == 90) {

		shipanimator(&myship2.x);

		if ((player1->secondship_player.getfirstsquare().getsquareposY() >= (9 * squarepix_y)))
		{
			DrawTextureEx(texture2, { (float)myship2.x + squarepix_y - 20 ,(float)myship2.y + 20 - 2 * squarepix_y }, player1->secondship_player.getshipangle(), shipsize, WHITE);
		}
		else
		{
			DrawTextureEx(texture, { (float)myship2.x + squarepix_y - 20 ,(float)myship2.y+15 }, player1->secondship_player.getshipangle(), shipsize, WHITE);
		}
	}
	if (player1->secondship_player.getshipangle() == 0)
	{
		shipanimator(&myship2.y);

		if ((player1->secondship_player.getfirstsquare().getsquareposX() >= (9 * squarepix_x)))
		{
			DrawTextureEx(texture2, { (float)myship2.x - 2 * squarepix_x+15,(float)myship2.y + 20 }, player1->secondship_player.getshipangle(), shipsize, WHITE);

		}
		else
		{
			DrawTextureEx(texture, { (float)myship2.x + 15,(float)myship2.y + 20 }, player1->secondship_player.getshipangle(), shipsize, WHITE);
		}
	}

//third
	if (player1->thirdship_player.getshipangle() == 90) {

		shipanimator(&myship3.x);

		if ((player1->thirdship_player.getfirstsquare().getsquareposY() >= (9 * squarepix_y)))
		{
			DrawTextureEx(texture2, { (float)myship3.x + squarepix_y - 20,(float)myship3.y + 20 - 2 * squarepix_y }, player1->thirdship_player.getshipangle(), shipsize, WHITE);
		}
		else
		{
			DrawTextureEx(texture, { (float)myship3.x + squarepix_y - 20 ,(float)myship3.y+15 }, player1->thirdship_player.getshipangle(), shipsize, WHITE);
		}
	}
	if (player1->thirdship_player.getshipangle() == 0)
	{
		shipanimator(&myship3.y);

		if ((player1->thirdship_player.getfirstsquare().getsquareposX() >= (9 * squarepix_x)))
		{
			DrawTextureEx(texture2, { (float)myship3.x - 2 * squarepix_x + 15,(float)myship3.y + 20 }, player1->thirdship_player.getshipangle(), shipsize, WHITE);

		}
		else
		{
			DrawTextureEx(texture, { (float)myship3.x + 15,(float)myship3.y + 20 }, player1->thirdship_player.getshipangle(), shipsize, WHITE);
		}
	}

}

void graphichandler::EndingScreen(player *player1 , player *ai1, Font font1)
{
	DrawRectangleRounded({ squarepix_x/2,squarepix_y/2,screenw - 1 * squarepix_x,screenh - 1 * squarepix_y }, 0.1, 2, LIGHTGRAY);
	DrawText("GAME OVER!", screenw / 2 - 4 * squarepix_x, screenh / 2-2*squarepix_x+90,100,BLACK);

	if (player1->HasWon)DrawTextEx(font1,"Player-1 Wins!",{screenw/2-2*squarepix_x-30,screenh/2+100},50,10,WHITE);
	if (ai1->HasWon)DrawTextEx(font1, "AI-1 Wins!", { screenw / 2 - 2 * squarepix_x - 30,screenh / 2 + 100 }, 50, 10, WHITE);
	

}

void graphichandler::Options()
{


}

void graphichandler::shipshot(ship *ship1,Texture2D crosstexture)
{
	
	if (ship1->getfirstsquare().thissquarewasshot)
	{
		DrawTextureEx(crosstexture, { (float)ship1->getfirstsquare().getsquareposX() + 5,(float)ship1->getfirstsquare().getsquareposY()+5 }, 0, 0.28, WHITE);
		
	}
	if (ship1->getsecondsquare().thissquarewasshot)
	{
		DrawTextureEx(crosstexture, { (float)ship1->getsecondsquare().getsquareposX() + 5,(float)ship1->getsecondsquare().getsquareposY()+5 }, 0, 0.28, WHITE);
		
	}
	if (ship1->getthirdsquare().thissquarewasshot)
	{

		DrawTextureEx(crosstexture, { (float)ship1->getthirdsquare().getsquareposX() + 5,(float)ship1->getthirdsquare().getsquareposY()+5 }, 0, 0.28, WHITE);
		
	}
	
	
}

void graphichandler::drawwhitecross(Texture2D whitecross, int whitex[], int whitey[], square* current_square)
{
	static int e = 0;
	static bool permtowrite = true;
	

	square newchosensquare;
	newchosensquare.assignpos(current_square->getsquareposX(), current_square->getsquareposY());
	newchosensquare.name = current_square->getname();

	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
	{
		if ((!((GetMouseX() <= squarepix_x) || (GetMouseY() <= (squarepix_x * 2)))))
		{


			for (size_t i = 0; i < e; i++)
			{
				if (comparesqpositions(whitex[i], whitey[i], current_square->getsquareposX(), current_square->getsquareposY()))
				{
					permtowrite = false;
				}
			}

			if (permtowrite)
			{
				whitex[e] = current_square->getsquareposX();
				whitey[e] = current_square->getsquareposY();
				e++;
				
			}


		}
	}

	

	for (size_t i = 0; i < e; i++)
	{
		DrawTextureEx(whitecross, { (float)whitex[i]+5,(float)whitey[i]+5}, 0, 0.28, WHITE);
	}

	permtowrite = true;
}

void graphichandler::drawscores(player *player1 , int posx , int posy)
{
	
	DrawText(TextFormat("%i", player1->TimesShipWasSinked) , posx , posy , 50, BLACK);

}

void graphichandler::ashanimation(Texture2D ash , int amountofash)
{
	static int g1_posx[20];
	static int g1_posy[20];
	static int g1_size[20];
	static int g1_rotation[20];
	static int g1_poschecker = 0;
	static bool g1_initialized = false;
	

		if (!g1_initialized)
		{

			for (size_t i = 0; i < 20; i++)
			{
				g1_posx[i] = GiveRandomSquarePos(0, screenw, 50, false, 1);
				g1_posy[i] = GiveRandomSquarePos(0, screenh, 50, false, 1);
				g1_rotation[i] = GiveRandomSquarePos(0, 360, 50, false, 1);
				g1_size[i] = GiveRandomSquarePos(2 , 4, 50, false, 1);

			}

			g1_initialized = true;

		}
		if (g1_initialized)
		{

			for (size_t i = 0; i < 20; i++)
			{
				int choose = GiveRandomSquarePos(0, 1, 50, false, 7);

				if (choose == 1)
				{
					g1_posx[i] += GiveRandomSquarePos(0, 2, 50, false, 1);
					g1_rotation[i] += GiveRandomSquarePos(0, 3, 15, false, 1);
				}
				if (choose == 0)
				{
					g1_posx[i] -= GiveRandomSquarePos(0, 2, 50, false, 1);
					g1_rotation[i] -= GiveRandomSquarePos(0, 3, 15,false, 1);
				}

				g1_posy[i] += GiveRandomSquarePos(2, 3, 50, false, 1);
				

				if ((g1_posy[i] > screenh) || (g1_posx[i] < 0) || (g1_posx[i] > screenw))
				{

					g1_posx[i] = GiveRandomSquarePos(0, screenw, 50, false, 1);
					g1_posy[i] = 0;



				}
				

			}

		
		}
		if (g1_initialized)
		{
			for (size_t i = 0; i < 20; i++)
			{
				DrawTextureEx(ash, { (float)g1_posx[i], (float)g1_posy[i] }, g1_rotation[i], (float)g1_size[i]/100, WHITE);

			}

		}
}

void graphichandler::Createwave()
{
	static int pixeldrawer[100];






}

void graphichandler::shipanimator(int* pos)
{
	static float increment = 0;
	static bool allowadd = true;
	static bool allowsub = false;
	
	if (allowadd)
	{
		increment += 1;
		*pos += 1;
		if (increment == incr)
		{
			
			allowadd = false;
			allowsub = true;

		}
	}
	if (allowsub)
	{
		increment -=  1;
		*pos -=  1;
		if (increment == 0)
		{
			
			allowadd = true;
			allowsub = false;;

		}
	}

}

void graphichandler::readimagefromheader(Texture2D* targettex, Image* targetim , static unsigned char *data , int format , int height , int width)
{
	
	targetim->format = format;
	targetim->height = height;
	targetim->width = width;
	targetim->data = data;
	targetim->mipmaps = 1;

	*targettex = LoadTextureFromImage(*targetim);

}

void graphichandler::thropyAnimator(Texture2D texture1)
{
	Rectangle rec = { 0.0f , 0.0f , (float)texture1.width / 3 , (float)texture1.height / 3 };
	static int framecounter = 0;
	int speed = 8;
	static int current = 0;

	framecounter++;

	if(framecounter >= (60 / speed))
	{

		framecounter = 0;
		current++;

	
	}
	if (current < 8)
	{
		if ((current <= 2))
		{
			rec.y = 0;
			rec.x = current * ((float)texture1.width / 3);
		}
		if ((current >= 3))
		{
			rec.y = ((float)texture1.height / 3);
			rec.x = current * ((float)texture1.width / 3);
		}
		if ((current >= 6) && (current < 7))
		{
			rec.y = 2 * ((float)texture1.height / 3);
			rec.x = current * ((float)texture1.width / 3);
		}
	}
	if (current > 7)
	{
		current = 0;
		rec.y = 0;
	}

	DrawTextureRec(texture1, rec ,{ (float)screenw / 2-150 , ((float)screenh / 3)-250 }, WHITE);

}

void graphichandler::selectsquare(Texture2D texture)
{
	Vector2 squarespos;
	
	int numbers[10] = { '1','2','3','4','5','6','7','8','9','10' };
	char letters[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	int i;
	int j;

	i = GetMousePosition().x;
	j = GetMousePosition().y;
	i = ((i - (i % squarepix_x)) / squarepix_x);
	j = ((j - (j % squarepix_x)) / squarepix_x);
	char word[2];
	word[0] = letters[j-2];
	word[1] = numbers[i-1];

	Color lightred = { 255,0,0,20 };
	
	int x = GetMouseX();
	int y = GetMouseY();
	x = (x - (x % squarepix_x))- 24;
	y = (y - (y % squarepix_x))- 24;
	squarespos = {(float)x,(float)y};

	DrawRectangle(x+25, y+25, squarepix_x, squarepix_x, lightred);
	DrawTextureEx(texture, squarespos, 0, 1, WHITE);
	DrawText(TextFormat("%c", word[0]), x - 5, y - 4, 15, LIGHTGRAY);
	DrawText(TextFormat("%c", word[1]), x + 5 , y - 4, 15, LIGHTGRAY);
		
}
