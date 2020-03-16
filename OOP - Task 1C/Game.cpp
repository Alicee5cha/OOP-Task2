#include "Game.h"

Game::Game(const int id,const std::string& name, const std::string& desc, int cost, int rating)
	: name(name), description(desc), cost(cost), ageRating(rating),id(id)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

const int Game::GetCost() const
{
	return cost;
}

const int Game::GetAgeRat() const //Added as it was missing for some reason.
{
	return ageRating;
}

const int Game::GetId()const {
	return id;
}