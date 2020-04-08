#include "StoreMenu.h"
#include "GameDetailsMenu.h"
StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app), SearchResults(app->GetStore().GetGames())
{
	Paint(); // required in constructor
}

StoreMenu::StoreMenu(const std::string& title, Application* app, std::string* SearchName) : Menu(title, app), SearchResults(app->GetStore().SearchByName(*SearchName))
{
	Paint(); // required in constructor
}

StoreMenu::StoreMenu(const std::string& title, Application* app, int PriceMin, int PriceMax) : Menu(title, app), SearchResults(app->GetStore().SearchByPrice(PriceMin, PriceMax))
{
	Paint(); // required in constructor
}
void StoreMenu::OutputOptions()
{
	
	for (int i = 0; i < SearchResults->length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, (*SearchResults)[i]->GetName());
	}
	
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < SearchResults->length())
	{
		GameDetailsMenu(Utils::ToUpperI((*SearchResults)[index]->GetName()).c_str(), app, (*SearchResults)[index]);
	}

	return false;
}
