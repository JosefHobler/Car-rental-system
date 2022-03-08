#include "pch.h"
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
			make.push_back(word);
			getline(read_to_vecs, word);
			model.push_back(word);
			getline(read_to_vecs, word);
			fuel_type.push_back(word);
			getline(read_to_vecs, word);
			years.push_back(stoi(word));
			getline(read_to_vecs, word);
			prices.push_back(stoi(word));
			getline(read_to_vecs, word);
			available.push_back(stoi(word));
		}
		read_to_vecs.close();
		std::ifstream list("List.txt");
		if (list.is_open())
		{
			while (!list.eof())
			{
				std::getline(list, word);
				names_of_borrowers.push_back(word);
			}
			list.close();
		}
		else
		{
			throw std::ios::failure("\nError Opening A File!\n");
		}
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
			for (int i = 0; i < make.size(); i++)
			{
				save_from_vecs << make[i] << "\n";
				save_from_vecs << model[i] << "\n";
				save_from_vecs << fuel_type[i] << "\n";
				save_from_vecs << years[i] << "\n";
				save_from_vecs << prices[i] << "\n";
				save_from_vecs << available[i];
				if (i != make.size() - 1)
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
		<< custom::CenteredText("Price", 12) << "|" << custom::CenteredText("In Servis", 14);
	std::cout << "\n---------------+---------------+------------+--------------\n";
	for (int i = 0; i < make.size(); i++)
	{
		std::cout << custom::CenteredText(make[i], 15) << "|" << custom::CenteredText(model[i], 15) << "|"
			<< custom::CenteredText(std::to_string(prices[i]) + '$', 12) << "|" << custom::CenteredText(available[i] ? "Available" : "Unavailable", 14);
		std::cout << "\n";
	}
}

bool User::PrintBill(const std::string& username, const int& days, const int& index)
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
			receipt << "Make: " << std::fixed << std::setprecision(20) << make[index] << '\n';
			receipt << "Model: " << std::fixed << std::setprecision(20) << model[index] << '\n';
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
		if (std::find(names_of_borrowers.begin(), names_of_borrowers.end(), username) == names_of_borrowers.end())
		{
			names_of_borrowers.push_back(username);
			if (!ModifyListOfBorrowers())
			{
				return false;
			}
		}
		std::fstream user_list;
		user_list.open(username + "List.txt", std::ios::app);
		if (user_list.is_open())
		{
			user_list << make[index] << "\n";
			user_list << model[index] << "\n";
			user_list << prices[index] << "\n";
			user_list << days << "\n";
			user_list.close();
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

bool User::ModifyListOfBorrowers()
{
	
	std::ofstream list("List.txt");
	if (list.is_open())
	{
		for (int i = 0; i < names_of_borrowers.size(); i++)
		{
			list << names_of_borrowers[i] << "\n";
			list.close();
		}
	}
	else
	{
		throw std::ios::failure("\nError Opening A File!\n");
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

bool User::Return(const int& index)
{
	return true;
}

bool User::ReadCars(const std::string& username)
{
	lent_cars_days.clear();
	lent_cars_makes.clear();
	lent_cars_models.clear();
	lent_cars_prices.clear();
	std::string word;
	try
	{
		std::ifstream read_cars(username + "List.txt");
		if (read_cars.is_open())
		{
			while (!read_cars.eof())
			{
				std::getline(read_cars, word);
				if (word == "")
				{
					break;
				}
				lent_cars_makes.push_back(word);
				std::getline(read_cars, word);
				lent_cars_models.push_back(word); 
				std::getline(read_cars, word);
				lent_cars_days.push_back(stoi(word)); 
				std::getline(read_cars, word);
				lent_cars_prices.push_back(stoi(word));
				//	map.emplace(username, std::vector<std::string>{ lent_cars_makes[lent_cars_makes.size() - 1], lent_cars_models[lent_cars_models.size() - 1] });
			}
			read_cars.close();
		}
		else
		{
			throw std::ios::failure("\nError Opening A File!\n");
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		if (lent_cars_makes.size() == 0)
		{
			throw "\nNo Borrowed Cars\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	catch (const std::string& e)
	{
		std::cout << e;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

bool User::Delete(const std::string& username, const int& index)
{
	std::swap(lent_cars_prices[index], lent_cars_prices[lent_cars_prices.size() - 1]);
	std::swap(lent_cars_makes[index], lent_cars_makes[lent_cars_makes.size() - 1]);
	std::swap(lent_cars_models[index], lent_cars_models[lent_cars_models.size() - 1]);
	std::swap(lent_cars_days[index], lent_cars_days[lent_cars_days.size() - 1]);
	/*
	lent_cars_makes[index] = lent_cars_makes[lent_cars_makes.size() - 1];
	lent_cars_models[index] = lent_cars_models[lent_cars_models.size() - 1];
	lent_cars_days[index] = lent_cars_days[lent_cars_days.size() - 1];
	lent_cars_prices[index] = lent_cars_prices[lent_cars_prices.size() - 1];
	*/

	lent_cars_makes.resize(lent_cars_makes.size() - 1);
	lent_cars_models.resize(lent_cars_models.size() - 1);
	lent_cars_days.resize(lent_cars_days.size() - 1);
	lent_cars_prices.resize(lent_cars_prices.size() - 1);
	if (lent_cars_makes.empty())
	{
		std::swap(names_of_borrowers[std::find(names_of_borrowers.begin(), names_of_borrowers.end(), username) - names_of_borrowers.begin()], names_of_borrowers[names_of_borrowers.size() - 1]);
		names_of_borrowers.resize(names_of_borrowers.size() - 1);
		if (!ModifyListOfBorrowers())
		{
			return false;
		}
	}
	try
	{
		std::ofstream rewrite(username + "List.txt");
		if (rewrite.is_open())
		{
			for (int i = 0; i < lent_cars_makes.size(); i++)
			{
				rewrite << lent_cars_makes[i] << "\n";
				rewrite << lent_cars_models[i] << "\n";
				rewrite << lent_cars_days[i] << "\n";
				rewrite << lent_cars_prices[i] << "\n";
			}
			rewrite.close();
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
	std::cout << custom::CenteredText(make[index] + " " + model[index] + " Details", 20);
	std::cout << "\n\n";
	std::cout << "Make: " << make[index] << "\n";
	std::cout << "Model: " << model[index] << "\n";
	std::cout << "Fuel Type: " << fuel_type[index] << "\n";
	std::cout << "Year Prod: " << years[index] << "\n";
	std::cout << "Price: " << prices[index] << "\n";
}

void User::ChooseCar() const
{
	for (int i = 0; i < make.size(); i++)
	{
		std::cout << i + 1 << ") " << make[i] << " " << model[i] << "\n";
	}
}

void User::ChooseLentCar() const
{
	for (int i = 0; i < lent_cars_makes.size(); i++)
	{
		std::cout << i + 1 << ") " << lent_cars_makes[i] << " " << lent_cars_models[i] << ", Days Left: " << lent_cars_days[i] << "\n";
	}
}

bool User::SetAvailable(const bool& value, const int& index)
{
	available[index] = value;
	return SaveCarDetails();
}