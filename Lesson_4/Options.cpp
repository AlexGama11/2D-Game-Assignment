#include <iostream>
#include <string>
#include "Directory.h"


int Options()
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
	}
}