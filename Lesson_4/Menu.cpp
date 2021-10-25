#include <iostream>
#include <string>
#include "Menu.h"
#include "Calculator.h"


int MenuCTRL()
{
	MainMenu mainmenu = MainMenu::Play;

	bool GameisRunning = true;

	//while loop
	while (GameisRunning)
	{
		int menuOption = (int)MainMenu::Play;
		std::cout << "What do you wish to do?[Play = 0, Options = 1, Help = 2, Quit = 3}";
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
			std::cout << "Thank you for choosing this option, however there is no game to play right now, so here are some questions:" << std::endl;

			//enter a boolean and display
			bool isHuman = false;
			std::string answer;
			std::cout << "Are you a Human? Yes or No? ";
			std::getline(std::cin, answer);

			if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y")
			{
				isHuman = true;
				std::cout << "Your answer is: Yes" << std::endl;
			}

			else if (answer == "No" || answer == "no" || answer == "n" || answer == "N")
			{
				isHuman = false;
				std::cout << "Your answer is: No" << std::endl;
			}

			else
			{
				std::cout << "Invalid Input" << std::endl;
			}

			//enter a string and display
			std::string name;
			std::cout << "Hi, What is your name?" << std::endl;
			std::getline(std::cin, name);
			std::cout << "Your name is: " << name << std::endl;

			//enter a float and display
			float number = 0.0f;

			std::cout << "Enter a number:" << std::endl;
			std::cin >> number;
			//stops the code from breaking if someone inputs a letter, previously used in line 27 as well
			while (std::cin.fail()) {
				std::cout << "Please input a number!" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> number;
			}
			std::cout << "You've entered:" << number << std::endl;
			std::cin.get();

			//enter a char and display
			char character = ' ';

			std::cout << "Enter your favourite character (A-Z, 0-9): ";
			std::cin >> character;
			std::cout << "You have entered: " << character << std::endl;
			std::cin.get();
			break;
		}


		case MainMenu::Options:
		{
			int volume = 0;
			std::cout << "Choose the volume for this game (0-10): " << std::endl;
			std::cin >> volume;
			{
				//volume must be between 0 or 10
				if (volume >= 0 && volume <= 10)
				{
					std::cout << "You chose:" << volume << std::endl;

				}
				//if failed
				else if (volume < 0 || volume > 10)
				{
					std::cout << "Please input a number between 0 and 10!" << std::endl;
				}
				break;
			}
		}

		case MainMenu::Help:
		{
			std::cout <<"If you need help you can email me at AFD0046@my.londonmet.ac.uk or through discord: 『AlexMango』#8429" << std::endl;
			break;
		}

		case MainMenu::Quit:
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
