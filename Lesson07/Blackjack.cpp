////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание игры Blackjack                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
// #include <set>
#include <string>
#include "Game.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "\t\tДобро пожаловать в игру Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		std::cout << "Сколько будет игроков? (1 - 7): ";
		std::cin >> numPlayers;
	}

	std::vector<std::string> names;
	std::string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		std::cout << "Введите имя игрока: ";
		std::cin >> name;
		names.push_back(name);
	};
	std::cout << std::endl;

	// ИГРА
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		std::cout << "\nВы хотите сыграть заново? (Y/N): ";
		std::cin >> again;
	}

	return 0;
};