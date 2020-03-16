#pragma once

#include <string>
#include "Player.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		List<User*> users = { };
		
		const std::string GetEmail()const;
		const std::string GetPass()const;
		const std::string GetDate()const;

	private:
		std::string email;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};