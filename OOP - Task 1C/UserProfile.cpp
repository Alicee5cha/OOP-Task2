#include "UserProfile.h"
#include "MainMenu.h"

UserProfile::UserProfile(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void UserProfile::OutputOptions()
{
	//TODO: add actual number of credits
	std::cout << "Credits:" + app->GetCurrentUser()->GetCredit();
	
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	std::cout << "\n";
	std::cout << "GAMES";

	//TODO: output games purchased
	//for (int i = 0; i < app->GetCurrentUser()->getLibrary().length(); i++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, app->GetCurrentUser()->getLibrary().);
	//}


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
		//app->GetCurrentUser()->GetCredit() + 1;
		break;
	}
	case 'O':
	{
		//app->GetCurrentUser()->GetCredit() + 10;
		break;
	}
	case 'P':
	{
		//app->GetCurrentUser()->GetCredit() + 100;
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