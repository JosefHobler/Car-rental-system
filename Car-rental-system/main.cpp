#include "pch.h"
#include "Client.h"
#include "Admin.h"

// Develop:
// Lambda for try-catch functions
// 
// Making Files More Readable 

int main()
{
	// Basic Variables
	std::vector<std::string> buffer;
	std::unique_ptr<Client> client;
	std::unique_ptr<Admin> admin;
	try
	{
		client = std::make_unique<Client>();
		admin = std::make_unique<Admin>();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return 0;
	}
	int choice = 0;
	// Lambda For Displaying Menu
	auto Menus = [&choice, &buffer](std::string title)
	{
		choice = 0;
		while (choice <= 0 || choice > buffer.size())
		{
			std::cout << custom::CenteredText(title, 20) << "\n\n";
			for (int i = 0; i < buffer.size(); i++)
			{
				std::cout << i + 1 << ") " << buffer[i] << "\n";
			}
			custom::GetInput(choice, "Your Choice: ");
			system("cls");
		}
		buffer.clear();
	};
	// Logging Variables
	std::string username, password;
	// Add Function Variables
	std::string make, model, fuel_type;
	int year, price;
	// Modify Details;
	int choice_helper; std::string detail_name;

	// Main Menu
	buffer.push_back("Login as Admin");
	buffer.push_back("Run App As Client");
	buffer.push_back("Exit");
	Menus("Welcome In Car Rental System");
	switch (choice)
	{
	case 1:
		// Login As Admin
		custom::GetInput(username, "Enter Username: ");
		custom::GetInput(password, "Enter Password: ");
		std::cout << '\n';
		try
		{
			if (!admin->Login(username, password))
			{
				std::cout << "Wrong Username Or Password\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 0;
		}
		std::cout << "Login Successfull\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		// Admin's Menu
		while (true)
		{
			system("cls");
			buffer.push_back("Add A Car");
			buffer.push_back("Update Car Details");
			buffer.push_back("Remove Any Car");
			buffer.push_back("List Of Cars");
			buffer.push_back("Check Any Car");
			buffer.push_back("Modify Rent Details");
			buffer.push_back("Rent A Car");
			buffer.push_back("Exit");
			Menus("Admin's Menu");
			switch (choice)
			{
			case 1:
				// Add New Car
				std::cout << custom::CenteredText("Add New Car", 20) << "\n\n";
				custom::GetInput(make, "Car's Make: ");
				custom::GetInput(model, "Model: ");
				custom::GetInput(fuel_type, "Fuel Type: ");
				custom::GetInput(year, "Year Of Production: ");
				custom::GetInput(price, "Price for 1 day: ");
				try
				{
					if(!admin->AddCar(make, model, fuel_type, year, price))
					{
						std::cout << "\nCar Not Added Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				std::cout << "\nCar Successfully Added\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 2:
				// Update Car's Details
				choice = 0;
				while (choice <= 0 || choice > admin->GetCars())
				{
					std::cout << custom::CenteredText("Choose car", 20) << "\n\n";
					admin->ChooseCar();
					custom::GetInput(choice, "Your Choice: ");
					system("cls");
				}
				choice_helper = choice;
				buffer.push_back("Make");
				buffer.push_back("Model");
				buffer.push_back("Fuel Type");
				buffer.push_back("Year Of Production");
				buffer.push_back("Price");
				Menus("Details To Modify");
				custom::GetInput(detail_name, "Write New Car Detail: ");
				system("cls");
				try
				{
					if (!admin->Update(choice_helper - 1, choice, detail_name))
					{
						std::cout << "Car Detail Not Modified Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				std::cout << "Car Detail Succesfully Modified\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 3:
				// Remove Any Car
				choice = 0;
				while (choice <= 0 || choice > admin->GetCars())
				{
					std::cout << custom::CenteredText("Choose car", 20) << "\n\n";
					admin->ChooseCar();
					custom::GetInput(choice, "Your Choice: ");
					system("cls");
				}
				try
				{
					if (!admin->Remove(choice - 1))
					{
						std::cout << "Car Not Removed Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const std::exception& e)
				{
					std::cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				std::cout << "Car Successfully Removed\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 4:
				// List Of Cars
				admin->ShowCars();
				break;
			case 5:
				// Check Any Car
				break;
			case 6:
				// Modify Rent Details
				break;
			case 7:
				// Rent A Car
				break;
			case 8:
				// Exit
				return 0;
			}
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "\n\n\nPress [Any Key] For Menu\n";
			_getch();
		}
	case 2:
		// Client Menu 1.
		buffer.push_back("Login As Client");
		buffer.push_back("Register As Client");
		Menus("Client Login Menu");
		custom::GetInput(username, "Enter Username");
		custom::GetInput(password, "Enter Password");
		std::cout << "\n";
		switch (choice)
		{
		case 1:
			// Login As Client
			try
			{
				if (!client->Login(username, password))
				{
					std::cout << "Wrong Username Or Password\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
			std::cout << "Login Successfull\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		case 2:
			// Register New Client
			try
			{
				client->Register(username, password);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
			std::cout << "Register Successfull\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}
		while (true)
		{
			// Client Menu 2.
			system("cls");
			buffer.push_back("List Of Cars");
			buffer.push_back("Check Any Car");
			buffer.push_back("Modify Rent Details");
			buffer.push_back("Rent A Car");
			buffer.push_back("Exit");
			Menus("Client Menu");
			switch (choice)
			{
			case 1:
				// List Of Cars
				client->ShowCars();
				break;
			case 2:
				// Check Any Car
				break;
			case 3:
				// Modify Rent Details
				break;
			case 4:
				// Rent A Car
				break;
			case 5:
				// Exit
				return 0;
			}
			std::cout << "\n\n\nPress [Any Key] For Menu\n";
			_getch();
		}
	case 3:
		// Exit
		return 0;
	}
}

