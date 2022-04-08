#include <iostream>

using namespace std;

bool isLetter(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

size_t length(const char *cstr) {
    size_t i = 0;
    while (cstr[i] != '\0')
        i++;
    return i;
}

char *reverse(char *cstr) {
    size_t size = length(cstr);
    for (size_t i = size - 1, j = 0; i >= size / 2; i--, j++) {
        char tmp = cstr[j];
        cstr[j] = cstr[i];
        cstr[i] = tmp;
    }
    return cstr;
}

size_t words(const char *cstr) {
    size_t wordCount = 0;
    bool space = isLetter(cstr[0]), onWord = isLetter(cstr[0]);
    for (int i = 0; i < length(cstr); i++)
        if (cstr[i] == ' ') {
            if (onWord) {
                onWord = false;
                wordCount++;
            }
            space = true;
        } else if (space == true && onWord == false && isLetter(cstr[i])) {
            onWord = true;
            space = false;
        }
    return wordCount;
}

size_t words2(const char *cstr) {
    size_t wordCount = 0, letterCount = 0;
    bool space = isLetter(cstr[0]);
    for (int i = 0; i < length(cstr); ++i)
        if (isLetter(cstr[i]))
            letterCount++;
        else if (cstr[i] == ' ') {
            if (letterCount >= 2)
                wordCount++;
            letterCount = 0;
            space = true;
        } else if (space == true && isLetter(cstr[i])) {
            space = false;
        }
    return wordCount;
}

char *concat(char *t, const char *s) {
    size_t sizeT = length(t), sizeS = length(s);
    for (int i = 0, j = sizeT; i < sizeS; i++, j++)
        t[j] = s[i];
    return t;
}

int main() {
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1) << endl;
    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words  : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";
    cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;
    return 0;
}