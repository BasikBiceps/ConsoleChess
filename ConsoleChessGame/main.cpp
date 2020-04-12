#include <iostream>
#include <string>
#include "Game.h"

int main()
{
	std::string firstPlayer;
	std::string secondPlayer;

	std::cout << "Welcome you to the Console Chess!" << std::endl;
	std::cout << "Enter first player nickname: ";
	std::cin >> firstPlayer;
	std::cout << "Enter second player nickname: ";
	std::cin >> secondPlayer;

	Game game(Player(firstPlayer, FigureColor::White), Player(secondPlayer, FigureColor::Black));

	game.start();

	return 0;
}