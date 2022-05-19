#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Letters {
    int letters[26]{0};
public:
    Letters(const char *text) {
        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < strlen(text); ++j) {
                if (toupper(text[j]) == 'A' + i)
                    letters[i]++;
            }
        }
    }

    int size() {
        return sizeof(letters) / sizeof(int);
    }

    char getMostFrequent() {
        int indexMostFrequent = 0;
        for (int i = 0; i < size(); ++i) {
            if (letters[i] > letters[indexMostFrequent])
                indexMostFrequent = i;
        }
        return ('A' + indexMostFrequent);
    }

    int getMostFrequentId() {
        int indexMostFrequent = 0;
        for (int i = 0; i < size(); ++i) {
            if (letters[i] > letters[indexMostFrequent])
                indexMostFrequent = i;
        }
        return indexMostFrequent;
    }

    int numOfDifferent() {
        int num = 0;
        for (int i = 0; i < size(); ++i) {
            if (letters[i] > 0)
                num++;
        }
        return num;
    }

    void printFrequencies() {
        for (int i = letters[getMostFrequentId()]; i > 0; i--) {
            for (int j = 0; j < size(); j++) {
                cout << (letters[j] >= i ? "*" : " ");
            }
            cout << endl;
        }
        for (int i = 0; i < size(); ++i) {
            cout << (char) ('A' + i);
        }
        cout << endl;
    }
};

int main() {
    const char *text = "To be, or not to be- that is the questiona\n:"
                       "Whether'tis nobler in the mind to suffer\n"
                       "The slings and arrows of outrageous fortune\n"
                       "Or to take arms against a sea of troubles,\n"
                       "And by opposing end them.";
    cout << *text;
    Letters lett(text);
    std::cout << "Most frequent letter:        " << lett.getMostFrequent() << std::endl;
    std::cout << "Number of different letters: " << lett.numOfDifferent() << std::endl;
    std::cout << "Frequency table of all letters:\n";
    std::cout << std::endl;
    lett.printFrequencies();
}

