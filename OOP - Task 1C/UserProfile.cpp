#include "UserProfile.h"
#include "GameDetailsMenu.h"

UserProfile::UserProfile(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void UserProfile::OutputOptions()
{
	std::string cred = to_string(app->GetCurrentUser()->GetCredit());
	std::cout << "Credits:" + cred + "\n\n";

	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	std::cout << "\n";
	std::cout << "GAMES";
	std::cout << "\n";

	//TODO: output games purchased
	for (int i = 0; i < app->GetCurrentUser()->getLibrary()->size(); i++)
	{
		string gameName = app->GetCurrentUser()->getLibrary()->at(i)->getGame()->GetName();
		// adding 1 so the display is nicer for the user
		Option(i + 1, gameName);
	}

	if (typeid(app->GetCurrentUser) == typeid(Admin*))
	{
		std::cout << "ADMINISTRATOR";
		Option('A', "Add new user");
		Option('R', "Remove user");
		Option('G', "Guest per-game access");
	}
}

bool UserProfile::HandleChoice(char choice)
{
// since we are using numbers here we shift the char down by '1'
// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->getLibrary()->size())
	{
		//TODO: game details menu, game should be const but is not when called from the GetLibrary function
		//Game* gameObj = app->GetCurrentUser()->getLibrary()->at(index)->getGame();
		//GameDetailsMenu(Utils::ToUpperI(app->GetCurrentUser()->getLibrary()->at(index)->getGame()->GetName()).c_str(), app, gameObj);
			return true;
	}

	switch (choice)
	{
	case 'I':
	{
		app->GetCurrentUser()->AddCredit(1);
		break;
	}
	case 'O':
	{
		app->GetCurrentUser()->AddCredit(10);
		break;
	}
	case 'P':
	{
		app->GetCurrentUser()->AddCredit(100);
		break;
	}
	case 'A':
	{
		break;
	}
	case 'R':
	{
		break;
	}
	case 'G':
	{
		break;
	}
	}

	return false;
}