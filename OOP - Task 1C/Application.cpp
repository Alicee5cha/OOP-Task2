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

const bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	for (int i = 0; i < accounts.length(); i++)
	{
		if (accounts[i]->GetEmail()._Equal(email))
			if (accounts[i]->GetPass()._Equal(password))
			{
				currentAccount = accounts[i];
				return true;
			}
	}
	return false;
}

const void Application::LogoutAccount()
{
	LogoutUser();
	currentAccount = nullptr;
}

const bool Application::LoginUser(const std::string& username, const std::string& password)
{
	for (int i=0;i<currentAccount->users.length();i++)
	{
		if (currentAccount->users[i]->GetUsername()._Equal(username))
			if (currentAccount->users[i]->GetPass()._Equal(password))
			{
				currentUser = currentAccount->users[i];
				return true;
			}
	}
	return false;
}

const void Application::LogoutUser()
{
	currentUser = nullptr;
}

const void Application::Load()
{
	ifstream file("data.txt"); //Open file.

	string currentLine;	//Current line to check, usually one of the headers below.
	string headers[5] = {"GAME","ACCOUNT","ACCOUNT-PLAYER","LIBRARY-ITEM","ACCOUNT-ADMIN"};

	getline(file,currentLine);

	do
	{
		if (currentLine == headers[0])//Game
		{
			string gId, gName ,gDesc, gCost, gAgeRat; //Game data strings.

			getline(file,gId);		//Game id.
			getline(file,gName);	//Game name.
			getline(file,gDesc);	//Game description.
			getline(file,gCost);	//Game cost.
			getline(file,gAgeRat);	//Game agerating.

			store.games.addAtEnd(new Game(stoi(gId),gName, gDesc, stoi(gCost), stoi(gAgeRat))); //Create new game.

			getline(file, currentLine); //Get the next header.
		}
		else
			if (currentLine == headers[1])//Account
			{
				//Super account;
				string dateA;		//Account made date
				string emailA;		//Account email
				string passwordA;	//Account password
				getline(file, dateA);
				getline(file, emailA);
				getline(file, passwordA);

				Account* a = new Account(emailA, passwordA, dateA);//Make the account

				getline(file , currentLine); //Get the next header.

				do
				{
					
					if (currentLine == headers[2] || currentLine == headers[4])//Account player or admin
					{
						string dateU;		//User date
						string userU;		//User username
						string passwordU;	//User password
						string credU;		//User credits

						getline(file,dateU);
						getline(file, userU);
						getline(file, passwordU);
						getline(file,credU);


						string idL;			//Library item, game id.
						string dateL;		//Library item, date bought.
						string hoursL;		//Library item, hours played.

						if (currentLine == headers[2]) //Player
						{
							Player* u = new Player(userU, passwordU, dateU,stoi(credU));
							getline(file, currentLine); //Get next header.
							

							do {

								if (currentLine == headers[3])//Purchased game
								{


									getline(file, idL);
									getline(file, dateL);
									getline(file, hoursL);
									Game* cGame;
									for (int i = 0; i < store.games.length(); i++)
									{
										if (store.games[i]->GetId() == stoi(idL))
										{
											cGame = store.games[i];
											LibraryItem* l = new LibraryItem(dateL, cGame);
											u->getLibrary()->addAtEnd(l);
										}
									}

									getline(file, currentLine); //Get next header.
								}
							} while (currentLine == headers[3]);

							a->users.addAtEnd(u); //Add the user to the account.
						}
						else
						{//Admin
							Admin* u = new Admin(userU, passwordU, dateU, stoi(credU));
							getline(file, currentLine);
							do {

								if (currentLine == headers[3])//Purchased game
								{

									getline(file, idL);
									getline(file, dateL);
									getline(file, hoursL);
									Game* cGame;
									for (int i = 0; i < store.games.length(); i++)
									{
										if (store.games[i]->GetId() == stoi(idL))
										{
											cGame = store.games[i];
											LibraryItem* l = new LibraryItem(dateL, cGame);
											u->getLibrary()->addAtEnd(l);
											break;
										}
									}
									
									getline(file, currentLine);
								}
							} while (currentLine == headers[3]);
							a->users.addAtEnd(u);	//After user had been built, add it to the account.
						}		
					}
								
				} while (currentLine == headers[2] || currentLine == headers[4]);

				accounts.addAtEnd(a); //After all parts for the account have been made, add it to the list of accounts.

				getline(file, currentLine);	//Get next header.
			}
	} while(currentLine != "");
	file.close();
}

const void Application::Save()
{
	ofstream file;
	file.open("data.txt");

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

			List<LibraryItem*> li = *cUser->getLibrary();
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

