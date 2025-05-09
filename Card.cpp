#include "Card.h"

#include <iostream>
#include <iomanip>

namespace Trick
{
	const std::vector<std::string> gCardNames =
	{
		"  Ace of Spades",
		"  Two of Spades",
		"Three of Spades",
		" Four of Spades",
		" Five of Spades",
		"  Six of Spades",
		"Seven of Spades",
		"Eight of Spades",
		" Nine of Spades",
		"  Ten of Spades",
		" Jack of Spades",
		"Queen of Spades",
		" King of Spades",

		"  Ace of Hearts",
		"  Two of Hearts",
		"Three of Hearts",
		" Four of Hearts",
		" Five of Hearts",
		"  Six of Hearts",
		"Seven of Hearts",
		"Eight of Hearts",
		" Nine of Hearts",
		"  Ten of Hearts",
		" Jack of Hearts",
		"Queen of Hearts",
		" King of Hearts",

		"  Ace of Clubs",
		"  Two of Clubs",
		"Three of Clubs",
		" Four of Clubs",
		" Five of Clubs",
		"  Six of Clubs",
		"Seven of Clubs",
		"Eight of Clubs",
		" Nine of Clubs",
		"  Ten of Clubs",
		" Jack of Clubs",
		"Queen of Clubs",
		" King of Clubs",

		"  Ace of Diamonds",
		"  Two of Diamonds",
		"Three of Diamonds",
		" Four of Diamonds",
		" Five of Diamonds",
		"  Six of Diamonds",
		"Seven of Diamonds",
		"Eight of Diamonds",
		" Nine of Diamonds",
		"  Ten of Diamonds",
		" Jack of Diamonds",
		"Queen of Diamonds",
		" King of Diamonds",
	};

	std::vector<Card> GetOrderedCards()
	{
		std::vector<Card> cards;

		for (unsigned int i = 0; i < gCardNames.size(); ++i)
		{
			cards.push_back({ i, UP, gCardNames[i]});
		}

		// return vector by NRVO (Named Return Value Optimization)
		return cards;
	}

	void PrintCards(const std::vector<Card>& cards)
	{
		std::cout << "------------------------" << std::endl;
		for (const auto& card : cards)
		{
			std::cout << std::setw(2) << std::setfill('0') << card.mId << (card.mOrientation == UP ? "   UP" : " DOWN") << " " << card.mName << std:: endl;
		}
		std::cout << "------------------------" << std::endl;
	}

	Card FindPickedCard(const std::vector<Card>& cards)
	{
		// now, finding the picked card is easy because of the trick
		// that we cut the deck, looked at the bottom of the first cut as the picked card
		// then shuffle both cuts, rotate the first cut and merge it back into the deck.
		// the picked card will be the largest id of all the rotated cards
		
		// init it to be the first position
		unsigned int pickedCardId = 0;
		Card pickedCard = cards[0];

		// iterate the cards, looking at only the rotated cards, and the biggest id will be it
		for (const auto& card : cards)
		{
			if (card.mOrientation == UP)
			{
				continue;
			}

			if (card.mId > pickedCardId)
			{
				pickedCardId = card.mId;
				pickedCard = card;
			}
		}

		return pickedCard;
	}

} // namespace Trick
