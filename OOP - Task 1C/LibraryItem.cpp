#include "LibraryItem.h"
#include "date.h"
#include"Utils.h"
LibraryItem::LibraryItem(Date* d, const Game* game, int t): purchased(d), game(game),timePlayed(t)
{
}
LibraryItem::LibraryItem(Date* d, const Game* game, int t,bool shared) : purchased(d), game(game), timePlayed(t),shareable(shared)
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

const void LibraryItem::unShareGame() {
	shareable = false;
}

const void LibraryItem::shareGame() {
	shareable = true;
}

const bool LibraryItem::isShared() const {
	return shareable;
}