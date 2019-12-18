// Lab4.cpp : Defines the body of the program
// Team: Amanda
//Author:
//Zhanqi Zhang  Zuyu Liao, Xinyi Wu
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The Lab4 program is used to build and play the tic-tac-toe and gomoku 

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


//Constructor for the base case
GameBase::GameBase()
	: my_game_board(), player(), turn_number(0), longestLength(0)
{

}

//dynamic allocation: 
GameBase *  GameBase::p(int argc, char *argv[]) {
	string gamename1 = "TicTacToe";
	string gamename2 = "Gomoku";
	GameBase * q;
	if (argc != human_player && argc != with_size && argc != with_win_num) {
		q = 0;
		return q;
	}
	if (argv[input_file_name] != gamename1 && argv[input_file_name] != gamename2)
	{
		q = 0;
		return q;
	}
	//if TicTacToe && argc != 2
	if (argv[input_file_name] == gamename1 && argc != expected_num_argument)
	{
		q = 0;
		return q;
	}

	if (argv[input_file_name] == gamename2 && argc == expected_num_argument)
	{
		Gomoku *g = new Gomoku();
		return g;
	}

	if (argv[input_file_name] == gamename2 && argc == with_size)
	{
		Gomoku *g = new Gomoku(atoi(argv[with_size-1]));
		return g;
	}

	if (argv[input_file_name] == gamename2 && argc == with_win_num)
	{
		Gomoku *g = new Gomoku(atoi(argv[with_size-1]), atoi(argv[with_win_num-1]));
		return g;
	}
	
	TicTacToeGame *m = new TicTacToeGame();
	return m;

}

//Constructor for TicTacToe
TicTacToeGame::TicTacToeGame()
{
	longestLength = space;
	player = 'X';
	player1 = 'X';
	player2 = 'O';
	game_column = col;
	game_row = row;
	display_col = col;
	display_row = row;
	for (unsigned int i = 0; i < row*col; ++i) {
		game_piece this_game;
		this_game.c_ = no_color;
		this_game.display_as_ = " ";
		this_game.name_ = " ";
		my_game_board.push_back(this_game);

	}
}
//define the constructor for Gomoku
Gomoku::Gomoku()

{
	longestLength = three_space;
	player = 'B';
	player1 = 'B';
	player2 = 'W';
	game_column = col_g + 2;
	game_row = row_g + 2;
	display_col = col_g;
	display_row = row_g;
	assigned_win = n_in_a_row;
	for (unsigned int i = 0; i < (row_g + 1)*(col_g + 1); ++i) {
		game_piece this_game;
		this_game.c_ = no_color;
		this_game.display_as_ = " ";
		this_game.name_ = " ";
		my_game_board.push_back(this_game);

	}
}

Gomoku::Gomoku(int dim)
{
	longestLength = three_space;
	player = 'B';
	player1 = 'B';
	player2 = 'W';
	game_column = dim + 2;
	game_row = dim + 2;
	display_col = dim;
	display_row = dim;
	assigned_win = dim;
	for (int i = 0; i < (dim + 1)*(dim + 1); ++i) {
		game_piece this_game;
		this_game.c_ = no_color;
		this_game.display_as_ = " ";
		this_game.name_ = " ";
		my_game_board.push_back(this_game);

	}
}

Gomoku::Gomoku(int dim, int win) {
	longestLength = three_space;
	player = 'B';
	player1 = 'B';
	player2 = 'W';
	game_column = dim + 2;
	game_row = dim + 2;
	display_col = dim;
	display_row = dim;
	assigned_win = win;
	for (int i = 0; i < (dim + 1)*(dim + 1); ++i) {
		game_piece this_game;
		this_game.c_ = no_color;
		this_game.display_as_ = " ";
		this_game.name_ = " ";
		my_game_board.push_back(this_game);

	}
}
///////////////////////define out funtion for the class & remember longest length
ostream  & operator<< (ostream & out, const TicTacToeGame & game) {
	for (int i = row - 1; i >= 0; --i) {
		out << setw(game.longestLength) << i;
		for (int j = 0; j <= col - 1; ++j) {
			out << setw(game.longestLength) << " " << game.my_game_board[col*i + j].display_as_;
		}
		out << endl;
	}
	out << setw(game.longestLength) << " ";
	for (int i = 0; i < col; ++i) {
		out << setw(game.longestLength) << " " << i;
	}
	out << endl;
	return out;
}

