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

class Car : public virtual Transport {
    char const *color;
    int capacity;
public:
    Car(const char *name, int productionYear, const char *color, int capacity) :
            Transport(name, productionYear), color(color), capacity(capacity) {}

    void show() override {
        Transport::show();
        cout << ", color: " << color << ", capacity: " << capacity;
    }

    char const * getColor(){
        return this->color;
    }

    int getCapacity(){
        return capacity;
    }

    ~Car() {
        delete color;
    }
};

class Boat : public virtual Transport {
    char const *type;
    int displacement;
public:
    Boat(const char *name, int productionYear, const char *type, int displacement) :
            Transport(name, productionYear), type(type), displacement(displacement) {}


    char const * getType(){
        return this->type;
    }

    int getDisplacement(){
        return displacement;
    }

    void show() override {
        Transport::show();
        cout << ", type: " << type << ", displacement: " << displacement;
    }

    ~Boat() {
        delete type;
    }
};

class Amphibian : public Boat, public Car{
public:
    Amphibian(const char * name, int productionYear, const char * type, int displacement, const char * color, int capacity) :
            Transport(name, productionYear), Boat(name, productionYear, type, displacement), Car(name, productionYear, color, capacity){};
    void show (){
        Transport::show();
        cout << ", color:" << getColor() << ", capacity: " << getCapacity() << ", displacement: " << getDisplacement() << ", type: " << getType();
    }
};

int main() {
//    const char *a = "BMW";
//    Transport t1(a, 1920);
//    a = "AUDI";
//    Transport t2(a, 1924);
//    a = "";
//    Transport t3("Mercedes", 1974);
//FixMe

//    t1.show();
//    t2.show();
//    t3.show();

    vector<Transport*> vec ({
        new Car ("BMW 740i", 2002, "Black", 5),
        new Car ("Mercedes e350", 2012, "Gray", 5),
        new Boat ("Shark 72", 2010, "small boat", 60),
        new Boat ("Whale 12", 2016, "gigantic ship", 300),
        new Amphibian("Crocodile", 2020, "regular sized ship", 80, "Green", 6)
    });
    for (int i = 0; i < vec.size(); ++i) {
        vec[i]->show();
        cout << endl;
    }
    return 0;
}