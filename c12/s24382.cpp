#include <iostream>
#include <vector>
//s24382
using namespace std;

class Animal {
public:
    Animal() {
        cout << "new Animal" << endl;
    }

    virtual void hello() {
        cout << "Hello Animal" << endl;
    }

    void bye() { //w tresci jest napisane nie polimorficzna!
        cout << "Bye Animal" << endl;
    }
};

class Herbivore : public virtual Animal {
public:
    void hello() override {
        cout << "Hello Herbivore" << endl;
    }

    void bye() {
        cout << "Bye Herbivore" << endl;
    }
};

class Carnivore : public virtual Animal {
public:
    void hello() override {
        cout << "Hello Carnivore" << endl;
    }

    void bye() {
        cout << "Bye Carnivore" << endl;
    }
};

class Pig : public Carnivore, public Herbivore { //public Car, public Transport
public:
    void hello() override {
        cout << "Hello Pig" << endl;
    }

    void bye() {
        cout << "Bye Pig" << endl;
    }
};

int main() {
    vector<Animal *> vec({new Carnivore(), new Pig(), new Herbivore(), new Animal()});
    for (Animal * animal : vec) {
        animal->hello();
        animal->bye();
    }
    cout <<"\n\n";
    Carnivore a;
    a.bye();
    return 0;
}