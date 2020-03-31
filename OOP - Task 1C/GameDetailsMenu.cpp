#include "GameDetailsMenu.h"

GameDetailsMenu::GameDetailsMenu(const char* title, Application* app, Game* game):Menu(title,app),currentGame(game)
{
	Paint();//Required here
}

void GameDetailsMenu::OutputOptions()
{
	cout << "Name: " << Utils::ToUpperR(currentGame->GetName()) << endl;
	cout << "Details: "<<currentGame->GetDescription() << endl;
	cout << "Age Rating: " << currentGame->GetAgeRat() << endl << endl;
	if (app->IsUserLoggedIn())
	{
		vector<LibraryItem*> cUserLib = *(app->GetCurrentUser()->getLibrary());
		int i;
		for (i = 0; i < cUserLib.size(); i++)
		{
			if (cUserLib[i]->getGame() == currentGame)
			{
				cout << "Game purchased on: " << cUserLib[i]->purchasedDate() << endl;
				break;
			}
		}

		if (cUserLib.size() == i)
		{
			Option('P', "Purchase game: " + to_string(currentGame->GetCost()) + " credits");
		}

		
	}
	else
	{
		cout << "Price: " << to_string(currentGame->GetCost()) << " credits";
	}
}

bool GameDetailsMenu::HandleChoice(char choice)
{
	if (choice == 'P')
	{
		if (app->IsUserLoggedIn())
		{
			vector<LibraryItem*> cUserLib = *(app->GetCurrentUser()->getLibrary());
			int i;
			for (i = 0; i < cUserLib.size(); i++)
			{
				if (cUserLib[i]->getGame() == currentGame)
				{
					break;
				}

			}
			if (cUserLib.size() == i)
			{
				//Purchase game
				if (app->GetCurrentUser()->MinusCredits(currentGame->GetCost()))
				{
					app->GetCurrentUser()->getLibrary()->push_back(new LibraryItem(Utils::getCurrentDate(), currentGame, 0));
					return true;
				}
			}
		}
	}
	return false;
}