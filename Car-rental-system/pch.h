#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <string>

namespace custom
{
	std::string CenteredText(std::string msg, const int& size_to_center);

	template<typename T>
	void GetInput(T& input, const std::string& msg);
}