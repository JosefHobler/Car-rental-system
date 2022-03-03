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
	
	bool SaveCarDetails() const;
	void ShowCars() const; 

	inline void ModifyMakes(const string& make) { makes.push_back(make); }
	inline void ModifyModels(const string& model) { models.push_back(model); }
	inline void ModifyFuelTypes(const string& fuel_type) { fuel_types.push_back(fuel_type); }
	inline void ModifyYears(const int& year) { years.push_back(year); }
	inline void ModifyPrices(const int& price) { prices.push_back(price); }
};