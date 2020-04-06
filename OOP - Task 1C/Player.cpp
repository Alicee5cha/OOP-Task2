#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const std::string& created,  int cred)
	: User(username, password, created, cred)
{
}

Player::~Player()
{
}
