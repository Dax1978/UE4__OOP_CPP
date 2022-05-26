////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задача 3                                                                                                       //
// Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.  //
// Этот шаблон класса должен наследовать частично специализированный класс Pair,                                  //
// в котором первый параметр — string, а второй — любого типа данных.                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair
{
private:
    T1 m_first;
    T2 m_second;

public:
    Pair(const T1& first, const T2& second)
        : m_first(first), m_second(second)
    { }

    ~Pair()
    { }

    const T1& first() const { return m_first; }
    const T2& second() const { return m_second; }
};


template <typename T>
class StringValuePair: public Pair<std::string, T>
{
public:
    StringValuePair(const std::string& first, const T& second) :
        Pair<std::string, T>(first, second) {}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}