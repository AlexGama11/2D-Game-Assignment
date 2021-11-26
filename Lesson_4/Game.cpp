#include <iostream>
#include <string>
#include "Directory.h"


int Game()
{
	MainMenu mainmenu = MainMenu::Play;

	bool GameisRunning = true;

	//while loop
	while (GameisRunning)
	{
		int menuOption = (int)MainMenu::Play;
		std::cout << "What do you wish to do?[Play (0) or go back to main menu (1) }";
		std::cin >> menuOption;
		std::cin.get();

		//if the answer fails, it clears cin and tells the player to put a number between 0 and 3.
		while (std::cin.fail())
		{
			std::cout << "Please input a number between 0 and 3" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> menuOption;
		}

		mainmenu = (MainMenu)(menuOption);
		//switch case statement
		switch (mainmenu)
		{
		case MainMenu::Play:
		{
			int PlayTTC = mainGame();
			break;
		}


		case MainMenu::BackToMain:
		{
			std::string answer2;
			std::cout << "Do you wish to return to the initial menu? Yes or No " << std::endl;
			std::getline(std::cin, answer2);

			if (answer2 == "Yes" || answer2 == "yes" || answer2 == "y" || answer2 == "Y")
			{
				GameisRunning = false;
				break;
			}

			else if (answer2 == "No" || answer2 == "no" || answer2 == "n" || answer2 == "N")
			{
				std::cout << "You've chosen to return to the main menu" << std::endl;
				break;
			}
		}

		default:
		{
			std::cout << "That input is invalid!" << std::endl;
			break;
		}
		}

	}
	return 1;
}
