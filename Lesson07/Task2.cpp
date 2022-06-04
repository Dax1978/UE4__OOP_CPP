////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 2                                                                                                      //
// По условию предыдущей задачи создайте два умных указателя date1 и date2.                                       //
//    - Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их    //
//       между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.                  //
//    - Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в       //
//       качестве параметров.                                                                                     //
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

std::unique_ptr<Date>& comparisonDates(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2)
{
    if (date1->getYear() > date2->getYear())
        return date1;
    else if (date1->getYear() < date2->getYear())
        return date2;
    else
    {
        if (date1->getMonth() > date2->getMonth())
            return date1;
        else if (date1->getMonth() < date2->getMonth())
            return date2;
        else
        {
            if (date1->getDay() > date2->getDay())
                return date1;
            else
                return date2;
        }
    }
}

void changeDates(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2)
{
    auto date3 = std::make_unique<Date>(date2->getDay(), date2->getMonth(), date2->getYear());
    date2 = std::move(date1);
    date1 = std::move(date3);
}

int main()
{
    setlocale(LC_ALL, "Russian"); // задаём русский текст
    system("chcp 1251"); // настраиваем кодировку консоли

    // Создаем "умный" указатель
    auto date1 = std::make_unique<Date>(6, 6, 2022);
    auto date2 = std::make_unique<Date>(7, 7, 2027);

    std::cout << "Данные в date1: " << *date1;
    std::cout << "Данные в date2: " << *date2;
    std::cout << "Более свежая дата: " << *comparisonDates(date1, date2);
    changeDates(date1, date2);
    std::cout << "Данные в date1: " << *date1;
    std::cout << "Данные в date2: " << *date2;


    return 0;
}