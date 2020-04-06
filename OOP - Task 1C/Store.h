#pragma once

#include "Game.h"
#include "ListT.h"
class Store
{
	public:
		Store();
		~Store();

		const bool SearchByName(std::string name) const;
		const bool SearchByPrice(int priceMin, int priceMax) const;
		List<Game*>* GetGames();
	private:
		List<Game*> games = { };
};