// deck.h
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <deque>

class Deck {
public:
    Deck();

    void shuffle();
    Card drawCard();
    bool isEmpty() const;

private:
    std::deque<Card> cards;
};

#endif // DECK_H
