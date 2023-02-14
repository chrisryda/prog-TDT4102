#pragma once 
#include <string>

enum class Suit{clubs, diamonds, hearts, spades};
enum class Rank{two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

std::string suitToString(Suit suit);
std::string rankToString(Rank rank);
int rankToInt(Rank rank);

class Card {
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    std::string toString();
};
