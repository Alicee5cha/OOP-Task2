#include "AddUser.h"
#include "UserProfile.h"
#include "MainMenu.h"

AddUser::AddUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void AddUser::OutputOptions()
{

}

bool AddUser::HandleChoice(char choice)
{
//return true if option has been selected

	return false;
}