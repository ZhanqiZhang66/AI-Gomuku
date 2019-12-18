#pragma once
// game.h : This is the header file of game.cpp

//lab4
//Team : Amanda
//	Team memebers : Zhanqi Zhang, Zuyu Liao, Xinyi Wu

//Purpose: =>The Lab4 program is used to build and play the tic-tac-toe game
//         =>This head file is used declare and define functions, enumerations and other features to the program

#include <iostream>
#include <vector>
#include <string>

using namespace std;
#ifndef GAME_H
#define GAME_H

//Declare enum for piece colors
enum color {
	red = 0, RED = 0, black = 1, BLACK = 0, white = 2, WHITE = 2, invalid = 3, no_color = 4, blue = 5, BLUE = 5
};



//Declare and define a struct to represent a game piece
struct game_piece {
	color c_;
	string name_;
	string display_as_;
};

#endif