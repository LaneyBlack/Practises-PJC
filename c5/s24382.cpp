#include <iostream>
#include <vector>
//s24382
using namespace std;

void minMaxRep(int a[], size_t size, int **mn, size_t *&in, int &mx, size_t *ix) {
    **mn = a[0];
    mx = a[0];
    for (int i = 0; i < size; ++i) {
        if (**mn > a[i])
            **mn = a[i];
        else if (mx < a[i])
            mx = a[i];
    }
    for (int i = 0; i < size; ++i)
        if (**mn == a[i])
            (*in)++;
        else if (mx == a[i])
            (*ix)++;
}

size_t countMinNumbers(int a[], size_t size) {
    int minNumber = a[0];
    size_t minNumberCount = 1;
    for (int i = 1; i < size; ++i) {
        if (a[i] < minNumber) {
            minNumber = a[i];
            minNumberCount = 1;
        } else if (minNumber == a[i])
            minNumberCount++;
    }
    return minNumberCount;
}

size_t countMinNumbers(vector<int> a, size_t size) {
    return countMinNumbers(a.data(), size);
//    int minNumber = a[0];
//    size_t minNumberCount = 1;
//    for (int i = 1; i < size; ++i) {
//        if (a[i] < minNumber) {
//            minNumber = a[i];
//            minNumberCount = 1;
//        } else if (minNumber == a[i]) {
//            minNumberCount++;
//        }
//    }
//    return minNumberCount;
}

size_t getBiggestIndex(vector<int> a) {
    size_t biggestIndex = 0;
    for (int i = 0; i < size(a); i++)
        if (a[i] > a[biggestIndex])
            biggestIndex = i;
    return biggestIndex;
}

void erase_n_biggest(vector<int> &a, size_t n) {
    cout<< "Erasing " << n << " biggest numbers" << endl;
    if (n < size(a))
        while (n > 0) {
            for (int i = getBiggestIndex(a); i < size(a)-1; i++) {
                a[i] = a[i + 1];
            }
            a.erase(a.end()-1);
            n--;
        }
    else
        a.clear();
}

int main() {
    cout << "---------------Ex1---------------" << endl;
    int myArray[]{6, 6, 6, 2, 3, 4, 2, 7, 4, 7, 2};
    int mn, mx, *pmn;
    size_t ix = 0, in = 0, *pin;
    pin = &in, pmn = &mn;
    size_t myArraySize = size(myArray);
    minMaxRep(myArray, myArraySize, &pmn, pin, mx, &ix);
    cout << mn << ' ' << mx << ' ' << myArraySize << ' ' << in << ' ' << ix << endl;
    cout << "---------------Ex2---------------" << endl;
    cout << countMinNumbers(myArray, myArraySize) << endl;
    vector<int> myVector{6, 6, 6, 2, 3, 4, 2, 7, 4, 7, 2};
    size_t myVectorSize = size(myVector);
    cout << countMinNumbers(myVector, myVectorSize) << endl;
    cout << "---------------Ex3---------------" << endl;
    for (int i = 0; i < size(myVector); ++i)
        cout << myVector[i] << " ";
    cout << endl;
    erase_n_biggest(myVector, 3);
    for (int i = 0; i < size(myVector); ++i) {
        cout << myVector[i] << " ";
    }
    cout << endl;
    erase_n_biggest(myVector, 10);
    for (int i = 0; i < size(myVector); ++i) {
        cout << myVector[i] << " ";
    }
    return 0;
}