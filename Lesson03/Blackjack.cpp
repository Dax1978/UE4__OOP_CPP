////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Игра Blackjack                                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>

#include "card.h"



int main()
{
    setlocale(LC_ALL, "rus");

    Card card(__7, D, false);
    // std::cout << card.getCard() << ", " << std::boolalpha << card.getFlip() << ", " << card.getValue() << std::endl;
    std::cout << card.getCard() << ", номинал = " << card.getValue() << std::endl;
    card.flip();
    std::cout << card.getCard() << ", номинал = " << card.getValue() << std::endl;

    return 0;
}