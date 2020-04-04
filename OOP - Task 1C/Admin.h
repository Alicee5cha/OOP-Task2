#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const std::string&, const std::string&, const std::string&,int);
		~Admin();

		const void addGuestGame(LibraryItem*);
		const void removeGuestGame(LibraryItem*);

		vector<LibraryItem*> GetGuestGames() const;
private:
	vector<LibraryItem*> guestGames = {};
		
};