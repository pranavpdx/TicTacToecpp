#include "Board.h"

/*
Constructor method. Initializes the board as blank and sets the player's names
*/
Board::Board(string player1, string player2)
{
    this->_player1 = player1;
    this->_player2 = player2;   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
            board[i][j] = BLANK;
        }
    }
}
// runs the game
void Board::Run() {
    // runs multiple games while users want to play
    while (playing == true) {
        cout << "Ok!Lets play!\n";
        Display();
        // runs a single game while nobody has won
        while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
            if (turn == X_TURN) {
                cout << "It is " << _player1<< "'s turn. Enter a move \n";
            }
            else {
                cout << "It is " << _player2 << "'s turn. Enter a move \n";
            }
            cin >> input;
            // makes sure the users inputs are valid
            if (input.length() != 2) {
                cout << "Enter a letter(a, b, or c) followed by a number(1, 2, or 3)\n";
            }
            else if (input.at(0) != 'a' && input.at(0) != 'b' && input.at(0) != 'c') {
                cout << "Row entry must be an a, b, or c\n";
            }
            else if (input.at(1) != '1' && input.at(1) != '2' && input.at(1) != '3') {
                cout << "colomn entry must be a 1, 2, or 3\n";
            }
            // places indicator in array equal to what the user inputs
            else {
                int row = input.at(0) - 'a';
                int colomn = input.at(1) - '1';
                // if spot is empty
                if (board[row][colomn] == BLANK) {
                    if (turn == X_TURN) {
                        board[row][colomn] = X_MOVE;
                        turn = O_TURN;
                    }
                    else if (turn == O_TURN) {
                        board[row][colomn] = O_MOVE;
                        turn = X_TURN;
                    }
                }
                // lets user know if spot is filled
                else {

                    cout << "Oops! This place is already taken, try again\n";
                }
                // paints board at the end of a turn
                Display();
;            }
        }
        // prints results if player 1(x) wins
        if (checkWin(X_MOVE) == true) {
            xWins++;
            cout << "Great job " << _player1 << "!\n";
        }
        // prints results if player 2(o) wins
        else if (checkWin(O_MOVE) == true) {
            oWins++;
            cout << "Great job " << _player2 << "!\n";
        }
        // prints results if tie
        else {
            cout << "Its a Tie! \n";
        }
        // prints results and asks if users would like to play again
        cout << _player1 << " has won: " << xWins << " times \n" << _player2 << " has won: " << oWins << " times\n";
        cout << "Would you like to play again?(Y/N)";
        cin >> input;
        if (!(input == "Y")) {
            playing = false;
            cout << "Thank you for playing";
        }
        // resets board
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3;j++) {
                    board[i][j] = BLANK;
                }
            }
        }

   }
}
// displays on the console what the board looks like
void Board::Display(){
    cout << "\t1\t2\t3 \n";
    for (int row = 0; row < 3; row++) {
        string output = "";
        output = output + (char)((int)('a') + row);
        for (int colomn = 0; colomn < 3; colomn++) {
            if (board[row][colomn] == BLANK) {
                output += "\t";
            }
            else if (board[row][colomn] == X_MOVE) {
                output += "\tX";
            }
            else if (board[row][colomn] == O_MOVE) {
                output += "\tO";
            }
        }
        cout << output << "\n";
    }
}
// checks to see if a user has won
bool Board::checkWin(int player) {
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
        return true;
    }
    if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
        return true;
    }
    if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
        return true;
    }
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    else {
        return false;
    }
}
// checks to see if the board is filled with no winners - then says its a tie!
bool Board::checkTie() {
    int x = 0;
    for (int row = 0; row < 3; row++) {
        for (int colomn = 0; colomn < 3; colomn++) {
            if (board[row][colomn] != BLANK) {
                x = x + 1;
            }
        }
    }
    if (x == 9) {
        return true;
    }
    else {
        return false;
    }
}
