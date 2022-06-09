#include <iostream>
#include <math.h>
//s24382
using namespace std;

class LiczbaZespolona {
    double positive, negative;
public:
    LiczbaZespolona (){
        positive = 0;
        negative = 0;
    }

    LiczbaZespolona(double value) {
        if (value > 0){
            positive = value;
            negative = -value;
        } else {
            positive = -value;
            negative = value;
        }
    }

    friend LiczbaZespolona operator+(LiczbaZespolona liczba, double i);
    friend LiczbaZespolona operator+(double i, LiczbaZespolona liczba);
    friend LiczbaZespolona operator+(LiczbaZespolona liczba1, LiczbaZespolona liczba2);

    friend std::ostream &operator<<(std::ostream &stream, const LiczbaZespolona liczba);
};

LiczbaZespolona operator+(LiczbaZespolona liczba, double i) {
    liczba.positive += i;
    liczba.negative += i;
    return liczba;
}

LiczbaZespolona operator+(double i, LiczbaZespolona liczba) {
    liczba.positive += i;
    liczba.negative += i;
    return liczba;
}

LiczbaZespolona operator+(LiczbaZespolona liczba1, LiczbaZespolona liczba2) {
    LiczbaZespolona result;
    result.positive = liczba1.positive + liczba2.positive;
    result.negative = liczba1.negative + liczba2.negative;
    return result;
}

std::ostream &operator<<(std::ostream &stream, const LiczbaZespolona liczba) {
    return stream << "Liczba: [Positive " << liczba.positive << ", Negative " << liczba.negative << "]";
}

int main() {
    LiczbaZespolona val1(2);
    cout  << "Zespolona 2 --- " << val1 << endl;
    cout << "2 + zespolona 2 --- "<< 2+ val1 << endl;
    cout << "Zespolona 2 + (-2) --- "<< val1 + (-2) << endl;
    LiczbaZespolona val2 (-5.5);
    cout << "-------------" << endl;
    cout  << "Zespolona 2 --- " << val1 << endl;
    cout << "Zespolona 5.5 --- "<< val2 << endl;
    cout << "Zespolona 5.5 + zespolona 2 --- "<< val1 + val2 << endl;
}

