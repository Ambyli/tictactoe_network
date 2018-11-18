#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
  public:

    //initializes empty board and 0 points for 'O' and 'X'
    TicTacToe();
    
    //simply prints game title
    void printTitle();

    //places a 'X' in a cordinate
    //return: 0 for valid move, 1 for invalid move
    int insert_x(int cord);

    //places a 'O' in a cordinate
    //return: 0 for valid move, 1 for invalid move
    int insert_o(int cord);

    //resets the game board
    void resetBoard();

    //prints the game board
    void printBoard();

    //uses checkRow, checkColumn, and checkDiag to see if either 'O' or 'X' won
    //returns 'O' or 'X' if win condition is met
    char checkBoard(char s);

    //tallies win condition with +1
    void x_won();

    //tallies win condition with +1
    void o_won();

    //prints the scoreboard
    void printScore();

    //tallies +1 to counter
    void turnCount();


  private:
    
    //contains the game board, default empty
    char board[9]; //this will hold the 2D board as a 1D array, it being 3x3

    //checks for win condition in rows
    void checkRow(char s); //naive

    //checks for win condition in columns
    void checkColumn(char s); //naive

    //checks for win condition in diagonals
    void checkDiag(char s); //naive

    void checkTie();

    //carries 'X' points
    int x_score;

    //carries 'O' points
    int o_score;

    //turn counter
    //this can prevent cheating
    //could let you check last board with current board, reset commit
    int turn_counter;

};

#endif
