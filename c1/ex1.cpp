#include <iostream>
#include <cmath>

int main() {
    std::cout << "Type your height in meters" << std::endl;
    double height = -1; // height(-1);
    double weight = -1; // weight(-1);
    std::cin >> height;
    std::cout << "Type your weight in kg" << std::endl;
    std::cin >> weight;
    double bmi = weight/std::pow(height,2) ; // weight(-1);
    std::cout << "Your BMI is " << bmi << std::endl;
    return 0;
}

//return 0 mustn't be in the end of main
//std = standard package
// U can use "using namespace std;" and the no need to type "std::"
