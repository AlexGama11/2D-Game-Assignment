#include <iostream>
#include <string>
#include "Directory.h"


int main()
{
	bool MenuisRunning = true;
	while (MenuisRunning)
	{
		std::string answer0;
		std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|Do you wish to play the game, to calculate, to ask for help, or to exit?|" << std::endl;
		std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
		std::getline(std::cin, answer0);

		if (answer0 == "Game" || answer0 == "game" || answer0 == "g" || answer0 == "G")
		{
			int MenuLoader = Game();
		}

		else if (answer0 == "Calculate" || answer0 == "calculate" || answer0 == "c" || answer0 == "C")
		{
			int CalculatorLoader = CalculatorCTRL();
		}

		else if (answer0 == "Help" || answer0 == "help" || answer0 == "h" || answer0 == "H")
		{
			int HelpMenu = Help();
		}

		else if (answer0 == "Exit" || answer0 == "exit" || answer0 == "e" || answer0 == "E")
		{
			MenuisRunning = false;
		}


		else
		{
			std::cout << "----------------" << std::endl;
			std::cout << "|Invalid Input!|" << std::endl;
			std::cout << "----------------" << std::endl;
		}
	}
	return 0;
}

