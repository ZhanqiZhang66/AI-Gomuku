====================================================
lab4
Team: Amanda
Team memebers: Zhanqi Zhang, Zuyu Liao, Xinyi Wu
==========================================================


Errors and warnings encountered when building the program:
===========================================================
1) signed/ unsigned mismatch
sol:fixed the int into unsigned int

2)Mismatch the row and col in the done() function when checking
sol: By inverting all row into col from the part going thru each row, we got the part going thru each col

3)Fail to indicate success when there are 3 X_s or O_s in a colume
sol: the +1 part was in wrong place. It should added to the row, not added to the colume.

4)Fail to indicate correct success when there are 3_X_s or O_s in a diagonal
sol: in the second diagonal checking process, the bool another_flag was typed as flag, leading this error.

5)Fail to realize the XXO or OOX is not success in diagonal
sol: one bool was initialize into false, when it becomes true, we jump out of the function at the wrong time

6)Not all path of draw() has a return value
sol: check all the pathes and make sure each has a return value.

After fixing all the errors, the program can be built successfully and function correctly.


=====================================================
Trials Run:
=====================================================

#1 Wrong Number or arguments: not two arguments
H:\lab4 new\lab4\x64\Debug>lab4.exe
usage: lab4.exe <input_file_name>
Error: The number of argument entered is unexpected
Please enter the correct number of command argument

H:\lab4 new\lab4\x64\Debug>lab4.exe TicTacToe Gomoku
usage: lab4.exe TicTacToe
Error: The number of argument entered is unexpected
Please enter TicTacToe    ONLY

H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku TicTacToe
usage: lab4.exe Gomoku
alternative usage :lab4.exe Gomoku <Dimension> <Win_Number>
Please enter numeric values for dimension or win_number after Gomoku

----------------------------------------------------------
#2The second argument is wrong
H:\lab4 new\lab4\x64\Debug>lab4.exe pdskgpeokrg
usage: lab4.exe TicTacToe or Gomoku
Please enter TicTacToe or Gomoku
----------------------------------------------------------

#3 default Gomoku
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1
     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player1: 1,2;

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2  B
  1
     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y

----------------------------------------------------------------

#4 position has been taken
Player1: 1,1; 1,2; 1,3; 1,4;

  5              W
  4  B           W
  3  B           W
  2  B
  1  B
     1  2  3  4  5
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
5,4
=========>Hey! The spot has been taken

===========>The Position you chose is not good. Please enter a new spot

-----------------------------------------------------------------------------------------

#5done
TicTacToe:
H:\lab4 new\lab4\x64\Debug>lab4.exe TicTacToe
4
3
2
1
0
  0 1 2 3 4
>>>>>>>Player X! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,1

Player1: 1,1;
4
3
2
1   X
0
  0 1 2 3 4
>>>>>>>Player O! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,2

Player2: 2,2;
4
3
2     O
1   X
0
  0 1 2 3 4
>>>>>>>Player X! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,1

Player1: 1,1; 2,1;
4
3
2     O
1   X X
0
  0 1 2 3 4
>>>>>>>Player O! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,3

Player2: 2,2; 3,3;
4
3       O
2     O
1   X X
0
  0 1 2 3 4
>>>>>>>Player X! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,1

Player1: 1,1; 2,1; 3,1;
4
3       O
2     O
1   X X X
0
  0 1 2 3 4

Player X won this game

Gomoku:
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku 3 3

  3
  2
  1
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,1

Player1: 1,1;

  3
  2
  1  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player2: 1,2;

  3
  2  W
  1  B
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,2

Player1: 1,1; 2,2;

  3
  2  W  B
  1  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,3

Player2: 1,2; 1,3;

  3  W
  2  W  B
  1  B
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,3

Player1: 1,1; 2,2; 3,3;

  3  W     B
  2  W  B
  1  B
     1  2  3

Player B won this game


--------------------------------------------------------------------------------
#6 draw
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku 3 3

  3
  2
  1
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,1

