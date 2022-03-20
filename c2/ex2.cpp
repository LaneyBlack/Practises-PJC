#include <iostream>
#include <cmath>

int main() {
    std::cout << "Please enter variables of quadratic equation (ax^2 + bx + c): " << std::endl;
    int a, b, c;
    std::cin >> a >> b >> c;
    int d = b * b - 4 * a * c;
    if (d > 0) {
        std::cout << "x1 = " << ((-b + sqrt(d)) / (2 * a)) << std::endl;
        std::cout << "x2 = " << ((-b - sqrt(d)) / (2 * a)) << std::endl;
    } else if (d == 0)
        std::cout << "x = " << (-b / (2 * a)) << std::endl;
    else
        std::cout << "This quadratic equation has no solutions in real numbers "<< std::endl;
    return 0;
}