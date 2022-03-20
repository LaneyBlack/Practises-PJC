#include <iostream>

int main() {
    std::cout << "Please throw in 3 positive numbers" << std::endl;
    int a = -1, b = -1, c = -1;
    std::cin >> a >> b >> c;
    int biggest = a > b ? a > c ? a : c : b > c ? b : c;
    for (biggest; biggest > 0; biggest--) {
        std::cout << (a>=biggest?" * ": "   ");
        std::cout << (b>=biggest?" * ": "   ");
        std::cout << (c>=biggest?" * ": "   ") << std::endl;
    }
    return 0;
}
