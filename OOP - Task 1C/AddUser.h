#pragma once

#include "Menu.h"

class AddUser : public Menu
{
public:
	AddUser(const std::string& title, Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
};

