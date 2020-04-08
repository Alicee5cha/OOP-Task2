#pragma once

#include "Menu.h"

class SearchResult : public Menu
{
public:
	SearchResult(const std::string& title, Application* app, const std::string& SearchByName);
	SearchResult(const std::string& title, Application* app, int SearchByPrice[2]);

	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:

};
