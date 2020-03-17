#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (!app->IsUserLoggedIn())
	{
		Option('L', "Login");
	}
	else
	{
		Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
		Option('P', "View profile for " + app->GetCurrentUser()->GetUsername());
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
			LoginUserMenu("LOGIN", app);
		}
		else
		{
			app->LogoutUser();
		}
	} break;
	case 'P':
	{
		//proflie page
	} break;
	}

	return false;
}