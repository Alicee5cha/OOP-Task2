#pragma once
#include "Menu.h"

class GameDetailsMenu : public Menu
{
public:
	GameDetailsMenu(const char*,Application*,Game*);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:
	Game* currentGame;
};