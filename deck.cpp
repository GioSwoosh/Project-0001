// deck.cpp
#include "deck.h"
#include <algorithm>

Deck::Deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            cards.push_back(Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
        }
    }
}

void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    Card drawnCard = cards.front();
    cards.pop_front();
    return drawnCard;
}

bool Deck::isEmpty() const {
    return cards.empty();
}
