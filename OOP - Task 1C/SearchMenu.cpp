#include "SearchMenu.h"
#include "StoreMenu.h"
SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void SearchMenu::OutputOptions()
{
	Option('N', "Search By Name");
	Option('P', "Search By Price");
}


bool SearchMenu::HandleChoice(char choice)
{
	
	switch (choice)
		{
		case 'N':
		{
			string name;
			std::cout << "Search By Name: ";
			getline(std::cin, name);

			
			StoreMenu("SEARCH RESULT(S)", app, &name);
		} break;

		case 'P':
		{	
			string priceMin, priceMax;
			std::cout << "Search By Price\n";
			std::cout << "Minimum Price: ";
			getline(std::cin, priceMin);
			std::cout << "Max Price: ";
			getline(std::cin, priceMax);
			if(stoi(priceMin) && stoi(priceMax))
				StoreMenu("SEARCH RESULT(S)", app, stoi(priceMin), stoi(priceMax));
			
			//Store::SearchByPrice(priceMin, priceMax);
		} break;
	}

	return false;
}