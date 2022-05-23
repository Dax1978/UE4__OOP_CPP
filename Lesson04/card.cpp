#include <iostream>
#include <sstream>
#include "card.h"

Card::Card(RANK rank, SUIT suit, bool flip)
    : c_suit(suit), c_rank(rank), c_flip(flip) {
    
    switch (c_rank) {
    case 0: card = "_2"; c_value = 2; break;
    case 1: card = "_3"; c_value = 3; break;
    case 2: card = "_4"; c_value = 4; break;
    case 3: card = "_5"; c_value = 5; break;
    case 4: card = "_6"; c_value = 6; break;
    case 5: card = "_7"; c_value = 7; break;
    case 6: card = "_8"; c_value = 8; break;
    case 7: card = "_9"; c_value = 9; break;
    case 8: card = "10"; c_value = 10; break;
    case 9: card = "_J"; c_value = 10; break;
    case 10: card = "_Q"; c_value = 10; break;
    case 11: card = "_K"; c_value = 10; break;
    case 12: card = "_A"; c_value = 1; break;
    }

    switch (c_suit) {
    case 0: card += "D"; break;
    case 1: card += "H"; break;
    case 2: card += "C"; break;
    case 3: card += "S"; break;;
    }
}

void Card::flip() { c_flip = !c_flip; }

std::string Card::getCard() {
    if (c_flip) {
        return card;
    }
    return "___";
}

bool Card::getFlip() { return c_flip; }

int Card::getValue() { return c_value; }
