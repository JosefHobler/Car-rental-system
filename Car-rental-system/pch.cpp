#include "pch.h"

namespace custom
{
	extern std::string CenteredText(std::string msg, const int& size_to_center)
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
}