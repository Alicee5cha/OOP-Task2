#include "LibraryItem.h"
#include "date.h"
#include"Utils.h"
LibraryItem::LibraryItem(Date* d, const Game* game, int t): purchased(d), game(game),timePlayed(t)
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

const int LibraryItem::getTime() const {
	return timePlayed;
}

const void LibraryItem::addTime() {
	timePlayed += Utils::randomInt(10, 60);
}