// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <list>
#include <string>

class Player {
public:
    Player(const std::string& name);

    void drawCard(const Card& card);
    Card playCard();
    void resetHand(); // Added function to reset the player's hand

    bool hasCards() const;
    std::string getName() const;
    const std::list<Card>& getHand() const;
    int getHandValue() const; // Added function to calculate the total value of the hand

private:
    std::list<Card> hand;
    std::string name;
};

#endif // PLAYER_H