ostream &operator<<(ostream &out, const Gomoku & game) {
	cout << endl;
	for (int i = game.display_row; i > 0; --i) {
		out << setw(game.longestLength) << i;
		for (unsigned int j = 1; j <= game.display_row; ++j) {
			out << setw(game.longestLength) << game.my_game_board[game.display_row * i + j].display_as_;
		}
		out << endl;
	}
	out << setw(game.longestLength) << "X";
	for (unsigned int i = 1; i <= game.display_col; ++i) {
		out << setw(game.longestLength) << i;
	}
	out << endl;
	return out;
}
//Override that virtual print() method and define it as simply inserting *this into an ostream
//Parameter: none
//(so that it uses the insertion operator described above)
void Gomoku::print()
{
	cout << *this;
}

//Override that virtual print() method and define it as simply inserting *this into an ostream 
//Parameter: none
//(so that it uses the insertion operator described above)
void TicTacToeGame::print() {
	cout << *this;
}

//Define done() method for tictactow
//Parameters: none
//Return true if: 3-Xs or Os in a vertical, horizontal, or diagonal line
//Otherwise: return false
bool TicTacToeGame::done() {

	bool flag = false;
	bool another_flag = false;
	//going thru every row//    row   
	//    4 # # # # #
	//    3 # X X X #  -> i = row-2
	//    2 # * * * #   
	//    1 # * * * #  -> i = 1 
	//    0 # # # # #
	//col   0 1 2 3 4
	//        |   |
	//       j=1  j=col-2
	for (int i = row - 2; i >= 1; --i) {
		bool Flag = true;
		for (int j = 1; j <= col - 2; ++j) {
			if (my_game_board[col * i + j].display_as_ == " ") {
				Flag = false;
				break;
			}
		}
		if (Flag == false) {
			continue;
		}
		for (int k = 1; k < col - 2; ++k) {
			if (my_game_board[col*i + k + 1].display_as_ != my_game_board[col*i + k].display_as_) {
				Flag = false;
			}
		}
		if (Flag == true) {
			return true;
		}
	}
	//going thru each col
	//    row   
	//    4 # # # # #
	//    3 # * * X #  -> i = row-2
	//    2 # * * X #   
	//    1 # * * X #  -> i = 1 
	//    0 # # # # #
	//col   0 1 2 3 4
	//        |   |
	//       j=1  j=col-2
	for (int i = col - 2; i >= 1; --i) {
		bool Flag = true;
		for (int j = 1; j <= row - 2; ++j) {
			if (my_game_board[row * j + i].display_as_ == " ") {
				Flag = false;
				break;
			}
		}
		if (Flag == false) {
			continue;
		}
		for (int k = 1; k < row - 2; ++k) {
			if (my_game_board[row*(k + 1) + i].display_as_ != my_game_board[row*k + i].display_as_) {
				Flag = false;
			}
		}
		if (Flag == true) {
			return true;
		}
	}
	//going thru two diagonals
	//    row   
	//    4 # # # # #
	//    3 # X * * #  
	//    2 # * X * #   
	//    1 # * * X #   
	//    0 # # # # #
	//col   0 1 2 3 4
	//        | |
	//      j=1 j=row-3 

	bool Flag1 = true;
	for (int j = 1; j <= row - 2; ++j) {
		if (my_game_board[row * j + (col - 1) - j].display_as_ == " ") {
			Flag1 = false;
			break;
		}
	}
	if (Flag1) {
		flag = true;
		for (int i = row - 3; i >= 1; --i) {

			if (my_game_board[row* i + ((col - 1) - i)].display_as_ != my_game_board[row *(i + 1) + ((col - 1) - (i + 1))].display_as_) {
				flag = false;
			}
		}
	}
	//    row   
	//    4 # # # # #
	//    3 # * * X #  
	//    2 # * X * #   
	//    1 # X * * #   
	//    0 # # # # #
	//col   0 1 2 3 4
	//        | |
	//      i=1 i=row-3 
	bool Flag2 = true;
	for (int j = 1; j <= row - 2; ++j) {
		if (my_game_board[row * j + j].display_as_ == " ") {
			Flag2 = false;
			break;
		}
	}

	if (Flag2) {
		another_flag = true;
		for (int i = row - 3; i >= 1; --i) {
			if (my_game_board[row* i + i].display_as_ != my_game_board[row *(i + 1) + (i + 1)].display_as_) {
				another_flag = false;
			}
		}
	}
	if (flag == true || another_flag == true) {
		return true;
	}
	return false;
}
//Define done() method
//Parameters: none
//Return true if: 3-Xs or Os in a vertical, horizontal, or diagonal line
//Otherwise: return false
bool Gomoku::done() {

	bool flag = false;
	bool another_flag = false;
	//going thru every row//    row   
	//    5 # # # # #
	//    4 # X X X #  -> i = row-2
	//    3 # * * * #   
	//    2 5 * * * #  -> i = 1 
	//    1 0 1 2 3 4
	//col   1 2 3 4 5
	//        |   |
	//       j=1  j=col-2

	for (unsigned int i = 1; i <= display_row; ++i) {
		for (unsigned int h = 1; h <= (display_col + 1) - assigned_win; ++h) {
			bool Flag = true;
			for (unsigned int j = h; j < h + assigned_win; ++j) {
				if (my_game_board[display_col * i + j].display_as_ == " ") {
					Flag = false;
					break;
				}
			}
			if (Flag == false) {
				continue;
			}
			for (unsigned int k = h; k < h + assigned_win - 1; ++k) {
				
				if (my_game_board[display_col*i + k + 1].display_as_ != my_game_board[display_col*i + k].display_as_) {
					Flag = false;
				}
			}
			if (Flag == true) {
			
				return true;
			}
		}
	}
	//going thru each col
	//    row   
	//    4 # # # # #
	//    3 # * * X #  -> i = row-2
	//    2 # * * X #   
	//    1 # * * X #  -> i = 1 
	//    0 # # # # #
	//col   0 1 2 3 4
	//        |   |
	//       j=1  j=col-2


	for (unsigned int i = 1; i < display_col; ++i) {
		bool Flag = true;
		for (unsigned int h = 1; h <= (display_row + 1) - assigned_win; ++h) {
			for (unsigned int j = h; j < h + assigned_win; ++j) {
				if (my_game_board[display_col * j + i].display_as_ == " ") {
					Flag = false;
					break;
				}
			}
			if (Flag == false) {
				continue;
			}
			for (unsigned int k = h; k < h + assigned_win - 1; ++k) {
				if (my_game_board[display_col*(k + 1) + i].display_as_ != my_game_board[display_col*k + i].display_as_) {
					Flag = false;
				}
			}
			if (Flag == true) {
				
				return true;
			}
		}
	}


	//going thru two diagonals
	//    row   
	//    5 # # # # #
	//    4 # * * X #  
	//    3 # * X * #   
	//    2 # X * * #   
	//    1 # # # # #
	//col   1 2 3 4 5
	//        | |
	//      j=1 j=row-3 

	bool Flag1 = true;
	for (unsigned int i = 1; i <= (display_row + 1) - assigned_win; ++i) {
		for (unsigned int h = 1; h <= (display_col + 1) - assigned_win; ++h) {
	
			Flag1 = true;
			for (int j = 0; j < assigned_win; ++j) {
				if (my_game_board[display_col * (i + j) + (h + j)].display_as_ == " ") {
					Flag1 = false;
					break;
				}
			}
			if (Flag1) {
				flag = true;
				for (int k = 0; k < assigned_win - 1; ++k) {
					if (my_game_board[display_col * (i + k) + (h + k)].display_as_ != my_game_board[display_col * (i + k + 1) + (h + k + 1)].display_as_) {
						flag = false;
					}

				}
			}

			if (flag) { break; }

		}
		if (flag) { break; }
	}

	//    row   
	//    5 # # # # #
	//    4 # X * * #  
	//    3 # * X * #   
	//    2 # * * X #   
	//    1 # # # # #
	//col   1 2 3 4 5
	//        | |
	//      i=1 i=row-3 


	for (unsigned int i = 1; i <= (display_row + 1) - assigned_win; ++i) {
		for (unsigned int h = 1; h <= (display_col + 1) - assigned_win; ++h) {
			bool Flag2 = true;
			for (int j = 0; j < assigned_win; ++j) {
				if (my_game_board[display_col * (i + j) + (display_col+1 - (h + j))].display_as_ == " ") {
					Flag2 = false;
					break;
				}
			}
			if (Flag2) {
				another_flag = true;
				for (int k = 0; k < assigned_win - 1; ++k) {
					if (my_game_board[display_col * (i + k) + (display_col+1 - (h + k))].display_as_ != my_game_board[display_row * (i + k + 1) + (display_col+1 - (h + k + 1))].display_as_) {
						another_flag = false;
					}

				}
			}
			if (another_flag) { break; }
		}
		if (another_flag) { break; }
	}
	if (flag == true || another_flag == true) {
	
		return true;
	}
	return false;
}


	
	//Define draw() method for tictactow
	//Parameters: none
	//Return true if: no moves remain
	//Otherwise: return false
