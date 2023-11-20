// card.cpp
#include "card.h"

Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

Card::Rank Card::getRank() const {
    return rank;
}

Card::Suit Card::getSuit() const {
    return suit;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    const char* ranks[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
    const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    os << ranks[card.rank] << " of " << suits[card.suit];
    return os;
}
