#pragma once
#include "Card.h"
#include <vector>

class Hand
{
protected:
	std::vector<Card*> m_Cards;

public:
	Hand();

	// виртуальный деструктор
	virtual ~Hand();

	// добавл€ет карту в руку
	void Add(Card* pCard);

	// ќчищает руку от карт
	void Clear();

	// —читаем количество очков в руке
	int GetTotal() const;
};