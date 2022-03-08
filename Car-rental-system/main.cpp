#include "pch.h"
#include "Client.h"
#include "Admin.h"


// Develop:
// Lambda for try-catch functions
// 
// Making Files More Readable 
//
// Define std::cout, etc.

int main()
{
	// Basic Variables
	std::vector<std::string> buffer;
	std::unique_ptr<Client> client;
	std::unique_ptr<Admin> admin;
	int choice = 0;

	// Lambda For Searching Desired Car
	auto Search = [&choice](User* user)
	{
		choice = 0;
		while (choice <= 0 || choice > user->GetCars())
		{
			std::cout << custom::CenteredText("Choose car", 20) << "\n\n";
			user->ChooseCar();
			custom::GetInput<int>(choice, "Your Choice: ");
			system("cls");
		}
	};

	// Lambda For Searching Lent Desired Car
	auto Search2 = [&choice](User* user)
	{
		choice = 0;
		while (choice <= 0 || choice > user->GetLentCars())
		{
			std::cout << custom::CenteredText("Choose car", 20) << "\n\n";
			user->ChooseLentCar();
			custom::GetInput<int>(choice, "Your Choice: ");
			system("cls");
		}
	};

	// Lambda For Displaying Menu
	auto Menus = [&choice, &buffer](const std::string& title)
	{
		choice = 0;
		while (choice <= 0 || choice > buffer.size())
		{
			std::cout << custom::CenteredText(title, 20) << "\n\n";
			for (int i = 0; i < buffer.size(); i++)
			{
				std::cout << i + 1 << ") " << buffer[i] << "\n";
			}
			custom::GetInput<int>(choice, "Your Choice: ");
			system("cls");
		}
		buffer.clear();
	};
	// Logging Variables

	std::string username, password;

	// Add Function Variables
	std::string make, model, fuel_type;
	int year, price;

	// Modify Variables;
	int choice_helper; std::string detail_name;

	// Rent Variables
	int days;

	// Rent A Car Lambda
	auto RentCar = [&username, &days, &choice](User* user)
	{
		if (!user->GetAvailable(choice - 1))
		{
			std::cout << "\nCar Unavailable In Servis";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return false;
		}
		custom::GetInput<int>(days, "Days ( " + std::to_string(user->GetPrice(choice - 1)) + "$ Per Day): ");
		system("cls");
		if (!user->PrintBill(username, days, choice - 1) || !user->ShowBill(username) || !user->SetAvailable(false, choice - 1))
		{
			std::cout << "\nError";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return false;
		}
		std::cout << "\n\nSucessfully Rented!\n";
		std::cout << "All Available Receipts In: " << username << "Receipt.txt\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	};

	// Return A Car Lambda
	auto ReturnCar = [&Search2,&username, &choice](User* user)
	{
		if (!user->ReadCars(username))
		{
			std::cout << "\nError";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		if (user->GetLentCars() == 0)
		{
			std::cout << "\nNo Borrowed Cars";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		Search2(user);
		if (!user->SetAvailable(true, user->ModelsAt(user->GetLentCarModel(choice - 1))))
		{
			std::cout << "\nError";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		if (!user->Delete(username, choice - 1))
		{
			std::cout << "\nError";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		std::cout << "\nSucessfully Returned";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	};

	// Main Menu
	buffer.push_back("Login as Admin");
	buffer.push_back("Run App As Client");
	buffer.push_back("Exit");
	Menus("Welcome In Car Rental System");
	switch (choice)
	{
	case 1:
		// Login As Admin
		custom::GetInput<std::string>(username, "Enter Username: ");
		custom::GetInput<std::string>(password, "Enter Password: ");
		std::cout << '\n';
		try
		{
			admin = std::make_unique<Admin>();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 0;
		}
		if (!admin->Login(username, password))
		{
			std::cout << "Wrong Username Or Password\n";
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
			buffer.push_back("Rent A Car");
			buffer.push_back("Return A Car");
			buffer.push_back("Exit");
			Menus("Admin's Menu");
			switch (choice)
			{
			case 1:
				// Add New Car
				std::cout << custom::CenteredText("Add New Car", 20) << "\n\n";
				custom::GetInput<std::string>(make, "Car's Make: ");
				custom::GetInput<std::string>(model, "Model: ");
				custom::GetInput<std::string>(fuel_type, "Fuel Type: ");
				custom::GetInput<int>(year, "Year Of Production: ");
				custom::GetInput<int>(price, "Price for 1 day: ");
				if (!admin->AddCar(make, model, fuel_type, year, price))
				{
					std::cout << "\nError";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					break;
				}
				std::cout << "\nCar Successfully Added\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 2:
				// Update Car's Details
				Search(admin.get());
				choice_helper = choice;
				buffer.push_back("Make");
				buffer.push_back("Model");
				buffer.push_back("Fuel Type");
				buffer.push_back("Year Of Production");
				buffer.push_back("Price");
				Menus("Details To Modify");
				custom::GetInput<std::string>(detail_name, "Write New Car Detail: ");
				system("cls");
				if (!admin->Update(choice_helper - 1, choice, detail_name))
				{
					std::cout << "\nError";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					break;
				}
				std::cout << "Car Detail Succesfully Modified\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 3:
				// Remove Any Car
				Search(admin.get());
				if (!admin->Remove(choice - 1))
				{
					std::cout << "\nError";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					break;
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
				Search(admin.get());
				admin->CheckCar(choice - 1);
				break;
			case 6:
				// Rent A Car
				Search(admin.get());
				RentCar(admin.get());
				break;
			case 7:
				// Return A Car
				ReturnCar(admin.get());
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
		custom::GetInput<std::string>(username, "Enter Username: ");
		custom::GetInput<std::string>(password, "Enter Password: ");
		std::cout << "\n";
		try
		{
			client = std::make_unique<Client>();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 0;
		}
		switch (choice)
		{
		case 1:
			// Login As Client
			if (!client->Login(username, password))
			{
				std::cout << "Wrong Username Or Password\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
			std::cout << "Login Successfull\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		case 2:
			// Register New Client
			if (!client->Register(username, password))
			{
				std::cout << "\nError";
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
			buffer.push_back("Rent A Car");
			buffer.push_back("Return A Car");
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
				Search(client.get());
				client->CheckCar(choice - 1);
				break;
			case 3:
				// Rent A Car
				Search(client.get());
				RentCar(client.get());
				break;
			case 4:
				// Return A Car
				ReturnCar(client.get());
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