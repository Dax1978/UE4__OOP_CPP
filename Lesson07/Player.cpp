#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : GenericPlayer(name) { }


bool Player::IsHitting() const
{
    std::cout << m_Name << ", ��� �����? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
    std::cout << m_Name << " �������.\n";
}

void Player::Lose() const
{
    std::cout << m_Name << " ��������.\n";
}

void Player::Push() const
{
    std::cout << m_Name << " �����.\n";
}