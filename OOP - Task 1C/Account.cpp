#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	int len = users.length();
	for (int i = 0; i < len; ++i)
	{
		//delete users[0];
		users.deleteFirst();
	}
}

const std::string Account::GetEmail() const{
	return email;
}
const std::string Account::GetPass() const {
	return password;
}
const std::string Account::GetDate() const {
	return created;
}