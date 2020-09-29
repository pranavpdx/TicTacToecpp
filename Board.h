// header file used to define the methods and variables used in the board
#pragma once
using namespace std;
#include <iostream>

class Board
{
	const int BLANK = 0;
	const int X_MOVE = 1;
	const int O_MOVE = 2;
	const int X_TURN = 1;
	const int O_TURN = 2;
	string _player1;
	string _player2;
	string input;
	int turn = X_TURN;
	int xWins = 0;
	int oWins = 0;
	int board[3][3];
	bool playing = true;

public:
	void Run();
	void Display();
	bool checkWin(int player);
	bool checkTie();
	Board(string player1, string player2);
};

