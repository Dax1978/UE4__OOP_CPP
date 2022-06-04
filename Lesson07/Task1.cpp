////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 1                                                                                                      //
// Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для //
// данного класса. Создайте два "умных" указателя today и date. Первому присвойте значение сегодняшней даты. Для  //
// него вызовите по отдельности методы доступа к полям класса Date, а также выведите на экран данные всего        //
// объекта с помощью перегруженного оператора вывода. Затем переместите ресурс, которым владеет указатель today в //
// указатель date. Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию   //
// об этом в консоль.                                                                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date(int day = 1, int month = 1, int year = 2022) : m_day(day), m_month(month), m_year(year) {  }

    int getDay() { return m_day; }
    int getMonth() { return m_month; }
    int getYear() { return m_year; }

    friend std::ostream& operator<< (std::ostream& out, const Date& date);

};

std::ostream& operator<< (std::ostream& out, const Date& date)
{
    // Поскольку operator<< является другом класса Date, мы можем напрямую обращаться к членам класса Date.
    // здесь выполняется фактический вывод
    out << "Дата: " << date.m_day << "." << date.m_month << "." << date.m_year << std::endl;

    // возвращаем std::ostream, чтобы мы могли объединить в цепочку вызовы operator<<
    return out;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // задаём русский текст
    system("chcp 1251"); // настраиваем кодировку консоли

    // Создаем "умный" указатель
    auto today = std::make_unique<Date>(6, 6, 2022);
    auto date = std::make_unique<Date>();

    std::cout << "Сегодняшняя дата: " << today->getDay() << std::endl;
    std::cout << "Сегодняшний месяц: " << today->getMonth() << std::endl;
    std::cout << "Сегодняшний год: " << today->getYear() << std::endl;
    std::cout << *today;

    date = std::move(today);

    // if (today == NULL) - так понятней, но говорят надо делать так:
    if (today) {
        std::cout << "Указатель today нулевой." << std::endl;
    }
    else {
        std::cout << "Указатель today не нулевой." << std::endl;
    }

    if (today == nullptr) {
        std::cout << "Указатель today не нулевой." << std::endl;
    }
    else {
        std::cout << "Указатель today нулевой." << std::endl;
    }

    date ? std::cout << "Указатель date нулевой.\n" : std::cout << "Указатель date не нулевой.\n";
    std::cout << "Дата в date: " << date->getDay() << std::endl;
    std::cout << "Месяц в date: " << date->getMonth() << std::endl;
    std::cout << "Год в date: " << date->getYear() << std::endl;

    return 0;
}