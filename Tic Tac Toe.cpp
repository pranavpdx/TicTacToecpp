//Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//The program runs a version of tic tac toe on the console played by two players. 
//Author: Pranav Sharma Date: 9/28/20

#include <iostream>
#include "Board.h"
using namespace std;
// main function gets users information and starts running the board properties
int main()
{
    string playerx, playero;
    cout << "Welcome to the console Tic - Tac - Toe Game! \n" << "Enter player 1's name (This player will be X):\n ";
    cin >> playerx;
    cout << "Great! Welcome " << playerx << "! Enter player 2's name (This player will be O): \n";
    cin >> playero;


    Board* board = new Board(playerx, playero);
    board->Run();

}
