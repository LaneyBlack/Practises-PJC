#include <iostream>
#include <cmath>
#include "vector"

using namespace std;

enum comparing_by {
    name,
    mana_cost,
    power,
    health
};

class Card {
public:
    string name;
    int mana_cost;
    int power;
    int health;

    static Card max(vector<Card> cards, comparing_by compare) {
        int maxIndex = 0;
        switch (compare) {
            case comparing_by::name : {
                for (int i = 0; i < cards.size(); ++i) {
                    if (cards[i].name.size() > cards[maxIndex].name.size())
                        maxIndex = i;
                };
                break;
            }
            case comparing_by::mana_cost : {
                for (int i = 0; i < cards.size(); ++i) {
                    if (cards[i].mana_cost > cards[maxIndex].mana_cost)
                        maxIndex = i;
                };
                break;
            }
            case comparing_by::power : {
                for (int i = 0; i < cards.size(); ++i) {
                    if (cards[i].power > cards[maxIndex].power)
                        maxIndex = i;
                };
                break;
            }
            case comparing_by::health : {
                for (int i = 0; i < cards.size(); ++i) {
                    if (cards[i].health > cards[maxIndex].health)
                        maxIndex = i;
                };
                break;
            }
        }
        return cards[maxIndex];
    }

    Card(string name, int mana, int power, int health) {
        this->name = name;
        this->mana_cost = mana;
        this->power = power;
        this->health = health;
    }
};

int main() {
    vector<Card> cards{*new Card("Orc", 3, 4, 8), *new Card("Magician", 6, 24, 2), *new Card("Paladin", 8, 12, 12)};
    Card card = Card::max(cards, comparing_by::mana_cost);
    cout << card.name << endl;
    return 0;
}