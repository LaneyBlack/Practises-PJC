#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    else {
        double nSqrt = std::sqrt(n);
        for (int i = 2; i <= nSqrt; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

bool allDiff(const int arr[], size_t sz) {
    for (int i = 0; i < sz; ++i)
        for (int j = i + 1; j < sz; ++j)
            if (arr[i] == arr[j])
                return false;
    return true;
}

bool allDiff(const vector<int> &vec) {
    return allDiff(vec.data(), vec.size());
}

int numDiff(const int *arr, size_t sz) {
    int counter = 0;
    for (int i = 0; i < sz; ++i) {
        bool firstOccurrence = true;
        for (int j = i - 1; j >= 0 && firstOccurrence; --j) {
            if (arr[i] == arr[j])
                firstOccurrence = false;
        }
        if (firstOccurrence)
            counter++;
    }
    return counter;
}

int numDiff(const std::vector<int> &vec) {
    return numDiff(vec.data(), vec.size());
}

int fillWithPrimes(int arr[], size_t sz) {
    int lastPrime = 1;
    for (int i = 0; i < sz; ++i) {
        lastPrime++;
        while (!isPrime(lastPrime))
            lastPrime++;
        arr[i] = lastPrime;
    }
    return lastPrime;
}

int fillWithPrimes(std::vector<int> &vec) {
    return fillWithPrimes(vec.data(), vec.size());
}

int findMinIndex(int arr[], size_t sz) {
    int minIndex = 0;
    for (int i = 1; i < sz; ++i)
        if (arr[i] < arr[minIndex])
            minIndex = i;
    return minIndex;
}

int findMinIndexFrom(int arr[], size_t sz, int from) {
    int minIndex = 0;
    while (arr[minIndex] <= from)
        minIndex++;
    for (int i = minIndex; i < sz; ++i)
        if (arr[i] < arr[minIndex] && arr[i] >= from)
            minIndex = i;
    return minIndex;
}

int fillGaps(int arr[], size_t sz) {
    int min = arr[findMinIndex(arr, sz)] + 1;
    int ret;
    for (; min < numDiff(arr, sz); ++min) {
        int value = arr[findMinIndexFrom(arr, sz, min)];
        for (int i = 0; i < sz; ++i)
            if (arr[i] == value) {
                ret = arr[i];
                arr[i] = min;
            }
    }
    return ret;
}

int fillGaps(std::vector<int> &vec) {
    return fillGaps(vec.data(), vec.size());
}

size_t blockRem(int arr[], size_t sz, size_t from, size_t to) {
    if (from > sz)
        cout << "Exception. From is bigger than size" << endl;
    for (int i = 0; i < to - from; ++i) {
        arr[from + i] = arr[to + i];
    }
    return sz - (to - from);
}

size_t blockRem(std::vector<int> &vec, size_t from, size_t to) {
    if (from > vec.size())
        cout << "Exception. From is bigger than size" << endl;
    for (int i = 0; i < to - from + 1; ++i)
        vec[from + i] = vec[to + i];
    for (int i = 0; i < to - from; ++i)
        vec.erase(vec.end() - 1);
    return vec.size();
}

int main() {
    using namespace std;
    int a[]{3, 2, 3, 2, 5};
    size_t sza = sizeof(a) / sizeof(*a);
    vector<int> b(a, a + sza);
    cout << "allDiff: " << std::boolalpha << "a - " << allDiff(a, sza) << ", " << "b - " << allDiff(b) << '\n';
    cout << "numDiff: " << "a - " << numDiff(a, sza) << ", " << "b - " << numDiff(b) << '\n';
    int c[15];
    size_t szc = sizeof(c) / sizeof(*c);
    vector<int> d(szc, 0);
    auto lastc = fillWithPrimes(c, szc);
    cout << "Primes: ";
    for (auto x: c)
        cout << x << " ";
    cout << "\n  Last: " << lastc << "\n";
    auto lastd = fillWithPrimes(d);
    cout << "Primes: ";
    for (auto x: d)
        cout << x << " ";
    cout << "\n  Last: " << lastd << "\n";
    int e[]{-3, 3, 5, -2, 8, 5, 8, -2};
    size_t sze = sizeof(e) / sizeof(*e);
    vector<int> f(e, e + sze);
    cout << "Filling gaps: ";
    for (auto x: e)
        cout << x << " ";
    auto laste = fillGaps(e, sze);
    cout << "\n     becomes: ";
    for (auto x: e)
        cout << x << " ";
    cout << "\n   max value: " << laste << "\n";
    cout << "Filling gaps: ";
    for (auto x: f)
        cout << x << " ";
    auto lastf = fillGaps(f);
    cout << "\n     becomes: ";
    for (auto x: f)
        cout << x << " ";
    cout << "\n   max value: " << lastf << endl;
    int g[]{1, 2, 3, 4, 5, 6, 7};
    size_t szg = sizeof(g) / sizeof(*g);
    vector<int> h(g, g + szg);
    cout << "Original arr: ";
    for (auto x: g)
        cout << x << " ";
    auto newDimg = blockRem(g, szg, 2, 5);
    cout << "\nAfter'removing': ";
    for (size_t i = 0; i < newDimg; ++i)
        cout << g[i] << " ";
    cout << "\nOriginal vec: ";
    for (auto x: h)
        cout << x << "";
    auto newDimh = blockRem(h, 2, 5);
    cout << "\nAfter   removing: ";
    // vector has been resized by the function
    for (auto x: h)
        cout << x << " ";
    cout << endl;
}