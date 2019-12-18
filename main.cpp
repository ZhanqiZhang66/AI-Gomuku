//lab4
//Team: Amanda
//Author:
//Zhanqi Zhang  Zuyu Liao, Xinyi Wu  
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The main program is used to execute the tic-tac-toe and gomoku 
#include "stdafx.h"
#include "lab4.h"
#include "game.h"
#include "game_board.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <cstdlib>
using namespace std;



//main function
int main(int argc, char * argv[])
{
	string gamename1 = "TicTacToe";
	string gamename2 = "Gomoku";

	shared_ptr<GameBase> m(GameBase::p(argc, argv));
	//when wrong argument number
	if (!(argc == expected_num_argument || argc == with_size || argc == with_win_num)) {
		return usage_message(argv[program_name]);
	}
	//when tictactoe has more than 1 argument
	if (argv[input_file_name] == gamename1 && (argc > expected_num_argument)) {
		return game_message3(argv[program_name]);
	}
	//when gomoku has not numeric argument input 
	if (argv[input_file_name] == gamename2 && (argc > expected_num_argument)) {

		istringstream temp(argv[with_size - 1]);

		int number;
		string tmp;
		if (!(temp >> number) || temp >> tmp) {
			return game_message2(argv[program_name]);
		}
		if (number <= 0) {
			return game_message4(argv[program_name]);
		}

		if (argc == with_win_num) {
			istringstream temp2(argv[with_win_num - 1]);

			int number2;
			if (!(temp2 >> number2) || temp >> tmp) {
				return game_message2(argv[program_name]);
			}
			if (number2 <= 0) {
				return game_message4(argv[program_name]);
			}

		}

	}
	//when play the undefined game
	if ((argv[input_file_name] != gamename1) && (argv[input_file_name] != gamename2)) {
		return game_message(argv[program_name]);

	}

	try { return m->play(); }
	catch (bad_alloc)
	{
		cout << "bad Allocation" << endl;
		return badAlloc;
	}


}