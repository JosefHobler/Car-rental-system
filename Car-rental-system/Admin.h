#pragma once
#include "User.h"

class Admin : public User
{
private:
public:
	bool Login(const std::string& username, const std::string& password) override;
	bool AddCar(const std::string& make, const std::string& model, const std::string& fuel_type, const int& year, const int& price);
	bool Remove(const int& index);
	bool Update(const int& index, const int& choice, const std::string& detail_name);
};
