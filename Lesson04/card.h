#pragma once

// ������������ - �����
enum SUIT {
    D,          // Diamond (���� / ������)
    H,          // Hearts (����� / ������)
    C,          // Clubs (����� / �����)
    S,          // Spades (���� / ������)
};

// ������������ - �������� �����
enum RANK {
    __2,
    __3,
    __4,
    __5,
    __6,
    __7,
    __8,
    __9,
    _10,
    __J,        // Jack (����� / ����)
    __Q,        // Queen (���� / ��������)
    __K,        // King (������)
    __A,        // Ace (���)
};

class Card {
private:
    SUIT c_suit;                // �����
    RANK c_rank;                // ��������
    bool c_flip;                // ��������� �����: true - ����� �����, false - �������� �����

    std::string card = "";      // ��� ������ �������� � ����� �����
    int c_value = 0;            // �������� ������� �����

public:
    Card(RANK rank, SUIT suit, bool flip);

    // ����� ���������� �����
    void flip();

    // ����� ���������� �����. ���� ����� ����� - �������� � �����, ���� �������� - �� ___
    std::string getCard();

    // ����� ���������� ��������� �����
    bool getFlip();

    // ����� ���������� ������� �����
    int getValue();
};