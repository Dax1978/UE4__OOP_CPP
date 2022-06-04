#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

class GenericPlayer : public Hand
{
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

protected:
	std::string m_Name;

public:
	// ����������� ������� ������ ��������� ������, �������������� ����� ��� ������
	GenericPlayer(const std::string& name = "");

	// ���������� ������������� ���������� �����������, ��������� ��������� ��� �������� �� ������ Hand
	virtual ~GenericPlayer();

	// ����� ����������� �������, ���������� ����������, ����� �� ������ ��� ���� �����
	virtual bool IsHitting() const = 0;

	// ���������� bool ��������, ���� �� � ������ �������
	bool IsBusted() const;

	// ������� �� ����� ��� ������ � ���������, ��� � ���� �������
	void Bust() const;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);