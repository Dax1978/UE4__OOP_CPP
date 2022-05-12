////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 2                                                                                                      //
// Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и  //
// m_alpha (#include cstdint для доступа к этому типу).                                                           //
// Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.                        //
// Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для     //
// m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов. //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>

class RGBA {
private:
    std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;

public:
    RGBA(unsigned int red = 0, unsigned int green = 0, unsigned int blue = 0, unsigned int alpha = 255) {
        this->m_red = static_cast<std::uint8_t>(red);
        this->m_green = static_cast<std::uint8_t>(green);
        this->m_blue = static_cast<std::uint8_t>(blue);
        this->m_alpha = static_cast<std::uint8_t>(alpha);
    };

    void print() {
        std::cout << "Красный: " << static_cast<unsigned>(m_red) << " Зеленый: " << static_cast<unsigned>(m_green) << " Синий: " << static_cast<unsigned>(m_blue) << " Прозрачность: " << static_cast<unsigned>(m_alpha) << std::endl;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");

    RGBA rgba(77, 77, 77, 255);
    rgba.print();

    return 0;
};