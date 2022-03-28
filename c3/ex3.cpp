#include <iostream>

using std::cout, std::endl, std::swap;

void ord3(double &a, double &b, double &c) {
    double tmp;
    a > c ? (tmp = a, a = c, c = tmp) : 1; //can use swap();
    b > c ? (tmp = c, c = b, b = tmp) : 1;
    a > b ? (tmp = a, a = b, b = tmp) : 1;
}

void ord3(double *a, double *b, double *c) {
    if (*a > *c) { swap(*a, *c); }
    if (*b > *c) { swap(*b, *c); }
    if (*a > *b) { swap(*a, *b); }
}

void getMinMax(const double &a, const double &b, const double &c, const double *&pMin, const double *&pMax) {
    pMax = a > b ? a > c ? &a : &c : b > c ? &b : &c;
    pMin = a < b ? a < c ? &a : &c : b < c ? &b : &c;
}

void getMinMax(const double *a, const double *b, const double *c, const double **pMin, const double **pMax) {
    *pMax = *a > *b ? *a > *c ? a : c : b > c ? b : c;
    *pMin = *a < *b ? *a < *c ? a : c : *b < *c ? b : c;
}

void printOrd(const double *a, const double *b, const double *c) {
    cout << *a << ' ' << *b << ' ' << *c << endl;
}

void printMinMax(const double *pmn, const double *pmx) {
    cout << "Min = " << *pmn << "; " << "Max = " << *pmx << endl;
}

int main() {
    double a, b, c;
    const double *pMin, *pMax;
    a = 2, b = 1, c = 3;
    ord3(a, b, c);
    printOrd(&a, &b, &c);

    a = 3, b = 2, c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = -1, b = -1, c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = 2, b = 3, c = 1;
    getMinMax(a, b, c, pMin, pMax);
    printMinMax(pMin, pMax);

    a = 3, b = 1, c = 2;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);

    a = 3, b = 3, c = -1;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);
    return 0;
}
