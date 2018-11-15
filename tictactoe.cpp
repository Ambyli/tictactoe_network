#include "tictactoe.h"
#include <iostream>

using namespace std;

//initializes empty board and 0 points for 'O' and 'X'
TicTacToe::TicTacToe()
{
  fill_n(board, 9, ' ');
  x_score = 0;
  o_score = 0;
}

//places a 'X' in a cordinate
int TicTacToe::insert_x(int cord)
{
  if(board[cord] == ' ')
  {
    board[cord] = 'x';
    return 0; //valid move
  }
  else
    return 1; //invalid move
}

//places a 'O' in a cordinate
int TicTacToe::insert_o(int cord)
{
  if(board[cord] == ' ')
  {
    board[cord] = 'o';
    return 0;
  }
  else
    return 1; //invalid move
}

//resets the game board
void TicTacToe::resetBoard()
{
  fill_n(board, 9, ' ');
}

//prints the game board
void TicTacToe::printBoard()
{
  cout<<" _ _ _ "<<endl;
  cout<<"|"<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<"|"<<endl;
  cout<<" _ _ _ "<<endl;
  cout<<"|"<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<"|"<<endl;
  cout<<" _ _ _ "<<endl;
  cout<<"|"<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<"|"<<endl;
  cout<<" _ _ _ "<<endl;
}

//uses checkRow, checkColumn, and checkDiag to see if either 'O' or 'X' won
//returns 'O' or 'X' if win condition is met
char TicTacToe::checkBoard()
{
  checkRow();
  checkColumn();
  checkDiag();
}

//tallies win condition with +1
void TicTacToe::x_won()
{
  x_score += 1;
  resetBoard();
}

//tallies win condition with +1
void TicTacToe::o_won()
{
  o_score += 1;
  resetBoard();
}

//prints the scoreboard
void TicTacToe::printScore()
{
  cout<<"X's score: "<<x_score<<endl;
  cout<<"O's score: "<<o_score<<endl;
}

//checks for win condition in rows
void TicTacToe::checkRow()
{
}

//checks for win condition in columns
void TicTacToe::checkColumn()
{
}

//checks for win condition in diagonals
void TicTacToe::checkDiag()
{
}

