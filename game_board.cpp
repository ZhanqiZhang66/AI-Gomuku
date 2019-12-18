// game_board.cpp : Defines the  game board for the game 
// ========lab3
//Author: Zhanqi Zhang 450455 
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The Lab3 program is used to build and play the tic-tac-toe game
//         =>This program is used to read in and test the dimension of the game board, 
//			 and read in and print every lines for the game.


#include "stdafx.h"
#include "lab4.h"
#include "game.h"
#include "game_board.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//This function is used to read in the dimensions of a game board with its row and column variables
//from its input file stream
//Parameters: a reference to input file stream; unsigned int #row ; unsigned int #column
//Output: int value indicating whether the reading is successed.
int dimension(ifstream & ifs, unsigned int & row, unsigned int & col)
{
	string line;

	if (getline(ifs, line)) {
		istringstream  temp(line);
		if ((temp >> row) && (temp >> col)) {
			return success;
		}
		else {
			cout << "The dimension of the game is incorrect." << endl;
			cout << "Please adjust the the dimension" << endl;
			return wrongDimension;
		}
	}
	else {
		cout << "Fail to read lines." << endl;
		return cannotReadALine;
	}
}
//This funtion is used to read in game pieces form an input file stream.
//Parameters: a reference to input file stream; a reference to a vector of game pieces; two unsigned int by value
//Output: int value to indicating success and other situations
int reading_in_game(ifstream & ifs, vector<game_piece>& game_def, unsigned int row, unsigned int col)
{
	string line;
	bool flag = false;
	while (getline(ifs, line)) {

		istringstream temp(line);
		string color;
		string name;
		string display;

		unsigned int hori;
		unsigned int vert;
		if ((temp >> color) && (temp >> name) && (temp >> display) && (temp >> hori) && (temp >> vert)) {
			passing_name(color);
			if (!(hori <= row && vert <= col)) {
				continue;
			}
			if (passing_name(color) == invalid) {
				continue;
			}
			else {
				int index;
				index = col*vert + hori;

				game_def[index].c_ = passing_name(color);
				game_def[index].display_as_ = display;
				game_def[index].name_ = name;

				flag = true;
			}

		}
		else {
			continue;
		}
	}
	if (flag) {
		return success;
	}
	else {
		cout << "Fail to contruct the game with the given definition. " << endl;
		return failedDef;
	}
}
//This is the function that print out the gameboard
//Parameters: const vector of game pieces, two unsigned int by values
//Output: int value indicating success and other specific reason that it failed
int lay_out(const vector<game_piece>& pieces, unsigned int row, unsigned int col)
{
	if (pieces.size() == (row *col)) {
		for (int j = row - 1; j >= 0; --j) {
			for (unsigned int i = 0; i <= col - 1; ++i) {
				cout << pieces[col * j + i].display_as_;
			}
			cout << endl;
		}
		return success;
	}
	else {
		cout << "The dimension of the game board does not match that of the game pieces." << endl;
		return dimensionNotMatched;
	}
}