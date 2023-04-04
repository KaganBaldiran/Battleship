#pragma once
#include <time.h>
#include <iostream>
#include <raylib.h>
#include <string>
#define screenw 880
#define screenh 960
#define squarepix_x (screenw/11)
#define squarepix_y (screenh/12)

class checkifshipsinked
{
public:

	bool firstshipsinked;
	bool secondshipsinked;
	bool thirdshipsinked;

	checkifshipsinked();

};

struct chosensquare
{
	int productx;
	int producty;
	struct finalsquare* next;

};

//class where all the data created for an instance of square will be stored at
class square {
public:

	int xpos;
	int ypos;
	std::string name;
	square* next;
	bool thissquarewasshot;

	void assignpos(int xpos, int ypos);

	int getsquareposX();

	int getsquareposY();

	std::string getname();

};

//class where the data of a ship is stored
class ship {

public:

	square FirstSquare;
	square SecondSquare;
	square ThirdSquare;
	int shipangle;
	std::string shipname;
	int timesshipshot;
	bool isshipsinked;



	ship* next;

	ship();

	int getfirstsquare_x();

	int getfirstsquare_y();

	int getsecondsquare_x();

	int getsecondsquare_y();

	int getthirdsquare_x();

	int getthirdsquare_y();

	square getfirstsquare();

	square getsecondsquare();

	square getthirdsquare();


	int getshipangle();


	void IsShipSinked(square* current_square);

	~ship();
};

class player {
public:

	ship firstship_player ;
	ship secondship_player ;
	ship thirdship_player ;
	bool HasWon;
	bool thisplayersturn;

	int TimesShipWasSinked;

	std::string playername;

	bool thisplayerwon();

	void take_turn();

	//creating squares from current mousepos
	std::string CreateSquareFromMousePos(square* first);

};

//giving random numbers in a range of given values
int GiveRandomSquarePos(int min, int max, int sizeofarray, bool exclude_on_off, int numtoexclude);
//check if the cursor is on the desired area
int IsCursorOnSquares(int initial_x, int end_x, int initial_y, int end_y);
//comparing two squares by their positions
int compare_names(square square1, square square2);
//standalone function to create square name from positions
std::string CreateSquareName(int x, int y);
int settimer(int time);

int comparesqpositions(int xpos1, int ypos1 , int xpos2, int ypos2);













