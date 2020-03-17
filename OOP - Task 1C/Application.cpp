#include "Application.h"
#include <fstream>
#include <stdlib.h>
using namespace std;
Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	int len = accounts.length();
	for (int i = 0; i < len; ++i)
	{
		delete accounts[0];
		accounts.deleteFirst();
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
	ifstream file;
	file.open("data.txt");
	string currentLine;
	string headers[5] = {"GAME","ACCOUNT","ACCOUNT-PLAYER","LIBRARY-ITEM","ACCOUNT-ADMIN"};

	getline(file,currentLine);

	do
	{
		if (currentLine == headers[0])//Game
		{
			string gId;
			string gName;
			string gDesc;
			string gCost;
			string gAgeRat;

			getline(file,gId);
			getline(file,gName);
			getline(file,gDesc);
			getline(file,gCost);
			getline(file,gAgeRat);

			store.games.addAtEnd(new Game(stoi(gId),gName, gDesc, stoi(gCost), stoi(gAgeRat)));

			getline(file, currentLine);
		}
		else
			if (currentLine == headers[1])//Account
			{
				//Super account;
				string dateA;
				string email;
				string password;
				getline(file, dateA);
				getline(file, email);
				getline(file, password);
				Account* a = new Account(email, password, dateA);
				getline(file , currentLine);

				do
				{
					
					if (currentLine == headers[2] || currentLine == headers[4])//Account player or admin
					{
						string dateU;
						string userU;
						string passwordU;
						string credU;

						getline(file,dateU);
						getline(file, userU);
						getline(file, passwordU);
						getline(file,credU);


						string id;
						string date;
						string hours;

						if (currentLine == headers[2]) //Player
						{
							Player* p = new Player(userU, passwordU, dateU,stoi(credU));
							getline(file, currentLine);
							

							do {

								if (currentLine == headers[3])//Purchased game
								{


									getline(file, id);
									getline(file, date);
									getline(file, hours);
									Game* cGame;
									for (int i = 0; i < store.games.length(); i++)
									{
										if (store.games[i]->GetId() == stoi(id))
										{
											cGame = store.games[i];
											LibraryItem* l = new LibraryItem(date, cGame);
											p->getLibrary().addAtEnd(l);
										}
									}

									getline(file, currentLine);
								}
							} while (currentLine == headers[3]);
							a->users.addAtEnd(p);
						}
						else
						{//Admin
							Admin* p = new Admin(userU, passwordU, dateU, stoi(credU));
							getline(file, currentLine);
							do {

								if (currentLine == headers[3])//Purchased game
								{

									getline(file, id);
									getline(file, date);
									getline(file, hours);
									Game* cGame = nullptr;
									for (int i = 0; i < store.games.length(); i++)
									{
										if (store.games[i]->GetId() == stoi(id))
										{
											cGame = store.games[i];
											LibraryItem* l = new LibraryItem(date, cGame);
											List<LibraryItem*> lib = p->getLibrary();
											lib.addAtEnd(l);
											break;
										}
									}
									
									getline(file, currentLine);
								}
							} while (currentLine == headers[3]);
							List<User*> newAUsers = a->users;
							newAUsers.addAtEnd(p);
						}		
					}
								
				} while (currentLine == headers[2] || currentLine == headers[4]);
				accounts.addAtEnd(a);
				getline(file, currentLine);
			}
	} while(currentLine != "");
	file.close();
}
void Application::Save()
{
	ofstream file;
	file.open("tempData.txt");//TODO: Fix library item saving not working.

	for (int i =0;i<store.games.length();i++)
	{
		Game* currentGame = store.games[i];
		file << "GAME" << endl;
		file << i << endl;
		file << currentGame->GetName() << endl;
		file << currentGame->GetDescription() << endl;
		file << currentGame->GetCost() << endl;
		file << currentGame->GetAgeRat() << endl;
	}

	for (int i = 0; i < accounts.length(); i++)
	{
		Account* cAcc = accounts[i];
		file << "ACCOUNT" << endl;
		file << cAcc->GetDate() << endl;
		file << cAcc->GetEmail() << endl;
		file << cAcc->GetPass() << endl;

		for (int j = 0; j < cAcc->users.length(); j++)
		{
			User* cUser = cAcc->users[j];
			if (typeid(cUser) == typeid(Admin*))
			{
				file << "ACCOUNT-ADMIN" << endl;
			}
			else
			{
				file << "ACCOUNT-PLAYER" << endl;
			}
			
			file << cUser->GetDateMade() << endl;
			file << cUser->GetUsername() << endl;
			file << cUser->GetPass() << endl;
			file << cUser->GetCredit() << endl;

			List<LibraryItem*> li = cUser->getLibrary();
			for (int lItem = 0; lItem < li.length(); lItem++)
			{
				file << "LIBRARY-ITEM" << endl;
				file << li[lItem]->getGame()->GetId() << endl;
				file << li[lItem]->purchasedDate() << endl;
				file << li[lItem]->getTime() << endl;
			}
		}

	}
}

