/*
	Create a function that calculates the missing value
	of 3 inputs using Ohm's law. The inputs are
	`v`, `r`, or `i` (aka: voltage, resistance, and current)

	Ohm's law: `V = R * I`
*/

#include <cassert>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

std::string get_string(double n)
{
	std::stringstream s;
	
	if (n < 1 && n > 0)
	{
		s << std::fixed << std::setprecision(2);
	}

	s << n;
	
	return s.str();
}

std::string ohmsLaw(std::string v, std::string r, std::string i)
{
	std::list<std::string> components;

	components.push_back(v);
	components.push_back(r);
	components.push_back(i);

	unsigned n = std::count_if(components.begin(), components.end(), [](std::string s) { return s == ""; });

	if (n != 1)
	{
		return "Invalid";
	}

	double v_num, r_num, i_num;

	if (v == "")
	{
		r_num = std::stof(r);
		i_num = std::stof(i);

		v_num = r_num * i_num;

		return get_string(v_num);		
	}
	
	if (r == "")
	{
		v_num = std::stof(v);
		i_num = std::stof(i);

		r_num = v_num / i_num;

		return get_string(r_num);
	}	

	if (i == "")
	{
		v_num = std::stof(v);
		r_num = std::stof(r);
		
		i_num = v_num / r_num;

		return get_string(i_num);
	}	
	
	return "Invalid";
}

int main()
{
	assert(ohmsLaw("12", "220", "") == "0.05");
	assert(ohmsLaw("230", "", "2") == "115");
	assert(ohmsLaw("", "220", "0.02") == "4.4");
	assert(ohmsLaw("", "", "10") == "Invalid");
	assert(ohmsLaw("500", "50", "10") == "Invalid");

	return 0;
}
