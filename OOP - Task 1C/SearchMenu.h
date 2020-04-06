#pragma once

#include "Menu.h"

class SearchMenu : public Menu
{
public:
	SearchMenu(const std::string& title, Application* app);

	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:

};

