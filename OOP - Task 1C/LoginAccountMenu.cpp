#include "LoginAccountMenu.h"
#include "UserProfile.h"
#include "MainMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccountMenu::OutputOptions()
{
	if (!app->IsUserLoggedIn() && !app->IsAccountLoggedIn())
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
	std::string password;

	//New
	if (index >= 0 && index < app->accounts.length())
	{
		const Account* cAcc = app->accounts[index];
		std::cout << "Enter password for " + app->accounts[index]->GetEmail() + ": ";
		getline(std::cin, password);

		if (app->LoginAccount(cAcc->GetEmail(), password))	
		{
			//if password is correct go back to main menu
			return true;
		}
		else
		{
			cout << "\n\tPassword incorrect. Please try again or select another user.";
			cout << "\n\tPress any key to continue.";
			_getwch();//Wait for user input before continuing. This functions return value is ignored on purpose.
		}
	}
	return false;
}