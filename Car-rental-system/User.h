#pragma once

class User
{
protected:
	std::vector<std::string> makes;
	std::vector<std::string> models;
	std::vector<std::string> fuel_types;
	std::vector<int> years;
	std::vector<int> prices;
public:
	User();

	virtual bool Login(const std::string& username, const std::string& password) = 0;
	
	bool SaveCarDetails() const;
	void ShowCars() const; 
	void ChooseCar() const;

	inline int GetCars() { return makes.size(); }
};