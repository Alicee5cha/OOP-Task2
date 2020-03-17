#pragma once

#include <string>
#include "LibraryItem.h"
#include "ListT.h"
class User
{
	public:
		User(const std::string&, const std::string&, const std::string&, int);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPass() const;
		const std::string& GetDateMade() const;
		const int GetCredit()const;
		List<LibraryItem*>* getLibrary();
	private:
		std::string username;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		int credits;
		List<LibraryItem*> library = { };
};