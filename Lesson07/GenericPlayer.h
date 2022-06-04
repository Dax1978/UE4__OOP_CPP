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
	//  онструктор данного класса принимает строку, представл€ющую собой им€ игрока
	GenericPlayer(const std::string& name = "");

	// ƒеструктор автоматически становитс€ виртуальным, поскольку наследует это свойство от класса Hand
	virtual ~GenericPlayer();

	// чисто виртуальна€ функци€, возвращает информацию, нужна ли игроку еще одна карта
	virtual bool IsHitting() const = 0;

	// возвращает bool значение, есть ли у игрока перебор
	bool IsBusted() const;

	// выводит на экран им€ игрока и объ€вл€ет, что у него перебор
	void Bust() const;
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);