bool TicTacToeGame::draw() {
	if (turn_number != (row - 2)*(col - 2) || done() == true) {
		return false;
	}
	else {
		return true;
	}
}
//Define draw() method for gomoku
//Parameters: none
//Return true if: no winning moves remain
//Otherwise: return false
bool Gomoku::draw() {


	vector<game_piece> v(my_game_board);


	if (player == player1) {
		for (unsigned int i = 1; i <= display_row; ++i) {
			for (unsigned int j = 1; j <= display_col; ++j) {
				if (my_game_board[display_col * i + j].display_as_ == " ") {
					my_game_board[display_col * i + j].display_as_ = player1;
				}
			}
		}

		bool chance_to_win = done();
		if (!chance_to_win) {//done == false  return true
			cout << "Player1: No path left that can lead to a win" << endl;
			for (unsigned int i = 1; i <= display_row; ++i) {
				for (unsigned int j = 1; j <= display_col; ++j) {
					my_game_board[display_col * i + j].display_as_ = v[display_col * i + j].display_as_;
				}
			}
		}
		else {
			for (unsigned int i = 1; i <= display_row; ++i) {
				for (unsigned int j = 1; j <= display_col; ++j) {
					my_game_board[display_col * i + j] = v[display_col * i + j];
				}
			}
		}
		if (!chance_to_win) {
			return true;
		}
		return false;
	}


	else{

		for (unsigned int i = 1; i <= display_row; ++i) {
			for (unsigned int j = 1; j <= display_col; ++j) {

				if (my_game_board[display_col * i + j].display_as_ == " ") {
					my_game_board[display_col * i + j].display_as_ = player2;
				}
			}
		}
		bool chance_to_win_here = done();
		if (!chance_to_win_here)//done == false  return true
		{
			cout << "Player2: No path left that can lead to a win" << endl;
			for (unsigned int i = 1; i <= display_row; ++i) {
				for (unsigned int j = 1; j <= display_col; ++j) {
					my_game_board[display_col * i + j].display_as_ = v[display_col * i + j].display_as_;

				}
			}
		}
		else {
			for (unsigned int i = 1; i <= display_row; ++i) {
				for (unsigned int j = 1; j <= display_col; ++j) {
					my_game_board[display_col * i + j].display_as_ = v[display_col * i + j].display_as_;

				}
			}
		}
		if (!chance_to_win_here) {
			return true;
		}
		return false;
	}

}


