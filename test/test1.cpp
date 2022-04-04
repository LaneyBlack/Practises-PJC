#include <iostream>
#include <vector>

using namespace std;

int calculate(int x) {
    x += 9;
    return x;
}


void calculatePath(int &x) {
    x += 9;
}
int sum (int x, int b, int counter) {
    for (int i = 0; i < counter; i++)
        x+=b;
    return x;
}

int main() {
    int x = 9;
    cout << x << endl;
    cout << &x << endl;
    int *px = &x;
    cout << px << endl;
    cout << *px << endl;
    cout << &px << endl;
    int **ppx = &px;
    cout << "-----------------" << endl;
    cout << ppx << endl;
    cout << *ppx << endl;
    cout << **ppx << endl;
    cout << &ppx << endl;
    cout << *&ppx << endl;


    {
        int x = 9, *px = &x;
        cout << x << endl;
        cout << "Address " << px << endl;
        cout << *px << endl;

//    *px = 3;
//    cout << x << endl;
//    cout << "Address " << px << endl;
//    cout << *px << endl;
//    calculate(x);
//    cout << x << endl;
//    cout << "Address " << px << endl;
//    cout << *px << endl;
//    calculatePath(*px);
//    cout << x << endl;
//    cout << "Address " << px << endl;
//    cout << *px << endl;
    }
    {
        cout << "---------------------" << endl;
        std::vector<int> vector = {10, 20, 30, 40};
        for (int &i: vector) {
            i += 5;
        }
        for (int i: vector) {
            cout << i << endl;
        }
    }
    {
        cout << "---------------------" << endl;
        int i = 10;
        int &x = i;
        int *p = &i;
        int **pt = &p;
        int ***ptr = &pt;
        cout << i << endl;
        cout << &i << endl;
        cout << x << endl;
        cout << &x << endl;
        cout << p << endl;
        cout << *p << endl;
        cout << pt << endl;
        cout << *pt << endl;
        cout << **pt << endl;
        cout << ptr << endl;
        cout << *ptr << endl;
        cout << **ptr << endl;
        cout << ***ptr << endl;
    }
    {
        cout << "---------------------" << endl;
        int x = 10;
        int *ptr = &x;
        int *&ptr1 = ptr;
        cout << x << endl;
        cout << ptr << endl;
        cout << ptr1 << endl;
        cout << *ptr << endl;
        cout << *ptr1 << endl;
    }
    return 0;
}

