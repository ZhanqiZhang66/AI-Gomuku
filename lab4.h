// Lab4.h : This is the header file for lab4.cpp
// 
//Author: Zhanqi Zhang  Zuyu Liao, Xinyi Wu
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The Lab3 program is used to build tic-tac-toe game 
//		   =>This head file is used declare and define functions, enumerations and other features to the program
#pragma once
#include "game.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef LAB4_H
#define LAB4_H

///===========================================================
//Declare enum for different array indices that are relevant 
//============================================================
enum returnValue {
	success = 0, cannotOpenFile = 1, wrongNumberArgument = 2, wrongFileType = 3, wrongDimension = 4, cannotReadALine = 5, failedDef = 6, dimensionNotMatched = 7,
	quit = 8, invalid_position = 9, bad_input = 10, run_out_of_turns = 11, notGame = 12, notNumber = 13, taken = 14, badAlloc = 15, nonpositive =16, notTicTacToe=17
};
enum argvIndexes {
	program_name = 0, input_file_name = 1, expected_num_argument = 2, with_size=3, with_win_num=4
};
enum definition {
	row = 5, col = 5, row_g = 19, col_g = 19
};
enum numberArgument {
	human_player = 2, auto_player_in = 3, too_many = 4, too_few = 1, singular = 0,
};
enum length {
	space = 1, three_space = 3, n_in_a_row= 5,
};

///=====================================
//declare and define a class of the game
///=====================================
class GameBase {
	friend class Gomoku;
protected:
	vector<game_piece> my_game_board;
	vector <unsigned int> move_1;
	vector <unsigned int> move_2;
	char player;
	char player1;
	char player2;
	int turn_number;
	int longestLength;
	unsigned int game_column;
	unsigned int game_row;
	unsigned int display_col;
	unsigned int display_row;
	int assigned_win;
public:
	GameBase();
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual int turn();
	int prompt(unsigned int & x,unsigned int & y);
	int play();
	static GameBase *  p(int argc, char *argv[]);
};

class TicTacToeGame :public GameBase{
	//decare the insertion operator to be a friend
	friend ostream &operator<<(ostream &o, const TicTacToeGame & g);
public:
	//declare constructor
	TicTacToeGame();
	//declare functions
	virtual bool done();
	virtual bool draw();
	
	virtual void print();
private:
	
};

class Gomoku :public GameBase {
	friend ostream &operator<<(ostream &o, const Gomoku & g);
public:
	Gomoku();
	Gomoku(int dim);
	Gomoku(int dim, int win);
	virtual void print();
	virtual bool draw();
	virtual bool done();

};







///==============================
//Define functions used in lab3
///==============================

int usage_message(char * program_name);

int game_message(char * program_name);
int game_message2(char * program_name);
int game_message3(char * program_name);
int game_message4(char * program_name);

//Declare and define an insertion operator
ostream  & operator<< (ostream & out, const TicTacToeGame & game);
ostream &operator<<(ostream &out, const Gomoku & game);



#endif#pragma once
