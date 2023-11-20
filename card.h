// card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

    Card(Rank rank, Suit suit);

    Rank getRank() const;
    Suit getSuit() const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Rank rank;
    Suit suit;
};

#endif // CARD_H
