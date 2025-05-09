#pragma once

#include <string>
#include <vector>

namespace Trick
{
	enum Orientation
	{
		UP,
		DOWN
	};

	struct Card
	{
		unsigned int mId;
		Orientation mOrientation;
		std::string mName;
	};

	extern const std::vector<std::string> gCardNames;

	std::vector<Card> GetOrderedCards();
	void PrintCards(const std::vector<Card>& cards);

	Card FindPickedCard(const std::vector<Card>& cards);

} // namspace trick
