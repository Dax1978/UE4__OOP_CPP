////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание игры Blackjack                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(suit s, rank r = ACE, bool ifu = true) : m_Suit(s), m_Rank(r), m_IsFaceUp(ifu) { }

	// переворачивание карты
	void Flip() { m_IsFaceUp = !(m_IsFaceUp); }

	int GetValue() const
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
	}

	friend std::ostream& operator<<(std::ostream& s, const Card& aCard);

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

class Hand
{
protected:
	std::vector<Card*> m_Cards;

public:
	Hand() { m_Cards.reserve(7); }

	// виртуальный деструктор
	virtual ~Hand() { Clear(); }

	// добавляет карту в руку
	void Add(Card* pCard) { m_Cards.push_back(pCard); }

	void Clear()
	{
		// проходит по вектору, освобождая всю память в куче
		std::vector<Card*>::iterator iter = m_Cards.begin();
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			delete* iter;
			*iter = nullptr;
		}

		m_Cards.clear();
	}

	int GetTotal() const
	{

		// если карт в руке нет, возвращает значение 0
		if (m_Cards.empty()) 
		{
			return 0;
		}

		//если первая карта имеет значение 0, то она лежит рубашкой вверх:
		// вернуть значение 0
		if (m_Cards[0]->GetValue() == 0)
		{
			return 0;
		}

		// находит сумму очков всех карт, каждый туз дает 1 очко
		int total = 0;
		std::vector<Card*>::const_iterator iter;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			total += (*iter)->GetValue();
		}

		// определяет, держит ли рука туз
		bool containsAce = false;
		for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		{
			if ((*iter)->GetValue() == Card::ACE)
			{
				containsAce = true;
			}
		}

		// если рука держит туз и сумма довольно маленькая, туз дает 11 очков
		if (containsAce && total <= 11)
		{
			// добавляем только 10 очков, поскольку мы уже добавили
			// за каждый туз по одному очку
			total += 10;
		}
		return total;
	}
};

class GenericPlayer : public Hand
{
private:
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

protected:
	std::string m_Name;

public:
	GenericPlayer(const std::string& name = "") : m_Name(name) { }

	virtual ~GenericPlayer();

	// чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта
	virtual bool IsHitting() const = 0;

	// возвращает bool значение, есть ли у игрока перебор
	bool IsBusted() const { return (GetTotal() > 21); }

	// выводит на экран имя игрока и объявляет, что у него перебор
	void Bust() const { std::cout << m_Name << " перебор." << std::endl; }
};






int main()
{
	setlocale(LC_ALL, "Russian");



	return 0;
}