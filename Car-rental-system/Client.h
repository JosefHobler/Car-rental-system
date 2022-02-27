#pragma once
#include "Custom Functions.h"

class Client
{
private:
	vector<string> makes;
	vector<string> models;
	vector<string> fuel_types;
	vector<int> years;
	vector<int> prices;
public:
	Client();
	void ModifyMakes(const string& make);
	void ModifyModels(const string& model);
	void ModifyFuelTypes(const string& fuel_type);
	void ModifyYears(const int& year);
	void ModifyPrices(const int& price);
	bool SaveCar();
};