#include <iostream>

using namespace std;

void merge(const int *a, size_t dima, const int *b, size_t dimb, int *c) {
    int iA = 0, iB = 0;
    for (int i = 0; i < dima + dimb; ++i)
        if (a[iA] < b[iB])
            c[i] = a[iA++];
        else
            c[i] = b[iB++];
}

void printArr(const int *a, size_t dima, const char *m) {
    cout << m << " [ ";
    for (size_t i = 0; i < dima; i++)
        cout << a[i] << " ";
    cout << "]\n";
}

int main() {
    int a[]{1, 4, 4, 5, 8};
    int b[]{1, 2, 2, 4, 6, 6, 9};
    constexpr size_t dima = size(a);
    constexpr size_t dimb = size(b);
    constexpr size_t dimc = dima + dimb;
    int c[dimc];
    merge(a, dima, b, dimb, c);
    printArr(a, dima, "a");
    printArr(b, dimb, "b");
    printArr(c, dimc, "c");
}