#include "Admin.h"

bool Admin::Add(const string& make, const string& model, const string& fuel_type, const int& year, const int& price)
{
	ModifyMakes(make);
	ModifyModels(model);
	ModifyFuelTypes(fuel_type);
	ModifyYears(year);
	ModifyPrices(price);
	return true;
}
