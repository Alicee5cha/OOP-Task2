#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= GAME LIBRARY =-\n";
	std::cout << "                    \n";
	Option('S', "Browse Store");

	if (!app->IsUserLoggedIn())
	{
		Option('L', "Login");
		Option('Q', "Quit");
	}
	else
	{
		Option('L', "Logout");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);

	} break;
	case 'L':
	{
		if (!app->IsUserLoggedIn())
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			LoginUserMenu("LOGIN", app);
		}
		else
		{
			app->LogoutUser();
		}
	} break;
	case 'Q':
	{
		exit;
		
	} break;
	}

	return false;
}