//Declare and define prompt() method for base calss
//The method is used to repeatedly used cout to prompt the user to type a line that either is quit to end the game
//or a string representing a valid coordinate of a square on the board as a comma-separated pair of unsigned decimal integers
//Parameters: unsigned int x and unsigned int y
//return: different failure value

int GameBase::prompt(unsigned int & x, unsigned int & y) {
	cout << "READY?" << endl;
	cout << "Please enter the position for your turn here. For example: x,y " << endl;
	string line;
	getline(cin, line);

	size_t found_comma = line.find(",", 1);
	if (line == "quit") {
		return quit;
	}
	if (found_comma == string::npos) {
		cout << endl;
		cout << "============>Ummm. Seems like the position you just entered is bad :( " << endl;
		cout << endl;
		return bad_input;
	}

	line.replace(found_comma, 1, " ");


	istringstream input(line);
	string temp;
	if (input >> x && input >> y && !(input >> temp)) {
		if (x > game_column - 2 || y > game_row - 2 || x < 1 || y < 1) {
			cout << endl;
			cout << "=========>The position you entered is invalid (not on the board)" << endl;
			cout << endl;
			return invalid_position;
		}
		if (my_game_board[display_col*y + x].display_as_.compare(" ") != 0) {
			cout << "=========>Hey! The spot has been taken " << endl;
			cout << endl;
			return taken;
		}
	
		cout << endl;
		return success;
	}
	else {
		cout << endl;
		cout << "=========>Ummm. Seems like the position you just entered is bad :( " << endl;
		cout << endl;
		return bad_input;
	}
}

//Declare and define turn() method for game class
//The method is used to remember and alternate the turn
//Parameter: none
//Return: int for an appropriate failure value

