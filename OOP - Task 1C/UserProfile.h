#pragma once

#include "Menu.h"
#include <string>
#include <vector>

class UserProfile : public Menu
{
public:
	UserProfile(const std::string& title, Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:
};