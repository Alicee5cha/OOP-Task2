#include "GameDetailsMenu.h"

GameDetailsMenu::GameDetailsMenu(const char* title, Application* app, const Game* game): Menu(title,app), currentGame(game)
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
				Option('P',"Play game!");
				
				if (cUserLib[i]->getTime() < 60)
					printf("Total Time: %.0f", cUserLib[i]->getTime());
				else if (cUserLib[i]->getTime() < 300)
					printf("Total Time: %.1f", ((float)cUserLib[i]->getTime() / 60.0f));
				else
					printf("Total Time: %.0f", (cUserLib[i]->getTime()/60));

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
			
			for (int i = 0; i < cUserLib.size(); i++)
			{
				if (cUserLib[i]->getGame() == currentGame)
				{
					//Play game
					cUserLib[i]->addTime();
					break;
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
	}
	return false;
}