#include <iostream>
#include <vector>

int stat = 10;

int main() {
    using namespace std;
    std::vector<int> v3;
    std::vector<int>::iterator it;
    for (int i = 0; i < 10; ++i) {
        it = v3.begin();
        v3.insert(it, i);
    }
    for(int var : v3) {
        cout << var <<endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    static int stat;
    cout << ++stat << endl;
    cout << ::stat << endl;
    {
        static int stat;
        cout << --stat << endl;
    }
    return 0;
}
