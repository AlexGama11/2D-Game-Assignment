#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Directory.h"

//constants for game
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// calling functions
void tutorial();
int askNumber(std::string question, int high, int low = 0);
char playerChar();
char pcChar(char playerChar);
void displayBoard(const std::vector<char>& board);
char winner(const std::vector<char>& board);
int playerMove(const std::vector<char>& board, char player);
int pcMove(std::vector<char> board, char pc);
void announceWinner(char winner, char pc, char player);


// main TicTacToe function
int playTTC()
{
	int move;
	const int BOARD_NUM = 9;
	std::vector<char> board(BOARD_NUM, EMPTY);

	tutorial();
	char player = playerChar();
	char pc = pcChar(player);
	char turn = X;
	displayBoard(board);

	while (winner(board) == NO_ONE)
	{
		if (turn == player)
		{
			move = playerMove(board, player);
			board[move] = player;
		}

		else
		{
			move = pcMove(board, pc);
			board[move] = pc;
		}

		displayBoard(board);
		turn = pcChar(turn);
	}

	announceWinner(winner(board), pc, player);
	return 0;
}

// teaches player how to play
void tutorial()
{
	std::cout << "Welcome to Tic Tac Toe!!!" << std::endl;
	std::cout << "You'll face the PC in this game" << std::endl;

	std::cout << "Enter a number from 0 to 8 to move." << std::endl;
	std::cout << "The number you input will dictate your position on the board" << std::endl;

	std::cout << "0 | 1 | 2" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << "3 | 4 | 5" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << "6 | 7 | 8" << std::endl;

	std::cout << "Good luck and have fun!" << std::endl;
}

// for the Yes/No question
int askYesNo(std::string question)
{
	char answer;
	do
	{
		std::cout << question << " (y/n):";
		std::cin >> answer;
		std::cin.get();
	}

	while (answer != 'y' && answer != 'n');
	{
		return answer;
	}
}

// For the numbers
int askNumber(std::string question, int high, int low)
{
	int number;
	do
	{
		std::cout << question << "(" << low << "-" << high << "):";
		std::cin >> number;
		std::cin.get();
	}

	while (number > high || number < low);
	{
		return number;
	}
}

// defines player's character
char playerChar()
{
	char first_move = askYesNo("Do you wish to go first?");
	if (first_move == 'y')
	{
		std::cout << "You'll have the first move." << std::endl;
		return X;
	}

	else
	{
		std::cout << "You'll move last." << std::endl;
		return O;
	}
}

//defines enemy character
char pcChar(char Char)
{
	if (Char == X)
	{
		return O;
	}

	else if (Char == O)
	{
		return X;
	}
}

// defines the board
void displayBoard(const std::vector<char>& board)
{
	std::cout << board[0] << " | " << board[1] << " | " << board[2]<< std::endl;
	std::cout << "---------" << std::endl;
	std::cout << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << board[6] << " | " << board[7] << " | " << board[8] << std::endl;

}

//dictates winner
char winner(const std::vector<char>& board)
{
	//winning combinations
	const int WINNING_COMBINATIONS[8][3] = 
	{ {0, 1, 2},
	  {3, 4, 5},
	  {6, 7, 8},
	  {0, 3, 6},
	  {1, 4, 7},
	  {2, 5, 8},
	  {0, 4, 8},
	  {2, 4, 6} };

	const int TOTAL_ROWS = 8;
	//if someone achieves a winning combination, they win
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
	//checks if there are 3 squares in a row with the same char, or if there are still some empty
		if ((board[WINNING_COMBINATIONS[row][0]] != EMPTY) && (board[WINNING_COMBINATIONS[row][0]] == board[WINNING_COMBINATIONS[row][1]]) && (board[WINNING_COMBINATIONS[row][1]] == board[WINNING_COMBINATIONS[row][2]]))
		{
			return board[WINNING_COMBINATIONS[row][0]];
		}
	}

	//checks if game ended in a tie
	if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		return TIE;
	}

	return NO_ONE;
}

//inline for optimising, checks if move is legal
inline bool isLegal(int move, const std::vector<char>& board)
{
	return (board[move] == EMPTY);
}

//for player movement
int playerMove(const std::vector<char>& board, char player)
{
	int move = askNumber("What square do you choose?", (board.size() - 1));
	while (!isLegal(move, board))
	{
	//checks if move is legal
		std::cout << "Choose a square that isn't occupied! You Cheater!" << std::endl;
			move = askNumber("What square do you choose?", (board.size() - 1));
	}

	std::cout << "Well done!" << std::endl;
	return move;
}

//for pc movement
int pcMove(std::vector<char> board, char pc)
{
	//how AI works:
	//pc first makes a move that it sees it can win, else it makes a move to block player, else it just makes best move
	unsigned int move = 0;
	bool found = false;

	//if pc can win
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = pc;
			found = winner(board) == pc;
			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}

	}

	//if it needs to block the player
	if (!found)
	{
		move = 0;
		char player = pcChar(pc);

		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = player;
				found = winner(board) == player;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}

	//if both fail ---> order for best moves Centre ---> Corners
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 7, 1, 3, 5, 7 };

			while (!found && i < board.size())
			{
				move = BEST_MOVES[i];
				if (isLegal(move, board))
				{
					found = true;
				}

				++i;
		    }
	}

	std::cout << "PC chose square:" << move << std::endl;
	return move;
}

// announces the winner, previously tried to make a custom name in a separate cpp, but it failed (my Visual studio was problematic), kept default name
void announceWinner(char winner, char pc, char player)
{
	if (winner == pc)
	{
		std::cout << "The winner is:" << winner << "!" << std::endl;
		std::cout << "You lost! Better luck next time!" << std::endl;
	}

	else if (winner == player)
	{
		std::cout << "The winner is:" << winner << "!" << std::endl;
		std::cout << "You won! Congratulations!" << std::endl;
	}

	else
	{
		std::cout << "You Tied! Better luck next time!" << std::endl;
	}
}