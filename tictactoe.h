#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

using namespace std;

class TicTacToe
{
  public:

    TicTacToe();

    void insert_x(int cordinate);

    void insert_o(int cordinate);

    void resetBoard();

    void printBoard();


  private:

    char board[3][3]; //this will hold the 2D board as an array, it being 3x3

};

#endif
