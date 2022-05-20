////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).                  //
// Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:                                                  //
//      ● математические бинарные операторы (+, -, *, / ) для выполнения действий с дробями                       //
//      ● унарный оператор (-)                                                                                    //
//      ● логические операторы сравнения двух дробей (== , != , <, >, <= , >= ).                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>

class Fraction {
private:
    double c_numerator;
    double c_denominator;
    double fraction;
public:
    Fraction(double numerator, double denominator)
        : c_numerator(numerator) {
        if (denominator != 0) {
            c_denominator = denominator;
            fraction = numerator / denominator;
        }
        else {
            std::cout << "Знаменатель не может быть равен нулю!\nПроверьте дробь, т.к. сейчас в знаменателе будет числится 1." << std::endl;
            c_denominator = 1;
            fraction = numerator;
        }        
    }

    void viewFraction() { std::cout << std::to_string(c_numerator) + "/" + std::to_string(c_denominator) << std::endl; }
    std::string writeFraction() { return std::to_string(c_numerator) + "/" + std::to_string(c_denominator); }
    double const getFraction() { return fraction; }

    friend Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2) {
        return Fraction(fraction1.c_numerator * fraction2.c_denominator + fraction2.c_numerator * fraction1.c_denominator, fraction1.c_denominator * fraction2.c_denominator);
    };
    friend Fraction operator- (const Fraction& fraction1, const Fraction& fraction2) {
        return Fraction(fraction1.c_numerator * fraction2.c_denominator - fraction2.c_numerator * fraction1.c_denominator, fraction1.c_denominator * fraction2.c_denominator);
    };
    friend Fraction operator* (const Fraction& fraction1, const Fraction& fraction2) {
        return Fraction(fraction1.c_numerator * fraction2.c_numerator, fraction1.c_denominator * fraction2.c_denominator);
    };
    friend Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2) {
        return Fraction(fraction1.c_numerator * fraction2.c_denominator, fraction1.c_denominator * fraction2.c_numerator);
    };

    friend bool operator== (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) == (fraction2.c_numerator * fraction1.c_denominator);
    };

    friend bool operator!= (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) != (fraction2.c_numerator * fraction1.c_denominator);
    };

    friend bool operator< (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) < (fraction2.c_numerator * fraction1.c_denominator);
    };

    friend bool operator> (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) > (fraction2.c_numerator * fraction1.c_denominator);
    };

    friend bool operator<= (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) <= (fraction2.c_numerator * fraction1.c_denominator);
    };

    friend bool operator>= (const Fraction& fraction1, const Fraction& fraction2) {
        return (fraction1.c_numerator * fraction2.c_denominator) >= (fraction2.c_numerator * fraction1.c_denominator);
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Fraction fraction1(3, 7);
    fraction1.viewFraction();
    std::cout << fraction1.getFraction() << std::endl;
    Fraction fraction2(9, 2);
    fraction2.viewFraction();
    std::cout << fraction2.getFraction() << std::endl;
    std::cout << std::endl;

    Fraction fractionSum = fraction1 + fraction2;
    std::cout << "3/7 + 9/2 = " << fractionSum.writeFraction() << std::endl;
    Fraction fractionDif = fraction1 - fraction2;
    std::cout << "3/7 - 9/2 = " << fractionDif.writeFraction() << std::endl;
    Fraction fractionMul = fraction1 * fraction2;
    std::cout << "3/7 * 9/2 = " << fractionMul.writeFraction() << std::endl;
    Fraction fractionDiv = fraction1 / fraction2;
    std::cout << "3/7 / 9/2 = " << fractionDiv.writeFraction() << std::endl;
    std::cout << std::endl;

    std::cout << "Равны ли дроби 3/7 и 9/2: " << std::boolalpha << (fraction1 == fraction2) << std::endl;
    std::cout << "Не равны ли дроби 3/7 и 9/2: " << std::boolalpha << (fraction1 != fraction2) << std::endl;
    std::cout << "Сравнение 3/7 < 9/2: " << std::boolalpha << (fraction1 < fraction2) << std::endl;
    std::cout << "Сравнение 3/7 > 9/2: " << std::boolalpha << (fraction1 > fraction2) << std::endl;
    std::cout << "Сравнение 3/7 <= 9/2: " << std::boolalpha << (fraction1 <= fraction2) << std::endl;
    std::cout << "Сравнение 3/7 >= 9/2: " << std::boolalpha << (fraction1 >= fraction2) << std::endl;
    std::cout << std::endl;

    Fraction fractionZero(7, 0);
    std::cout << std::endl;
    fractionZero.viewFraction();
    std::cout << fractionZero.getFraction() << std::endl;
}