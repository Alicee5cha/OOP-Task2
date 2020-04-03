#include "RemoveUser.h"
#include "UserProfile.h"
#include "MainMenu.h"

RemoveUser::RemoveUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void RemoveUser::OutputOptions()
{

}

bool RemoveUser::HandleChoice(char choice)
{
	//return true if option has been selected

	return false;
}