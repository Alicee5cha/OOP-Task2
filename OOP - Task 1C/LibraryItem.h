#pragma once

#include "Game.h"
#include "date.h"
class LibraryItem
{
	public:
		LibraryItem(Date* , const Game*,int);
		LibraryItem(Date* d, const Game* game, int t, bool shared);
		~LibraryItem();
		const Game* getGame() const;
		const Date* purchasedDate() const;
		const int getTime() const;
		const void addTime();

		const void shareGame();
		const void unShareGame();
		const bool isShared() const;
	private:
		const Game *game;
		const Date* purchased; 
		int timePlayed;
		bool shareable = false;
};