#pragma once

#include "Game.h"
#include "ListT.h"
class Store
{
	public:
		Store();
		~Store();

		const List<Game*>* SearchByName(std::string name);
		const List<Game*>* SearchByPrice(int priceMin, int priceMax);
		List<Game*>* GetGames();
	private:
		List<Game*> games = { };
};