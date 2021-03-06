#include "MainMenu.h"
#include "SearchMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('R', "Browse Store");
	Option('S', "Search Store");

	if (!app->IsAccountLoggedIn())
	{
		Option('A', "Login Account ");
	}
	else
	{
		Option('A', "Logout Account " + app->GetCurrentAccount()->GetEmail());

		if (!app->IsUserLoggedIn())
		{
			Option('L', "Login User");
			Option('G', "Login Guest User");
		}
		else
		{
			
			if (app->GetCurrentUser()->isGuest())
			{
				Option('G', "Logout of Guest");
				Option('P', "View Guest profile.");
			}
			else
			{
				Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
				Option('P', "View profile for " + app->GetCurrentUser()->GetUsername());
			}
		}
	}
	
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'R':
		{
			StoreMenu("STORE", app);

		} break;

		case 'S':
		{
			SearchMenu("SEARCH MENU", app);

		} break;
		case 'A':
		{
			if (!app->IsAccountLoggedIn())
			{
				LoginAccountMenu("ACCOUNT LOGIN", app);
			}
			else
			{
				app->LogoutAccount();//This logs out user before logging out account.
			}
		}break;

		case 'L':
		{
			if (!app->IsUserLoggedIn() && app->IsAccountLoggedIn())
			{
				LoginUserMenu("USER LOGIN", app);
			}
			else
			{
				app->LogoutUser();//'L' Defaults to this if no account is logged in. AKA nothing happens when no account logged in. 
			}
		} break;

		case 'G':
		{
			if (!app->IsUserLoggedIn())
			{
				if (app->IsAccountLoggedIn())
					app->LoginGuest();
			}
			else
				if (app->GetCurrentUser()->isGuest())
					app->LogoutUser();
			break;
		}

		case 'P':
		{
			UserProfile(Utils::ToUpperI(app->GetCurrentUser()->GetUsername()) + "'S PROFILE", app);
			//go to proflie page
		} break;
	}

	return false;
}