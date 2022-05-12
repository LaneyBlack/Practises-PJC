#include <iostream>
#include <functional>
#include <cmath>
#include "vector"

using namespace std;

struct Point {
    int x;
    int y;
};

struct Rect{
    Point hlp;
    Point lrp;
};

template<typename T>
void printVec(vector<T> vec) {
    cout << "[ ";
    for (T type: vec)
        cout << type << " ";
    cout << "]" << endl;
}

vector<double> process(const Rect * rects, size_t sz, std::function<double(Rect) > f ) {
    vector<double> result;
    for (int i = 0; i < sz; ++i) {
        result.push_back(f(rects[i]));
    }
    return result;
}

double diagonal(Rect rect){
    return sqrt(abs(pow(rect.hlp.x, 2) - pow(rect.lrp.x,2)) + abs(pow(rect.hlp.y,2) - pow(rect.lrp.y,2)));
}

int main (){
    Rect rects [] = {{{0,4}, {4,1}},{{-6,3},{6,-2}},{ {-7,4},{8,-4}}};
    size_t size = sizeof(rects)/sizeof(Rect);
    cout << "Square:" << endl;
    printVec(process(rects, size, [](Rect rectangle)-> double{
       return abs((rectangle.hlp.y - rectangle.lrp.y)*(rectangle.hlp.x-rectangle.lrp.x));
    }));
    cout << "Diagonal:" << endl;
    printVec(process(rects, size, diagonal));
    return 0;
}