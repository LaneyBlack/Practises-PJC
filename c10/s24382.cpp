#include <iostream>
#include <cmath>
#include <string.h>
//s24382
using namespace std;

class Person {
    string name;
    int birthYear;
public:

    Person(string name, int birthYear) : name(name), birthYear(birthYear) {

    }

    Person(Person &person) {
        cout << "Copy" << endl;
        this->name = person.name;
        this->birthYear = person.birthYear;
    }

    string getName() {
        return name;
    }

    int getBirthYear() {
        return birthYear;
    }

    void setName(string name){
        this->name = name;
    }

    void setBirthYear(int birthYear){
        this->birthYear=birthYear;
    }

    ~Person() {
        cout << "Bin" << endl;
    }
};

int compare(Person person1, Person person2) {
    if (person1.getBirthYear() != person2.getBirthYear())
        return person1.getBirthYear() < person2.getBirthYear() ? 1 : -1;
    return person2.getName().compare(person1.getName());
    //if symbol goes earlier i want to return 1 (sort by name ( Tony > Jimy))
    //                                                                  7th symbol
    //return person1.getName() > person2.getName() ? 1 : person1.getName() == person2.getName() ? 0 : -1;
}

int main() {
    Person a("Tony", 1974);
    Person b = a;
    cout << "First Compare" << endl;
    cout << compare(a, b) << endl;
    b.setName("Jimy");
    cout << "Second Compare" << endl;
    cout << compare(a, b) << endl;
    b.setBirthYear(1980);
    cout << "Second Compare" << endl;
    cout << compare(a, b) << endl;
    return 0;
}