#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include "Card.hpp"

#define S 5

class Pokerhand {
    private:
        std::vector<Card> hand;
    public:
        Pokerhand() {}
        Pokerhand(std::vector<std::string> const& cards);
        ~Pokerhand();
        std::pair<int, int> hand_value();
        int high_card();
        int pair();
        int pairs();
        int three();
        int straight();
        int flush();
        int full_house();
        int four();
        int straight_flush();
        int royal_flush();
        int next_highest();

        bool operator <(Pokerhand& o_hand);
        bool operator >(Pokerhand& o_hand);
};

Pokerhand::Pokerhand(std::vector<std::string> const& cards) {
    for (auto card : cards) {
        hand.emplace_back(card[0], card[1]);
    }
}

Pokerhand::~Pokerhand() {
    hand.clear();
}

std::pair<int, int> Pokerhand::hand_value() {
    int val;

    if ((val = royal_flush()))
        return std::make_pair(10, val);
    if ((val = straight_flush()))
        return std::make_pair(9, val);
    if ((val = four()))
        return std::make_pair(8, val);
    if ((val = full_house()))
        return std::make_pair(7, val);
    if ((val = flush()))
        return std::make_pair(6, val);
    if ((val = straight()))
        return std::make_pair(5, val);
    if ((val = three()))
        return std::make_pair(4, val);
    if ((val = pairs()))
        return std::make_pair(3, val);
    if ((val = pair()))
        return std::make_pair(2, val);
    if ((val = high_card()))
        return std::make_pair(1, val);

    return std::make_pair(0, val);
}

int Pokerhand::high_card() {
    int high = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        if (hand[i].value() > high)
            high = hand[i].value() + 2;
    }
    return high;
}

int Pokerhand::pair() {
    int occur[14] {0};      // Track occurrences of each card value
    int high = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].value()];
    }
    for (int i = 0; i < 14; ++i) {
        if (occur[i] == 2)
            high = i + 2;
    }
    return high;
}

int Pokerhand::pairs() {
    int occur[14] {0};      // Track occurrences of each card value
    int c = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].value()];
    }
    for (int i = 0; i < 14; ++i) {
        if (occur[i] == 2) {
            if (c == 1)     // there is already 1 pair present
                return i + 2;
            else
                ++c;        // there is now 1 pair
        }
    }
    return 0;
}

int Pokerhand::three() {
    int occur[14] {0};      // Track occurrences of each card value
    int high = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].value()];
    }
    for (int i = 0; i < 14; ++i) {
        if (occur[i] == 3)
            high = i + 2;
    }
    return high;
}

int Pokerhand::straight() {
    int occur[14] {0};      // Track occurrences of each card value
    int high = 0;
    int c = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].value()];
    }
    // less than 13 because I'm looking ahead in the array
    for (int i = 0; i < 13; ++i) {
        if (occur[i] && occur[i+1]) {
            if (c == 3)     // There are already 4 straight cards
                high = i + 2;
            else
                ++c;
        } else {            // The straight has been broken, start over
            c = 0;
        }
    }
    return high;
}

int Pokerhand::flush() {
    int occur[4] {0};       // Track occurrences of each suit
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].suit()];
    }
    for (int i : occur) {
        if (i == 5)
            return high_card();
    }
    return 0;
}

int Pokerhand::full_house() {
    int high = 0;
    if (pair() && (high = three()))
        return high;
    return high;
}

int Pokerhand::four() {
    int occur[14] {0};      // Track occurrences of each card value
    int high = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        ++occur[hand[i].value()];
    }
    for (int i = 0; i < 14; ++i) {
        if (occur[i] == 4)
            high = i + 2;
    }
    return high;
}

int Pokerhand::straight_flush() {
    if (straight() && flush())
        return high_card();
    return 0;
}

int Pokerhand::royal_flush() {
    if (straight() && flush()) {
        if (high_card() == 15)
            return 15;
    }
    return 0;
}

int Pokerhand::next_highest() {
    int high = high_card();
    int h = 0;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        if (hand[i].value() + 2 > h && hand[i].value() + 2 < high)
            h = hand[i].value() + 2;
    }
    return h;
}

bool Pokerhand::operator <(Pokerhand& o_hand) {
    std::pair<int, int> val1 = hand_value();
    std::pair<int, int> val2 = o_hand.hand_value();

    if (val1.first == val2.first) {
        if (val1.second == val2.second) {
            return next_highest() < o_hand.next_highest();
        }
        return val1.second < val2.second;
    }
    return val1.first < val2.first;

}

bool Pokerhand::operator >(Pokerhand& o_hand) {
    std::pair<int, int> val1 = hand_value();
    std::pair<int, int> val2 = o_hand.hand_value();

    if (val1.first == val2.first) {
        if (val1.second == val2.second) {
            return next_highest() > o_hand.next_highest();
        }
        return val1.second > val2.second;
    }
    return val1.first > val2.first;
}
