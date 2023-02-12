#include "Card.h"
#include <string>
#include <iostream>
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
