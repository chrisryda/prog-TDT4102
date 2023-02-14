#pragma once
#include "CardDeck.h"
#include "Card.h"
#include <vector>

bool isAce(Card c);

class Blackjack {
private:
    CardDeck deck;
    std::vector<Card> player_hand;
    std::vector<Card> dealer_hand;
    int player_hand_sum;
    int dealer_hand_sum;
public:
    Blackjack();
    int getCardValue(Card c);
    int getHandScore(std::vector<Card> card_hand);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();
    void printPlayerInfo();
    void printDealerInfo();
    bool isPlayerBlackjack();
    bool isDealerBlackjack();

};
