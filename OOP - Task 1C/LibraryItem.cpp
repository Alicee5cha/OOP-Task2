#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::getGame() const{
	return game;
}

const std::string LibraryItem::purchasedDate() const {
	return purchased;
}

const double LibraryItem::getTime() const {
	return time;
}