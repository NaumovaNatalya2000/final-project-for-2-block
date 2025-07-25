#include "FunctionsSystem.h"

void clearScreen()
{
	std::cout << "\033[2J\033[H";
}

void pause()
{
	std::cout << "Нажмите Enter для продолжения...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}