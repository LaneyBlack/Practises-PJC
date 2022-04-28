#include <iostream>
#include <vector>
//s24382
using namespace std;

//Ex1
void fun(const std::vector<int> &v, int **min, int *&max) {
    for (int i = 0; i < v.size(); ++i) {
        if (**min > v[i])
            **min = v[i];
        if (*max < v[i])
            *max = v[i];
    }
}

//Ex2
char fromIntToLetter(int value) {
    if (value == 31)
        return '_';
    return (64 + value);
}

void transcribeFromInt(int value) {
    // 0000 0000 0000 0000 0000 0000 0000 0000 - int
    // 00 00000 00000 00000 00000 00000 00000 - our
    for (int i = 5; i >= 0; i--) {
        cout << fromIntToLetter(0b11111 & (value >> ((i * 5))));
    }
    cout << endl;
}

int main() {
    vector vec = {1, 2, 3, 9, 8, 7};
    int min = vec[0], max = vec[0], *pmin = &min, *pmax = &max;
    fun(vec, &pmin, pmax);
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << "]\nMin " << min << endl;
    cout << "Max " << max << endl;
    int value1 = 278905155; // 0b00_01000_01001_11111_10000_01010_00011;
    int value2 = 0b00000010111010100011110111011111; // to jest moje Imie :) (that's an Easter Egg)
    transcribeFromInt(value1);
    transcribeFromInt(value2);
    return 0;
}