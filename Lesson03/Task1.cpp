////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и   //
// Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат),          //
// Rhombus (ромб). Для всех классов создать конструкторы.                                                         //
// Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах               //
// переопределить эту функцию, исходя из геометрических формул нахождения площади.                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

class Figure {
public:
    virtual double area() = 0;
};

class Circle : public Figure {
private:
    double c_r;

public:
    Circle(double r) : c_r(r) {}

    double area() { return M_PI * pow(c_r, 2); }
};

class Parallelogram : public Figure {
};

class Rectangle : public Parallelogram {
private:
    double c_a, c_b;

public:
    Rectangle(double a, double b) : c_a(a), c_b(b) {}

    double area() { return c_a * c_b; }
};

class Square : public Parallelogram {
private:
    double c_a;

public:
    Square(double a) : c_a(a) {}

    double area() { return pow(c_a, 2); }
};

class Rhombus : public Parallelogram {
private:
    double c_d_max, c_d_min;

public:
    Rhombus(double d_max, double d_min) : c_d_max(d_max), c_d_min(d_min) {}

    double area() { return (c_d_max * c_d_min) / 2.0; }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Circle circle(7);
    Rectangle rectangle(7, 3);
    Square square(7);
    Rhombus rhombus(7, 3);

    Figure* figure_circle = &circle;
    Figure* figure_rectangle = &rectangle;
    Figure* figure_square = &square;
    Figure* figure_rhombus = &rhombus;

    std::cout << "Площадь круга радиусом 7 = " << figure_circle->area() << std::endl;
    std::cout << "Площадь прямоугольника со сторонами 7 и 3 = " << figure_rectangle->area() << std::endl;
    std::cout << "Площадь квадрата со стороной 7 = " << figure_square->area() << std::endl;
    std::cout << "Площадь ромба с длинной диагональю 7 и короткой 3 = " << figure_rhombus->area() << std::endl;

    std::cout << std::endl;

    Figure* figure;
    figure = &circle;
    std::cout << "Площадь круга радиусом 7 = " << figure->area() << std::endl;
    figure = &rectangle;
    std::cout << "Площадь прямоугольника со сторонами 7 и 3 = " << figure->area() << std::endl;
    figure = &square;
    std::cout << "Площадь квадрата со стороной 7 = " << figure->area() << std::endl;
    figure = &rhombus;
    std::cout << "Площадь ромба с длинной диагональю 7 и короткой 3 = " << figure->area() << std::endl;
}