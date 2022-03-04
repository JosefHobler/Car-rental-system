#pragma once
#include "Custom Functions.h"

class User
{
protected:
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
	void ChooseCar() const;

	inline int GetCars() { return makes.size(); }
};