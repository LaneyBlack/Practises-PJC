#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<size_t> smallSum3(const std::vector<int> &a) {
    vector<size_t> vect = {1,2,3};
    size_t closest = 10;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j)
            if (i!=j)
            for (int k = 0; k < a.size(); ++k) {
                if (i != k && k!=j)
                    if (abs(0 - a[i] - a[j] - a[k]) < closest) {
                        closest = 0 - a[i] - a[j] - a[k];
                        vect[0] = i;
                        vect[1] = j;
                        vect[2] = k;
                    }
        }
    }
    return vect;
}

int main() {
    std::vector<int> a{2, -13, 3, 6, 4, 5, -14, 1, -15};
    auto r = smallSum3(a);
    std::printf("Sum=%d for elements ""a[%u]=%d, a[%u]=%d, a[%u]=%d\n", a[r[0]] + a[r[1]] + a[r[2]], r[0], a[r[0]],
                r[1], a[r[1]], r[2], a[r[2]]);
    return 0;
}