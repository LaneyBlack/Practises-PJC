#include <iostream>
//s24382
using namespace std;

// 0  00  00  00    00      0000   000
//sex ms age edu residence region answer
unsigned short code(int sex, int marital_status, int age, int edu, int residence, int region, int answer) {
    if (sex > 2 || marital_status > 4 || age > 4 || edu > 4 || residence > 4 || region > 16 || answer > 8) {
        cout << "Error wrong data input" << endl;
        return -1;
    } else {
        int data[] = {marital_status, age, edu, residence};
        unsigned short value = 0;
        value |= sex;
        for (int i : data) {
            value <<= 2;
            value |= i;
        }
        value <<= 4;
        value |= region;
        value <<= 3;
        value |= answer;
        return value;
    }
}

void info (unsigned short code) {
    cout << "Sex: " << (code >> 15) << endl;
    cout << "Marital Status: " << ((code >> 13) & 0b011) << endl;
    cout << "Age Group: " << ((code >> 11) & 0b00011) << endl;
    cout << "Education Group: " << ((code >> 9) & 0b0000011) << endl;
    cout << "Residence: " << ((code >> 7) & 0b000000011) << endl;
    cout << "Region: " << ((code >> 3) & 0b0000000001111) << endl;
    cout << "Answer: " << (code & 0b00000000000111) << endl;
}

int main() {
    //0  00   00   00  00   0000 000
    //p stan wiek edu zam region odp
    unsigned short value = code(0, 3, 2, 3, 0, 12, 6);
    info(value);
    return 0;
}