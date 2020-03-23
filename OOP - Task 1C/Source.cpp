#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"

void createHardcodedTestData(Application* app)
{
	
}


void main()
{
	Application* app = new Application();
	//createHardcodedTestData(app);

	app->Load();

	MainMenu("MENU", app);

	app->Save();
}