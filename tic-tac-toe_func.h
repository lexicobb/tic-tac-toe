#include <iostream>
using namespace std;

// print the game board
void print_game_board(int** game_board, int rows, int cols);

// initialize all of the spaces to 0
void initialize_game_board(int** game_board, int rows, int cols);

// X takes a turn
int update_game_boardX(int** game_board, int row, int col);

// O takes a turn
int update_game_boardO(int** game_board, int row, int col);

// after each turn, determine if someone has won
bool winner(int** game_board, int rows, int cols);