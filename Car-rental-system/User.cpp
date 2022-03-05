#include "User.h"

User::User()
{
	std::string word;
	int number;
	std::ifstream read_to_vecs("Cars.txt");
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
			getline(read_to_vecs, word);
			available.push_back(word);
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
	try
	{
		std::ofstream save_from_vecs("Cars.txt");
		if (save_from_vecs.is_open())
		{
			for (int i = 0; i < makes.size(); i++)
			{
				save_from_vecs << makes[i] << "\n";
				save_from_vecs << models[i] << "\n";
				save_from_vecs << fuel_types[i] << "\n";
				save_from_vecs << years[i] << "\n";
				save_from_vecs << prices[i] << "\n";
				save_from_vecs << available[i];
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
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

void User::ShowCars() const
{
	std::cout << custom::CenteredText("Makes", 15) << "|" << custom::CenteredText("Model", 15) << "|"
		<< custom::CenteredText("Price", 12) << "|" << custom::CenteredText("Available", 14);
	std::cout << "\n---------------+---------------+------------+--------------\n";
	for (int i = 0; i < makes.size(); i++)
	{
		std::cout << custom::CenteredText(makes[i], 15) << "|" << custom::CenteredText(models[i], 15) << "|"
			<< custom::CenteredText(std::to_string(prices[i]) + '$', 12) << "|" << custom::CenteredText(available[i], 14);
		std::cout << "\n";
	}
}

bool User::PrintBill(const std::string& username, const int& days, const int& index) const
{
	try
	{
		std::fstream receipt;
		receipt.open(username + "Receipt.txt", std::ios::app);
		if (receipt.is_open())
		{
			receipt << "--------ABC Servis Agency--------\n";
			receipt << "-------------Receipt-------------\n";
			receipt << "_________________________________\n";
			receipt << "Customer Name: " << username << "\n\n";
			receipt << "Description" << '\n';
			receipt << "Make: " << std::fixed << std::setprecision(20) << makes[index] << '\n';
			receipt << "Model: " << std::fixed << std::setprecision(20) << models[index] << '\n';
			receipt << "Days: " << std::fixed << std::setprecision(15) << days << '\n';
			receipt << "Price/Day: " << std::fixed << std::setprecision(15) << prices[index] << "$\n";
			receipt << "_________________________________" << '\n';
			receipt << "Total Charge: " << std::fixed << std::setprecision(15) << days * prices[index] << "$\n";
			receipt << "_________________________________" << '\n';
			receipt << "------------THANK YOU------------" << "\n\n\n";
		}
		else
		{
			throw std::ios::failure("\nError Opening A File!\n");
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		receipt.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

bool User::ShowBill(const std::string& username) const
{
	std::string line;
	std::ifstream receipt(username + "Receipt.txt");
	try
	{
		if (receipt.is_open())
		{
			while (!receipt.eof())
			{
				getline(receipt, line);
				std::cout << line << "\n";
			}
		}
		else
		{
			throw std::ios::failure("\nError Opening A File!\n");
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

bool User::ModifyRentDetails(const int& index)
{
	return true;
}

void User::CheckCar(const int& index) const
{
	std::cout << custom::CenteredText(makes[index] + " " + models[index] + " Details", 20);
	std::cout << "\n\n";
	std::cout << "Make: " << makes[index] << "\n";
	std::cout << "Model: " << models[index] << "\n";
	std::cout << "Fuel Type: " << fuel_types[index] << "\n";
	std::cout << "Year Prod: " << years[index] << "\n";
	std::cout << "Price: " << prices[index] << "\n";
}

void User::ChooseCar() const
{
	for (int i = 0; i < makes.size(); i++)
	{
		std::cout << i + 1 << ") " << makes[i] << " " << models[i] << "\n";
	}
}

bool User::SetAvailable(const std::string& value, const int& index)
{
	available[index] = value;
	return SaveCarDetails();
}