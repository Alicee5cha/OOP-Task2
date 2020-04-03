#pragma once

#include "Menu.h"

class RemoveUser : Menu
{
public:
	RemoveUser(const std::string& title, Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
};



