#pragma once

#include <string>
#include "LibraryItem.h"
#include "ListT.h"
#include "date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const std::string&, int);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPass() const;
		const Date* GetDateMade() const;
		const int GetCredit()const;
		List<LibraryItem*>* getLibrary();
	private:
		std::string username;
		std::string password;
		Date* created; 
		int credits;
		List<LibraryItem*> library = { };
};