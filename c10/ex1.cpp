#include <iostream>
using namespace std;

class Resistor {
    double value;
public:
    Resistor(){
        value=0;
    };

    Resistor(double value){
        this->value = value;
    };

    double r() const {
        return value;
    }

    void r(double value){
        this->value = value;
    }
};

Resistor operator+(const Resistor&r, const Resistor& r1){
    Resistor result;
    return result = r.r()+ r1.r();
}

Resistor operator*(const Resistor& r, const Resistor& r1 ){
    Resistor result;
    return result = (r.r() * r1.r()) / (r.r()+r1.r());
}

ostream & operator << (ostream& stream, const Resistor& r){
    return stream << r.r();
}

int main (){
    Resistor r1, r2{7};
    r1.r(4);
    cout << "Sum of resistors: " <<(r1 + r2) << endl;
    cout << "Multiply resistors: " <<(r1 * r2) << endl;
    return 0;
}