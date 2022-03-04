#include "Admin.h"

bool Admin::Login(const string& username, const string& password)
{
	string right_username, right_password;
	ifstream admin("Admin.txt");
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
	return right_username == username && right_password == password;
}

bool Admin::AddCar(const string& make, const string& model, const string& fuel_type, const int& year, const int& price)
{
	makes.push_back(make);
	models.push_back(model);
	fuel_types.push_back(fuel_type);
	years.push_back(year);
	prices.push_back(price);
	return SaveCarDetails();
}

bool Admin::Remove(const int& index)
{
	swap(makes[index], makes[makes.size() - 1]);
	swap(models[index], models[models.size() - 1]);
	swap(fuel_types[index], fuel_types[fuel_types.size() - 1]);
	swap(years[index], years[years.size() - 1]);
	swap(prices[index], prices[prices.size() - 1]);
	makes.resize(makes.size() - 1);
	models.resize(models.size() - 1);
	fuel_types.resize(fuel_types.size() - 1);
	years.resize(years.size() - 1);
	prices.resize(prices.size() - 1);
	return SaveCarDetails();
}

bool Admin::Update(const int& index, const int& choice, const string& detail_name)
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
		years[index] = stoi(detail_name);
		break;
	case 5:
		prices[index] = stoi(detail_name);
		break;
	}
	return SaveCarDetails();
}