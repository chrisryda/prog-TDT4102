#include "Blackjack.h"
#include <vector>
#include <iostream>

using namespace std;

bool isAce(Card c) {
    return c.getRank() == Rank::ace; 
}

Blackjack::Blackjack() {
    deck.shuffle();
    for (int i = 0; i < 2; i++) {
        drawDealerCard();
        drawPlayerCard();
    }
    printPlayerInfo();
    cout << "\nDealer's card: " << endl;
    cout << dealer_hand[0].toString() << endl;
    cout << "\n" << endl;
};

int Blackjack::getCardValue(Card c) {
    if (isAce(c)) {
        return 11;
    }
    else if (c.getRank() == Rank::jack || c.getRank() == Rank::queen || c.getRank() == Rank::king) {
        return 10;
    }
    else {
        return rankToInt(c.getRank());
    }
}

int Blackjack::getHandScore(vector<Card> card_hand) {
    int hand_score = 0;
    for (Card c : card_hand) {
        if (isAce(c) && (hand_score += getCardValue(c) > 21)) {
            hand_score += 1;
            continue;
        }
        hand_score += getCardValue(c);
    }
    return hand_score;
}

bool Blackjack::askPlayerDrawCard() {
    char response;
    cout << "Do you want to draw another card? (y/n): ";
    cin >> response;
    while (true) {
        switch (response) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Invalid input, try again" << endl;
                return true;
        }
    }
}

void Blackjack::drawPlayerCard() {
    Card drawn_card = deck.drawCard();
    player_hand.emplace_back(drawn_card);
    player_hand_sum = getHandScore(player_hand);
}

void Blackjack::drawDealerCard() {
    Card drawn_card = deck.drawCard();
    dealer_hand.emplace_back(drawn_card);
    dealer_hand_sum = getHandScore(dealer_hand);
}

void Blackjack::playGame() {
    while (player_hand_sum < 21 && askPlayerDrawCard()) {
        drawPlayerCard();
        printPlayerInfo();
    }
    while (dealer_hand_sum <= 17) {
        drawDealerCard();
    }

    cout << "Final result:" << endl;
    printPlayerInfo();
    printDealerInfo();
    if (isPlayerBlackjack() && !isDealerBlackjack()) {
        cout << "\nCongratulations, you have won!" << endl;
        return;
    }
    else if (player_hand_sum <= 21 && player_hand_sum > dealer_hand_sum) {
        cout << "\nCongratulations, you have won!" << endl;
        return;
    }
    else if (player_hand_sum <= 21 && dealer_hand_sum > 21) {
        cout << "\nCongratulations, you have won!" << endl;
        return;
    }
    else {
        cout << "I am sorry, but no winning this time. Please try again!" << endl;
        return;
    }
}

// Definitions of Blackjack vary, but in this implementation 
// of the game it means having an ace + picture card or 10
bool Blackjack::isPlayerBlackjack() {
    if (player_hand.size() == 2 && player_hand_sum == 21 && player_hand[0].getRank() == Rank::ace) {
        return true;
    }
    else if (player_hand.size() == 2 && player_hand_sum == 21 && player_hand[1].getRank() == Rank::ace) {
        return true;
    } 
    else {
        return false;
    }
}

bool Blackjack::isDealerBlackjack() {
    if (dealer_hand.size() == 2 && dealer_hand_sum == 21 && dealer_hand[0].getRank() == Rank::ace) {
        return true;
    }
    else if (dealer_hand.size() == 2 && dealer_hand_sum == 21 && dealer_hand[1].getRank() == Rank::ace) {
        return true;
    } 
    else {
        return false;
    }
    
}

void Blackjack::printPlayerInfo() {
    cout << "\nYour cards: " << endl;
    for (Card c : player_hand) {
        cout << c.toString() << endl;
    }
    cout << "Your hand score: " << player_hand_sum << "\n" << endl;
}

void Blackjack::printDealerInfo() {
    cout << "\nDealer's cards: " << endl;
    for (Card c : dealer_hand) {
        cout << c.toString() << endl;
    }
    cout << "Dealer's hand score: " << dealer_hand_sum << "\n" << endl;
}
