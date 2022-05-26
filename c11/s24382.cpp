#include <iostream>
#include <math.h>
//s24382
using namespace std;

class Segment {
    double A, B;
public:
    Segment(double A, double B) : A(A), B(B) {}

    friend Segment operator*(Segment seg, double i);

    friend Segment operator*(double i, Segment seg);

    friend Segment operator/(Segment seg, double i);

    friend Segment operator-(Segment seg, double i);

    friend Segment operator+(Segment seg, double i);

    friend Segment operator+(double i, Segment);

    friend std::ostream &operator<<(std::ostream &stream, const Segment m);

    friend Segment operator+(Segment seg, Segment i);

    bool operator()(double i) {
        if (i > this->A && i < this->B)
            return true;
        else
            return false;
    }
};

Segment operator*(Segment seg, double i) {
    seg.A *= i;
    seg.B *= i;
    return seg;
}

Segment operator*(double i, Segment seg) {
    seg.A *= i;
    seg.B *= i;
    return seg;
}

Segment operator/(Segment seg, double i) {
    seg.A /= i;
    seg.B /= i;
    return seg;
}

Segment operator-(Segment seg, double i) {
    seg.A -= i;
    seg.B -= i;
    return seg;
}

Segment operator+(Segment seg, double i) {
    seg.A += i;
    seg.B += i;
    return seg;
}

Segment operator+(double i, Segment seg) {
    seg.A += i;
    seg.B += i;
    return seg;
}

Segment operator+(Segment seg, Segment i) {
    return *(new Segment((std::min(seg.A, i.A)), std::max(seg.B, i.B)));
}

std::ostream &operator<<(std::ostream &stream, const Segment m) {
    return stream << "[" << m.A << "," << m.B << "]";
}

int main() {
    Segment seg{2, 3}, s = 1 + 2 * ((seg - 2) / 2 + seg) / 3;
    cout << s << endl << boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        cout << "x=" << x << ": " << s(x) << endl;
}

