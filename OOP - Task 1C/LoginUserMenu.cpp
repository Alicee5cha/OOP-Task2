#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	if (!app->IsUserLoggedIn())
	{//TODO: Make a loop for all accounts to be listed.
		for (int i = 0; i < app->accounts[0]->users.length(); i++)
		{
			std::cout << "  " << (i + 1) << ") " << (app->accounts[0]->users[i]->GetUsername()) << '\n';
		}

	}
	
}

bool LoginUserMenu::HandleChoice(char choice)
{

	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->accounts.length())
	{
		BlockingMessage("Not implemented, press return to continue");
		// go to user profile page
	}

	return false;

	switch (choice)
	{
	case '1':
	{
		

	} break;
	}

	return false;
}