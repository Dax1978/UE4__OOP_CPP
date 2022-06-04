#include "Hand.h"

Hand::Hand() { m_Cards.reserve(7); };

Hand::~Hand() { Clear(); };

void Hand::Add(Card* pCard) { m_Cards.push_back(pCard); };

void Hand::Clear()
{
	// �������� �� �������, ���������� ��� ������ � ����
	std::vector<Card*>::iterator iter = m_Cards.begin();

	// for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	for (auto iter : m_Cards)
	{
		// delete* iter;
		// *iter = nullptr;
		delete iter;
		iter = 0;
	}

	m_Cards.clear();
};

int Hand::GetTotal() const
{
	// ���� ���� � ���� ���, ���������� �������� 0
	if (m_Cards.empty())
	{
		return 0;
	}

	//���� ������ ����� ����� �������� 0, �� ��� ����� �������� �����:
	// ������� �������� 0
	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}

	// ������� ����� ����� ���� ����, ������ ��� ���� 1 ����
	int total = 0;

	std::vector<Card*>::const_iterator iter;

	// for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	for (Card* iter : m_Cards)
	{
		// total += (*iter)->GetValue();
		total += (iter)->GetValue();
	}

	// ����������, ������ �� ���� ���
	bool containsAce = false;
	// for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	for (Card* iter : m_Cards)
	{
		// if ((*iter)->GetValue() == Card::ACE)
		if ((iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	// ���� ���� ������ ��� � ����� �������� ���������, ��� ���� 11 �����
	if (containsAce && total <= 11)
	{
		// ��������� ������ 10 �����, ��������� �� ��� ��������
		// �� ������ ��� �� ������ ����
		total += 10;
	}
	return total;
};