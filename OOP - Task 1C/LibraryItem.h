#pragma once

#include "Game.h"
#include "date.h"
class LibraryItem
{
	public:
		LibraryItem(Date* , const Game*,int);
		~LibraryItem();
		const Game* getGame() const;
		const Date* purchasedDate() const;
		const double getTime() const;
	private:
		const Game *game;
		const Date* purchased; 
		int time;
};