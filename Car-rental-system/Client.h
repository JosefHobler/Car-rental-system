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
	inline void ModifyMakes(const string& make);
	inline void ModifyModels(const string& model);
	inline void ModifyFuelTypes(const string& fuel_type);
	inline void ModifyYears(const int& year);
	inline void ModifyPrices(const int& price);
};