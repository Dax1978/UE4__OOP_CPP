////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 3                                                                                                      //
// Написать класс, который реализует функциональность стека. Класс Stack должен иметь:                            //
// • private-массив целых чисел длиной 10;                                                                        //
// • private целочисленное значение для отслеживания длины стека;                                                 //
// • public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;               //
// • public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать             //
//     значение false, если массив уже заполнен, и true в противном случае;                                       //
// • public - метод с именем pop() для вытягивания и возврата значения из стека.                                  //
//     Если в стеке нет значений, то должно выводиться предупреждение;                                            //
// • public - метод с именем print(), который будет выводить все значения стека.                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "string.h"

class Stack 
{  

private:
    const size_t size = 10;

    int* arr = new int[size]{ 0 };
    int l_arr = -1;    

public:
    void reset() 
    {
        memset(arr, 0, 10 * sizeof(arr[0]));
    };

    bool push(int e)
    {
        l_arr++;
        if (l_arr < size)
        {
            arr[l_arr] = e;
            return true;
        }
        else
        {
            return false;
        };
    };

    int pop()
    {
        l_arr--;
        if (l_arr > -1)
        {
            int z = arr[l_arr + 1];
            arr[l_arr + 1] = 0;
            return z;
        }
        else
        {
            std::cout << "В стеке больше нет значений." << std::endl;
            return 0;
        };
        
    };

    void print()
    {
        std::cout << "( ";
        for (size_t i = 0; i < l_arr + 1; i++) std::cout << arr[i] << " ";
        std::cout << ")" << std::endl;
    };

    ~Stack() 
    {
        delete[] arr;
    };

};

int main()
{
    setlocale(LC_ALL, "Russian");

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}