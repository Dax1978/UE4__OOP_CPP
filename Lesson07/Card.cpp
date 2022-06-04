#include "Card.h"

Card::Card(suit s, rank r, bool ifu) : m_Suit(s), m_Rank(r), m_IsFaceUp(ifu) { };

void Card::Flip() { m_IsFaceUp = !(m_IsFaceUp); };

int Card::GetValue() const
{
	//если карта перевернута лицом вниз, ее значение равно О
	int value = 0;
	if (m_IsFaceUp)
	{
		// значение - это число, указанное на карте
		value = m_Rank;

		// значение равно 10 для JACK, QUEEN и KING
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
};

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const std::string SUITS[] = { "c", "d", "h", "s" };
	if (aCard.m_IsFaceUp)
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	}
	else
	{
		os << "XX";
	}

	return os;
}