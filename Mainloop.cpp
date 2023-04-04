#include <iostream>
#include "Mainloop.h"
#include "Squarelib.h"
#include "Game.h"



//Main function for the games loop system.
void mainloop(player* player1, AI* ai1 , square *current_square ,std::string hardness , bool *gamehasended , checkifshipsinked *player , checkifshipsinked *ai) {



	if (!(player1->HasWon) && !(ai1->HasWon)) {

		if (player1->thisplayersturn == true)
		{
			if ((!((GetMouseX() <= squarepix_x) || (GetMouseY() <= (squarepix_x * 2))))) {

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					player1->CreateSquareFromMousePos(current_square);
					ai1->firstship_player.IsShipSinked(current_square);
					ai1->secondship_player.IsShipSinked(current_square);
					ai1->thirdship_player.IsShipSinked(current_square);

					std::cout << "current square is : "<<current_square->getname() << std::endl;

					if (ai1->firstship_player.isshipsinked && !ai->firstshipsinked)
					{
						ai1->TimesShipWasSinked++;
						ai->firstshipsinked = true;
						
					}

					if (ai1->secondship_player.isshipsinked && !ai->secondshipsinked)
					{
						ai1->TimesShipWasSinked++;
						ai->secondshipsinked = true;

					}

					if (ai1->thirdship_player.isshipsinked && !ai->thirdshipsinked)
					{
						ai1->TimesShipWasSinked++;
						ai->thirdshipsinked = true;

					}

					if (ai1->TimesShipWasSinked == 3)
					{
						player1->thisplayerwon();
						
					}
					
					player1->thisplayersturn = false;
					ai1->take_turn();
					
				}
			}
		}
		if (ai1->thisplayersturn == true)
		{
			
			square currentsq;
			static int previoussq_x_first[100];
			static int previoussq_y_first[100];
			static int previoussq_x_second[100];
			static int previoussq_y_second[100];
			static int previoussq_x_third[100];
			static int previoussq_y_third[100];
			static bool shotship = false;
			static bool lockfirst = false;
			static bool locksecond = false;
			static bool lockthird = false;
			

			if (ai1->aimoved)
			{

				if (hardness == "easy")
				{
					std::cout << "reached to easy" << std::endl;

					int chooseship = GiveRandomSquarePos(1, 3, 10, false, 20);

				aiturneasy:
					
					 chooseship = GiveRandomSquarePos(1, 3, 10, false, 20);

						if ((chooseship == 1) && !(player1->firstship_player.isshipsinked))
						{
							currentsq = ai1->easyAI(&(player1->firstship_player), previoussq_x_first, previoussq_y_first, chooseship);
						}

						if ((chooseship == 1) && (player1->firstship_player.isshipsinked))
						{
							goto aiturneasy;
						}


						if ((chooseship == 2) && !(player1->secondship_player.isshipsinked))
						{
							currentsq = ai1->easyAI(&(player1->secondship_player), previoussq_x_first, previoussq_y_first, chooseship);
						}

						if ((chooseship == 2) && (player1->secondship_player.isshipsinked))
						{
							goto aiturneasy;
						}


						if ((chooseship == 3) && !(player1->thirdship_player.isshipsinked))
						{
							currentsq = ai1->easyAI(&(player1->thirdship_player), previoussq_x_first, previoussq_y_first, chooseship);
						}

						if ((chooseship == 3) && (player1->thirdship_player.isshipsinked))
						{
							goto aiturneasy;
						}


						std::cout << "ai shot : " << currentsq.getname() << std::endl;
					
				}
				if (hardness == "medium")
				{
					int chooseship = NULL;

				aiturnmedium:
					if (!shotship)
					{
						chooseship = GiveRandomSquarePos(1, 3, 45, false, 20);
					}

					//first
					if ((player1->firstship_player.getfirstsquare().thissquarewasshot || player1->firstship_player.getsecondsquare().thissquarewasshot || player1->firstship_player.getthirdsquare().thissquarewasshot) && !player1->firstship_player.isshipsinked && !lockfirst)
					{
						shotship = true;
						locksecond = true;
						lockthird = true;
						chooseship = 1;
						std::cout << "reached the first one" << std::endl;

					}
					if (player1->firstship_player.isshipsinked && !lockfirst)
					{
						shotship = false;
						locksecond = false;
						lockfirst = true;
						lockthird = false;
						chooseship = GiveRandomSquarePos(1, 3, 45, false, 20);

					}
					

					//second
					if ((player1->secondship_player.getfirstsquare().thissquarewasshot || player1->secondship_player.getsecondsquare().thissquarewasshot || player1->thirdship_player.getthirdsquare().thissquarewasshot) && !player1->secondship_player.isshipsinked && !locksecond)
					{
						shotship = true;
						lockfirst = true;
						lockthird = true;
						chooseship = 2;
						std::cout << "reached the second one" << std::endl;

					}
					if (player1->secondship_player.isshipsinked && !locksecond)
					{
						shotship = false;
						lockfirst = false;
						locksecond = true;
						lockthird = false;
						chooseship = GiveRandomSquarePos(1, 3, 45, false, 20);

					}
					

					//third
					if ((player1->thirdship_player.getfirstsquare().thissquarewasshot || player1->thirdship_player.getsecondsquare().thissquarewasshot || player1->thirdship_player.getthirdsquare().thissquarewasshot) && !player1->thirdship_player.isshipsinked && !lockthird)
					{
						shotship = true;
						lockfirst = true;
						locksecond = true;
						chooseship = 3;
						std::cout << "reached the third one" << std::endl;

					}
					if (player1->thirdship_player.isshipsinked && !lockthird)
					{
						shotship = false;
						lockfirst = false;
						lockthird = true;
						locksecond = false;
						chooseship = GiveRandomSquarePos(1, 3, 45, false, 20);

					}
					

						if ((chooseship == 1) && !(player1->firstship_player.isshipsinked))
						{
							currentsq = ai1->mediumAI(&(player1->firstship_player), previoussq_x_first , previoussq_y_first, chooseship);
						}

						if ((chooseship == 1) && (player1->firstship_player.isshipsinked))
						{
							
							goto aiturnmedium;
						}


						if ((chooseship == 2) && !(player1->secondship_player.isshipsinked))
						{
							currentsq = ai1->mediumAI(&(player1->secondship_player),previoussq_x_second , previoussq_y_second , chooseship);
						}

						if ((chooseship == 2) && (player1->secondship_player.isshipsinked))
						{
							
							goto aiturnmedium;
						}


						if ((chooseship == 3) && !(player1->thirdship_player.isshipsinked))
						{
							currentsq = ai1->mediumAI(&(player1->thirdship_player), previoussq_x_third , previoussq_y_third , chooseship);
						}

						if ((chooseship == 3) && (player1->thirdship_player.isshipsinked))
						{
							
							goto aiturnmedium;
						}


						std::cout << "ai shot : " << currentsq.getname() << std::endl;
					
				}
				if (hardness == "hard")
				{
					int chooseship = GiveRandomSquarePos(1, 3, 10, false, 20);
					if (chooseship == 1)
					{
						currentsq = ai1->hardAI(&(player1->firstship_player), previoussq_x_first, previoussq_y_first, chooseship);
					}
					if (chooseship == 2)
					{
						currentsq = ai1->hardAI(&(player1->secondship_player), previoussq_x_first, previoussq_y_first, chooseship);
					}
					if (chooseship == 3)
					{
						currentsq = ai1->hardAI(&(player1->thirdship_player), previoussq_x_first, previoussq_y_first, chooseship);
					}


					
				}

				player1->firstship_player.IsShipSinked(&currentsq);
				player1->secondship_player.IsShipSinked(&currentsq);
				player1->thirdship_player.IsShipSinked(&currentsq);

				if (player1->firstship_player.isshipsinked && !player->firstshipsinked)
				{
					player1->TimesShipWasSinked++;
					player->firstshipsinked = true;

				}

				if (player1->secondship_player.isshipsinked && !player->secondshipsinked)
				{
					player1->TimesShipWasSinked++;
					player->secondshipsinked = true;

				}

				if (player1->thirdship_player.isshipsinked && !player->thirdshipsinked)
				{
					player1->TimesShipWasSinked++;
					player->thirdshipsinked = true;

				}

				if (player1->TimesShipWasSinked == 3)
				{
					ai1->thisplayerwon();
				}

				ai1->aimoved = false;
				ai1->thisplayersturn = false;
				player1->take_turn();
			}
			else
			{
				static int milisecond_f = 0;

				static int second_f = 0;

				
					milisecond_f++;

					if (milisecond_f == 60)
					{
						milisecond_f %= 60;
						second_f++;

					}
					if (second_f == 5)
					{
						second_f %= 5;
						ai1->aimoved = true;
						
					}

			}

			

		
		}

	}
	else
	{

	  *gamehasended = true;

	}
	
}


