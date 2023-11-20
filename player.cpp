// player.cpp
#include "player.h"

Player::Player(const std::string& name) : name(name) {}

void Player::drawCard(const Card& card) {
    hand.push_back(card);
}

Card Player::playCard() {
    if (!hand.empty()) {
        Card playedCard = hand.front();
        hand.pop_front();
        return playedCard;
    } else {
        // You might want to handle the case where the hand is empty
        // For now, return a default-constructed card
        return Card(Card::TWO, Card::HEARTS); // Adjust as needed
    }
}

void Player::resetHand() {
    hand.clear();
}

bool Player::hasCards() const {
    return !hand.empty();
}

std::string Player::getName() const {
    return name;
}

const std::list<Card>& Player::getHand() const {
    return hand;
}

int Player::getHandValue() const {
    int totalValue = 0;
    for (const auto& card : hand) {
        totalValue += card.getRank() + 2; // Adding 2 because ranks start from TWO
    }
    return totalValue;
}
