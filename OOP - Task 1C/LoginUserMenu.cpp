#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{
	system("CLS");
	std::cout << "                    \n";
	std::cout << "  -= LOGIN =-       \n";
	std::cout << "                    \n";
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
			for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
			{
				std::cout << "  " << (i + 1) << ") " << app->GetCurrentAccount()->users[i]->GetUsername() << "\n";
			}

			std::cout << "                    \n";
			std::cout << "  B) Back           \n";
			std::cout << "                    \n";
			std::cout << "                    \n";
			std::cout << "  >>> ";


		}
	} break;
	}

	return false;
}