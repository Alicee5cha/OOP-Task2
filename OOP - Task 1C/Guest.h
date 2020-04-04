#pragma once
#include "User.h"
class Guest :public User
{
public:
	Guest(vector<LibraryItem*>* AdminLibrary);
private:
	
};