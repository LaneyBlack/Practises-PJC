#include <iostream>
size_t length(const char* cstr);
bool isLetter(char c);
char* reverse(char* cstr);
size_t words(const char* cstr);
size_t words2(const char* cstr);
char* concat(char* t, const char* s);

int main() {
    using std::cout; using std::endl;
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1) << endl;

    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";

    cout << "concat : "
         << concat(concat(s3, ", world"), "!") << endl;
}

bool isLetter(char c) {
    return (c >= 'A' &&  c <= 'Z') || (c >= 'a' &&  c <= 'z');
}

size_t length(const char* cstr) {

    size_t i = 0;
    while (cstr[i] != '\0')
    {
        i++;
    }

    return i;
}

char* reverse(char* cstr) {

    size_t size = length(cstr);
    size--;

    size_t i = 0;
    size_t j = size;
    while (i <= size / 2) {
        char tmp = cstr[i];
        cstr[i] = cstr[j];
        cstr[j] = tmp;
        i++;
        j--;
    }

    return cstr;
}

size_t words(const char* cstr) {
    size_t size = length(cstr);
    size_t result = 0;

    size_t index = 0;
    while (index < size) {
        if (!isLetter(cstr[index]) && index + 1 < size) {
            index++;
            if (!isLetter(cstr[index])) {

            }
            else
            {
                result++;
                while (isLetter(cstr[index]) && index < size) {
                    index++;
                }
            }
        }
        else {
            index++;
        }
    }
    return result;
}

size_t words2(const char* cstr) {
    size_t size = length(cstr);
    size_t result = 0;

    size_t index = 0;
    while (index < size) {
        if (!isLetter(cstr[index]) && index + 1 < size) {
            index++;
            if (!isLetter(cstr[index])) {

            }else
            {
                size_t counter = 0;
                while (isLetter(cstr[index]) && index < size) {
                    index++;
                    counter++;
                }
                if (counter >= 2) {
                    result++;
                }
            }
        }
        else {
            index++;
        }
    }
    return result;
}

char* concat(char* t, const char* s) {
    size_t sizeT = length(t);
    size_t sizeS = length(s);

    size_t indexT = 0;

    while (indexT < sizeT && t[indexT] != '\0') {
        indexT++;
    }

    for (size_t i = 0; i < sizeS; i++) {
        t[indexT + i] = s[i];
    }
    return t;
}