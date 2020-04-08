#include "Store.h"
#include "Utils.h"

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

const List <Game*>* Store::SearchByName(std::string name){
	//TODO: Show a search page giving only the results of games starting with "name";
	List<Game*>* SearchList = new List<Game*>();
	for (int i = 0; i < games.length(); i++)
	{
		if (Utils::StartsWith(games[i]->GetName(), name)) {
			// adding 1 so the display is nicer for the user
			SearchList->addAtEnd(games[i]);
		}
	}
	return SearchList;
}
const List <Game*>* Store::SearchByPrice(const int priceMin,const int priceMax){
	//TODO: Show a search page giving only the results of games whose price falls in the range
	List<Game*>* SearchList = new List<Game*>();
	for (int i = 0; i < games.length(); i++)
	{
		if (games[i]->GetCost() <= priceMax && games[i]->GetCost() >= priceMin) {
			// adding 1 so the display is nicer for the user
			SearchList->addAtEnd(games[i]);
		}
	}
	return SearchList;
}

List<Game*>* Store::GetGames(){
	return &games;
}