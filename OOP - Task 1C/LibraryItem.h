#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*);
		~LibraryItem();
		const Game* getGame()const;
		const std::string purchasedDate() const;
		const double getTime() const;
	private:
		const Game *game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		double time;
};