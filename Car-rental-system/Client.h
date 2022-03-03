#pragma once
#include "Custom Functions.h"
#include "User.h"

class Client : public User
{	
public:
	bool Login(const string& username, const string& password) override;

	void Register(const string& username, const string& password) const;
};