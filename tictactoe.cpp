#include "tictactoe.h"
#include <iostream>

using namespace std;

//initializes empty board and 0 points for 'O' and 'X'
TicTacToe::TicTacToe()
{
  fill_n(board, 9, ' ');
  x_score = 0;
  o_score = 0;
  turn_counter = 0;
}

void TicTacToe::printTitle()
{
  cout<<"TicTacToe!\t"<<endl;
  printScore();
}

//places a 'X' in a cordinate
int TicTacToe::insert_x(int cord)
{
  if(board[cord] == ' ')
  {
    board[cord] = 'x';
    turnCount(); //turn was valid, +1
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
    turnCount(); //turn was valid, +1
    return 0; //valid move
  }
  else
    return 1; //invalid move
}

//resets the game board
void TicTacToe::resetBoard()
{
  fill_n(board, 9, ' ');
  turn_counter = 0;
}

//prints the game board
void TicTacToe::printBoard()
{
  cout<<" - - - "<<endl;
  cout<<"|"<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<"|"<<endl;
  cout<<" - - - "<<endl;
  cout<<"|"<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<"|"<<endl;
  cout<<" - - - "<<endl;
  cout<<"|"<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<"|"<<endl;
  cout<<" - - - "<<endl;
}

//uses checkRow, checkColumn, and checkDiag to see if either 'O' or 'X' won
//returns 'O' or 'X' if win condition is met
char TicTacToe::checkBoard(char s)
{
  checkRow(s);
  checkColumn(s);
  checkDiag(s);
  checkTie();
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
  cout<<"Turn: "<<turn_counter<<endl;
}

void TicTacToe::turnCount()
{
  turn_counter += 1;
} 

//checks for win condition in rows depending on what s is
void TicTacToe::checkRow(char s)
{
  for(int i = 0; i <= 6; i+= 3) //increment by each row
  {
    //does everything in the 3 rows == s?
    if(s == board[i] && s == board[i + 1] && s == board[i + 2]) 
    {
      if(s == 'x') //if x won
        x_won();
      else         //if o won
        o_won();
    }
  }
}

//checks for win condition in columns
void TicTacToe::checkColumn(char s)
{
  for(int i = 0; i < 3; i++)
  {
    //does everything in the 3 columns == s?
    if(s == board[i] && s == board[i + 3] && s == board[i + 6])
    {
      if(s == 'x') //if x won
        x_won();
      else         //if o won
        o_won();
    }
  }
}

//checks for win condition in diagonals
void TicTacToe::checkDiag(char s)
{
  //does everything in the 2 diagonals == s?
  if(s == board[0] && s == board[4] && s == board[8])
  {
      if(s == 'x') //if x won
        x_won();
      else
        o_won();
  }
  if(s == board[2] && s == board[4] && s == board[6])
  {
      if(s == 'x') //if x won
        x_won();
      else         //if o won
        o_won();
  }
}

//check for tie
void TicTacToe::checkTie()
{
  int MAX_TURNS = 9;
  if(turn_counter == MAX_TURNS)
  {
    resetBoard();
    turn_counter = 0;
  }
}
