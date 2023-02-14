#include "Card.h"
#include <string>
#include <map>

using namespace std;

Card::Card(Suit suit, Rank rank): s{suit}, r{rank} {}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

string Card::toString() {
    return rankToString(r) + " of " + suitToString(s); 
}

string suitToString(Suit suit) {
    map<Suit, string> m{{Suit::clubs, "Clubs"}, {Suit::diamonds, "Diamonds"}, {Suit::hearts, "Hearts"}, {Suit::spades, "Spades"}}; 
    return m.at(suit);
}

string rankToString(Rank rank) {
    map<Rank, string> m{
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"},
        {Rank::six, "Six"},
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"},
        {Rank::queen, "Queen"},
        {Rank::king, "King"},
        {Rank::ace, "Ace"},
    }; 
    return m.at(rank);
}

int rankToInt(Rank rank) {
    map<Rank, int> m{
        {Rank::two, 2},
        {Rank::three, 3},
        {Rank::four, 4},
        {Rank::five, 5},
        {Rank::six, 6},
        {Rank::seven, 7},
        {Rank::eight, 8},
        {Rank::nine, 9},
        {Rank::ten, 10},
        {Rank::jack, 11},
        {Rank::queen, 12},
        {Rank::king, 13},
        {Rank::ace, 14},
    };
    return m.at(rank);
}
