#include "User.h"

User::User()
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

bool User::SaveCarDetails() const
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
		this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

void User::ShowCars() const
{
	cout << CenteredText("Makes", 15) << "|" << CenteredText("Model", 15) << "|" <<
		CenteredText("Fuel Type", 15) << "|" << CenteredText("Year Prod.", 10) << "|" << CenteredText("Price", 12);
	cout << "\n---------------+---------------+---------------+----------+-------------\n";
	for (int i = 0; i < makes.size(); i++)
	{
		cout << CenteredText(makes[i], 15) << "|" << CenteredText(models[i], 15) << "|" <<
			CenteredText(fuel_types[i], 15) << "|" << CenteredText(to_string(years[i]), 10) <<
			"|" << CenteredText((prices[i] != 0) ? to_string(prices[i]) : "Unavailable", 12);
		cout << "\n";
	}
}

void User::ChooseCar() const
{
	for (int i = 0; i < makes.size(); i++)
	{
		cout << i + 1 << ") " << makes[i] << " " << models[i] << "\n";
	}
}