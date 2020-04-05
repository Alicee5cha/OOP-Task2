#include "RemoveUser.h"
#include "UserProfile.h"
#include "MainMenu.h"

RemoveUser::RemoveUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void RemoveUser::OutputOptions()
{
	List<User*>* users = app->GetCurrentAccount()->GetUsers();
	int profileCount = 1;
	for (int i = 0; i < users->length(); i++)
	{
		if ((*users)[i]->GetUsername() != app->GetCurrentUser()->GetUsername())
			Option(profileCount++, (*app->GetCurrentAccount()->GetUsers())[i]->GetUsername());
	}
}

bool RemoveUser::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	std::string password;

	if (index >= 0 && index < app->GetCurrentAccount()->GetUsers()->length())
	{
		
		User* cUser = (*app->GetCurrentAccount()->GetUsers())[index];
		if (cUser->GetUsername() == app->GetCurrentUser()->GetUsername())
			if (index != app->GetCurrentAccount()->GetUsers()->length() - 1)
				cUser = (*app->GetCurrentAccount()->GetUsers())[index + 1];
			else
				return false;

		(*app->GetCurrentAccount()->GetUsers()).deleteOne(cUser);

		return true;
	}
	else
	{
		cout << "\n\tChoose a valid user";
		cout << "\n\tPress any key to continue";
		_getwch();//Wait for user input before continuing. This functions return value is ignored on purpose.
	}

	return false;
}