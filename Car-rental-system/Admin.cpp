#include "pch.h"
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
	this->make.push_back(make);
	this->model.push_back(model);
	this->fuel_type.push_back(fuel_type);
	this->years.push_back(year);
	this->prices.push_back(price);
	available.push_back(true);
	return SaveCarDetails();
}

bool Admin::Remove(const int& index)
{
	make[index] = make[make.size() - 1];
	model[index] = model[model.size() - 1];
	fuel_type[index] = fuel_type[fuel_type.size() - 1];
	years[index] = years[years.size() - 1];
	prices[index] = prices[prices.size() - 1];
	available[index] = available[available.size() - 1];
	make.resize(make.size() - 1);
	model.resize(model.size() - 1);
	fuel_type.resize(fuel_type.size() - 1);
	years.resize(years.size() - 1);
	prices.resize(prices.size() - 1);
	return SaveCarDetails();
}

bool Admin::Update(const int& index, const int& choice, const std::string& detail_name)
{
	switch (choice)
	{
	case 1:
		make[index] = detail_name;
		break;
	case 2:
		model[index] = detail_name;
		break;
	case 3:
		fuel_type[index] = detail_name;
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