#include <iostream>
#include <vector>

using namespace std;

template<typename T>
size_t findMaxIndex(T &arr, size_t size) {
    size_t maxIndex = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int main() {
    int integerArr[] = {1, 2, 9, 2, 3, 4, 1, 5};
    double doubleArr[] = {3.3, 2.1, 9.1, 9.2, 2.3, 3.7, 4.0, 1.4, 5.3};
    string stringArr [] = {"2", "6", "9", "2", "3", "8"};
    cout << "Int : " << integerArr[findMaxIndex(integerArr,8)] << endl;
    cout << "Double : " << doubleArr[findMaxIndex(doubleArr,9)] << endl;
    cout << "String : " << stringArr [findMaxIndex(stringArr,6)] << endl;
    return 0;
}