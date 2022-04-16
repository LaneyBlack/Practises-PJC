#include <iostream>
#include <vector>

using namespace std;

bool sumOfTwo(const vector<int> vector, int val, int &a, int &b) {
    for (int i = 0; i < vector.size(); ++i)
        for (int j = 0; j < vector.size(); ++j)
            if (i != j && (vector[i] + vector[j]) == val) {
                a = i;
                b = j;
                return true;
            }
    return false;
}

int main() {
    int i, j;
    vector<int> a{2, 4, 5, 8, 9, 11, 13, 15};
    cout << sumOfTwo(a, 21, i, j) << endl;
    cout << "Number 1: " << a[i] << " Index 1: " << i << endl;
    cout << "Number 2: " << a[j] << " Index 2: " << j << endl;
    return 0;
}
