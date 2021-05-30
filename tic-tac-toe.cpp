#include <iostream>
#include <ctime>
#include "tic-tac-toe_func.h"
using namespace std;

int ROWS = 3;
int COLS = 3;

int main()
{
    srand(time(NULL));
    bool finish = false;
    int turn = 1;
    int row, col, valid_turn;

    // create game board
    int** game_board = new int*[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        game_board[i] = new int[COLS];
    }

    initialize_game_board(game_board, ROWS, COLS);

    // greeting
    cout << "Hello! Welcome to Tic-Tac-Toe!" << endl;

    // play the game
    while (!finish)
    {
        print_game_board(game_board, ROWS, COLS);
        if (turn % 2 != 0) // player 1's turn
        {
            do
            {
                cout << "Player 1, where would you like to mark an 'X'?" << endl;
                cout << "Row: ";
                cin  >> row;
                cin.ignore();

                cout << "Column: ";
                cin  >> col;
                cin.ignore();

                valid_turn = update_game_boardX(game_board, row, col);
            } while (valid_turn == -1);
        }
        else // player 2's turn
        {
            do
            {
                cout << "Player 2, where would you like to mark an 'O'?" << endl;
                cout << "Row: ";
                cin  >> row;
                cin.ignore();

                cout << "Column: ";
                cin  >> col;
                cin.ignore();

                valid_turn = update_game_boardO(game_board, row, col);
            } while (valid_turn == -1);
        }

        finish = winner(game_board, ROWS, COLS);
        if (finish)
        {
            print_game_board(game_board, ROWS, COLS);
        }

        turn++;
        if (turn > 9)
        {
            print_game_board(game_board, ROWS, COLS);
            cout << "Catfish! Better luck next time!" << endl << endl;
            break;
        }
    }

    // clear space allocated for game board
    for (int i = 0; i < ROWS; i++)
    {
        delete [] game_board[i];
    }
    delete [] game_board;

    return 0;
}