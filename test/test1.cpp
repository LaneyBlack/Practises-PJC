#include <iostream>

void calculate(int x) {
    x+=9;
}


void calculatePath(int &x) {
    x+=9;
}

int main () {
    using namespace std;
    int x = 9, *px = &x;
    cout << x << endl;
    cout << "Address " << px << endl;
    cout << *px << endl;
    *px = 3;
    cout << x << endl;
    cout << "Address " << px << endl;
    cout << *px << endl;
    calculate(x);
    cout << x << endl;
    cout << "Address " << px << endl;
    cout << *px << endl;
    calculatePath(*px);
    cout << x << endl;
    cout << "Address " << px << endl;
    cout << *px << endl;
    return 0;
}

