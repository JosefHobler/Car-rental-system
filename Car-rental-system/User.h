#pragma once

class User
{
protected:
	std::vector<std::string> make;
	std::vector<std::string> model;
	std::vector<std::string> fuel_type;
	std::vector<std::string> seats;
	std::vector<int> horse_power;
	std::vector<int> years;
	std::vector<int> prices;
	std::vector<bool> available;

	std::vector<std::string> names_of_borrowers;
	std::vector<std::string> lent_cars_makes;
	std::vector<std::string> lent_cars_models;
	std::vector<int> lent_cars_prices;
	std::vector<int> lent_cars_days;
	std::multimap<std::string, std::vector<std::string>> map;
public:
	User();

	virtual bool Login(const std::string& username, const std::string& password) = 0;
	
	bool Return(const int& index);
	bool ModifyRentDetails(const int& index);
	bool SaveCarDetails() const;
	void CheckCar(const int& index) const;
	void ShowCars() const; 
	bool PrintBill(const std::string& username, const int& days, const int& index);
	bool ShowBill(const std::string& username) const;
	bool ReadCars(const std::string& username);
	void ChooseCar() const;
	void ChooseLentCar() const;
	bool SetAvailable(const bool& value, const int& index);
	bool Delete(const std::string& username, const int& index);
	bool ModifyListOfBorrowers();

	inline int GetPrice(const int& index) const { return prices[index]; }
	inline int GetCars() const { return make.size(); }
	inline int GetLentCars() const { return lent_cars_makes.size(); }
	inline bool GetAvailable(const int& index) const { return available[index]; }
	inline int GetBorrowersSize() const { return names_of_borrowers.size(); }
	inline std::string GetBorrowerAt(const int& index) const { return names_of_borrowers[index]; }
	inline int ModelsAt(const std::string model) const { return std::find(model.begin(), model.end(), model) - model.begin(); }
	inline std::string GetLentCarModel(const int index) const { return lent_cars_models[index]; }
};