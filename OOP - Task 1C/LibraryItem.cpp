#include "LibraryItem.h"
#include "date.h"
LibraryItem::LibraryItem(const std::string& date, Game* game)
	: purchased(new Date(date)), game(game)
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