#include <iostream>

using namespace std;

int main() {
    int inputVariable, maxVariable, maxCounter = 1, minVariable, minCounter = 1;
    cout << "Please throw me some numbers: " << endl;
    cin >> inputVariable;
    if (inputVariable == 0) {
        cout << "Min: 0 time 1" << endl;
        cout << "Max: 0 time 1" << endl;
    } else {
        maxVariable = inputVariable;
        minVariable = inputVariable;
    }
    do {
        cin >> inputVariable;
        if (inputVariable != 0) {
            if (inputVariable == maxVariable)
                maxCounter++;
            if (inputVariable == minVariable)
                minCounter++;
            if (inputVariable > maxVariable) {
                maxVariable = inputVariable;
                maxCounter = 1;
            }
            if (inputVariable < minVariable) {
                minVariable = inputVariable;
                minCounter = 1;
            }
        }
    } while (inputVariable!=0);
    cout << "Min: " << minVariable << ", times: " << minCounter << endl;
    cout << "Max: " << maxVariable << ", times: " << maxCounter << endl;

}