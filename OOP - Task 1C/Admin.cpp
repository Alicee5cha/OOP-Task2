#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const std::string& created,int cred)
	: Player(username, password, created, cred)
{
}

Admin::~Admin()
{
}

const bool Admin::isAdmin()const{
	return true;
}