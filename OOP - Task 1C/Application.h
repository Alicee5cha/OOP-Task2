#pragma once

#include "Account.h"

#include "Admin.h"
#include "Store.h"

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		User* GetCurrentUser() const;

		Store& GetStore();

		const bool LoginAccount(const std::string& email, const std::string& password);
		const void LogoutAccount();
		const bool LoginUser(const std::string& username, const std::string& password);
		const void LogoutUser();
		const void Load();
		const void Save();
		
		List<Account*> accounts = { };
	private:
		Store store;
		Account* currentAccount;
		User* currentUser;
};