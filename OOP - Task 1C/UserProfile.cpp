#include "UserProfile.h"
#include "GameDetailsMenu.h"
#include "AddUser.h"
#include "RemoveUser.h"
#include <algorithm>
UserProfile::UserProfile(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


bool sortName(LibraryItem* a, LibraryItem* b) {
	return (a->getGame()->GetName().compare(b->getGame()->GetName())) < 0;
}

bool sortDate(LibraryItem* a, LibraryItem* b) {
	//Years
	if (a->purchasedDate()->getYear() < b->purchasedDate()->getYear())
		return true;
	else
		if (a->purchasedDate()->getYear() == b->purchasedDate()->getYear()) {
			//Months
			if (a->purchasedDate()->getMonth() < b->purchasedDate()->getMonth())
				return true;
			else
				if (a->purchasedDate()->getMonth() == b->purchasedDate()->getMonth()){
					//Days
					if (a->purchasedDate()->getDay() < b->purchasedDate()->getDay())
						return true;
				}
		}
	return false;
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
	Option('N', "Sort library by name");
	Option('D', "Sort library by date");
	std::cout << "\n";

	for (int i = 0; i < app->GetCurrentUser()->getLibrary()->size(); i++)
	{
		string gameName = app->GetCurrentUser()->getLibrary()->at(i)->getGame()->GetName();
		// adding 1 so the display is nicer for the user
		Option(i + 1, gameName);
	}

	User* cUser = app->GetCurrentUser();

	if (typeid(*cUser) == typeid(Admin))
	{
		std::cout << "\n";
		std::cout << "ADMINISTRATOR";
		std::cout << "\n";
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
		const Game* gameObj = app->GetCurrentUser()->getLibrary()->at(index)->getGame();
		GameDetailsMenu(Utils::ToUpperI(app->GetCurrentUser()->getLibrary()->at(index)->getGame()->GetName()).c_str(), app, gameObj);
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
			AddUser("ADD A NEW USER", app);
			break;
		}
		case 'R':
		{
			RemoveUser("REMOVE A USER", app);
			break;
		}
		case 'G':
		{
			break;
		}
		case 'E':
		{
			//editguest menu???
			//EditGuest("EDIT GUEST GAMES", app);
			break;
		}
		case 'N':
		{
			sort(app->GetCurrentUser()->getLibrary()->begin(), app->GetCurrentUser()->getLibrary()->end(),sortName);
			break;
		}
		case 'D':
		{
			sort(app->GetCurrentUser()->getLibrary()->begin(), app->GetCurrentUser()->getLibrary()->end(),sortDate);
			break;
		}
	}

	return false;
}
