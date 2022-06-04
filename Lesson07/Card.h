#pragma once
#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>

class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(suit s = SPADES, rank r = ACE, bool ifu = true);

	// переворачивание карты
	void Flip();

	// выдать значение карты
	int GetValue() const;

	friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

std::ostream& operator<<(std::ostream& os, const Card& aCard);

#endif