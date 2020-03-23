#pragma once

#include <string>
#include "Player.h"
#include "date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		List<User*> users = { };
		
		const std::string GetEmail()const;
		const std::string GetPass()const;
		const Date* GetDate()const;

	private:
		std::string email;
		std::string password;
		Date* created; 
};