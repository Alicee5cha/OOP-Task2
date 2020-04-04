#pragma once
#include "Menu.h"

class GuestGameOptions : public Menu
{
public:
	GuestGameOptions(const string& title,Application* app);
	void OutputOptions() override;
	bool HandleChoice(char choice) override;
private:

};