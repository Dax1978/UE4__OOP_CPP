////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 2                                                                                                      //
// Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).                         //
// У Fruit есть две переменные - члена: name(имя) и color(цвет).                                                  //
// Добавить новый класс GrannySmith, который наследует класс Apple.                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Fruit
{
private:
    std::string name;
    std::string color;

public:
    Fruit(std::string name, std::string color)
        : name(name), color(color)
    {}

    std::string getName() { return name; }
    std::string getColor() { return color; }
};

class Apple : public Fruit
{
public:
    Apple(std::string color)
        : Fruit("apple", color)
    {}
};

class Banana : public Fruit
{
public:
    Banana()
        : Fruit("banana", "yellow")
    {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple("green")
    {}

    std::string getName() { return "GrannySmith " + Apple::getName(); }
};

int main()
{
    // Задано условием задания
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Результат должен быть:                                                                                         //
//    My apple is red.                                                                                            //
//    My banana is yellow.                                                                                        //
//    My Granny Smith apple is green.                                                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////