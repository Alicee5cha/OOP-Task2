#pragma once

#include "Menu.h"


#include <string>
#include <vector>

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:
};