#include "Admin.h"

bool Admin::Login(const std::string& username, const std::string& password)
{
	std::string right_username, right_password;
	try
	{
		std::ifstream admin("Admin.txt");
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
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return right_username == username && right_password == password;
}

bool Admin::AddCar(const std::string& make, const std::string& model, const std::string& fuel_type, const int& year, const int& price)
{
	makes.push_back(make);
	models.push_back(model);
	fuel_types.push_back(fuel_type);
	years.push_back(year);
	prices.push_back(price);
	available.push_back("Available");
	return SaveCarDetails();
}

bool Admin::Remove(const int& index)
{
	std::swap(makes[index], makes[makes.size() - 1]);
	std::swap(models[index], models[models.size() - 1]);
	std::swap(fuel_types[index], fuel_types[fuel_types.size() - 1]);
	std::swap(years[index], years[years.size() - 1]);
	std::swap(prices[index], prices[prices.size() - 1]);
	std::swap(available[index], available[available.size() - 1]);
	makes.resize(makes.size() - 1);
	models.resize(models.size() - 1);
	fuel_types.resize(fuel_types.size() - 1);
	years.resize(years.size() - 1);
	prices.resize(prices.size() - 1);
	return SaveCarDetails();
}

bool Admin::Update(const int& index, const int& choice, const std::string& detail_name)
{
	switch (choice)
	{
	case 1:
		makes[index] = detail_name;
		break;
	case 2:
		models[index] = detail_name;
		break;
	case 3:
		fuel_types[index] = detail_name;
		break;
	case 4:
		years[index] = std::stoi(detail_name);
		break;
	case 5:
		prices[index] = std::stoi(detail_name);
		break;
	}
	return SaveCarDetails();
}