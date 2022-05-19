#include <iostream>
#include <cmath>

class Point {
    double x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(double s) {
        x = s;
        y = s;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    Point &setX(double xx) {
        x = xx;
        return *this;
    }

    Point &setY(double yy) {
        y = yy;
        return *this;
    }

    Point &transX(double dx) {
        x += dx;
        return *this;
    }

    Point &transY(double dy) {
        y += dy;
        return *this;
    }

    Point &transXY(double dx, double dy) {
        x += dx;
        y += dy;
        return *this;
    }

    static double dist(const Point &p, const Point &q) {
        return sqrt((pow(p.x - q.x, 2)) + (pow(p.y - q.y, 2)));
    }

};

int main() {
    Point p;
    Point q(1);
    Point r(1, 2);
    p.transXY(5, 6);
    q.transX(-1).transY(-1).transXY(2, 2);
    r.setX(10).transY(-8);
    std::cout << Point::dist(p, q) << std::endl;
    std::cout << Point::dist(p, r) << std::endl;
    return 0;
}

