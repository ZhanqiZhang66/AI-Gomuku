// game.cpp : Defines the game pieces for the game
// ========lab3
//Author: Zhanqi Zhang 450455 
//zhanqizhang@wustl.edu 
// 
// 
//Purpose: =>The Lab3 program is used to build and play the tic-tac-toe game 
//         =>This program is used to convert the name of color to its enum value, 
//			 convert color's enum value to its name


#include "stdafx.h"
#include "lab4.h"
#include "game.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//This function is used to take a enumerated type for the colors of game pieces
//and return the lower-case string corresponding to the value that was passed.
//Parameters: enum color
//Output: color's name
string passing_color(color input_color) {
	if (input_color == red) {
		return "red";
	}
	else if (input_color == white) {
		return "white";
	}
	else if (input_color == black) {
		return "black";
	}
	else if (input_color == blue) {
		return "blue";
	}
	else if (input_color == no_color) {
		return "no color";
	}
	else {
		return "invalid";
	}

}
//This function is used to take a string by value and converts it into its corresponding enum lables
//Parameters: color's name in string
//Output: enum color
color passing_name(string input_name) {
	if (lower_case(input_name) == "red") {
		return red;
	}
	else if (lower_case(input_name) == "white") {
		return white;
	}
	else if (lower_case(input_name) == "black") {
		return black;
	}
	else if (lower_case(input_name) == "blue") {
		return blue;
	}
	else if (input_name == "\t" || input_name == " ") {
		return no_color;
	}
	else {
		return invalid;
	}
}