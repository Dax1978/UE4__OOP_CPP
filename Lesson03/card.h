#pragma once

// Перечисление - масти
enum SUIT {
    D,          // Diamond (Бубы / Алмазы)
    H,          // Hearts (Черви / Сердца)
    C,          // Clubs (Трефы / Клубы)
    S,          // Spades (Пики / Лопаты)
};

// Перечисление - значение карты
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
    __J,        // Jack (Валет / Джек)
    __Q,        // Queen (Дама / Королева)
    __K,        // King (Король)
    __A,        // Ace (Туз)
};

class Card {
private:
    SUIT c_suit;                // Масть
    RANK c_rank;                // Значение
    bool c_flip;                // Положение карты: true - лицом вверх, false - рубашкой вверх

    std::string card = "";      // Для записи значения и масти карты
    int c_value = 0;            // Числовой номинал карты

public:
    Card(RANK rank, SUIT suit, bool flip);

    // Метод переворота карты
    void flip();

    // Метод возвращает карту. Если лицом вверх - значение и масть, если рубашкой - то ___
    std::string getCard();

    // Метод возвращает положение карты
    bool getFlip();

    // Метод возвращает номинал карты
    int getValue();
};