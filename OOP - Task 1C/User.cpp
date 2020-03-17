#include "User.h"

User::User(const std::string& username, const std::string& password, const std::string& created, int cred)
	: username(username), password(password), created(created), credits(cred)
{
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
const std::string& User::GetDateMade() const
{
	return created;
}
const int User::GetCredit() const {
	return credits;
}

List<LibraryItem*>* User::getLibrary() {
	return &library;
}