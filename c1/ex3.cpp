#include <iostream>

int main() {
    int numberWithMaxDigSum, maxDigitSum = 0, number = 0;
    do {
        int numberCopy, digitSum = 0;
        std::cout << "Please throw number (0 = end)" << std::endl;
        std::cin >> number;
        numberCopy = number;
        //ToDo sum is not wright
        while(numberCopy!=0) {
            digitSum+=numberCopy%10;
            numberCopy/=10;
        }
        if (digitSum>maxDigitSum) {
            maxDigitSum = digitSum;
            numberWithMaxDigSum = number;
        }
    } while (number != 0);
    std::cout << "Max sum of digits was " << maxDigitSum << " for " << numberWithMaxDigSum << std::endl;
    return 0;
}

