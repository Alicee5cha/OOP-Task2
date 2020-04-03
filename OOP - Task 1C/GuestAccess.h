#pragma once

#include "Menu.h"

class GuestAccess : Menu
{
public:
	GuestAccess(const std::string& title, Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
};

