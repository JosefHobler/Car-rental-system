#include "Custom Functions.h"
#include "Client.h"
#include "Admin.h"

int main()
{
	// Basic Variables
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
		Sleep(1000);
		return 0;
	}
	int choice = 0;
	// Logging Variables
	string username, password;
	// Add Function Variables
	string make, model, fuel_type;
	int year, price;
	
	// Main Menu
	while (choice <= 0 || choice > 3)
	{
		cout << CenteredText("Welcome In Car Rental System", 20);
		cout << "\n\n1) Login as Admin\n";
		cout << "2) Run App As Client\n";
		cout << "3) Exit\n";
		cout << "Your Choice: "; cin >> choice;
		system("cls");
	}
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
				Sleep(1000);
				return 0;
			}
		}
		catch (const exception& e)
		{
			cout << e.what();
			Sleep(1000);
			return 0;
		}
		cout << "Login Successfull\n";
		Sleep(1000);
		// Admin's Menu
		while (true)
		{
			system("cls");
			choice = 0;
			while (choice <= 0 || choice > 8)
			{
				cout << CenteredText("Admin's Menu", 20);
				cout << "\n\n1) Add A Car\n";
				cout << "2) Update Car's Details\n";
				cout << "3) Remove Any Car\n";
				cout << "4) List Of Cars\n";
				cout << "5) Check Any Car\n";
				cout << "6) Modify Rent Details\n";
				cout << "7) Rent A Car\n";
				cout << "8) Exit\n";
				cout << "Your Choice: "; cin >> choice;
				system("cls");
			}
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
					if(admin->AddCar(make, model, fuel_type, year, price));
					{
						cout << "\nCar Successfully Added\n";
					}
				}
				catch(const exception& e)
				{
					cout << e.what();
					Sleep(1000);
					break;
				}
				break;
			case 2:
				// Update Car's Details
				break;
			case 3:
				// Remove Any Car
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
			cout << "\n\n\nPress [Escape] For Menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}
	case 2:
		// Client Menu 1.
		choice = 0;
		while (choice <= 0 || choice > 2)
		{
			cout << "1) Login As Client\n";
			cout << "2) Register As Client\n";
			cout << "Your Choice: "; cin >> choice;
			system("cls");
		}
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
					Sleep(1000);
					return 0;
				}
			}
			catch (const exception& e)
			{
				cout << e.what();
				Sleep(1000);
				return 0;
			}
			cout << "Login Successfull\n";
			Sleep(1000);
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
				Sleep(1000);
				return 0;
			}
			cout << "Register Successfull\n";
			Sleep(1000);
			break;
		}
		while (true)
		{
			// Client Menu 2.
			system("cls");
			choice = 0;
			while (choice <= 0 || choice > 5)
			{
				cout << CenteredText("Client's Menu", 20);
				cout << "\n\n1) List Of Cars\n";
				cout << "2) Check Any Car\n";
				cout << "3) Modify Rent Details\n";
				cout << "4) Rent A Car\n";
				cout << "5) Exit\n";
				cout << "Your Choice: "; cin >> choice;
				system("cls");
			}
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
			cout << "\n\n\nPress [Escape] For Menu\n";
			while ((0x8000 & GetAsyncKeyState((unsigned char)(VK_ESCAPE))) == 0) {}
		}
	case 3:
		// Exit
		return 0;
	}
}

