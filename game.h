// game.h
#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include <queue>
#include <stack>
#include <set>

// Custom comparison function for Card
struct CardComparator {
    bool operator()(const Card& lhs, const Card& rhs) const {
        // Implement your comparison logic here
        // For example, you can compare based on rank and suit
        if (lhs.getRank() == rhs.getRank()) {
            return lhs.getSuit() < rhs.getSuit();
        }
        return lhs.getRank() < rhs.getRank();
    }
};

class Game {
public:
    Game();

    void play();

private:
    Deck deck;
    Player player1;
    Player player2;
    std::queue<Card> warPile;
    std::stack<Card> warHistory;
    std::set<Card, CardComparator> warSet;  // Use the custom comparator

    int player1Score;
    int player2Score;

    void performWar();
    void printRoundInfo(int roundNumber) const;
    void printPlayerHands() const;
    void printScores() const;
};

#endif // GAME_H
