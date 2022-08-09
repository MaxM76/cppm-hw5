#include <iostream>
#include <Windows.h>

class Figure {
protected:
    int sides;
    std::string name;
public:
    Figure() {
        sides = 0;
        name = "Фигура";
    }

    int getSides() {
        return sides;
    }

    std::string getName() {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() {
        sides = 3;
        name = "Треугольник";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() {
        sides = 4;
        name = "Четырёхугольник";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;
    std::cout << "Количество сторон:\n";
    std::cout << figure.getName() << ": " << figure.getSides() << "\n";
    std::cout << triangle.getName() << ": " << triangle.getSides() << "\n";
    std::cout << quadrilateral.getName() << ": " << quadrilateral.getSides() << "\n";
}