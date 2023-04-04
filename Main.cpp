#include <raylib.h>
#include <iostream>
#include "Squarelib.h"
#include "Game.h"
#include "Mainloop.h"
#include "GraphicHandler.h"
#include "Variables.h"
#include "ash.h"
#include "battleshipart.h"
#include "button_normal.h"
#include "button_startingpage_cursor.h"
#include "ocean.h"
#include "red_cross.h"
#include "selected_square.h"
#include "squares.h"
#include "white_x.h"
#include "logomain.h"
#include "thropy_animation_atlas_small_2.h"
#include "shipimage2_scaled.h"
#include "shipimage3_scaled.h"
#define MAXPOW 400;
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


int main() {

	InitWindow(screenw, screenh, "BattleShip");

	if (!IsWindowReady()) {

		std::cout << "Error initializing the window" << std::endl;

		CloseWindow();

	}
	
	Image icon = LoadImage("Sail away.png");

	SetWindowState(FLAG_VSYNC_HINT);
	//SetWindowState(FLAG_WINDOW_ALWAYS_RUN);
	SetTargetFPS(60);

	game newgame;

	square* head;

	player player1;

	player1.HasWon = false;

	player1.take_turn();

	square current_square;

	graphichandler gameplayscreen; 

	AI ai1;

	ai1.HasWon = false;

	bool GameHasEnded = false;

	ai1.aimoved = false;

	typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

	GameScreen currentScreen = TITLE;
	

	struct finalsquare* headoffinalsquare;
	
	Texture2D Squares_tex;
	Image Squares_im = { 0 };
	Texture2D squareindicator_tex ;
	Image squareindicator_im = { 0 };
	Texture2D shiptoleft_tex;
	Image shiptoleft_im = { 0 };
	Texture2D shiptoright_tex;//image 2
	Image shiptoright_im = { 0 };
	Texture2D background_tex;
	Image background_im = { 0 };
	Texture2D buttonfrontpage_tex;
	Image buttonfrontpage_im = { 0 };
	Texture2D Coverart_tex;
	Image Coverart_im = { 0 };
	Texture2D red_cross_tex;
	Image red_cross_im = { 0 };
	Texture2D white_cross_tex;
	Image white_cross_im = { 0 };
	Texture2D buttonfrontpage_oncursor_tex;
	Image buttonfrontpage_oncursor_im = { 0 };
	Texture2D ash_tex;
	Image ash_im = { 0 };
	Texture2D Logomain_tex;
	Image Logomain_im = { 0 };
	Texture2D thropyatlas;
	Image thropyatlas_im = { 0 };

	Font font1 = LoadFontEx("Like_Eat.ttf",80,0,0);
	Font font2 = LoadFontEx("shortbaby.ttf", 50, 0, 0);

	gameplayscreen.readimagefromheader(&ash_tex, &ash_im, ASH_DATA, ASH_FORMAT, ASH_HEIGHT, ASH_WIDTH);
	gameplayscreen.readimagefromheader(&Squares_tex, &Squares_im, SQUARES_DATA, SQUARES_FORMAT, SQUARES_HEIGHT, SQUARES_WIDTH);
	gameplayscreen.readimagefromheader(&squareindicator_tex, &squareindicator_im, SELECTED_SQUARE_DATA, SELECTED_SQUARE_FORMAT, SELECTED_SQUARE_HEIGHT, SELECTED_SQUARE_WIDTH);
	gameplayscreen.readimagefromheader(&shiptoleft_tex, &shiptoleft_im, SHIPIMAGE3_SCALED_DATA, SHIPIMAGE3_SCALED_FORMAT, SHIPIMAGE3_SCALED_HEIGHT, SHIPIMAGE3_SCALED_WIDTH);
	gameplayscreen.readimagefromheader(&shiptoright_tex, &shiptoright_im, SHIPIMAGE2_SCALED_DATA, SHIPIMAGE2_SCALED_FORMAT, SHIPIMAGE2_SCALED_HEIGHT, SHIPIMAGE2_SCALED_WIDTH);
	gameplayscreen.readimagefromheader(&background_tex, &background_im, OCEAN_DATA, OCEAN_FORMAT, OCEAN_HEIGHT, OCEAN_WIDTH);
	gameplayscreen.readimagefromheader(&buttonfrontpage_tex, &buttonfrontpage_im, BUTTON_NORMAL_DATA, BUTTON_NORMAL_FORMAT, BUTTON_NORMAL_HEIGHT, BUTTON_NORMAL_WIDTH);
	gameplayscreen.readimagefromheader(&Coverart_tex, &Coverart_im , BATTLESHIPART_DATA, BATTLESHIPART_FORMAT, BATTLESHIPART_HEIGHT, BATTLESHIPART_WIDTH);
	gameplayscreen.readimagefromheader(&red_cross_tex, &red_cross_im, RED_CROSS_DATA, RED_CROSS_FORMAT, RED_CROSS_HEIGHT, RED_CROSS_WIDTH);
	gameplayscreen.readimagefromheader(&white_cross_tex, &white_cross_im, WHITE_X_DATA , WHITE_X_FORMAT, WHITE_X_HEIGHT, WHITE_X_WIDTH);
	gameplayscreen.readimagefromheader(&buttonfrontpage_oncursor_tex, &buttonfrontpage_oncursor_im, BUTTON_STARTINGPAGE_CURSOR_DATA, BUTTON_STARTINGPAGE_CURSOR_FORMAT, BUTTON_STARTINGPAGE_CURSOR_HEIGHT ,BUTTON_STARTINGPAGE_CURSOR_WIDTH);
	gameplayscreen.readimagefromheader(&Logomain_tex, &Logomain_im, LOGOMAIN_DATA, LOGOMAIN_FORMAT, LOGOMAIN_HEIGHT, LOGOMAIN_WIDTH);
	gameplayscreen.readimagefromheader(&thropyatlas, &thropyatlas_im, THROPY_ANIMATION_ATLAS_SMALL_2_DATA ,THROPY_ANIMATION_ATLAS_SMALL_2_FORMAT, THROPY_ANIMATION_ATLAS_SMALL_2_HEIGHT, THROPY_ANIMATION_ATLAS_SMALL_2_WIDTH);

	

	BoundingBox frontbutton = { (screenw / 2) - 140 , (screenh / 2) - 40, 350, 150 };



while (!WindowShouldClose()) {

	//SetWindowIcon(icon);

		switch (currentScreen)
		{
		case LOGO:
		{
			

			framesCounter++;    

			
			if (framesCounter > 120)
			{
				currentScreen = TITLE;
			}
		} break;
		case TITLE:
		{
			gameplayscreen.mainscreenbutton(&buttonsize , &buttonppos);

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{

				if ((300 <= GetMousePosition().x)&&(GetMousePosition().x <= 650) && (400 <= GetMousePosition().y) && (GetMousePosition().y <= 550))
				{
					
					
						playbuttonclickled = true;
					
		
				}
			}

			
			if (playbuttonclickled)
			{
	
				if (menuforhardness < 875 && !buttonpressedonce)
				{

					menuforhardness += 25;


				}
				if (menuforhardness == 875)
				{

					buttonpressedonce = true;
 
				}

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && buttonpressedonce && !reducemenu)
				{

					reducemenu = true;

				}
				if ((300 <= GetMousePosition().x) && (GetMousePosition().x <= 650) && (400 <= GetMousePosition().y) && (GetMousePosition().y <= 550) && reducemenu)
				{



					if (menuforhardness > 600)
					{
						menuforhardness -= 25;
					}

					if (menuforhardness == 600)
					{
						playbuttonclickled = false;
						buttonpressedonce = false;
						reducemenu = false;
					}

				}


			}

		} break;
		case GAMEPLAY:
		{
			if (!GameHasEnded)
			{

				mainloop(&player1, &ai1, &current_square, hardness, &GameHasEnded , &playerc , &aic);

				if (!shipinfoshowed)
				{
					std::cout << "Firstship:" << ai1.firstship_player.getfirstsquare().name << std::endl;
					std::cout << "secondship:" << ai1.secondship_player.getfirstsquare().name << std::endl;
					std::cout << "thirdship:" << ai1.thirdship_player.getfirstsquare().name << std::endl;
					std::cout << "Firstshippl_first:" << player1.firstship_player.getfirstsquare().name << std::endl;
					std::cout << "secondshippl_first:" << player1.secondship_player.getfirstsquare().name << std::endl;
					std::cout << "thirdshippl_first:" << player1.thirdship_player.getfirstsquare().name << std::endl;
					std::cout << "Firstshippl_second:" << player1.firstship_player.getsecondsquare().name << std::endl;
					std::cout << "secondshippl_second:" << player1.secondship_player.getsecondsquare().name << std::endl;
					std::cout << "thirdshippl_second:" << player1.thirdship_player.getsecondsquare().name << std::endl;
					std::cout << "Firstshippl_third:" << player1.firstship_player.getthirdsquare().name << std::endl;
					std::cout << "secondshippl_third:" << player1.secondship_player.getthirdsquare().name << std::endl;
					std::cout << "thirdshippl_third:" << player1.thirdship_player.getthirdsquare().name << std::endl;
					std::cout << "firstshippl:" << player1.firstship_player.getshipangle() << std::endl;
					std::cout << "secondshippl:" << player1.secondship_player.getshipangle() << std::endl;
					std::cout << "thirdshippl:" << player1.thirdship_player.getshipangle() << std::endl;
					std::cout << "firstship_secondsuqx:" << player1.firstship_player.getsecondsquare_x() << std::endl;
					std::cout << "secondship_secondsuqx:" << player1.secondship_player.getsecondsquare_x() << std::endl;
					std::cout << "thirdship_secondsuqx:" << player1.thirdship_player.getsecondsquare_x() << std::endl;
					shipinfoshowed = true;

				}

				milisecond++;

				if (milisecond == 60)
				{
					milisecond %= 60;
					second++;

				}
				if (second == 60)
				{
					second %= 60;
					min++;
				}

			
			}
			else
			{
				currentScreen = ENDING;
			}
			
			
		} break;
		case ENDING:
		{
			
			// Press enter to return to TITLE screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
				return 0;
			}
		} break;
		default: break;
		}



	BeginDrawing();

		ClearBackground(WHITE);


		switch (currentScreen)
		{
		case LOGO:
		{
			
			DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
			DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

		} break;
		case TITLE:
		{
			
			DrawTextureEx(Coverart_tex, { 0,-40 }, 0, 0.688, LIGHTGRAY);
			gameplayscreen.ashanimation(ash_tex, 20);
			gameplayscreen.StartingScreen(buttonfrontpage_tex,Coverart_tex , buttonfrontpage_oncursor_tex, Logomain_tex, buttonsize , &buttonppos);

			if (playbuttonclickled)
			{

				//DrawRectangle(300, 600, 350, menuforhardness - 600, DARKGRAY);
				DrawRectangleRounded({ 300, 600, 350, (float)menuforhardness - 600 }, 0.3, 8, { 150,10,10,220 });
				if (menuforhardness >= 850)
				{

					if ((300 <= GetMousePosition().x) && (GetMousePosition().x <= 650) && (630 <= GetMousePosition().y) && (GetMousePosition().y <= 810))
					{

						int y = (GetMouseY() - (GetMouseY() % 70));
						Color lightred = { 255,0,0,20 };
						//DrawRectangle(300, y, 350, 70, { 50,70,100,180 });
						DrawRectangleRounded({ 300, (float)y, 350, 70 }, 0.2, 8, { 50,70,100,180 });

						if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						{

							if ((630 <= GetMousePosition().y) && (GetMousePosition().y <= 700) && (300 <= GetMousePosition().x) && (GetMousePosition().x <= 650))
							{
								hardness = "easy";
								std::cout << hardness << std::endl;
								currentScreen = GAMEPLAY;
							}
							if ((700 <= GetMousePosition().y) && (GetMousePosition().y <= 770) && (300 <= GetMousePosition().x) && (GetMousePosition().x <= 650))
							{
								hardness = "medium";
								std::cout << hardness << std::endl;
								currentScreen = GAMEPLAY;
							}
							if ((770 <= GetMousePosition().y) && (GetMousePosition().y <= 840) && (300 <= GetMousePosition().x) && (GetMousePosition().x <= 650))
							{
								hardness = "hard";
								std::cout << hardness << std::endl;
								currentScreen = GAMEPLAY;
							}
						}

					}

					DrawText("Easy", 350, 650, 30, {0,10,120,255});
					DrawText("Medium", 350, 720, 30, { 0,10,120,255 });
					DrawText("Hard", 350, 790, 30, { 0,10,120,255 });

				}

			}

			

		} break;
		case GAMEPLAY:
		{
			
			gameplayscreen.GamePlayScreen(Squares_tex , background_tex, font1);

			DrawText(TextFormat("Time: %i ", min), (squarepix_x * 5) , 10, 20, BLACK);
			DrawText(TextFormat(": %i", second), (squarepix_x * 5) + 85, 10, 20, BLACK);

			gameplayscreen.drawscores(&ai1 , 2*squarepix_x+10,squarepix_x/2-25);
			gameplayscreen.drawscores(&player1, 9 * squarepix_x - 10, squarepix_x / 2 - 25);

			gameplayscreen.DrawShip(&player1, shiptoleft_tex,shiptoright_tex);


			gameplayscreen.drawwhitecross(white_cross_tex, whitex, whitey, &current_square);
			gameplayscreen.shipshot(&ai1.firstship_player, red_cross_tex);
			gameplayscreen.shipshot(&ai1.secondship_player, red_cross_tex);
			gameplayscreen.shipshot(&ai1.thirdship_player, red_cross_tex);
			gameplayscreen.shipshot(&player1.firstship_player, red_cross_tex);
			gameplayscreen.shipshot(&player1.secondship_player, red_cross_tex);
			gameplayscreen.shipshot(&player1.thirdship_player, red_cross_tex);


			if (player1.thisplayersturn == true)
			{
				if ((!((GetMouseX() <= squarepix_x) || (GetMouseY() <= (squarepix_x * 2)))&& GetMouseX()< screenw && GetMouseY() < screenh))
				{
					gameplayscreen.selectsquare(squareindicator_tex);

				}
			}
			

		} break;
		case ENDING:
		{
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
			gameplayscreen.EndingScreen(&player1, &ai1, font2);
			DrawText(TextFormat("Time : %i  ", min), (squarepix_x * 5)-60, screenh/2 +20, 30, BLACK);
			DrawText(TextFormat(" :  %i", second), (squarepix_x * 5) + 65, screenh / 2 +20, 30, BLACK);
			if (player1.HasWon)gameplayscreen.thropyAnimator(thropyatlas);

		} break;
		default: break;
		}


		f_fullscreen();

		DrawFPS(15, 15);

	EndDrawing();

	}

	 delete(whitex);
	 delete(whitey);

	UnloadTexture(Squares_tex);
	UnloadTexture(squareindicator_tex);
	UnloadTexture(shiptoleft_tex);
	UnloadTexture(shiptoright_tex);
	UnloadTexture(background_tex);
	UnloadTexture(buttonfrontpage_tex);
	UnloadTexture(Coverart_tex);
	UnloadTexture(red_cross_tex);
	UnloadTexture(white_cross_tex);
	UnloadTexture(buttonfrontpage_oncursor_tex);
	UnloadTexture(ash_tex);
	UnloadTexture(Logomain_tex);
	UnloadTexture(thropyatlas);
	UnloadFont(font1);
	UnloadFont(font2);
	
	

	CloseWindow();

	return 0;
}

