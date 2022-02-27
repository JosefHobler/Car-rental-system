#include "Client.h"

Client::Client()
{
	ifstream read_to_vecs("Cars.txt");
	if (read_to_vecs.is_open())
	{

	}
	else
	{
		throw std::ios::failure("\nError Opening A File!\n");
	}
}

void Client::ModifyFuelTypes(const string& fuel_type) { fuel_types.push_back(fuel_type); }

void Client::ModifyModels(const string& model) { models.push_back(model); }

void Client::ModifyMakes(const string& make) { makes.push_back(make); }

void Client::ModifyYears(const int& year) { years.push_back(year); }

void Client::ModifyPrices(const int& price) { prices.push_back(price); }