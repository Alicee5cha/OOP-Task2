#include "GameDetailsMenu.h"

GameDetailsMenu::GameDetailsMenu(const char* title, Application* app,Game* game):Menu(title,app),currentGame(game)
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
		List<LibraryItem*>* cUserLib = (app->GetCurrentUser()->getLibrary());
		for (int i = 0; i < cUserLib->length(); i++)
		{
			List<LibraryItem*> l = (cUserLib[i]);
			if (l[i]->getGame() == currentGame)
			{
				cout << "Game purchased on: " << l[i]->purchasedDate() << endl;
				break;
			}

			if (cUserLib->length() == i)
			{
				Option('P', "Purchase game: " + to_string(currentGame->GetCost()) +" credits");	
			}
		}

		
	}
}

bool GameDetailsMenu::HandleChoice(char choice)
{
	if (choice == 'P')
	{
		if (app->IsUserLoggedIn())
		{
			List<LibraryItem*>* cUserLib = (app->GetCurrentUser()->getLibrary());
			for (int i = 0; i < cUserLib->length(); i++)
			{
				List<LibraryItem*> l = (cUserLib[i]);
				if (l[i]->getGame() == currentGame)
				{
					break;
				}

				if (cUserLib->length() == i)
				{
					//Purchase game
					return app->GetCurrentUser()->MinusCredits(currentGame->GetCost());
					app->GetCurrentUser()->getLibrary()->addAtEnd(new LibraryItem(Utils::getCurrentDate(),currentGame,0));
				}
			}


		}
	}
	return false;
}