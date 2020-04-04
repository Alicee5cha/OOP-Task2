#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& date): email(email), password(password)
{
	created = new Date(date);
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

List<User*>* Account::GetUsers(){
	return &users;
}

const std::string Account::GetEmail() const{
	return email;
}
const std::string Account::GetPass() const {
	return password;
}
const Date* Account::GetDate() const {
	return created;
}