Player1: 1,1;

  3
  2
  1  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,2

Player2: 2,2;

  3
  2     W
  1  B
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,1

Player1: 1,1; 2,1;

  3
  2     W
  1  B  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,1

Player2: 2,2; 3,1;

  3
  2     W
  1  B  B  W
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,3

Player1: 1,1; 2,1; 1,3;

  3  B
  2     W
  1  B  B  W
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player2: 2,2; 3,1; 1,2;

  3  B
  2  W  W
  1  B  B  W
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,2

Player1: 1,1; 2,1; 1,3; 3,2;

  3  B
  2  W  W  B
  1  B  B  W
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,3

Player2: 2,2; 3,1; 1,2; 3,3;
Player2: No path left that can lead to a win

  3  B     W
  2  W  W  B
  1  B  B  W
     1  2  3

8 turns were ran and no winning moves remain

-------------------------------------------------------------------------------------------------------
#7 Quit
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1
     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player1: 1,2;

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2  B
  1
     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
quit
Player2:

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2  B
  1
     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

2 turns were ran. User quit.



===========================================================================================
error message
===========================================================================================
////////////////////////////////////////////////////
All Error Messages the program generates and their solutions:
1)Success = 0, 
	Indicating the program runs successfully, 
	echo %errorlevel% command outputs 0;

2)cannotOpenFile = 1, 
	Indicating the program has not found the input text file, 
	echo %errorlevel% command outputs 1;
	The Error message is : "File is not found. 
							Please try another file" 
	the message is sent to the user to help the user correctly enter the file


3)wrongNumberArgument = 2, 
	Indicating the program has incorrect number of arguments
	echo %errorlevel% command outputs 2;
	The Error message is: "usage: Lab1.exe<input_file_name>
						   Error: The number of argument entered is unexpected
						   Please enter the correct number of command argument"
	the message is sent to the user to help the user correctly enter the arguments

4)wrongFileType = 3
	Indicating the input file is not a text file
	echo %errorlevel% command outputs 3;
	The Error message is: "Unexpected file type. 
						   Please enter a .txt file"
	the message is sent to the user to help the user enter the correct type of file
5)wrongDimension = 4, 
	Indicating the dimention of the game is not correct to be readin
	The user should input a new game piece with right dimension
6)cannotReadALine = 5, 
	Indicating none of the lines from the game is readable
	User should try to find if there is anything wrong with their input file and also the streams
7)failedDef = 6, 
	Meaning the defination of the game misses information
	It tells the users to have a correct format of game file
8)dimensionNotMatched = 7
	Saying that the dimension of the game setting is not matched the dimension of the game pieces
	User should adjust their game dimension
9)quit = 8, 
	Indicating the user quit the game
	and the game terminates
	e.g.
		READY?
		Please enter the position for your turn here. For example: x,y
		quit
		O:
		4
		3
		2
		1 X
		0
		 01234


		2 turns were ran. User quit.
10)invalid_position = 9, 
	Saying the user put the piece into a invalid position
	For example (0,0)(0,1)(0,2)(0,3)(0,4) (1,4)(2,4)(3,4) (4,4)(4,3)(4,2)(4,1) (4,0)(3,0)(2,0)(1,0) are invalid positions
	Basicly, if (x > col - 2 || y > row - 2 || x < 1 || y < 1), then the position is invalid
	When the positions above were entered, the output is something like:
	READY?

		Please enter the position for your turn here. For example: x,y
		-1,-1

		=========>The position you entered is invalid (not on the board)

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
		4,4

		=========>The position you entered is invalid (not on the board)

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
		32,32

		=========>The position you entered is invalid (not on the board)

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y

	Then pompt the user for a new turn
