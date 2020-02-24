#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	Option('S', "Browse Store");
	Option('L', "Login");
}

bool LoginUserMenu::HandleChoice(char choice)
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

			//app->LoginUser();

		}
	} break;
	}

	return false;
}