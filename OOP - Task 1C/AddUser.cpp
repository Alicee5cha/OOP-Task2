#include "AddUser.h"
#include "UserProfile.h"
#include "MainMenu.h"

AddUser::AddUser(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void AddUser::OutputOptions()
{
	std::string username;
	std::string password;
	std::string passwordRep;
	std::string created;
	std::cout << "Enter Username: ";
	getline(std::cin, username);
	std::cout << "\n";

	std::cout << "Enter Password: ";
	getline(std::cin, password);
	std::cout << "\n";

	std::cout << "Repeat Password: ";
	getline(std::cin, passwordRep);
	std::cout << "\n";

	if (((!username.empty()) || (!password.empty())) && (password == passwordRep))
	{
		app->GetCurrentAccount()->users.addAtEnd(new Player(username, password, Utils::getCurrentDate()->getDate(), 0));
	}
	else
	{
		cout << "\n\tEnter a username and password";
		cout << "\n\tPress any key to continue";
		_getwch();//Wait for user input before continuing. This functions return value is ignored on purpose.
	}
}


bool AddUser::HandleChoice(char choice)
{
	return true;
}