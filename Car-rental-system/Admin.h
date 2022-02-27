#pragma once
#include "Custom Functions.h"
#include "Client.h"

class Admin : public Client
{
private:
public:
	bool AddCar(const string& make, const string& model, const string& fuel_type, const int& year, const int& price);
};
