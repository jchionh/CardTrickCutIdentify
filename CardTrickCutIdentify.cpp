// CardTrickCutIdentify.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <algorithm>

#include "Card.h"

int main()
{
    std::random_device randomDevice;
    std::mt19937 randomGenerator(randomDevice());

    std::cout << "Welcome to the Card Trick" << std::endl;

    std::cout << "Get a deck of cards" << std::endl;
    // get an ordered deck of cards
    auto cards = Trick::GetOrderedCards();

    srand(time(NULL));
    int randomPos = 1 + (rand() % (cards.size() - 1));

    std::cout << "Cut the cards at random position: " << randomPos << std::endl;

    // the picked card is the bottom card of the first cut
    auto pickedCard = cards[randomPos - 1];
    std::cout << "Look at the botton of the first cut: (Secret) " << pickedCard.mName << std::endl;
    auto cutIterator = cards.begin() + randomPos;

    // ask the voluteer to shuffle the first cut
    std::cout << "Shufflle the first cut." << std::endl;
    std::shuffle(cards.begin(), cutIterator, randomGenerator);

    // then ask the volunteer to shuffle the second cut
    std::cout << "Shufflle the second cut." << std::endl;
    std::shuffle(cutIterator, cards.end(), randomGenerator);

    // this is the trick that make it work. We must rotate the first cut and merge shuffle back into
    // the second cut to form the entire deck again. 
    // Later, to find the picked card, we only need to look at rotated cards.
    std::cout << "Rotate the first cut and then merge shuffle into the second cut." << std::endl;

    // rotate the first cut
    std::for_each(cards.begin(), cutIterator, [](auto& card) {
        card.mOrientation = Trick::DOWN;
        });

    // shuffle everything together
    std::shuffle(cards.begin(), cards.end(), randomGenerator);

    std::cout << "Cards are now all shuffled together" << std::endl;
    Trick::PrintCards(cards);

    std::cout << "Find the picked card." << std::endl;
    // find the picked card
    auto foundPickedCard = Trick::FindPickedCard(cards);

    std::cout << "Actual Picked Card: " << pickedCard.mName << std::endl;
    std::cout << " Found Picked Card: " << foundPickedCard.mName << std::endl;
}
