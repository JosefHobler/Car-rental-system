#pragma once
#include "Custom Functions.h"
#include "User.h"

class Admin : public User
{
private:
public:
	bool AddCar(const string& make, const string& model, const string& fuel_type, const int& year, const int& price);
	bool Login(const string& username, const string& password);
};
