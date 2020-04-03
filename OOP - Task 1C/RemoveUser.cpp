#include "RemoveUser.h"
#include "UserProfile.h"
#include "MainMenu.h"

RemoveUser::RemoveUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void RemoveUser::OutputOptions()
{
	for (int i = 0; i < app->GetCurrentAccount()->users.length(); i++)
	{
		Option(i + 1, app->GetCurrentAccount()->users[i]->GetUsername());
	}
}

bool RemoveUser::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	std::string password;

	if (index >= 0 && index < app->GetCurrentAccount()->users.length())
	{
		User* cUser = app->GetCurrentAccount()->users[index];
		app->GetCurrentAccount()->users.deleteOne(cUser);

			return true;
	}

	return false;
}