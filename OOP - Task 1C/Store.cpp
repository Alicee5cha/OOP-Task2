#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete games[i];
	}
}

const bool Store::SearchByName(std::string name) const {
	//TODO: Show a search page giving only the results of games starting with "name";
	return false;
}
const bool Store::SearchByPrice(int priceMin, int priceMax) const {
	//TODO: Show a search page giving only the results of games whose price falls in the range
	return false;
}

List<Game*>* Store::GetGames(){
	return &games;
}