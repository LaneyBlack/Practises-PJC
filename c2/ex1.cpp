#include <iostream>

#define GET_MAX
#define GET_MIN

int main() {
    std::cout << "Please enter 3 numbers: " << std::endl;
    int a, b,c;
    std::cin >> a >> b >> c;
#ifndef GET_MAX
#ifndef GET_MIN
#error GET_MAX and GET_MIN are not defined
#endif
#endif

#ifdef GET_MAX
    std::cout << "Biggest number is " << (a>b?a>c?a:c:b>c?b:c);
#endif
#ifdef GET_MIN
    std::cout << "Smallest number is " << (a<b?a<c?a:c:b<c?b:c);
#endif
    return 0;
}
