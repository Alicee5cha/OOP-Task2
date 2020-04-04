#pragma once
#include "User.h"
class Guest :public User
{
public:
	Guest(vector<LibraryItem*>* AdminLibrary);
	const bool isGuest() const override;
private:
};