#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <string>
#include <limits>
#include <iomanip>

namespace custom
{
	extern std::string CenteredText(std::string msg, const int& size_to_center);

	template<typename T>
	extern void GetInput(T& input, const std::string& msg)
	{
		std::cout << msg;
		std::cin >> input;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error\n";
			std::cout << msg;
			std::cin >> input;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}