int GameBase::turn() {
	//==Repeatedly call prompt() method to obtain coordinates for a valid move in the game
	cout << ">>>>>>>Player " << player << "! It is your turn.<<<<<<<" << endl;
	unsigned int x;
	unsigned int y;
	int temp = prompt(x, y);

	//int X_s = 0;
	//int O_s = 0;

	while (temp == invalid_position || temp == bad_input || (temp == success && my_game_board[y*display_col + x].display_as_ != " ") || temp == taken) {
		cout << "===========>The Position you chose is not good. Please enter a new spot" << endl;
		temp = prompt(x, y);
	}

	//Unless the user quit, the piece is moved to the square.
	if (temp == quit) {
		return quit;
	}
	if (temp == success && my_game_board[display_col*y + x].display_as_ == " ") {
		game_piece & my_piece = my_game_board[display_col*y + x];
		my_piece.display_as_ = player;

		if (player == player1) {
			move_1.push_back(y*display_col + x);
		}
		if (player == player2) {
			move_2.push_back(y* display_col + x);
		}
	}
	return success;
}

//Declare play() method
//The method is used to print the game board and repeatedly calls the turn(), done() draw() until
//(1):done() is true: there are X_s or O_s combo 
//(2):draw() is true: no possible winning moves remained
//(3):user quit
//Parameters: none
//Return: different none zero failure value

int GameBase::play() {
	//==We first initialize the game
	turn_number = 0;
	player = player1;

	while (true) {
		//print the board
	
		print();
		++turn_number;
		int temp = turn();

		if (player == player1) {
			cout << "Player1: ";
			for (unsigned int i = 0; i < move_1.size(); ++i) {
				if (move_1[i] % display_col == 0) {
					cout << move_1[i] % display_col + display_col  << "," << move_1[i] / display_col -1 << "; ";
				}
				else {
					cout << move_1[i] % display_col << "," << move_1[i] / display_col << "; ";
				}
			}
			cout << endl;
		}
		if (player == player2) {
			cout << "Player2: ";
			for (unsigned int i = 0; i < move_2.size(); ++i) {
				if (move_2[i] % display_col == 0) {
					cout << move_2[i] % display_col + display_col << "," << move_2[i] / display_col - 1 << "; ";
				}
				else {
					cout << move_2[i] % display_col << "," << move_2[i] / display_col << "; ";
				}
			}
			cout << endl;
		}
		//==when combo appears, we print the board and indicates success

		if (done() == true) {
	
			print();
			cout << endl;
			cout << "Player " << player << " won this game" << endl;
			return success;
		}
	
	
		//==when user quit, we says user quit
		if (temp == quit) {
			print();
			cout << endl;
			cout << turn_number << " turns were ran. User quit." << endl;
			return quit;
		}
		
		//==when all turns are used, we print the board and indicates no winnint moves remain
		if (draw() == true) {		
			print();
			cout << endl;
			cout << turn_number << " turns were ran and no winning moves remain" << endl;
			return run_out_of_turns;
		}

		//alternate turn number
		if (player == player1) {
			player = player2;
		}
		else {
			player = player1;
		}
	}
}




//This function is used for printing our usage message based on the problem it encounters during execuation, 
//telling the user how to run the program correctly, and return the enumeration label corresponding to the failures 
//Parameters: a string of type char* 
//Output: Program name and  how to run the program using those parameters
int usage_message(char * program_name) {
	cout << "usage: " << program_name << " <input_file_name>" << endl;
	cout << "Error: The number of argument entered is unexpected" << endl;
	cout << "Please enter the correct number of command argument" << endl;
	return wrongNumberArgument;
}
//This function is used to printing usage message to tell the users to input the TicTacToe correctly
int game_message(char * program_name) {
	cout << "usage: " << program_name << " TicTacToe or Gomoku" << endl;
	cout << "Please enter TicTacToe or Gomoku" << endl;
	return notGame;
}

//This function is used to printing usage message to tell the users to enter numeric arguments for dimension/win_num
int game_message2(char * program_name) {
	cout << "usage: " << program_name << " Gomoku" << endl;
	cout << "alternative usage :" << program_name << " Gomoku <Dimension> <Win_Number>" << endl;
	cout << "Please enter numeric values for dimension or win_number after Gomoku" << endl;
	return notNumber;
}

//This function is used to printing usage message to tell the users to input the TicTacToe with correct number of argument
int game_message3(char * program_name) {
	cout << "usage: " << program_name << " TicTacToe" << endl;
	cout << "Error: The number of argument entered is unexpected" << endl;
	cout << "Please enter TicTacToe    ONLY" << endl;
	return notTicTacToe;
}

//This function is used to printing usage message to tell the users to input the TicTacToe with unsigned int
int game_message4(char * program_name) {
	cout << "usage: " << program_name << " TicTacToe or Gomoku" << endl;
	cout << "Error: The argument should be positive only" << endl;
	return nonpositive;
}







