#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& date, int cred)
	: username(username), password(password), credits(cred)
{
	created = new Date(date);
}

User::~User()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

const std::string& User::GetUsername() const
{
	return username;
}
const std::string& User::GetPass() const
{
	return password;
}
const Date* User::GetDateMade() const
{
	return created;
}
const int User::GetCredit() const 
{
	return credits;
}
int User::AddCredit(int cred)
{
	return credits + cred;
}
const bool User::MinusCredits(const int amount) {
	if (credits >= amount)
	{
		credits -= amount;
		return true;
	}
	else
		return false;
}

vector<LibraryItem*>* User::getLibrary() {
	return &library;
}