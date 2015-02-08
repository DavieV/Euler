#include <iostream>
#include <vector>
#include <string>
#include "Pokerhand.hpp"

int main() {
    std::vector<std::string> cards;
    std::string tmp;

    int count = 0;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> tmp;
            cards.push_back(tmp);
        }
        Pokerhand p1(cards);
        cards.clear();
        for (int j = 0; j < 5; ++j) {
            std::cin >> tmp;
            cards.push_back(tmp);
        }
        Pokerhand p2(cards);
        cards.clear();

        if (p1 > p2)
            ++count;
    }

    std::cout << count << std::endl;

    return 0;
}
