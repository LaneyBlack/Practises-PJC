#include <iostream>
//s24382

void minMaxRep(int a[], size_t size, int &mn, size_t *&in, int **mx, size_t *ix) {
    for (int i = 0; i < size; ++i) {
        mn = a[0];
        **mx = a[0];
        if (mn > a[i])
            mn = a[i];
        else if (**mx < a[i])
            **mx = a[i];
    }
    for (int i = 0; i < size; ++i) {
        if (mn == a[i])
            (*in)++;
        else if (**mx == a[i])
            (*ix)++;
    }
}

int main() {
    using namespace std;
    int mn, mx, *pmx,
    size_t ix = 0, in = 0, *pin;
    pmx = &mx;
    pin = &in;
    int a[] = {1, 2, 3, 2, 3, 4, 2, 7, 4, 7, 2};
    int size = std::size(a);
    minMaxRep(a, size, mn, pin, &pmx, &ix);
    cout << mn << ' ' << mx << ' ' << size << ' ' << in << ' ' << ix << endl;
    return 0;
}
