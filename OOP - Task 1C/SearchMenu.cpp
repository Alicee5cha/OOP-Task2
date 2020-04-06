#include "SearchMenu.h"
#include "GameDetailsMenu.h"
SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void SearchMenu::OutputOptions()
{

	for (int i = 0; i < app->GetStore().games.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, app->GetStore().games[i]->GetName());
	}
	Line();
	Line();
	Option('N', "Search By Name");
	Option('P', "Search By Price");
}


bool SearchMenu::HandleChoice(char choice)
{
	string name;
	int priceMin, priceMax;
	switch (choice)
		{
		case 'N':
		{
			std::cout << "Search By Name: ";
			std::cin >> name;

			for (int i = 0; i < app->GetStore().games.length(); i++)
			{
				Option(i + 1,app->GetStore().games[i]->GetName());
			}
			//Store::SearchByName(name);
		} break;

		case 'P':
		{
			std::cout << "Search By Price\n";
			std::cout << "Minimum Price: ";
			std::cin >> priceMin;
			std::cout << "Max Price: ";
			std::cin >> priceMax;
			for (int i = 0; i < app->GetStore().games.length(); i++)
			{
				if (priceMin < app->GetStore().games[i]->GetCost() > priceMax)
				{
					Option(i + 1, app->GetStore().games[i]->GetName()); 
				}
			}
			//Store::SearchByPrice(priceMin, priceMax);
		} break;
	}

	return false;
}