#include "pch.h"

namespace custom
{
	std::string CenteredText(std::string msg, const int& size_to_center)
	{
		bool space = true;
		for (int i = msg.size(); i < size_to_center; i++)
		{
			if (space)
			{
				msg += ' ';
			}
			else
			{
				msg = ' ' + msg;
			}
			space = !space;
		}
		return msg;
	}

	template<typename T>
	void GetInput(T& input, const std::string& msg)
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