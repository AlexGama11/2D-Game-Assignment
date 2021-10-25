#include <iostream>
#include <string>
#include "Menu.h"
#include "Calculator.h"


int main()
{
	bool MenuisRunning = true;
	while (MenuisRunning)
	{
		std::string answer0;
		std::cout << "---------------------------------------------------------" << std::endl;
		std::cout << "|Do you wish to play the game, to calculate, or to exit?|" << std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
		std::getline(std::cin, answer0);

		if (answer0 == "Game" || answer0 == "game" || answer0 == "g" || answer0 == "G")
		{
			int MenuLoader = MenuCTRL();
		}

		else if (answer0 == "Calculate" || answer0 == "calculate" || answer0 == "c" || answer0 == "C")
		{
			int CalculatorLoader = CalculatorCTRL();
		}

		else if (answer0 == "Exit" || answer0 == "exit" || answer0 == "e" || answer0 == "E")
		{
			MenuisRunning = false;
		}

		else
		{
			std::cout << "Invalid Input" << std::endl;
		}
	}
	return 0;
}

