#pragma once
// game_board.h : This is the header file for game_board.cpp
// ========lab3
//Author: Zhanqi Zhang 450455 
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The Lab3 program is used to build and play the tic-tac-toe game 
//         =>This head file is used declare and define functions, enumerations and other features to the program
#include <iostream>
#include <vector>
#include <string>
#include "game.h"
using namespace std;
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

//Define a function that used in game_board.cpp
int dimension(ifstream & ifs, unsigned int & row, unsigned int & col);
int reading_in_game(ifstream & ifs, vector<game_piece> & game_def, unsigned int x, unsigned int y);
int lay_out(const vector<game_piece>& pieces, unsigned int a, unsigned int b);

#endif