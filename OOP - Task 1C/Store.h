#pragma once

#include "Game.h"
#include "ListT.h"
class Store
{
	public:
		Store();
		~Store();
		List<Game*> games = { };

		const bool SearchByName(std::string name) const;
		const bool SearchByPrice(int priceMin, int priceMax) const;

	private:
};