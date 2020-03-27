#include "UserProfile.h"
#include "UserProfile.h"

UserProfile::UserProfile(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void UserProfile::OutputOptions()
{
	//TODO: add actual number of credits
	std::cout << "Credits:  + credits";
	Option('I', "Purchase 1 credit");
	Option('O', "Purchase 10 credits");
	Option('P', "Purchase 100 credits");
	std::cout << "\n";
	std::cout << "GAMES";

	//TODO: output games purchased
	//for (int i = 0; i < app-> ; i++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, app->GetStore().games[i]->GetName());
	//}

//	if (user == admin)
//	{
		std::cout << "ADMINISTRATOR";
		Option('A', "Add new user");
		Option('R', "Remove user");
		Option('G', "Guest per-game access");
//	}
}

bool UserProfile::HandleChoice(char choice)
{



	return false;
}