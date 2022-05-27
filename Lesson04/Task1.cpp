////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 1                                                                                                      //
// Добавить в контейнерный класс, который был написан в этом уроке, методы:                                       //
//      - для удаления последнего элемента массива (аналог функции pop_back() в векторах)                         //
//      - для удаления первого элемента массива (аналог pop_front() в векторах)                                   //
//      - для сортировки массива                                                                                  //
//      - для вывода на экран элементов.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ArrayInt.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    ArrayInt arr(0);

    std::cout << "Заполним и выведем:" << std::endl;
    arr.insertBefore(7, 0);
    arr.insertBefore(1, 1);
    arr.insertBefore(4, 2);
    arr.insertBefore(2, 3);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(5);
    arr.write();
    std::cout << "Длина массива = " << arr.getLength() << std::endl;

    std::cout << "\nДобавим элементы:" << std::endl;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(6);
    arr.push_back(7);
    arr.write();
    std::cout << "Длина массива = " << arr.getLength() << std::endl;

    std::cout << "\nУдалим последний эллемент массива:" << std::endl;
    arr.pop_back();
    arr.write();
    std::cout << "Длина массива = " << arr.getLength() << std::endl;

    std::cout << "\nУдалим первый эллемент массива:" << std::endl;
    arr.pop_front();
    arr.write();
    std::cout << "Длина массива = " << arr.getLength() << std::endl;

    std::cout << "\nПроведем сортировку массива:" << std::endl;
    arr.sort();    
    arr.write();

    return 0;
}