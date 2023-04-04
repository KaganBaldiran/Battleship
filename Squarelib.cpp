#include "Squarelib.h"
#include "Game.h"
#include <iostream>
#include <raylib.h>
#include <string>

checkifshipsinked::checkifshipsinked()
{
	firstshipsinked = false;
	secondshipsinked = false;
	thirdshipsinked = false;

}



void player::take_turn() {

	thisplayersturn = true;

}


bool player::thisplayerwon() {

	HasWon = true;
	return HasWon;

}


void square::assignpos(int xpos, int ypos) {

	xpos = xpos;
	ypos = ypos;

}


int square::getsquareposX() {

	return xpos;

}

int square::getsquareposY() {

	return ypos;

}

std::string square::getname() {


	return name;

}


ship::~ship() {

}

//Create a new ship with an initial position and name
ship::ship() {

	static int shipinstance = 0;

	static int sq1_x[100];
	static int sq1_y[100];
	static int sq2_x[100];
	static int sq2_y[100];
	static int sq3_x[100];
	static int sq3_y[100];
	

	std::string temp;
	static bool flagtosave = false;
	static int x1 = 0;
	static bool goback = false;
	

	std::string name1 = "Destroyer " + std::to_string(shipinstance + 1);

	int tempx;
	int tempy;

	squaressame:
	tempx = GiveRandomSquarePos(1,10,45,false,20) ;
	tempy = GiveRandomSquarePos(2,11,45,false,20) ;

	
	int numbers[10] = { '1','2','3','4','5','6','7','8','9','10' };
	char letters[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	
	int angle[2] = {0,90};

	shipname = name1;
	FirstSquare.xpos = tempx *squarepix_x;
	FirstSquare.ypos = tempy *squarepix_x;
	FirstSquare.name = CreateSquareName(tempx, tempy);
	shipangle = angle[GiveRandomSquarePos(0, 1, 40, false, 10)];

	if (shipangle == 90){

		
		if ((FirstSquare.ypos >= (9 * squarepix_y)))
		{
			SecondSquare.ypos = (FirstSquare.ypos - squarepix_x);
			ThirdSquare.ypos = (SecondSquare.ypos - squarepix_x);
			SecondSquare.xpos = (FirstSquare.xpos) ;
			ThirdSquare.xpos = (SecondSquare.xpos) ;
		}
		else
		{
			SecondSquare.ypos = (FirstSquare.ypos + squarepix_x);
			ThirdSquare.ypos = (SecondSquare.ypos + squarepix_x);
			SecondSquare.xpos = (FirstSquare.xpos);
			ThirdSquare.xpos = (SecondSquare.xpos);

		}
		
	}
	if (shipangle == 0)
	{
		
		if ((FirstSquare.xpos >= (9 * squarepix_x)))
		{
			SecondSquare.xpos = (FirstSquare.xpos - squarepix_x);
			ThirdSquare.xpos = (SecondSquare.xpos - squarepix_x);
			SecondSquare.ypos = (FirstSquare.ypos);
			ThirdSquare.ypos = (SecondSquare.ypos);
		}
		else
		{
			SecondSquare.xpos = (FirstSquare.xpos + squarepix_x);
			ThirdSquare.xpos = (SecondSquare.xpos + squarepix_x);
			SecondSquare.ypos = (FirstSquare.ypos);
			ThirdSquare.ypos = (SecondSquare.ypos);


		}
		
	}

	SecondSquare.name = CreateSquareName((SecondSquare.xpos/squarepix_x), (SecondSquare.ypos/squarepix_x));
	ThirdSquare.name = CreateSquareName((ThirdSquare.xpos/squarepix_x),( ThirdSquare.ypos/squarepix_x));
	
	
		for (size_t i = 0; i < x1; i++)
		{
			if (comparesqpositions(sq1_x[i],sq1_y[i],FirstSquare.xpos, FirstSquare.ypos) || comparesqpositions(sq1_x[i], sq1_y[i], SecondSquare.xpos, SecondSquare.ypos) || comparesqpositions(sq1_x[i],sq1_y[i],ThirdSquare.xpos, ThirdSquare.ypos))
			{
				
				goback = true;
					
			}
			if (comparesqpositions(sq2_x[i],sq2_y[i],FirstSquare.xpos, FirstSquare.ypos) || comparesqpositions(sq2_x[i], sq2_y[i],SecondSquare.xpos, SecondSquare.ypos) || comparesqpositions(sq2_x[i],sq2_y[i],ThirdSquare.xpos, ThirdSquare.ypos))
			{
				
				goback = true;
					
			}
			if (comparesqpositions(sq3_x[i], sq3_y[i],FirstSquare.xpos, FirstSquare.ypos) || comparesqpositions(sq3_x[i],sq3_y[i],SecondSquare.xpos, SecondSquare.ypos) || comparesqpositions(sq3_x[i],sq3_y[i],ThirdSquare.xpos, ThirdSquare.ypos))
			{
				
				goback = true;
			
			}
		}
	
	if (goback)
	{
		goback = false;
		flagtosave = false;
		std::cout << "back again3" << std::endl;
		goto squaressame;
	}
	if(!goback)
	{
		flagtosave = true;

	}


		if (flagtosave)
		{
			sq1_x[x1] = this->FirstSquare.getsquareposX();
			sq1_y[x1] = this->FirstSquare.getsquareposY();

			sq2_x[x1] = this->SecondSquare.getsquareposX();
			sq2_y[x1] = this->SecondSquare.getsquareposY();

			sq3_x[x1] = this->ThirdSquare.getsquareposX();
			sq3_y[x1] = this->ThirdSquare.getsquareposY();

			std::cout << sq1_x[x1] << std::endl;
			x1++;
			flagtosave = false;
		}
	

	shipinstance++;

	isshipsinked = false;
}

int ship::getfirstsquare_x() {

	return FirstSquare.xpos;

}

int ship::getfirstsquare_y() {

	return FirstSquare.ypos;

}

int ship::getsecondsquare_x() {

	return SecondSquare.xpos;

}

int ship::getsecondsquare_y() {

	return SecondSquare.ypos;

}

int ship::getthirdsquare_x() {

	return ThirdSquare.xpos;

}

int ship::getthirdsquare_y() {

	return ThirdSquare.ypos;

}

int ship::getshipangle() {

	return shipangle;

}

square ship::getfirstsquare() {

	return FirstSquare;
}

square ship::getsecondsquare() {

	return SecondSquare;
}

square ship::getthirdsquare() {

	return ThirdSquare;

}


//giving random numbers in a range of given values
int GiveRandomSquarePos(int min, int max, int sizeofarray, bool exclude_on_off, int numtoexclude) {

	static int timesthisfunctioncalled = 0;
	int* randarray = new int[sizeofarray];
	int finalresult;

	SetRandomSeed(time(NULL));

	for (size_t i = 0; i < sizeofarray; i++)
	{

		randarray[i] = GetRandomValue(min, max);
		if (exclude_on_off == true)
		{
			if (randarray[i] == numtoexclude)
			{

				i--;

			}

		}

	}

	timesthisfunctioncalled++;

	if (timesthisfunctioncalled >= sizeofarray)
	{
		timesthisfunctioncalled = (timesthisfunctioncalled % sizeofarray);
	}

	finalresult = randarray[timesthisfunctioncalled];
	delete[] randarray;
	return finalresult;

}

//check if the cursor is on the desired area
int IsCursorOnSquares(int initial_x , int end_x , int initial_y , int end_y) {

	if ((initial_x < GetMouseX() < end_x) && (initial_y < GetMouseY() < end_y))
	{
		return 1;
	}
	else
	{
		return 0;
		
	}

}

//comparing two squares by their positions
int compare_names(square square1 , square square2){

	if (square1.getname() == square2.getname())
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
//standalone function to create square name from positions
std::string CreateSquareName(int x , int y) {

	int numbers[10] = { '1','2','3','4','5','6','7','8','9','10' };
	char letters[10] = { 'A','B','C','D','E','F','G','H','I','J' };

	int i = x;
	int j = y;

	char word[2];
	word[0] = letters[j-2];
	word[1] = numbers[i-1];

	int sizeofarray = sizeof(word);
	std::string newword;

	int p = 0;
	while (p < sizeofarray) {

		newword = newword + word[p];
		p++;
	}

	return newword;

}

int settimer(int time)
{
	static int milisecond_f = 0;
	static int second_f = 0;


	milisecond_f++;

	if (milisecond_f == 60)
	{
		milisecond_f %= 60;
		second_f++;

	}
	if (second_f == time)
	{
		second_f %= time;
		return 1;
	
	}
	
}

//creating squares from current mousepos
std::string player::CreateSquareFromMousePos(square *first) {

	int numbers[10] = {'1','2','3','4','5','6','7','8','9','10'};
	char letters[10] = { 'A','B','C','D','E','F','G','H','I','J'};

	static int squareinstance = 0;

	square *newsquare = new (square);

	int i;
	int j;

	i = GetMousePosition().x;
	j = GetMousePosition().y;
	i = ((i - (i % squarepix_x)) / squarepix_x);
	j = ((j - (j % squarepix_x)) / squarepix_x);
	char word[2];
	word[0] = letters[j-2];
	word[1] = numbers[i-1];

	int sizeofarray = sizeof(word);
	std::string newword;

	int p = 0;
	while (p < sizeofarray) {

		newword = newword + word[p];
		p++;
	}

	newsquare->assignpos(i* squarepix_x, j* squarepix_x);

	//create the names according to positions
	newsquare->name = newword;

	squareinstance++;

	first->name = newword;

	first->xpos = (i * squarepix_x);
	first->ypos = (j * squarepix_x);

	return newword;

}
//Once its needed to input a square for the following function , "CreateSquareFromMousePos" will be called thus creating 
//the current square to compare with the squares which are related to the ships.

//Check if the square the player chooses is related to the ship. If so mark it as shot and once all three squares are shot
//declare the current ship as sinked and exclude it out of the game
void ship::IsShipSinked(square *current_square) {

	square newchosensquare;
	newchosensquare.assignpos(current_square->getsquareposX(),current_square->getsquareposY());
	newchosensquare.name = current_square->getname();

	if (!isshipsinked) {

		if (compare_names(newchosensquare , getfirstsquare()))
		{
			
			if (FirstSquare.thissquarewasshot != true) 
			{
				timesshipshot++;
				if (timesshipshot == 3) {

					isshipsinked = true;

					
				}

				FirstSquare.thissquarewasshot = true;
				
			}
		}
		if (compare_names(newchosensquare, getsecondsquare()))
		{

			if (SecondSquare.thissquarewasshot != true)
			{
				timesshipshot++;
				if (timesshipshot == 3) {

					isshipsinked = true;

				}

				SecondSquare.thissquarewasshot = true;
			}


		}
		if (compare_names(newchosensquare, getthirdsquare()))
		{

			if (ThirdSquare.thissquarewasshot != true)
			{
				timesshipshot++;
				if (timesshipshot == 3) {

					isshipsinked = true;


				}

				ThirdSquare.thissquarewasshot = true;
			}


		}
	}


}

int comparesqpositions(int xpos1, int ypos1, int xpos2, int ypos2)
{
	if ((xpos1 == xpos2) && (ypos1 == ypos2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}







