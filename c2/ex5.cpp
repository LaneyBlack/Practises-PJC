#include <iostream>

int nodRec(int a, int b);

int sumDigits(int n);

int numDigits(int n);

void printOddEven(int n);

void hailstone(int n);

int main() {
    std::cout << "gcdRec(12, 42) = " << nodRec(12, 42) << std::endl
              << "gcdRec(12, 25) = " << nodRec(12, 25) << std::endl
              << "gcdRec(12, 25) = " << 42%12 << std::endl;
    std::cout << "sumDigits(123) = " << sumDigits(123) << std::endl
              << "sumDigits(971) = " << sumDigits(971) << std::endl;
    std::cout << "numDigits(12345) = " << numDigits(12345) << std::endl
              << "numDigits(971) = " << numDigits(971) << std::endl;
    std::cout << "printOddEven(15): ";
    printOddEven(15);
    std::cout << std::endl;
    std::cout << "printOddEven(14): ";
    printOddEven(14);
    std::cout << std::endl;
    std::cout << "hailstone(13): ";
    hailstone(13);
    std::cout << std::endl;
}


int nodRec(int a, int b) {
    return (b == 0) ? a : nodRec(b, a % b);
}

int sumDigits(int n) {
    return (n == 0) ? 0 : n%10 + sumDigits(n / 10);
}

int numDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + numDigits(n / 10);
    }
}

void printOddEven(int n) {
    if (n == 2) {
        std::cout << 2 << " ";
    } else if (n == 1) {
        std::cout << 1 << " ";
    } else {
        printOddEven(n - 2);
        std::cout << n << " ";
    }
}

void hailstone(int n) {
    if (n == 1) {
        std::cout << 1 << " ";
    } else {
        std::cout << n << " ";
        if (n % 2 == 0) {
            hailstone(n / 2);
        } else {
            hailstone(3 * n + 1);
        }
    }
}