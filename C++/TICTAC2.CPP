//**************************************
// Name: A simple Tic-Tac-Toe game.
// Description:This is a simple Tic-Tac-Toe game that uses a 2D array. It illustrates how to constract a simple game. There are no bells and whistles, this is plain and simple C++.
// By: Ethan Croteau (from psc cd)
//**************************************

/*****************************************************************************
 * Author: Ethan Croteau
 * Creation Date: 7/31/02
 * Description: This is a simple console app that allows you to play Tic-Tac-Toe.
 * Compile: This is ANSI C++, it was compiled with Borland CPP 5.5.
 *****************************************************************************/
#include <iostream.h>
namespace std;
class TicTacToe
{
public:
TicTacToe();
int PlayerMove(int i);
void NextPlayer();
void WinCheck();
void DrawBoard();
private:
int board[3][3];
int turn; // player1 == 1, player2 == 2
int gameOver;
void PlayGame();
};
/*****************************************************************************
 * Clear the board, set turn for player1, set gameOver to false, draw the board,
 * then away we go!
 *****************************************************************************/
TicTacToe::TicTacToe()
{
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++)
 board[i][j] = 0;// 0 means empty
turn = 1; // player1
gameOver = 0;
DrawBoard();
PlayGame();
}
/*****************************************************************************
 * i is the board position that the player selects.
 * Calculate the x and y coordinates.
 * Ensure board position is valid. Check if game has been won. Switch Players. Update board.
 * Return: 0 if move was made, otherwise return the value stored in the board position.
 *****************************************************************************/
int TicTacToe::PlayerMove(int i)
{
int x = (i - 1)/3;
int y = ((i + 2) % 3);
int returnVal = board[x][y];
if (returnVal == 0)
{
board[x][y] = turn;
WinCheck();
if (!gameOver)
NextPlayer();
}
else
cout << "Invalid move, try again.\n";
DrawBoard();
return returnVal;
}
/*****************************************************************************
 * If turn equals 1, set it equal to 2. Otherwise set it equal to 1.
 * The switches the active player.
 *****************************************************************************/
void TicTacToe::NextPlayer()
{
if (turn == 1)
turn = 2;
else
turn = 1;
}
/*****************************************************************************
 * If the game has been won, set gameOver equal to turn.
 * Turn always contains a value that is boolean true: 1 or 2.
 *****************************************************************************/
void TicTacToe::WinCheck()
{
if ((board[0][0] == turn) && (board[1][0] == turn) && (board[2][0] == turn))
gameOver = turn;
else
if ((board[0][1] == turn) && (board[1][1] == turn) && (board[2][1] == turn))
gameOver = turn;
else
if ((board[0][2] == turn) && (board[1][2] == turn) && (board[2][2] == turn))
gameOver = turn;
else
if ((board[0][0] == turn) && (board[0][1] == turn) && (board[0][2] == turn))
gameOver = turn;
else
if ((board[1][0] == turn) && (board[1][1] == turn) && (board[1][2] == turn))
gameOver = turn;
else
if ((board[2][0] == turn) && (board[2][1] == turn) && (board[2][2] == turn))
gameOver = turn;
else
if ((board[0][0] == turn) && (board[1][1] == turn) && (board[2][2] == turn))
gameOver = turn;
else
if ((board[0][2] == turn) && (board[1][1] == turn) && (board[2][0] == turn))
gameOver = turn;
}
/*****************************************************************************
 * If the game has been won, set gameOver equal to turn.
 * Turn always contains a value that is boolean true: 1 or 2.
 *****************************************************************************/
void TicTacToe::PlayGame()
{
int i;
while (gameOver!=turn)
{
//DrawBoard();
cout << "Player[" << turn << "] Please enter move: ";
cin >> i;
PlayerMove(i);
}
cout << "Player[" << turn << "] Wins!" << endl;
}
/*****************************************************************************
 * Display the game board using ASCII characters.
 *****************************************************************************/
void TicTacToe::DrawBoard()
{
int temp[9];
int k = 0;
for(int i = 0; i < 3; i++)
for(int j = 0; j < 3; j++)
{
if (board[i][j] == 0)
temp[k] = k+49;
else
 {
if (board[i][j] == 1)
 temp[k] = 88;
else
 temp[k] = 79;
 }
k++;
}
cout << "+---+---+---+\n";
cout <<"| " << (char)temp[0] << " | " << (char)temp[1] << " | " << (char)temp[2] << " | \n";
cout << "+---+---+---+\n";
cout <<"| " << (char)temp[3] << " | " << (char)temp[4] << " | " << (char)temp[5] << " | \n";
cout << "+---+---+---+\n";
cout <<"| " << (char)temp[6] << " | " << (char)temp[7] << " | " << (char)temp[8] << " | \n";
cout << "+---+---+---+\n";
}
/*****************************************************************************
 * Instantiate a TicTacToe object, which effectively starts your game play.
 *****************************************************************************/
int main()
{
TicTacToe Game;
return 0;
}