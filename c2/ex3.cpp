#include <iostream>

int main () {
    std::cout << "Please throw me some numbers :) (0 to exit)" << std::endl;
    int n, maxCount = 0, nWithMaxCount, latestN = 0, latestNCount = 1;
    do {
        std::cin >> n;
        if (n==latestN)
            latestNCount++;
        else {
            if (latestNCount>maxCount) {
                maxCount = latestNCount;
                nWithMaxCount = latestN;
            }
            latestNCount = 1;
        }
        latestN = n;
    } while (n!=0);
    std::cout << "Number with the biggest count was " << nWithMaxCount << std::endl;
    std::cout << "The biggest count was " << maxCount << std::endl;
    return 0;
}
