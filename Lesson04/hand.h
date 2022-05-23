#pragma once

#include <vector>

#include "card.h"

class Hand {
private:
	std::vector<Card*> c_Cards;

public:
	Hand() {}
	// Добавление карты
	void add(Card* pCard) { c_Cards.push_back(pCard); }
	// Очистить руку - сбросить все карты
	void Clear() { c_Cards.clear(); }
	// Сумма очков на руке
	int getTotal()
	{
		int ace = 0;
		int sum = 0;
		if (c_Cards.size() == 0) {
			return 0;
		}
		else {
			for (size_t i = 0; i < c_Cards.size(); i++) {
				// Считаем количество тузов
				if (c_Cards[i]->getValue() == 1) { ace++; }
				sum += c_Cards[i]->getValue();
			}
			// Если туз в руке и сумма очков на руке менее либо равно 11, то добавляем 10
			// Первый туз 11 либо 1 очко.
			// Соответственно если туз есть, то из суммы -1 за ранее посчитанное очко и +11 за туз, то есть просто +10.
			if (ace > 0 && sum <= 11) { sum += 10; }
			return sum;
		}
	}

	// Показать карты
	void show() 
	{
		if (c_Cards.size() > 0) {
			for (size_t i = 0; i < c_Cards.size(); i++) {
				std::cout << c_Cards[i]->getCard() << " ";
			}
			std::cout << std::endl;
		}
	}
	// Показать карты открытыми
	void show_open()
	{
		if (c_Cards.size() > 0) {
			for (size_t i = 0; i < c_Cards.size(); i++) {
				if (!c_Cards[i]->getFlip()) { c_Cards[i]->flip(); }
				std::cout << c_Cards[i]->getCard() << " ";
			}
			std::cout << std::endl;
		}
	}
};