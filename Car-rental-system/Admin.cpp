#include "Admin.h"

bool Admin::AddCar(const string& make, const string& model, const string& fuel_type, const int& year, const int& price)
{
	ModifyMakes(make);
	ModifyModels(model);
	ModifyFuelTypes(fuel_type);
	ModifyYears(year);
	ModifyPrices(price);
	if (SaveCarDetails())
	{
		return true;
	}
	return false;
}

bool Admin::Login(const string& username, const string& password)
{
	string right_username, right_password;
	ifstream admin("Admin.txt");
	if (admin.is_open())
	{
		getline(admin, right_username);
		getline(admin, right_password);
		admin.close();
	}
	else
	{
		throw std::ios::failure("Error Opening A File!\n");
	}
	return right_username == username && right_password == password;
}
