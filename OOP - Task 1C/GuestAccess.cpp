#include "GuestAccess.h"
#include "UserProfile.h"
#include "MainMenu.h"

GuestAccess::GuestAccess(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void GuestAccess::OutputOptions()
{

}

bool GuestAccess::HandleChoice(char choice)
{
	//return true if option has been selected

	return false;
}