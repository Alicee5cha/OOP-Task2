#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccountMenu::OutputOptions()
{
	if (!app->IsUserLoggedIn())
	{
		for (int i = 0; i < app->accounts.length(); i++)
		{
			std::cout << "  " << (i + 1) << ") " << (app->accounts[i]->GetEmail()) << '\n';
		}
	}
}

bool LoginAccountMenu::HandleChoice(char choice)
{

	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->accounts.length())
	{
		const Account* cAcc = app->accounts[index];

		std::cout << "Enter password for " + cAcc->GetEmail() + ": ";
		std::string pass;
		cin >> pass;
		if (app->LoginAccount(cAcc->GetEmail(), pass))
			//TODO: go to user profile page	
			;
	}
	return false;
}