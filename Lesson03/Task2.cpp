////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создать класс Car (автомобиль) с полями company (компания) и model (модель).                                   //
// Классы - наследники: PassengerCar (легковой автомобиль) и Bus (автобус).                                       //
// От этих классов наследует класс Minivan (минивэн).                                                             //
// Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.                              //
// Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.      //
// Обратить внимание на проблему «алмаз смерти».                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Car {
private:
    std::string c_company;
    std::string c_model;
public:
    Car(std::string company, std::string model)
        : c_company(company), c_model(model)
    {
        std::cout << "Автомобиль. Компании: " << c_company << " Модель: " << c_model << std::endl;
    };
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(std::string company, std::string model)
        : Car(company, model)
    {
        std::cout << "Легковой автомобиль." << std::endl;
    }
};

class Bus : virtual public Car {
public:
    Bus(std::string company, std::string model)
        : Car(company, model)
    {
        std::cout << "Автобус." << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string company, std::string model)
        : Car(company, model), PassengerCar(company, model), Bus(company, model)
    {
        std::cout << "Минивэн." << std::endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Car car("что-то", "какая-то");
    std::cout << "-----------------------" << std::endl;
    PassengerCar passengerCar("ВАЗ", "Нива");
    std::cout << "-----------------------" << std::endl;
    Bus bus("ЛиАЗ", "5292");
    std::cout << "-----------------------" << std::endl;
    Minivan minivan("Hyundai", "Grand Starex");
    std::cout << "-----------------------" << std::endl;


    return 0;
}