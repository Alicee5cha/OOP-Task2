#include "UserProfile.h"

UserProfile::UserProfile(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void UserProfile::OutputOptions()
{
	//TODO: add actual number of credits
	string cred = "";
	cred = to_string(app->GetCurrentUser()->GetCredit());
	std::cout << "Credits:" + cred + "\n";

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