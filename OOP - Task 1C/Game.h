#pragma once

#include <string>

class Game
{
	public:
		Game(const int id,const std::string&, const std::string&, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		const int GetCost() const;
		const int GetAgeRat() const;
		const int GetId() const;
	private:
		const int id;
		const std::string name;
		const std::string description;
		const int cost;
		const int ageRating;
};