#include <iostream>

int main() {
    int number = 1000000, maxNumber = 0, minNumber = 0;
    char input = 0;
    std::cout << "Please choose number from " << 1 << " to " << number << std::endl;
    std::cout << "Now if the number is smaller please type s, if bigger type b, if this is the number type y, e to exit"
              << std::endl;
    number/=2;
    do {
        if (input == 'b') {
            minNumber = number;
            number = (number + maxNumber) / 2;
        } else if (input == 's') {
            maxNumber = number;
            number= (number+minNumber)/2;
        } else {
            std::cout << "Wrong input!";
        }
        std::cout << "Your number is : " << number << std::endl;
        std::cin >> input;
    } while (input != 'y' | input != 'e');
    return 0;
}