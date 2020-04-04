#include "GuestGameOptions.h"

GuestGameOptions::GuestGameOptions(const string& title, Application* app):Menu(title,app)
{
	Paint();
}

void GuestGameOptions::OutputOptions(){
	User* u = app->GetCurrentUser();
	
	cout << "GAME NAME \tSHARING" << endl;
	for (int i = 0; i < u->GetLibrary()->size(); i++)
	{
		string share = "NO";
		if ((*u->GetLibrary())[i]->isShared())
			share = "YES";
		Option(i + 1, (*u->GetLibrary())[i]->getGame()->GetName() + "\t" + share);
	}
}

bool GuestGameOptions::HandleChoice(char choice)
{
	int i = choice - '1';
	if (i >= 0 && i < app->GetCurrentUser()->GetLibrary()->size())
	{
		LibraryItem* cGame = (*app->GetCurrentUser()->GetLibrary())[i];
		if (cGame->isShared())
			cGame->unShareGame();
		else
			cGame->shareGame();
	}
	return false;
}