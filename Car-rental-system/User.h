#pragma once
#include "Custom Functions.h"

class User
{
private:
	vector<string> makes;
	vector<string> models;
	vector<string> fuel_types;
	vector<int> years;
	vector<int> prices;
public:
	User();
	virtual bool Login(const string& username, const string& password) = 0;
	void ModifyMakes(const string& make);
	void ModifyModels(const string& model);
	void ModifyFuelTypes(const string& fuel_type);
	void ModifyYears(const int& year);
	void ModifyPrices(const int& price);
	bool SaveCarDetails();
	void ShowCarDetails();
};