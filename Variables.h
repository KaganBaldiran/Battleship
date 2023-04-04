#pragma once

bool playbuttonclickled = false;

bool reducemenu = false;

int menuforhardness = 600;

bool easypressed = false;

float buttonsize = 1000;

int framesCounter = 0;

bool buttonpressedonce = false;

bool shipinfoshowed = false;

int milisecond = 0;

int second = 0;

int min = 0;

bool firstsq = false;
bool secondsq = false;
bool thirdsq = false;

int *whitex = new(int[200]);

int* whitey = new(int[200]);

checkifshipsinked playerc;

checkifshipsinked aic;

std::string hardness;

Vector2 buttonppos = { (screenw / 2) - (screenw / 4), (screenh / 2) - (screenw / 4) };