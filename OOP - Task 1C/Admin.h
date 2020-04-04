#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const std::string&, const std::string&, const std::string&,int);
		~Admin();
		const bool isAdmin() const override;
private:
		
};