#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<typename T, typename FunType>
vector<T> filter(const vector<T> &vec, FunType function) {
    vector result = vec;
    for (int i = 0; i < result.size(); ++i) {
        if (!function(result[i])) {
            result.erase(result.begin() + i);
            i--;
        }
    }
    return result;
}
template<typename T, typename FunType, typename FunType2>
vector<T> transfilt(vector<T> &vec, FunType function1, FunType2 function2) {
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = function1(vec[i]);
    }
    vector result = vec;
    for (int i = 0; i < result.size(); ++i) {
        if (!function2(result[i])) {
            result.erase(result.begin() + i);
            i--;
        }
    }
    return result;
}

template<typename T>
void printVec(vector<T> vec) {
    cout << "[ ";
    for (T type: vec)
        cout << type << " ";
    cout << "]" << endl;
}

int main() {
    vector<int> v{1, -3, 4, -2, 6, -8, 5};
    printVec(v);
    vector<int> r = filter(v, [](int x) -> bool { return x % 2 == 0; });
    printVec(r);
    vector<int> s = filter(v, [](int x) -> bool { return x > 0; });
    printVec(s);
    vector<double> w{1.5, -3.1, 4.0, -2.0, 6.3};
    printVec(w);
    double mn = -0.5, mx = 0.5;
    vector<double> d = transfilt(w,[](double x) -> double{return sin(x);},[mn, mx](double x) -> bool{return x<mx && x>mn;});
    printVec(w);
    printVec(d);
}