#include <iostream>

void minMaxRep(int a[], size_t size, int &mn, size_t &in, int &mx, size_t &ix) {
    mn = *a, mx = *a, in = 0, ix = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > mx) {
            mx = a[i];
            ix = 0;
        }
        if (a[i] < mn) {
            mn = a[i];
            in = 0;
        }
        if (a[i] == mx) {
            ix++;
        }
        if (a[i] == mn) {
            in++;
        }
    }
}

int main() {
    using std::cout;int a[]{2, 3, 4, 2, 7, 4, 7, 2};
    size_t size = std::size(a);
    int mn, mx;
    size_t in, ix;
    minMaxRep(a, size, mn, in, mx, ix);
    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)cout << a[i] << " ";
    cout << "]\n";
    cout << "Min = " << mn << " " << in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";
    return 0;
}

