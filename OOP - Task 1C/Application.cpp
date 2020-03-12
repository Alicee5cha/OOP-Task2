#include "Application.h"
#include <fstream>
using namespace std;
Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users[0];

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Load()
{
	fstream file;
	string currentLine = " ";
	string headers[5] = {"GAME","ACCOUNT","ACCOUNT-PLAYER","LIBRARY-ITEM","ACCOUNT-ADMIN"};

	file.open("data.txt");
	do
	{
		file >> currentLine;

		if (currentLine == headers[0])//Game
		{
			string gId, gName, gDesc, gCost, gAgeRat;
			file >> gId;
			file >> gName;
			file >> gDesc;
			file >> gCost;
			file >> gAgeRat;
			store.games.addInFront(new Game(gName, gDesc, stoi(gCost), stoi(gAgeRat)));
		}
		else
			if (currentLine == headers[1])//Account
			{
				//Super account
				string date, email, password,credit;
				file >> date;
				file >> email;
				file >> password;
				Account* a = new Account(email, password, date);
				do
				{
					file >> currentLine;
					if (currentLine == headers[2] || currentLine == headers[4])//Account player
					{
						string date, user, pass, cred;
						file >> date;
						file >> user;
						file >> pass;
						file >> cred;

						if (currentLine == headers[2])
							Player* p = new Player(user, pass, date);
						else
							Admin* p = new Admin(user, pass, date);

						do {
							file >> currentLine;

							if (currentLine == headers[3])//Purchased game
							{
								string id, date, hours;
								file >> id;
								file >> date;
								file >> hours;
								LibraryItem* l = new LibraryItem(date, store.games[stoi(id)]);
								p->library.addAtEnd(l);
							}
						} while (currentLine == headers[3]);





						accounts.last()->users.addAtEnd(p);
						
					}
								
				} while (currentLine == headers[2] || currentLine == headers[3] || currentLine == headers[4]);
				accounts.addAtEnd(a);
			}

	} while(currentLine != "");
}
void Application::Save()
{

}

