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

class Vector {
private:
    float x, y, z;
    int state;

public:
    static int count;

    Vector() : x(0), y(0), z(0), state(0) {
        count++;
    }

    Vector(float val) : x(val), y(val), z(val), state(0) {
        count++;
    }


    Vector(float* arr) : state(0) {
        if (arr == nullptr) {
            state = 1;
        }
        else {
            x = arr[0];
            y = arr[1];
            z = arr[2];
        }
        count++;
    }

    ~Vector() {
        cout << "Destructor of vector. State: " << state << endl;
        count--;
    }

    void setValue(float val, char axis = 'x') {
        switch (axis) {
        case 'x':
            x = val;
            break;
        case 'y':
            y = val;
            break;
        case 'z':
            z = val;
            break;
        default:
            cout << "Incorrect axis. Value was not assigned.\n";
        }
    }

    float getValue(char axis = 'x') const {
        switch (axis) {
        case 'x':
            return x;
        case 'y':
            return y;
        case 'z':
            return z;
        default:
            cout << "Incorrect axis.\n";
            return 0;
        }
    }

    Vector(const Vector& other) : x(other.x), y(other.y), z(other.z), state(other.state) {
        count++;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            state = other.state;
        }
        return *this;
    }

    void print() const {
        cout << "Vector (" << x << ", " << y << ", " << z << "), State: " << state << endl;
    }

    Vector add(const Vector& other) const {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    Vector subtract(const Vector& other) const {
        Vector result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }

    Vector crossProduct(const Vector& other) const {
        Vector result;
        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    Vector divide(short divisor) {
        Vector result;
        if (divisor != 0) {
            result.x = x / divisor;
            result.y = y / divisor;
            result.z = z / divisor;
        }
        else {
            cout << "Division by 0. State changed.\n";
            state = 2;
        }
        return result;
    }

    bool isEqual(const Vector& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    bool isGreater(const Vector& other) const {
        return (x > other.x && y > other.y && z > other.z);
    }

    bool isLess(const Vector& other) const {
        return (x < other.x && y < other.y && z < other.z);
    }
};

int Vector::count = 0;

void secondTask() {
    Vector v1;
    v1.print();

    Vector v2(5);
    v2.print();

    float arr[3] = { 1, 2, 3 };
    Vector v3(arr);
    v3.print();

    Vector v4 = v2;
    v4.print();

    v1.setValue(10, 'y');
    cout << "Value of y in vector v1: " << v1.getValue('y') << endl;

    Vector v5 = v1.add(v3);
    v5.print();

    Vector v6 = v1.subtract(v3);
    v6.print();

    Vector v7 = v1.crossProduct(v3);
    v7.print();

    Vector v8 = v1.divide(2);
    v8.print();

    cout << "v1 is greater than v2: " << v1.isGreater(v2) << endl;
    cout << "v1 is less than v2: " << v1.isLess(v2) << endl;
    cout << "Number of Vector objects: " << Vector::count << endl;
}

int main() {
    firstTask();
    secondTask();

    return 0;
}
