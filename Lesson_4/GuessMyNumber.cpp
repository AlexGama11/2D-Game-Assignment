#include <iostream>
#include<cstdlib>
#include <ctime>


int playGMN()
{
	// generates random numbers
	srand(static_cast<unsigned int>(time(0)));
	int guessNumber = rand() % 100 + 1;
	int lives = 5;
	int guess;
	bool numberGuessed = false;

	// has a lives mechanic, if lives reach 0 = death
	std::cout << "Welcome to Guess My Number!!!" << std::endl;
	std::cout << "You'll face the PC in this game" << std::endl;
	while ((lives > 0) || (numberGuessed == false))
	{
		std::cout << "Guess the Number:";
		std::cin >> guess;

		if (guess > guessNumber)
		{
			std::cout << "Your number is too high!" << std::endl;
			lives--;
		}

		else if (guess < guessNumber)
		{
			std::cout << "Your number is too low!" << std::endl;
			lives--;
		}

		else if (guess == guessNumber + 5 || guess == guessNumber - 5)
		{
			std::cout << "You were close! Have a life back!" << std::endl;
				++lives;
		}

		else if (lives == 0)
		{
			std::cout << "You Lost! Better luck next time! Lives left over:" << lives << std::endl;
			return 0;
		}

		else
		{
			std::cout << "Guessed it! You still have:" << lives << "lives!" << std::endl;
			numberGuessed = true;
			return 0;
		}

	}
}