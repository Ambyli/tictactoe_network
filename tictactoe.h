#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

using namespace std;

class TicTacToe
{
  public:

    //initializes empty board and 0 points for 'O' and 'X'
    TicTacToe();

    //places a 'X' in a cordinate
    void insert_x(int row_cord, int col_cord);

    //places a 'O' in a cordinate
    void insert_o(int row_cord, int col_cord);

    //resets the game board
    void resetBoard();

    //prints the game board
    void printBoard();

    //uses checkRow, checkColumn, and checkDiag to see if either 'O' or 'X' won
    //returns 'O' or 'X' if win condition is met
    char checkBoard();

    //tallies win condition with +1
    void x_won();

    //tallies win condition with +1
    void o_won();

    //prints the scoreboard
    void printScore();


  private:
    
    //contains the game board, default empty
    char board[3][3]; //this will hold the 2D board as an array, it being 3x3

    //checks for win condition in rows
    char checkRow();

    //checks for win condition in columns
    char checkColumn();

    //checks for win condition in diagonals
    char checkDiag();

    //carries 'X' points
    int x_score = 0;

    //carries 'O' points
    int o_score = 0;

};

#endif
