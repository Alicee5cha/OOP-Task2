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
		
		vector<LibraryItem*>* cUserLib = app->GetCurrentUser()->GetLibrary();

		int i;
		for (i = 0; i < cUserLib->size(); i++)
		{
			if ((*cUserLib)[i]->getGame() == currentGame)
			{
				cout << "Game purchased on: " << (*cUserLib)[i]->purchasedDate() << endl;
				Option('P',"Play game!");
				
				std::cout << "Total Time: " + Utils::ReturnPlayTime((*cUserLib)[i]->getTime()) << endl;

				break;
			}
		}

		if (cUserLib->size() == i && !app->GetCurrentUser()->isGuest())
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
			vector<LibraryItem*> cUserLib = *(app->GetCurrentUser()->GetLibrary());
			
			for (int i = 0; i < cUserLib.size(); i++)
			{
				if (cUserLib[i]->getGame() == currentGame)
				{
					//Play game
					cUserLib[i]->addTime();
					break;
				}
				if (cUserLib.size()-1 == i && !app->GetCurrentUser()->isGuest())
				{
					//Purchase game
					if (app->GetCurrentUser()->MinusCredits(currentGame->GetCost()))
					{
						app->GetCurrentUser()->GetLibrary()->push_back(new LibraryItem(new Date(), currentGame, 0));
					}
				}
			}
			
		}
	}
	return false;
}