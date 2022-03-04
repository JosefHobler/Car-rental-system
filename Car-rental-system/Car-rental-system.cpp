#include "Custom Functions.h"
#include "Client.h"
#include "Admin.h"

// Develop:
//
// Precompiled headers
//
// Lambda for try-catch functions
//
// Separating #includes into different files by best practice
//
// Making Files More Readable 

int main()
{
	// Basic Variables
	vector<string> buffer;
	unique_ptr<Client> client;
	unique_ptr<Admin> admin;
	try
	{
		client = make_unique<Client>();
		admin = make_unique<Admin>();
	}
	catch (const exception& e)
	{
		cout << e.what();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		return 0;
	}
	int choice = 0;
	// Lambda For Displaying Menu
	auto Menus = [&choice, &buffer](string title) {
		choice = 0;
		while (choice <= 0 || choice > buffer.size())
		{
			cout << CenteredText(title, 20) << "\n\n";
			for (int i = 0; i < buffer.size(); i++)
			{
				cout << i + 1 << ") " << buffer[i] << "\n";
			}
			cout << "Your Choice: "; cin >> choice;
			system("cls");
		}
		buffer.clear();
	};
	// Logging Variables
	string username, password;
	// Add Function Variables
	string make, model, fuel_type;
	int year, price;
	// Modify Details;
	int choice_helper; string new_car_detail_name;

	// Main Menu
	buffer.push_back("Login as Admin");
	buffer.push_back("Run App As Client");
	buffer.push_back("Exit");
	Menus("Welcome In Car Rental System");
	switch (choice)
	{
	case 1:
		// Login As Admin
		cout << "Enter Username: "; cin >> username;
		cout << "Enter Password: "; cin >> password; cout << "\n";
		try
		{
			if (!admin->Login(username, password))
			{
				cout << "Wrong Username Or Password\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
		}
		catch (const exception& e)
		{
			cout << e.what();
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 0;
		}
		cout << "Login Successfull\n";
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
				cout << CenteredText("Add New Car", 20);
				cout << "\n\nCar's Make: "; getline(cin >> ws, make);
				cout << "Model: "; getline(cin >> ws, model);
				cout << "Fuel Type: "; getline(cin >> ws, fuel_type);
				cout << "Year Of Production: "; cin >> year;
				cout << "Price for 1 day (CZK): "; cin >> price;
				try
				{
					if(!admin->AddCar(make, model, fuel_type, year, price))
					{
						cout << "\nCar Not Added Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const exception& e)
				{
					cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				cout << "\nCar Successfully Added\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 2:
				// Update Car's Details
				choice = 0;
				while (choice <= 0 || choice > admin->GetCars())
				{
					cout << CenteredText("Choose car", 20) << "\n\n";
					admin->ChooseCar();
					cout << "Your Choice: "; cin >> choice;
					system("cls");
				}
				choice_helper = choice;
				buffer.push_back("Make");
				buffer.push_back("Model");
				buffer.push_back("Fuel Type");
				buffer.push_back("Year Of Production");
				buffer.push_back("Price");
				Menus("Details To Modify");
				cout << "Write New Car Detail: "; cin >> new_car_detail_name;
				system("cls");
				try
				{
					if (!admin->Update(choice_helper - 1, choice, new_car_detail_name))
					{
						cout << "Car Detail Not Modified Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const exception& e)
				{
					cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				cout << "Car Detail Succesfully Modified\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			case 3:
				// Remove Any Car
				choice = 0;
				while (choice <= 0 || choice > admin->GetCars())
				{
					cout << CenteredText("Choose car", 20) << "\n\n";
					admin->ChooseCar();
					cout << "Your Choice: "; cin >> choice;
					system("cls");
				}
				try
				{
					if (!admin->Remove(choice - 1))
					{
						cout << "Car Not Removed Due To Error\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));
						return 0;
					}
				}
				catch (const exception& e)
				{
					cout << e.what();
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
				cout << "Car Successfully Removed\n";
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
			cout << "\n\n\nPress [Any Key] For Menu\n";
			_getch();
		}
	case 2:
		// Client Menu 1.
		buffer.push_back("Login As Client");
		buffer.push_back("Register As Client");
		Menus("Client Login Menu");
		cout << "Enter Username: "; cin >> username;
		cout << "Enter Password: "; cin >> password; cout << "\n";
		switch (choice)
		{
		case 1:
			// Login As Client
			try
			{
				if (!client->Login(username, password))
				{
					cout << "Wrong Username Or Password\n";
					std::this_thread::sleep_for(std::chrono::seconds(1));
					return 0;
				}
			}
			catch (const exception& e)
			{
				cout << e.what();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
			cout << "Login Successfull\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		case 2:
			// Register New Client
			try
			{
				client->Register(username, password);
			}
			catch (const exception& e)
			{
				cout << e.what();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return 0;
			}
			cout << "Register Successfull\n";
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
			cout << "\n\n\nPress [Any Key] For Menu\n";
			_getch();
		}
	case 3:
		// Exit
		return 0;
	}
}

