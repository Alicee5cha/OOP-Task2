#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const std::string& created,int cred)
	: Player(username, password, created, cred)
{
}

Admin::~Admin()
{
}

const void Admin::addGuestGame(LibraryItem* game)
{
	guestGames.push_back(game);
}
const void Admin::removeGuestGame(LibraryItem* gameToRemove)
{
	for (int i = 0; i < guestGames.size();i++) {
		if (guestGames[i]->getGame() == gameToRemove->getGame())
		{
			guestGames[i] == nullptr;
		}
	}
}

vector<LibraryItem*> Admin::GetGuestGames() const {
	return guestGames;
}