#include "Client.h"

bool Client::Login(const string& username, const string& password)
{
	string right_username, right_password;
	ifstream client("Clients.txt");
	if (client.is_open())
	{
		while (!client.eof())
		{
			getline(client, right_username);
			getline(client, right_password);
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
	return false;
}