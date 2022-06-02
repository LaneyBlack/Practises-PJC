#include <iostream>
#include <cstring>
#include <vector>
//s24382
using namespace std;

class Transport {
    const char *name;
    int productionYear;
public:
//    Transport(const char* name, int productionYear): name(strcpy(new char[strlen(name) + 1], name)), productionYear(productionYear) {}
    Transport(const char *name, int productionYear) {
        this->name = name;
        this->productionYear = productionYear;
    }

    virtual void show() {
        cout << "Name: " << name << ", production year: " << productionYear;
    }

    ~Transport() {
        delete name;
    }
};

class Amphibian : public Transport { //public Car, public Transport
public:
    Amphibian(const char *name, int productionYear):Transport(name, productionYear){};
    void show() {
        cout << endl;
    }
};

int main() {
    cout << "Hello" << endl;
    return 0;
}