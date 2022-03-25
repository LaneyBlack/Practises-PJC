#include <iostream>

#define s24382

int recPow(int n, int x) {
    if (x==0) {
        std::cout << n << " ^ " << x << " = " << 1 << std::endl;
        return 1;
    } else {
        int result = n * recPow(n,x-1);
        std::cout << n << " ^ " << x << " = " << result << std::endl;
        return result;
    }
}

int main() {
    using namespace std;
#ifdef s24382
    cout << "Hello PJC!" << endl;
#endif
    int a = recPow(2,3);
    cout << "a = " << a << endl;
    return 0;
}
