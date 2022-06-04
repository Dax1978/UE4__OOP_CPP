#pragma once
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
	Game(const std::vector<std::string>& names);

	~Game();

	// проводит игру в Blackjack
	void Play();

private:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
};