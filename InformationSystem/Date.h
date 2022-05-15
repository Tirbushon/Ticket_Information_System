#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


//a date class that represents a date in a
// yyyy-mm-dd format
class Date
{
private:
	std::string day;
	std::string month;
	std::string year;
public:
	Date();
	Date(std::string fullDate);
	std::string toString();
	void printDate();
	bool checkDate();
};

