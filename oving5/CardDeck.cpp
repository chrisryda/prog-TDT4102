#include "CardDeck.h"
#include "Card.h"
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

CardDeck::CardDeck() {
    for (int i = 2; i < 15; i++) {
        Rank r = static_cast<Rank>(i);
        for (int j = 0; j < 4; j++) {
            Suit s = static_cast<Suit>(j);
            Card c{s, r};
            cards.emplace_back(c);
        }
    }
}

void CardDeck::swap(int a, int b) {
    std::swap(cards[a], cards[b]);
}

void CardDeck::print() {
    for (Card c : cards) {
        cout << c.toString() << endl;
    }
}

void CardDeck::shuffle() {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 51);

    for (int i = 0; i < 1000; i++) {
        swap(distribution(generator), distribution(generator));
    }
}

Card CardDeck::drawCard() {
    Card c = cards[cards.size()-1];
    cards.pop_back();
    return c;
}
