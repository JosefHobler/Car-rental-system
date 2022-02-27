#include "Admin.h"

bool Admin::AddCar(const string& make, const string& model, const string& fuel_type, const int& year, const int& price)
{
	ModifyMakes(make);
	ModifyModels(model);
	ModifyFuelTypes(fuel_type);
	ModifyYears(year);
	ModifyPrices(price);
	if (SaveCar())
	{
		return true;
	}
	return false;
}
