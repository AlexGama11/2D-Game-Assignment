#pragma once


// my directory for functions in different cpp files

enum class MainMenu
{
	Play,
	BackToMain
};

enum class Calculator
{
	Add,
	Subtract,
	Multiply,
	Divide,
	Remainder,
	Return
};

int CalculatorCTRL();

int Game();

int Help();

int playTTC();

int playGMN();
