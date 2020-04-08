#pragma once

#include "Menu.h"


#include <string>
#include <vector>

class StoreMenu : public Menu
{
public:
	StoreMenu(const std::string& title, Application* app);
	StoreMenu(const std::string& title, Application* app, std::string* SearchName);
	StoreMenu(const std::string& title, Application* app, int PriceMin, int PriceMax);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:
	const List<Game*>* SearchResults;
};