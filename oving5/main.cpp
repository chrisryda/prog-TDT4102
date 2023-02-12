#include <iostream>
#include "Card.h"
#include "CardDeck.h"

using namespace std;

int main() {
    CardDeck cd;
    cd.shuffle();
    cd.print();
    return 0;
}
