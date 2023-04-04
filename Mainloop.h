#pragma once
#include <iostream>
#include "Squarelib.h"
#include "Game.h"

//Main function for the games loop system.
void mainloop(player* player1, AI* ai1 , square* current_square, std::string hardness, bool* gamehasended, checkifshipsinked* player, checkifshipsinked* ai);


