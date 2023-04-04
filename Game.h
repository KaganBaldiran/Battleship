#pragma once
#include <iostream>
#include <string>
#include "Squarelib.h"


class game {
public:


	void initilize();

		
};

class AI : public player {
public:
	std::string playername;

	bool aimoved;

	square easyAI(ship* ship1, static int previoussq_x[], static int previoussq_y[], int chooseship);

	square mediumAI(ship* ship1, static int previoussq_x[], static int previoussq_y[], int chooseship);

	square hardAI(ship* ship1, static int previoussq_x[], static int previoussq_y[], int chooseship);

};

//toggle fullscreen
void f_fullscreen();







