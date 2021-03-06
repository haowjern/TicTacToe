﻿// Tic Tac Toe Program
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	// declare variables
	const int ROWS = 3;
	const int COLUMNS = 3;
	std::string board[ROWS][COLUMNS]; // 3X3 board for tictactoe
	srand(static_cast<unsigned int>(time(0))); // seed

	// initialise board
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			board[i][j] = std::to_string(i * 3 + j + 1);	// label each element by 1-9
		}
		std::cout << std::endl;
	}
	int counter = 0;
	while (true)
	{
		// display
		std::cout << "Printing 9x9 TicTacToe Board..." << std::endl;

		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				std::cout << board[i][j];	// print out columns of each row 
			}
			std::cout << std::endl;
		}

		///////////////////////////////////////////////////////
		// CHECK WINNING CONDITION


		// check diagonals
		if (board[1][1] == "O")
		{
			if (board[0][0] == "O" && board[2][2] == "O")
			{
				std::cout << "Sorry, you lost :( \n" << std::endl;
				return 0;
			}

			else if (board[0][2] == "O" && board[2][0] == "O")
			{
				std::cout << "Sorry, you lost :( \n" << std::endl;
				return 0;
			}			
		}

		else if (board[1][1] == "X")	
		{
			if (board[0][0] == "X" && board[2][2] == "X")
			{
				std::cout << "Congratulations, you win!\n" << std::endl;
				return 0;
			}

			else if (board[0][2] == "X" && board[2][0] == "X")
			{
				std::cout << "Congratulations, you win!\n" << std::endl;
				return 0;
			}
		}

		// check_rows
		for (int i = 0; i < ROWS; ++i)
		{
			if (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O")
			{
				std::cout << "Sorry, you lost :( \n" << std::endl;
				return 0;
			}

			else if (board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X")
			{
				std::cout << "Congratulations, you win!\n" << std::endl;
				return 0;
			}
		}

		// check_columns
		for (int i = 0; i < COLUMNS; ++i)
		{
			if (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O")
			{
				std::cout << "Sorry, you lost :( \n" << std::endl;
				return 0;
			}

			else if (board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X")
			{
				std::cout << "Congratulations, you win!\n" << std::endl;
				return 0;
			}
		}


		// check draw 
		// if AI tried to put in 9 times, this means the board is filled, and since no win/loss 
		// condition was triggered, this means that it must be a draw

		if (counter == 9)
		{
			std::cout << "Oh no it's a draw :(\n" << std::endl;
			return 0;
		}
		

		////////////////////////////////////////////////////////
		// human input
		int choice = 0;
		std::cout << "Write 1-9 to indicate to write an 'X' where you want it to be." << std::endl;
		while (true)
		{
			std::cin >> choice;
			std::cout << std::endl;
			int new_row = (choice / 3);
			int new_col = (choice % 3) - 1;

			if (choice >= 1 || choice <= 9)
			{
				if (board[new_row][new_col] != "X")
				{
					if (board[new_row][new_col] != "O")
					{
						board[new_row][new_col] = "X";
						break;
					}
				}
			}
			std::cout << "Try Again" << std::endl;
		}

		///////////////////////////////////////////////////////
		// computer random input 'O' 
		counter = 0;
		while (true)
		{
			int comp_choice = rand() % 9 + 1; // choose between 1-9
			int comp_new_row = (comp_choice / 3);
			int comp_new_col = (comp_choice % 3) - 1;
			counter += 1;

			// if AI tried to put in 9 times, this means the board is filled, and since no win/loss 
			// condition was triggered, this means that it must be a draw

			if (counter == 9)  			
			{
				break;
			}

			if (board[comp_new_row][comp_new_col] != "X")
			{
				if (board[comp_new_row][comp_new_col] != "O")
				{
					board[comp_new_row][comp_new_col] = "O";
					break;
				}
			}
		}
	}
	return 0;
}
