#include <iostream>
#include <cmath>

using namespace std;

class Rect {
    double a, b;
public:
    Rect() {
        a = 1;
        b = 1;
    }

    Rect(double s) {
        a = s;
        b = s;
    }

    Rect(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getDiagonal() {
        return sqrt(pow(a, 2) + pow(b, 2));
    }

    double getArea() const {
        return a * b;
    }

    bool isLargerThan(const Rect &rect) {
        return getArea() > rect.getArea();
    }

    void info() {
        cout << "Rect[" << a << "," << b << "]" << endl;
    }
};

int main() {
    Rect r1(2, 24);
    Rect r2;
    Rect r3(12);

    r1.info();
    r2.info();
    r3.info();

    cout << endl;

    cout << "Side A of r1: " << r1.getA() << endl;
    cout << "Side B of r1: " << r1.getB() << endl;
    cout << "Side A of r2: " << r2.getA() << endl;
    cout << "Side B of r2: " << r2.getB() << endl;
    cout << "Side A of r3: " << r3.getA() << endl;
    cout << "Side B of r3: " << r3.getB() << endl << endl;

    cout << "Area of r1: " << r1.getArea() << endl;
    cout << "Area of r2: " << r2.getArea() << endl;
    cout << "Area of r3: " << r3.getArea() << endl << endl;

    cout << "r1 > r1: " << (r1.isLargerThan(r1) ? "true" : "false") << endl;
    cout << (r1.isLargerThan(r2) ? "true" : "false") << endl;
    cout << (r1.isLargerThan(r3) ? "true" : "false") << endl << endl;

    cout << "Diagonal of r1: " << r1.getDiagonal() << endl;
    cout << "Diagonal of r2: " << r2.getDiagonal() << endl;
    cout << "Diagonal of r3: " << r3.getDiagonal() << endl << endl;
    return 0;
}
