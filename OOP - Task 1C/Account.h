#pragma once

#include <string>
#include "Player.h"
#include "date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		List<User*>* GetUsers();
		
		const std::string GetEmail()const;
		const std::string GetPass()const;
		const Date* GetDate()const;

	private:
		List<User*> users = { };
		std::string email;
		std::string password;
		Date* created; 
};