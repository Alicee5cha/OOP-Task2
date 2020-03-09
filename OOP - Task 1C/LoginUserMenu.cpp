#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	if (!app->IsUserLoggedIn())
	{
		for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
		{
			std::cout << "  " << (i + 1) << ") " << app->GetCurrentAccount()->users[i]->GetUsername() << "\n";
		}

	}
	
}

bool LoginUserMenu::HandleChoice(char choice)
{

	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	// after dylan changes to list //app->GetUsers().users.size()
	if (index >= 0 && index < 3)
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