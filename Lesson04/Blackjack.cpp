////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Игра Blackjack                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <vector>

#include "card.h"
#include "hand.h"



int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "\t\tДобро пожаловать в игру Blackjack!\n\n";

    // Определяем количество игроков
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        std::cout << "Сколько будет игроков? (1 - 7): ";
        std::cin >> numPlayers;
    }

    // Дадим имена игрокам
    std::vector<std::string> names;
    std::string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Укажите имя игрока " << i + 1 << ": ";
        std::cin >> name;
        names.push_back(name);
    }
    std::cout << std::endl;

    ///*
    // Проверка работы класса карта
    Card card1(__7, D, false);
    // std::cout << card.getCard() << ", " << std::boolalpha << card.getFlip() << ", " << card.getValue() << std::endl;
    std::cout << card1.getCard() << ", номинал = " << card1.getValue() << std::endl;
    card1.flip();
    std::cout << card1.getCard() << ", номинал = " << card1.getValue() << std::endl;
    Card card2(__A, H, false);
    Card card3(__A, D, false);
    // Проверка работы класса рука
    Hand hand;
    hand.add(&card1);
    hand.add(&card2);
    hand.add(&card3);
    std::cout << "Сумма очков на руках: " << hand.getTotal() << std::endl;
    hand.show_open();
    //*/

    /*
    // игровой цикл
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
    }
    */

    return 0;
}