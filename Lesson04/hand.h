#pragma once

#include <vector>

#include "card.h"

class Hand {
private:
	std::vector<Card*> c_Cards;

public:
	Hand() {}
	// ���������� �����
	void add(Card* pCard) { c_Cards.push_back(pCard); }
	// �������� ���� - �������� ��� �����
	void Clear() { c_Cards.clear(); }
	// ����� ����� �� ����
	int getTotal()
	{
		int ace = 0;
		int sum = 0;
		if (c_Cards.size() == 0) {
			return 0;
		}
		else {
			for (size_t i = 0; i < c_Cards.size(); i++) {
				// ������� ���������� �����
				if (c_Cards[i]->getValue() == 1) { ace++; }
				sum += c_Cards[i]->getValue();
			}
			// ���� ��� � ���� � ����� ����� �� ���� ����� ���� ����� 11, �� ��������� 10
			// ������ ��� 11 ���� 1 ����.
			// �������������� ���� ��� ����, �� �� ����� -1 �� ����� ����������� ���� � +11 �� ���, �� ���� ������ +10.
			if (ace > 0 && sum <= 11) { sum += 10; }
			return sum;
		}
	}

	// �������� �����
	void show() 
	{
		if (c_Cards.size() > 0) {
			for (size_t i = 0; i < c_Cards.size(); i++) {
				std::cout << c_Cards[i]->getCard() << " ";
			}
			std::cout << std::endl;
		}
	}
	// �������� ����� ���������
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