11)bad_input = 10, 
	Saying the user put the piece into a bad position (one dimensional, on a existing spot etc.)
	For example:
	READY?
		Please enter the position for your turn here. For example: x,y
		12 23

		============>Ummm. Seems like the position you just entered is bad :(

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
		1,2,3

		=========>Ummm. Seems like the position you just entered is bad :(

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
		k

		============>Ummm. Seems like the position you just entered is bad :(

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
		-12

		============>Ummm. Seems like the position you just entered is bad :(

===========>The Position you chose is not avaliable. Please enter a new spot
READY?
Please enter the position for your turn here. For example: x,y
12)run_out_of_turns = 11, 
	Indicating the game is over and all the turns are used

	for example:
	READY?
	Please enter the position for your turn here. For example: x,y
	3,1	
	4
	3 XXO
	2 OOX
	1 XOX
	0
	01234

9 turns were ran and no winning moves remain
13)notGame = 12
	Indicating the user did not input the right game
	for example:
	H:\CSE332\lab3-ZhanqiZhang66\lab3\Debug>lab3.exe TicTacTo
	TicTacTo
	usage: lab3.exe TicTacToe
	Please enter TicTacToe

14)notauto=13
	Indicating the user did not input the right game for AI
	for example:
	H:\CSE332\lab3-ZhanqiZhang66\lab3\Debug>lab3.exe TicTacToe aaa
	TicTacToe aaa
	usage: lab3.exe TicTacToe
	Please enter TicTacToe auto_player to play with the AI
15)taken = 14
	Indicating the spot chose it taken,
	and it should prompt the user for a new input
	e.g.
	
		>>>>>>>Player X! It is your turn.<<<<<<<
		READY?
		Please enter the position for your turn here. For example: x,y
		1,1

		X: 1,1;
		4
		3
		2
		1 X
		0
		 01234

		>>>>>>>Player O! It is your turn.<<<<<<<
		READY?
		Please enter the position for your turn here. For example: x,y
		1,1
		=========>Hey! The spot has been taken

		===========>The Position you chose is not avaliable. Please enter a new spot
		READY?
		Please enter the position for your turn here. For example: x,y
16)badAlloc = 15
	Indicating bad allocation,
17)nonpositive =16
	Indicating nonpositive arguments
	(base) H:\CSE332\lab4-lab4_amanda\lab4\Debug>lab4.exe Gomoku 0 -3
	usage: lab4.exe TicTacToe or Gomoku
Error: The argument should be positive only
18)notTicTacToe=17
	Indicating the user did not input the tictactoe game and argument incorrectly 
	Error: The number of argument entered is unexpected
	Please enter TicTacToe    ONLY

============================================================================================



=============================================================
Extra Credit
=============================================================
If we only have three arguments, i.e. lab4.exe Gomoku <int> 
Then we assume that the dimension of the board and the winning number are both this integer

If we have four arguments instead, i.e. lab4.exe Gomoku <int> <int>
Then we assume that the first number is the dimension and the second number is the winning number

#1 Only Three arguments: The dimension and winning number is the same
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku 3

  3
  2
  1
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,1

Player1: 1,1;

  3
  2
  1  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player2: 1,2;

  3
  2  W
  1  B
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,2

Player1: 1,1; 2,2;

  3
  2  W  B
  1  B
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2
=========>Hey! The spot has been taken

===========>The Position you chose is not good. Please enter a new spot
READY?
Please enter the position for your turn here. For example: x,y
1,3

Player2: 1,2; 1,3;

  3  W
  2  W  B
  1  B
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
3,3

Player1: 1,1; 2,2; 3,3;

  3  W     B
  2  W  B
  1  B
     1  2  3

Player B won this game

#2 We have four arguments: The dimension and the winning number is different
H:\lab4 new\lab4\x64\Debug>lab4.exe Gomoku 3 2

  3
  2
  1
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
1,2

Player1: 1,2;

  3
  2  B
  1
     1  2  3
>>>>>>>Player W! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,3

Player2: 2,3;

  3     W
  2  B
  1
     1  2  3
>>>>>>>Player B! It is your turn.<<<<<<<
READY?
Please enter the position for your turn here. For example: x,y
2,2

Player1: 1,2; 2,2;

  3     W
  2  B  B
  1
     1  2  3

Player B won this game








 















