#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();

	// создает стандартную колоду из 52 карт
	void Populate();

	// тасует карты
	void Shuffle();

	// раздает одну карту в руку
	void Deal(Hand& aHand);

	// дает дополнительные карты игроку
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};