#include <iostream>
#include <vector>
//s24382
using namespace std;

template<typename T, typename FunType>
T temp(vector<T> vec, FunType function) {
    for (int i = 0; i < vec.size(); ++i) {
        if (function(vec[i]))
            return vec[0];
    }
    return vec[vec.size() - 1];
}

int main() {
    vector<int> vector1 = {2, 2, 3, 4, 5, 6, 7, 8}; //first
    vector<int> vector2 = {2, 4, 6, 8, 10, 12}; //last
    cout << "---Integers---" << endl;
    cout << "Example 1 : " << temp(vector1, [](int x) -> bool { return x % 2 == 1; }) << endl;
    cout << "Example 2 : " << temp(vector2, [](int x) -> bool { return x % 2 == 1; }) << endl;
    vector<string> vector3 = {"Micle", "Jim", "dwight"}; //first
    vector<string> vector4 = {"dwight", "bears", "beets", "battle star galactica"}; //last
    cout << "---Strings---" << endl;
    cout << "Example 1 : " << temp(vector3, [](string x) -> bool { return x[0] <='Z' && x[0] >= 'A'; }) << endl;
    cout << "Example 2 : " << temp(vector4, [](string x) -> bool { return x[0] <= 'Z' && x[0] >= 'A'; }) << endl;
    return 0;
}