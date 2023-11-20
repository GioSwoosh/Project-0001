// game.cpp
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : player1("Player 1"), player2("Player 2"), player1Score(0), player2Score(0) {
    deck.shuffle();

    while (!deck.isEmpty()) {
        player1.drawCard(deck.drawCard());
        player2.drawCard(deck.drawCard());
    }
}

void Game::play() {
    const int NUM_ROUNDS = 5;

    for (int round = 1; round <= NUM_ROUNDS; ++round) {
        std::cout << "\n=== Round " << round << " ===\n";
        int subRound = 1;

        warSet.clear();

        while (player1.hasCards() && player2.hasCards()) {
            std::cout << "\n--- Sub-Round " << subRound << " ---\n";
            printRoundInfo(round);
            printPlayerHands();

            Card card1 = player1.playCard();
            Card card2 = player2.playCard();

            if (card1.getRank() > card2.getRank()) {
                std::cout << player1.getName() << " wins the sub-round!\n";
                player1.drawCard(card1);
                player1.drawCard(card2);
                while (!warHistory.empty()) {
                    player1.drawCard(warHistory.top());
                    warHistory.pop();
                }
            } else if (card1.getRank() < card2.getRank()) {
                std::cout << player2.getName() << " wins the sub-round!\n";
                player2.drawCard(card1);
                player2.drawCard(card2);
                while (!warHistory.empty()) {
                    player2.drawCard(warHistory.top());
                    warHistory.pop();
                }
            } else {
                std::cout << "War!\n";
                warPile.push(card1);
                warPile.push(card2);
                performWar();

                // Check if one of the players has won after the war
                if (!player1.hasCards()) {
                    std::cout << player2.getName() << " wins the game!\n";
                    return;
                } else if (!player2.hasCards()) {
                    std::cout << player1.getName() << " wins the game!\n";
                    return;
                }
            }

            subRound++;
        }

        // Check if one of the players has won after the round
        if (!player1.hasCards()) {
            std::cout << player2.getName() << " wins the game!\n";
            return;
        } else if (!player2.hasCards()) {
            std::cout << player1.getName() << " wins the game!\n";
            return;
        }

        player1.resetHand();
        player2.resetHand();
        deck.shuffle();
        while (!deck.isEmpty()) {
            player1.drawCard(deck.drawCard());
            player2.drawCard(deck.drawCard());
        }
    }

    std::cout << "\n=== Game Over ===\n";
    printScores();

    if (player1Score > player2Score) {
        std::cout << player1.getName() << " wins the game!\n";
    } else if (player1Score < player2Score) {
        std::cout << player2.getName() << " wins the game!\n";
    } else {
        std::cout << "It's a tie for the game!\n";
    }
}


void Game::performWar() {
    const int WAR_SIZE = 3;

    if (player1.hasCards() && player2.hasCards()) {
        // Continue the war for the specified number of cards
        for (int i = 0; i < WAR_SIZE; ++i) {
            if (player1.hasCards() && player2.hasCards()) {
                warPile.push(player1.playCard());
                warPile.push(player2.playCard());
            }
        }

        // Check if there are unique cards in the warPile
        std::set<Card, CardComparator> uniqueCards(warPile.cbegin(), warPile.cend());
        if (uniqueCards.size() == warPile.size()) {
            std::cout << "War results in a tie!\n";

            // Distribute the tied cards between both players
            while (!warPile.empty()) {
                player1.drawCard(warPile.front());
                warPile.pop();
                if (!warPile.empty()) {
                    player2.drawCard(warPile.front());
                    warPile.pop();
                }
            }
        } else {
            std::cout << "War continues...\n";
            performWar();  // Continue the war with a recursive call
        }

        // Check if one of the players has run out of cards
        if (!player1.hasCards()) {
            std::cout << player2.getName() << " wins the game!\n";
            throw std::runtime_error("Game Over");
        } else if (!player2.hasCards()) {
            std::cout << player1.getName() << " wins the game!\n";
            throw std::runtime_error("Game Over");
        }
    }
}






void Game::printRoundInfo(int roundNumber) const {
    std::cout << "Scores - " << player1.getName() << ": " << player1Score << ", " << player2.getName() << ": " << player2Score << "\n";
    std::cout << "----- Round " << roundNumber << " -----\n";
}

void Game::printPlayerHands() const {
    std::cout << "Player 1 Hand: ";
    for (const auto& card : player1.getHand()) {
        std::cout << card << " ";
    }
    std::cout << "\n";

    std::cout << "Player 2 Hand: ";
    for (const auto& card : player2.getHand()) {
        std::cout << card << " ";
    }
    std::cout << "\n";
}

void Game::printScores() const {
    std::cout << "Final Scores - " << player1.getName() << ": " << player1Score << ", " << player2.getName() << ": " << player2Score << "\n";
}
