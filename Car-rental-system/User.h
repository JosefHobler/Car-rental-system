#pragma once
#include "Custom Functions.h"

class User
{
protected:
	std::vector<std::string> makes;
	std::vector<std::string> models;
	std::vector<std::string> fuel_types;
	std::vector<int> years;
	std::vector<int> prices;
	std::vector<std::string> available;
public:
	User();

	virtual bool Login(const std::string& username, const std::string& password) = 0;
	
	bool ModifyRentDetails(const int& index);
	bool SaveCarDetails() const;
	void CheckCar(const int& index) const;
	void ShowCars() const; 
	void ChooseCar() const;
	bool PrintBill(const std::string& username, const int& days, const int& index) const;
	bool ShowBill(const std::string& username) const;

	bool SetAvailable(const std::string& value, const int& index);
	inline int GetPrice(const int& index) const { return prices[index]; }
	inline int GetCars() const { return makes.size(); }
	inline std::string GetAvailable(const int& index) const { return available[index]; }
};