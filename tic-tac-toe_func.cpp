#include <iostream>
#include "tic-tac-toe_func.h"
using namespace std;

void print_game_board(int** game_board, int rows, int cols)
{
    cout << endl << "     0   1   2" << endl << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << i << "    ";
        for (int j = 0; j < cols; j++)
        {
            // if it is the last column, do not print the extra border
            if (j == 2)
            {
                if (game_board[i][j] == 0) // spot has not been chosen
                {
                    cout << "  " << endl;
                }
                else if (game_board[i][j] == 1) // X is played there
                {
                    cout << "X " << endl;
                }
                else // O is played there
                {
                    cout << "O " << endl;
                }
            }
            else
            {
                if (game_board[i][j] == 0) // spot has not been chosen
                {
                    cout << "  | ";
                }
                else if (game_board[i][j] == 1) // X is played there
                {
                    cout << "X | ";
                }
                else // O is played there
                {
                    cout << "O | ";
                }
            }
            
        }

        if (i < 2)
        {
            cout << "    -----------" << endl;
        }
    }
    cout << endl;
}

// initialize the game board to be blank
void initialize_game_board(int** game_board, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            game_board[i][j] = 0;
        }
    }
}

// X takes a turn
int update_game_boardX(int** game_board, int row, int col)
{
    if (row > 2 || col > 2)
    {
        cout << "That is not a valid spot" << endl;
        return -1;
    }
    else if (game_board[row][col] != 0)
    {
        cout << "That spot has already been taken!" << endl;
        return -1;
    }
    else
    {
        game_board[row][col] = 1;
        return 0;
    }
}

// O takes a turn
int update_game_boardO(int** game_board, int row, int col)
{
    if (row > 2 || col > 2)
    {
        cout << "That is not a valid spot" << endl;
        return -1;
    }
    else if (game_board[row][col] != 0)
    {
        cout << "That spot has already been taken!" << endl;
        return -1;
    }
    else
    {
        game_board[row][col] = 2;
        return 0;
    }
}

// after each turn, determine if someone has won
bool winner(int** game_board, int rows, int cols)
{
    // all possible winning combinations for X
    if ((game_board[0][0] == 1) && (game_board[1][1]) == 1 &&
        (game_board[2][2] == 1)) // diagonal top to bottom
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[2][0] == 1) && (game_board[1][1]) == 1 &&
             (game_board[0][2] == 1)) // diagonal bottom to top
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][0] == 1) && (game_board[0][1]) == 1 &&
             (game_board[0][2] == 1)) // top row
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[1][0] == 1) && (game_board[1][1]) == 1 &&
             (game_board[1][2] == 1)) // middle row
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[2][0] == 1) && (game_board[2][1]) == 1 &&
             (game_board[2][2] == 1)) // bottom row
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][0] == 1) && (game_board[1][0]) == 1 &&
        (game_board[2][0] == 1)) // left column
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][1] == 1) && (game_board[1][1]) == 1 &&
        (game_board[2][1] == 1)) // middle column
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][2] == 1) && (game_board[1][2]) == 1 &&
        (game_board[2][2] == 1)) // right column
    {
        cout << "Player 1 Wins!!" << endl;
        return true;
    }
    
    // all possible winning combinations for O
    if ((game_board[0][0] == 2) && (game_board[1][1]) == 2 &&
        (game_board[2][2] == 2)) // diagonal top to bottom
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[2][0] == 2) && (game_board[1][1]) == 2 &&
             (game_board[0][2] == 2)) // diagonal bottom to top
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][0] == 2) && (game_board[0][1]) == 2 &&
             (game_board[0][2] == 2)) // top row
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[1][0] == 2) && (game_board[1][1]) == 2 &&
             (game_board[1][2] == 2)) // middle row
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[2][0] == 2) && (game_board[2][1]) == 2 &&
             (game_board[2][2] == 2)) // bottom row
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][0] == 2) && (game_board[1][0]) == 2 &&
        (game_board[2][0] == 2)) // left column
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][1] == 2) && (game_board[1][1]) == 2 &&
        (game_board[2][1] == 2)) // middle column
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    else if ((game_board[0][2] == 2) && (game_board[1][2]) == 2 &&
        (game_board[2][2] == 2)) // right column
    {
        cout << "Player 2 Wins!!" << endl;
        return true;
    }
    
    return false;
}