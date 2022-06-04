#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <ctime>

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
};

Deck::~Deck() {};

void Deck::Populate()
{
	Clear();
	// создает стандартную колоду
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			Add(new Card(static_cast<Card::suit>(s),
				         static_cast<Card::rank>(r)));
		}
	}
};

void Deck::Shuffle()
{
	srand(static_cast<unsigned int>(time(0)));
	std::random_shuffle(m_Cards.begin(), m_Cards.end());
};

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		std::cout << "Out of cards. Unable to deal.";
	}
};

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;
	// продолжает раздавать карты до тех пор, пока у игрока не случается
	// перебор или пока он хочет взять еще одну карту
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;

		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	}
};