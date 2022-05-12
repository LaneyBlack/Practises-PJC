#include <iostream>
#include "vector"

using namespace std;

enum Banks {
    PKO, BGZ, BRE, BPH
};
struct Account {
    Banks bank;
    int balance;
};

struct Person {
    char name[20];
    Account account;
};

struct Couple {
    Person he;
    Person she;
};

const Couple *bestClient(const Couple *cpls, int size, Banks bank) {
    int bestCouple = -1;
    for (int i = 0; i < size; ++i) {
        if (cpls[i].he.account.bank == bank || cpls[i].she.account.bank == bank) {
            if (bestCouple == -1 || ((cpls[i].he.account.balance + cpls[i].she.account.balance) > (cpls[bestCouple].he.account.balance + cpls[bestCouple].she.account.balance))) {
                bestCouple = i;
            }
        }
    }
    if (bestCouple == -1)
        return nullptr;
    else return cpls + bestCouple;
}

int main() {
    Couple cpls[] = {{{"John",  {PKO, 1200}}, {"Mary", {BGZ, 1400}}},
                     {{"Peter", {BGZ, 1400}}, {"Suzy", {BRE, -1500}}},
                     {{"Kevin", {PKO, 1600}}, {"Katy", {BPH, 1500}}},
                     {{"Kenny", {BPH, 200 }}, {"Lucy", {BRE, -201}}}
    };
    const Couple *p = bestClient(cpls, 4, BRE);
    if (p)
        cout << p->he.name << " and " << p->she.name << ": " << p->he.account.balance + p->she.account.balance << endl;
    else
        cout << "No such couple...\n";
    return 0;
}