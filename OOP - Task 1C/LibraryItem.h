#pragma once

#include "Game.h"
#include "date.h"
class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*);
		~LibraryItem();
		const Game* getGame()const;
		const Date* purchasedDate() const;
		const double getTime() const;
	private:
		const Game *game;
		const Date* purchased; 
		double time;
};