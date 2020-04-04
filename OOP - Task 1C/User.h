#pragma once

#include <string>
#include "LibraryItem.h"
#include "ListT.h"
#include "date.h"
#include <vector>

class User
{
	public:
		User(const std::string& u, const std::string& p, const std::string& d, int c);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPass() const;
		const Date* GetDateMade() const;
		const int GetCredit()const;
		const bool MinusCredits(const int amount);
		int AddCredit(int cred);
		virtual const bool isGuest() const;
		virtual const bool isAdmin() const;


		vector<LibraryItem*>* GetLibrary();


	private:
		std::string username;
		std::string password;
		Date* created; 
		int credits;

		vector<LibraryItem*>* library = new vector<LibraryItem*>();


};