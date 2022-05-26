////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 1                                                                                                      //
// Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени,      //
// изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения.            //
// Определить методы переназначения и увеличения этого значения.                                                  //
// Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. //
// Вывести информацию о них.                                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

class Person
{
private:
    std::string name;
    int age;
    double weight;

public:

    Person(std::string name, int age, double weight)
        : name(name), age(age), weight(weight)
    {
    }

    void setName(std::string name) { this->name = name; }
    std::string getName() const { return name; }

    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }

    void setWeight(double weight) { this->weight = weight; }
    double getWeight() const { return weight; }

    void print()
    {
        std::cout << "Имя: " << name << " Возраст: " << age << " Вес: " << weight << std::endl;
    }
};

class Student : private Person
{
private:
    int year;
    static int count;

public:
    Student(std::string name, int age, double weight, int year)
        : Person(name, age, weight), year(year)
    {
        Student::count++;
    }

    static int getCount() { return count; }

    void setYear(int year) { this->year = year; }
    int getYear() const { return year; }

    

    void print()
    {
        std::cout << "Студент: " << getName() << ". Возраст: " << getAge() << " лет. Вес: " << getWeight() << " кг. Курс: " << year << std::endl;
    }

    ~Student()
    {
        Student::count--;
    }
};


int Student::count { 0 };

int main()
{
    setlocale(LC_ALL, "rus");

    Student * dasha = new Student("Даша", 18, 42, 2);
    Student * ksusha = new Student("Ксюша", 11, 26, 5);
    Student luba("Люба", 36, 50, 1);

    dasha->print();
    ksusha->print();
    luba.print();

    std::cout << "Количество созданных объектов Student: " << Student::getCount() << std::endl;

    delete dasha;
    delete ksusha;
    std::cout << "Операция удаления 2 динамически созданных объектов..." << std::endl;
    std::cout << "Количество созданных объектов Student: " << Student::getCount() << std::endl;

    return 0;
}