#include "LoginAccountMenu.h"
#include "UserProfile.h"
#include "MainMenu.h"

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
			Option(i+1, app->accounts[i]->GetEmail());
		}
	}
}

bool LoginAccountMenu::HandleChoice(char choice)
{

// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	const Account* cAcc = app->accounts[index];

	while ((index >= 0 && index < app->accounts.length())) //greater than 0, less than the number of accounts in the list
	{
		std::string password;

		while ((password.empty())) //if cin is empty, try again
		{
			std::cout << "Enter password for " + cAcc->GetEmail() + ": ";
			getline(std::cin, password);

			while (!(password == cAcc->GetPass())) //if cin password doesnt match stored password, try again
			{
				std::cout << "Wrong password, try again: ";
				getline(std::cin, password);
			}
		}

		std::cout << "Login successful";
		if (app->LoginAccount(cAcc->GetEmail(), password))
		{
			MainMenu("MENU", app);
			//if password is correct go to main menu
			return true;
		}
	}

	return false;
}