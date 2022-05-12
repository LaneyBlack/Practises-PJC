#include <iostream>
#include <cmath>
#include "vector"

using namespace std;

struct point {
    int x;
    int y;
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};


void printVec(vector<point> vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i].x << ' ' << vec[i].y << "|";
    cout << ']' << endl;
}

int distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) - pow(p1.y - p2.y, 2));
}

int closest(vector<point> vec, point point) {
    int index = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (distance(vec[index], point) > distance(vec[i], point)) {
            index = i;
        }
    }
    return index;
}

int main() {
    vector<point> vec{*new point(6, 1), *new point(2, 3), *new point(4, 6), *new point(5, 3)};
    point p = *new point(2, 2);
    int index = closest(vec, p);
    printVec(vec);
    cout << "Closest point" << endl;
    cout << "x:" << vec[index].x << " y:" << vec[index].y << endl;
    return 0;
}

