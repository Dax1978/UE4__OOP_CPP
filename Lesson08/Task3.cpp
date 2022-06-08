////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 3                                                                                                      //
//  Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий     //
// задание переместиться на соседнюю позицию. Эти методы должны запускать классы - исключения OffTheField, если   //
// робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном   //
// диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление      //
// движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,    //
// а также выводящую подробную информацию о всех возникающих ошибках.                                             //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

class MesssageRobot
{
public:
    std::string direction;
    int pos_x;
    int pos_y;
};

class Err
{ 
public:
    std::string m_message;

    Err(MesssageRobot message)
    {
        std::string msg = "Текущая позиция:\nСтрока: " + std::to_string(message.pos_x) + ". Столбец: " + std::to_string(message.pos_y) + "\n";
        if (message.direction == "l") {
            msg += "Движение на лево не возможно!\n";
        }
        else if (message.direction == "u") {
            msg += "Движение выше не возможно!\n";
        }
        else if (message.direction == "r") {
            msg += "Движение на право не возможно!\n";
        }
        else if (message.direction == "d") {
            msg += "Движение вниз возможно!\n";
        }
        m_message = msg;
    }
};

class Robot {
private:    
    MesssageRobot msg;

public:
    int pos_row = 0;
    int pos_col = 0;

    Robot(int row, int column) : pos_row(row), pos_col(column) { }

    void move(std::string m) {
        msg.pos_x = pos_row;
        msg.pos_y = pos_col;
        msg.direction = m;

        if (m == "l") {
            if (pos_col == 0) {
                throw Err(msg);
            }
            else {
                pos_col--;
            }            
        }

        if (m == "r") {
            if (pos_col == 9) {
                throw Err(msg);
            }
            else {
                pos_col++;
            }
        }

        if (m == "u") {
            if (pos_row == 0) {
                throw Err(msg);
            }
            else {
                pos_row--;
            }
        }

        if (m == "d") {
            if (pos_row == 9) {
                throw Err(msg);
            }
            else {
                pos_row++;
            }
        }
        std::cout << "Робот переместился в положение: строка = " << std::to_string(pos_row) << " и столбец = " << std::to_string(pos_col) << std::endl;
    }

    ~Robot() { }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Robot r(0, 0);

    std::cout << "Вы управляете роботом.\nРобот может перемещаться в поле, размером 10 х 10 ячеек.\nДля перемещения укажите:\n\tl - для движения в лево;\n\tr - для движения в право;\n\tu - для движения в верх;\n\td - для движения в низ;\nУкажите e - для завершения." << std::endl;
    std::cout << "Робот находится в позиции: строка = " << std::to_string(r.pos_row) << " и столбец = " << std::to_string(r.pos_col) << std::endl;

    std::string e;
    while (true) {
        std::cout << "Укажите направление движения (l, u, r, d) или команду для выхода (e): ";
        std::cin >> e;
        if (e == "e") {
            break;
        }
        else {
            try {
                r.move(e);
            }
            catch (Err& err) {
                std::cout << err.m_message;
            }
        }
    }

    return 0;
}