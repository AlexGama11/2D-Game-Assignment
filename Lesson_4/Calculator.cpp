#include <iostream>
#include <string>
#include "Directory.h"

// Calculator
int CalculatorCTRL()
{
			Calculator calculate = Calculator::Add;

			bool CalculatorisRunning = true;
			while (CalculatorisRunning)
			{
				int calculateoption = (int)Calculator::Add;
				std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
				std::cout << "|What do you wish to do?[Add = 0, Subtract = 1, Multiply = 2, Divide = 3, Remainder = 4, Return = 5}|" << std::endl;
				std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
				std::cin >> calculateoption;
				std::cin.get();
				//if the answer fails, it clears cin and tells the player to put a number between 0 and 4.
				while (std::cin.fail())
				{
					std::cout << "----------------------------------------" << std::endl;
					std::cout << "|Please input a number between 0 and 5!|" << std::endl;
					std::cout << "----------------------------------------" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> calculateoption;
				}
				calculate = (Calculator)(calculateoption);

				switch (calculate)
				{
					// adds numbers
				case Calculator::Add:
				{
					int num1 = 0;
					int num2 = 0;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "|Please input the first number!|" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cin >> num1;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					std::cout << "---------------------------------" << std::endl;
					std::cout << "|Please input the second number!|" << std::endl;
					std::cout << "---------------------------------" << std::endl;
					std::cin >> num2;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					int num3 = num1 + num2;
					std::cout << "The answer is:" << num3 << std::endl;
					break;

				}

				// subtracts numbers
				case Calculator::Subtract:
				{
					int num1 = 0;
					int num2 = 0;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "|Please input the first number!|" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cin >> num1;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					std::cout << "---------------------------------" << std::endl;
					std::cout << "|Please input the second number!|" << std::endl;
					std::cout << "---------------------------------" << std::endl;
					std::cin >> num2;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					int num3 = num1 - num2;
					std::cout << "The answer is:" << num3 << std::endl;
					break;
				}

				// multiplies numbers
				case Calculator::Multiply:
				{
					int num1 = 0;
					int num2 = 0;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "|Please input the first number!|" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cin >> num1;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					std::cout << "---------------------------------" << std::endl;
					std::cout << "|Please input the second number!|" << std::endl;
					std::cout << "---------------------------------" << std::endl;
					std::cin >> num2;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					int num3 = num1 * num2;
					std::cout << "The answer is:" << num3 << std::endl;
					break;
				}

				// divides numbers
				case Calculator::Divide:
				{
					int num1 = 0;
					int num2 = 0;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "|Please input the first number!|" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cin >> num1;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					std::cout << "---------------------------------" << std::endl;
					std::cout << "|Please input the second number!|" << std::endl;
					std::cout << "---------------------------------" << std::endl;
					std::cin >> num2;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}

					// no dividing by 0
					if (num2 == 0)
					{
						std::cout << "---------------------------------" << std::endl;
						std::cout << "|Error!Attempted to divide by 0!|" << std::endl;
						std::cout << "---------------------------------" << std::endl;
						break;
					}

					else
					{
						int num3 = num1 / num2;
						std::cout << "The answer is:" << num3 << std::endl;
						break;
					}
				}

				// gets the remainder of a division.
				case Calculator::Remainder:
				{
					int num1 = 0;
					int num2 = 0;
					std::cout << "--------------------------------" << std::endl;
					std::cout << "|Please input the first number!|" << std::endl;
					std::cout << "--------------------------------" << std::endl;
					std::cin >> num1;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}
					std::cout << "---------------------------------" << std::endl;
					std::cout << "|Please input the second number!|" << std::endl;
					std::cout << "---------------------------------" << std::endl;
					std::cin >> num2;
					std::cin.get();
					while (std::cin.fail())
					{
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cout << "|Your number is either too big, too small or not an integer!|" << std::endl;
						std::cout << "-------------------------------------------------------------" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> calculateoption;
					}

					// no dividing by 0
					if (num2 == 0)
					{
						std::cout << "----------------------------------" << std::endl;
						std::cout << "|Error! Attempted to divide by 0!|" << std::endl;
						std::cout << "----------------------------------" << std::endl;
						break;
					}
					else
					{
						int num3 = num1 % num2;
						std::cout << "The answer is:" << num3 << std::endl;
						break;
					}
				}
				// returns to main
				case Calculator::Return:
				{
					std::string answer3;
					std::cout << "-------------------------------------------------------" << std::endl;
					std::cout << "|Do you wish to return to the initial menu? Yes or No?|" << std::endl;
					std::cout << "-------------------------------------------------------" << std::endl;
					std::getline(std::cin, answer3);

					if (answer3 == "Yes" || answer3 == "yes" || answer3 == "y" || answer3 == "Y")
					{
						CalculatorisRunning = false;
						break;
					}

					else if (answer3 == "No" || answer3 == "no" || answer3 == "n" || answer3 == "N")
					{
						std::cout << "-------------------------------------------" << std::endl;
						std::cout << "|You've chosen to return to the calculator|" << std::endl;
						std::cout << "-------------------------------------------" << std::endl;
						break;
					}
				}

				default:
				{
					std::cout << "------------------------" << std::endl;
					std::cout << "|That input is invalid!|" << std::endl;
					std::cout << "------------------------" << std::endl;
					break;
				}
				}
			}
			return 2;
}