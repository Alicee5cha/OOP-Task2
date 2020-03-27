#include "LibraryItem.h"
#include "date.h"
LibraryItem::LibraryItem(Date* d, Game* game, int t): purchased(d), game(game),time(t)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::getGame() const{
	return game;
}

const Date* LibraryItem::purchasedDate() const {
	return purchased;
}

const double LibraryItem::getTime() const {
	return time;
}