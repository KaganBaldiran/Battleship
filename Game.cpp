#include "Game.h"
#include "Squarelib.h"
#include <iostream>

void game::initilize() {




}

square AI::easyAI(ship* ship1, static int previoussq_x[], static int previoussq_y[], int chooseship) {

	Vector2 temp_init;
	Vector2 temp_end;
	square square1;
	static int presq = 0;
	static bool firstsqshotbyai = false;
	static bool secondsqshotbyai = false;
	static bool thirdsqshotbyai = false;
	static bool sqincr = false;

	temp_init.x = (ship1->getsecondsquare_x() - 2 * squarepix_x) / squarepix_x;
	temp_end.x = (ship1->getsecondsquare_x() + 2 * squarepix_x) / squarepix_x;
	temp_init.y = (ship1->getsecondsquare_y() - 2 * squarepix_x) / squarepix_x;
	temp_end.y = (ship1->getsecondsquare_y() + 2 * squarepix_x) / squarepix_x;


	if (ship1->getsecondsquare_x() <= 4 * squarepix_x)
	{
		temp_init.x = 1;
		temp_end.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (ship1->getsecondsquare_x() - squarepix_x))) / squarepix_x;

		if (temp_end.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_x() + 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached first if" << std::endl;
	}
	if (ship1->getsecondsquare_x() >= 8 * squarepix_x)
	{
		temp_init.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;
		temp_end.x = 10;
		if (temp_init.x > 10)
		{
			temp_init.x = (ship1->getsecondsquare_x() - (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;

		}
		if (temp_init.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_init.x = (ship1->getsecondsquare_x() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached second if" << std::endl;
	}
	if (ship1->getsecondsquare_y() <= 5 * squarepix_x)
	{
		temp_init.y = 2;
		temp_end.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (ship1->getsecondsquare_y() - squarepix_x))) / squarepix_x;

		if (temp_end.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_y() + 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached third if" << std::endl;
	}
	if (ship1->getsecondsquare_y() >= 9 * squarepix_x)
	{
		temp_end.y = 11;
		temp_init.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;

		if (temp_init.y > 11)
		{

			temp_init.y = (ship1->getsecondsquare_y() - (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;


		}
		if (temp_init.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_init.y = (ship1->getsecondsquare_y() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached fourth if" << std::endl;
	}

	square1.xpos = GiveRandomSquarePos(temp_init.x, temp_end.x, 8, false, 20);
	square1.ypos = GiveRandomSquarePos(temp_init.y, temp_end.y, 8, false, 20);

	previoussq_x[presq] = ship1->getfirstsquare_x();
	previoussq_y[presq] = ship1->getfirstsquare_y();
	sqincr = true;

	square1.name = CreateSquareName(square1.getsquareposX(), square1.getsquareposY());

	std::cout << "presq:" << presq << std::endl;

	if (sqincr)
	{
		presq++;
		sqincr = false;
	}

	return square1;
}

square AI::mediumAI(ship *ship1 , static int previoussq_x[], static int previoussq_y[] , int chooseship) {

	Vector2 temp_init;
	Vector2 temp_end;
	square square1;
	static int presq = 0;
	static bool firstsqshotbyai= false;
	static bool secondsqshotbyai = false;
	static bool thirdsqshotbyai = false;
	static bool sqincr = false;
	
	temp_init.x = (ship1->getsecondsquare_x() - 1 * squarepix_x) / squarepix_x;
	temp_end.x = (ship1->getsecondsquare_x() + 1 * squarepix_x) / squarepix_x;
	temp_init.y = (ship1->getsecondsquare_y() - 1 * squarepix_x) / squarepix_x;
	temp_end.y = (ship1->getsecondsquare_y() + 1 * squarepix_x) / squarepix_x;


	if (ship1->getsecondsquare_x() <= 2 * squarepix_x)
	{
		temp_init.x = 1;
		temp_end.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (ship1->getsecondsquare_x() - squarepix_x))) / squarepix_x;
		
		if (temp_end.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_x() + 1 * squarepix_x) / squarepix_x;
		}
		
		std::cout << "reached first if" << std::endl;
	}
	if (ship1->getsecondsquare_x() >= 9 * squarepix_x)
	{
		temp_init.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;
		temp_end.x = 10;
		if (temp_init.x > 10)
		{
			temp_init.x = (ship1->getsecondsquare_x() - (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;

		}
		if (temp_init.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_init.x = (ship1->getsecondsquare_x() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached second if" << std::endl;
	}
	if (ship1->getsecondsquare_y() <= 3 * squarepix_x)
	{
		temp_init.y = 2;
		temp_end.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (ship1->getsecondsquare_y() - squarepix_x))) / squarepix_x;
		
		if (temp_end.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_y() + 1 * squarepix_x) / squarepix_x;
		}
		
		std::cout << "reached third if" << std::endl;
	}
	if (ship1->getsecondsquare_y() >= 10 * squarepix_x)
	{
		temp_end.y = 11;
		temp_init.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;
		
		if (temp_init.y > 11)
		{

			temp_init.y = (ship1->getsecondsquare_y() - (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;


		}
		if (temp_init.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_init.y = (ship1->getsecondsquare_y() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached fourth if" << std::endl;
	}
	

	
	square1.xpos = GiveRandomSquarePos(temp_init.x, temp_end.x, 25, false, 20);
	square1.ypos = GiveRandomSquarePos(temp_init.y, temp_end.y, 25, false, 20);


	
    previoussq_x[presq] = ship1->getfirstsquare_x();
	previoussq_y[presq] = ship1->getfirstsquare_y();
	sqincr = true;
	
	square1.name = CreateSquareName(square1.getsquareposX(), square1.getsquareposY());

	std::cout << "presq:" << presq << std::endl;

	if (sqincr)
	{
		presq++;
		sqincr = false;
	}
	
	return square1;

}

square AI::hardAI(ship* ship1, static int previoussq_x[], static int previoussq_y[], int chooseship) {

	Vector2 temp_init;
	Vector2 temp_end;
	square square1;
	static int presq = 0;
	static bool firstsqshotbyai = false;
	static bool secondsqshotbyai = false;
	static bool thirdsqshotbyai = false;
	static bool sqincr = false;

	temp_init.x = (ship1->getsecondsquare_x() - 1 * squarepix_x) / squarepix_x;
	temp_end.x = (ship1->getsecondsquare_x() + 1 * squarepix_x) / squarepix_x;
	temp_init.y = (ship1->getsecondsquare_y() - 1 * squarepix_x) / squarepix_x;
	temp_end.y = (ship1->getsecondsquare_y() + 1 * squarepix_x) / squarepix_x;


	if (ship1->getsecondsquare_x() <= 4 * squarepix_x)
	{
		temp_init.x = 1;
		temp_end.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (ship1->getsecondsquare_x() - squarepix_x))) / squarepix_x;

		if (temp_end.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_x() + 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached first if" << std::endl;
	}
	if (ship1->getsecondsquare_x() >= 8 * squarepix_x)
	{
		temp_init.x = (ship1->getsecondsquare_x() + (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;
		temp_end.x = 10;
		if (temp_init.x > 10)
		{
			temp_init.x = (ship1->getsecondsquare_x() - (2 * squarepix_x - (11 * squarepix_x - ship1->getsecondsquare_x()))) / squarepix_x;

		}
		if (temp_init.x == (ship1->getsecondsquare_x() / squarepix_x))
		{
			temp_init.x = (ship1->getsecondsquare_x() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached second if" << std::endl;
	}
	if (ship1->getsecondsquare_y() <= 5 * squarepix_x)
	{
		temp_init.y = 2;
		temp_end.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (ship1->getsecondsquare_y() - squarepix_x))) / squarepix_x;

		if (temp_end.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_end.y = (ship1->getsecondsquare_y() + 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached third if" << std::endl;
	}
	if (ship1->getsecondsquare_y() >= 9 * squarepix_x)
	{
		temp_end.y = 11;
		temp_init.y = (ship1->getsecondsquare_y() + (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;

		if (temp_init.y > 11)
		{

			temp_init.y = (ship1->getsecondsquare_y() - (2 * squarepix_x - (12 * squarepix_x - ship1->getsecondsquare_y()))) / squarepix_x;


		}
		if (temp_init.y == (ship1->getsecondsquare_y() / squarepix_x))
		{
			temp_init.y = (ship1->getsecondsquare_y() - 1 * squarepix_x) / squarepix_x;
		}

		std::cout << "reached fourth if" << std::endl;
	}



	square1.xpos = GiveRandomSquarePos(temp_init.x, temp_end.x, 8, false, 20);
	square1.ypos = GiveRandomSquarePos(temp_init.y, temp_end.y, 8, false, 20);



	previoussq_x[presq] = ship1->getfirstsquare_x();
	previoussq_y[presq] = ship1->getfirstsquare_y();
	sqincr = true;

	square1.name = CreateSquareName(square1.getsquareposX(), square1.getsquareposY());

	std::cout << "presq:" << presq << std::endl;

	if (sqincr)
	{
		presq++;
		sqincr = false;
	}

	return square1;

}

void f_fullscreen() {

	// check for alt + enter
	if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
	{
		// see what display we are on right now
		int display = GetCurrentMonitor();


		if (IsWindowFullscreen())
		{
			// if we are full screen, then go back to the windowed size
			SetWindowSize(GetScreenWidth(), GetScreenHeight());
		}
		else
		{
			// if we are not full screen, set the window size to match the monitor we are on
			SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
		}

		// toggle the state
		ToggleFullscreen();
	}

}








