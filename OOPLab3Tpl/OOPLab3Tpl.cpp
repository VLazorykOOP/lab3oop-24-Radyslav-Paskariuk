#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Diamond {
private:
    double side;
    double diagonal;
    string color;

public:

    Diamond() : side(0), diagonal(0), color("black") {}

    Diamond(double s, double d, string c) : side(s), diagonal(d), color(c) {}

    double calculateArea() {
        return 0.5 * side * diagonal;
    }
    double calculatePerimeter() {
        return 4 * side;
    }
    void setSide(double s) {
        if (s > 0)
            side = s;
        else
            cerr << "Incorrect value was entered.\n";
    }
    void setDiagonal(double d) {
        if (d > 0)
            diagonal = d;
        else
            cerr << "Incorrect value was entered.\n";
    }
    void setColor(const string& c) {
        color = c;
    }
    double getSide() const {
        return side;
    }
    double getDiagonal() const {
        return diagonal;
    }
    string getColor() const {
        return color;
    }
    void print() {
        cout << "Diamond with side " << side << ", diagonal " << diagonal << " and color " << color << ".\n";
    }
};

void firstTask() {
    Diamond d1;
    d1.setSide(5);
    d1.setDiagonal(8);
    d1.setColor("red");
    d1.print();
    cout << "Diamond's area: " << d1.calculateArea() << endl;
    cout << "Diamond's perimeter: " << d1.calculatePerimeter() << endl;

    Diamond d2(7, 10, "blue");
    d2.print();
    cout << "Color: " << d2.getColor() << "Side: " << d2.getSide() << "Diagonal: " << d2.getDiagonal() << endl;
    cout << "Diamond's area : " << d2.calculateArea() << endl;
    cout << "Diamond's perimeter : " << d2.calculatePerimeter() << endl;
}

int main() {
    firstTask();


    return 0;
}
