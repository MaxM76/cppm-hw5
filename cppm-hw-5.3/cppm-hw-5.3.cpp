#include <iostream>
#include <Windows.h>
#include <string>

namespace figures
{
    class Figure {
    protected:
        int sides;
        std::string name;

        virtual std::string getRegularityInfo() {
            if (isRegular()) {
                return "Правильная";
            }
            else {
                return "Неправильная";
            }
        }

        virtual std::string getAnglesInfo() {
            return "Углы: ";            
        }

        virtual std::string getSidesCountInfo() {
            return "Количество сторон: " + std::to_string(getSides());
        }

        virtual std::string getSidesInfo() {
            return "Стороны: ";
        }

        virtual bool isRegular() {
            return (getSides() == 0);
        }

    public:
        Figure() {
            sides = 0;
            name = "Фигура";
        }

        virtual int getSides() {
            return sides;
        }

        std::string getName() {
            return name;
        }

        std::string getInfo() {
            std::string result = name + "\n" + getSidesCountInfo() + "\n";
            if (getSides() > 0) {
                result = result + getSidesInfo() + "\n" + getAnglesInfo() + "\n";
            }
            result = result + getRegularityInfo() + "\n";
            return result;                
        }
    };

    class Triangle : public Figure {
    protected:
        int a;
        int b;
        int c;
        int A;
        int B;
        int C;

        bool isRegular() override {
            return ((getSides() == 3) && (getA() + getB() + getC() == 180));
        }

        std::string getAnglesInfo() override {
            return Figure::getAnglesInfo() 
                + "A = " + std::to_string(getA()) 
                + " B = " + std::to_string(getB()) 
                + " C = " + std::to_string(getC());
        }

        std::string getSidesInfo() override {
            return Figure::getSidesInfo() 
                + "a = " + std::to_string(geta()) 
                + " b = " + std::to_string(getb()) 
                + " c = " + std::to_string(getc());
        }

    public:
        Triangle() {
            this->a = 0;
            this->b = 0;
            this->c = 0;
            this->A = 60;
            this->B = 60;
            this->C = 60;
            sides = 3;
            name = "Треугольник";
        }

        Triangle(int a, int b, int c, int A, int B, int C) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
            sides = 3;
            name = "Треугольник";
        }

        int geta() {
            return a;
        }

        int getb() {
            return b;
        }

        int getc() {
            return c;
        }

        int getA() {
            return A;
        }

        int getB() {
            return B;
        }

