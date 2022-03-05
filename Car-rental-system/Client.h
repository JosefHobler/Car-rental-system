#pragma once
#include "User.h"

class Client : public User
{	
public:
	bool Login(const std::string& username, const std::string& password) override;

	bool Register(const std::string& username, const std::string& password) const;
};