#include "pch.h"
#include "Client.h"

bool Client::Login(const std::string& username, const std::string& password)
{
	std::string right_username, right_password;
	try
	{
		std::ifstream client("Clients.txt");
		if (client.is_open())
		{
			while (!client.eof())
			{
				std::getline(client, right_username);
				std::getline(client, right_password);
				if (right_username == username && right_password == password)
				{
					client.close();
					return true;
				}
			}
		}
		else
		{
			throw std::ios::failure("Error Opening A File!\n");
		}
		client.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return false;
	}
	return true;
}

bool Client::Register(const std::string& username, const std::string& password) const
{
	try
	{
		std::ofstream client;
		client.open("Clients.txt", std::ios::app);
		if (client.is_open())
		{
			client << "\n" << username << "\n" << password;
			client.close();
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
	return true;
}