        int getC() {
            return C;
        }
    };

    class Quadrilateral : public Figure {
    protected:
        int a;
        int b;
        int c;
        int d;
        int A;
        int B;
        int C;
        int D;

        bool isRegular() override {
            return ((getSides() == 4) && (getA() + getB() + getC() + getD() == 360));
        }

        std::string getAnglesInfo() override {
            return Figure::getAnglesInfo() 
                + "A = " + std::to_string(getA()) 
                + " B = " + std::to_string(getB()) 
                + " C = " + std::to_string(getC()) 
                + " D = " + std::to_string(getD());
        }

        std::string getSidesInfo() override {
            return Figure::getSidesInfo() 
                + "a = " + std::to_string(geta()) 
                + " b = " + std::to_string(getb()) 
                + " c = " + std::to_string(getc()) 
                + " d = " + std::to_string(getd());
        }
    public:
        Quadrilateral() {
            sides = 4;
            name = "Четырёхугольник";
            this->a = 0;
            this->b = 0;
            this->c = 0;
            this->d = 0;
            this->A = 90;
            this->B = 90;
            this->C = 90;
            this->D = 90;
        }

        Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
            sides = 4;
            name = "Четырёхугольник";
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }

        int geta() {
            return a;
        }

        int getb() {
            return b;
        }

        int getc() {
            return c;
        }

        int getd() {
            return d;
        }

        int getA() {
            return A;
        }

        int getB() {
            return B;
        }

        int getC() {
            return C;
        }

        int getD() {
            return D;
        }
    };

    class RightTriangle : public Triangle {
        //прямоугольный треугольник (угол C всегда равен 90)
    protected:
        bool isRegular() override {
            return (Triangle::isRegular() && (getC() == 90));
        }

    public:
        RightTriangle() : Triangle(0, 0, 0, 45, 45, 90) {
            name = "Прямоугольный треугольник";
        }

        RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, 90) {
            name = "Прямоугольный треугольник";
        }

        RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
            name = "Прямоугольный треугольник";
        }
    };

    class IsoscelesTriangle : public Triangle {
        // равнобедренный треугольник (стороны a и c равны, углы A и C равны)
    protected:
        bool isRegular() override {
            return (Triangle::isRegular() && (geta() == getc()) && (getA() == getC()));
        }

    public:
        IsoscelesTriangle() : Triangle(0, 0, 0, 60, 60, 60) {
            name = "Равнобедренный треугольник";
        }

        IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, a, A, B, A) {
            name = "Равнобедренный треугольник";
        }

        IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
            name = "Равнобедренный треугольник";
        }
    };

    class EquilateralTriangle : public IsoscelesTriangle {
        // равносторонний треугольник (все стороны равны, все углы равны 60)
    protected:
        bool isRegular() override {
            return (IsoscelesTriangle::isRegular() 
                && (getb() == getc()) 
                && (getA() == getB()) 
                && (getC() == 60));
        }

    public:
        EquilateralTriangle() : IsoscelesTriangle() {
            name = "Равносторонний треугольник";
        }

        EquilateralTriangle(int a, int b, int c, int A, int B, int C) : IsoscelesTriangle(a, a, 60, 60) {
            name = "Равносторонний треугольник";
        }

        EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60) {
            name = "Равносторонний треугольник";
        }
    };

    class Parallelogram : public Quadrilateral {
        // параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
    protected:
        bool isRegular() override {
            return (Quadrilateral::isRegular()
                && (geta() == getc())
                && (getb() == getd())
                && (getA() == getC())
                && (getB() == getD()));
        }

    public:
        Parallelogram() : Quadrilateral() {
            name = "Параллелограмм";
        }

        Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, a, b, A, B, A, B) {
            name = "Параллелограмм";
        }

        Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {
            name = "Параллелограмм";
        }
    };

    class Rhomb : public Parallelogram {
        // ромб (все стороны равны, углы A,C и B,D попарно равны)
    protected:
        bool isRegular() override {
            return (Parallelogram::isRegular()
                && (geta() == getb()));
        }

    public:
        Rhomb() : Parallelogram() {
            name = "Ромб";
        }

        Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, a, A, B) {
            name = "Ромб";
        }

        Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {
            name = "Ромб";
        }
    };

    class Rectangle : public Parallelogram {
        // прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
    protected:
        bool isRegular() override {
            return (Parallelogram::isRegular()
                && (getA() == getB())
                && (getC() == 90));
        }

    public:
        Rectangle() : Parallelogram() {
            name = "Прямоугольник";
        }

        Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(a, b, 90, 90) {
            name = "Прямоугольник";
        }

        Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {
            name = "Прямоугольник";
        }
    };


    class Square : public Rectangle {
        // квадрат (все стороны равны, все углы равны 90)
    protected:
        bool isRegular() override {
            return (Rectangle::isRegular()
                && (geta() == getb()));
        }

    public:
        Square() : Rectangle() {
            name = "Квадрат";
        }

        Square(int a, int b, int c, int d, int A, int B, int C, int D) : Rectangle(a, a) {
            name = "Квадрат";
        }

        Square(int a) : Rectangle(a, a) {
            name = "Квадрат";
        }
    };
}


void print_info(figures::Figure& figure) {
    std::cout << figure.getInfo() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    figures::Figure figure;
    figures::Triangle triangle(10, 20, 30, 50, 60, 70);
    figures::RightTriangle rightTriangle(10, 20, 30, 50, 60, 70);
    figures::IsoscelesTriangle isoscelesTriangle(10, 20, 30, 50, 60, 70);
    figures::EquilateralTriangle equilateralTriangle(10, 20, 30, 50, 60, 70);
    figures::Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    figures::Parallelogram parallelogram(10, 20, 30, 40, 50, 60, 70, 80);
    figures::Rhomb rhomb(10, 20, 30, 40, 50, 60, 70, 80);
    figures::Square square(10, 20, 30, 40, 50, 60, 70, 80);
    figures::Rectangle rectangle(10, 20, 30, 40, 50, 60, 70, 80);

    print_info(figure);
    print_info(triangle);
    print_info(rightTriangle);
    print_info(isoscelesTriangle);
    print_info(equilateralTriangle);
    print_info(quadrilateral);
    print_info(parallelogram);
    print_info(rhomb);
    print_info(square);
    print_info(rectangle);
}