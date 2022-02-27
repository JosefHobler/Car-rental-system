#include "Client.h"

Client::Client()
{
	string word;
	int number;
	ifstream read_to_vecs("Cars.txt");
	if (read_to_vecs.is_open())
	{
		while (!read_to_vecs.eof())
		{
			getline(read_to_vecs, word);
			makes.push_back(word);
			getline(read_to_vecs, word);
			models.push_back(word);
			getline(read_to_vecs, word);
			fuel_types.push_back(word);
			getline(read_to_vecs, word);
			years.push_back(stoi(word));
			getline(read_to_vecs, word);
			prices.push_back(stoi(word));
		}
		read_to_vecs.close();
	}
	else
	{
		throw std::ios::failure("\nError Opening A File!\n");
	}
}

bool Client::SaveCar()
{
	ofstream save_from_vecs("Cars.txt");
	if (save_from_vecs.is_open())
	{
		for (int i = 0; i < makes.size(); i++)
		{
			save_from_vecs << makes[i] << "\n";
			save_from_vecs << models[i] << "\n";
			save_from_vecs << fuel_types[i] << "\n";
			save_from_vecs << years[i] << "\n";
			save_from_vecs << prices[i];
			if (i != makes.size() - 1)
			{
				save_from_vecs << "\n";
			}
		}
		save_from_vecs.close();
	}
	else
	{
		throw std::ios::failure("\nError Opening A File!\n");
		return false;
	}
	return true;
}

void Client::ModifyFuelTypes(const string& fuel_type) { fuel_types.push_back(fuel_type); }

void Client::ModifyModels(const string& model) { models.push_back(model); }

void Client::ModifyMakes(const string& make) { makes.push_back(make); }

void Client::ModifyYears(const int& year) { years.push_back(year); }

void Client::ModifyPrices(const int& price) { prices.push_back(price); }