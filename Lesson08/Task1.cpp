﻿////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 1                                                                                                      //
// Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать         //
// исключение DivisionByZero, если второй параметр равен 0.                                                       //
// В функции main выводить результат вызова функции div в консоль, а также ловить исключения.                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

double div(const double a, const double b) {
    if (b == 0)
        throw "DivisionByZero";

    return a / b;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите делимое: ";
    double a;
    std::cin >> a;

    std::cout << "Введите делитель: ";
    double b;
    std::cin >> b;

    try {
        double d = div(a, b);
        std::cout << "Частное от делимого " << a << " и делителя " << b << " = " << d << '\n';
    }
    catch (const char* exception) // обработка исключений типа const char*
    {
        std::cerr << "Error: " << exception << std::endl;
    }
    return 0;

}