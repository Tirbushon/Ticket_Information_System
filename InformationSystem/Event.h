#pragma once
#include <iostream>
#include "Date.h"
#include <string>

class Event
{
private:
	std::string name;
	unsigned int id;
	Date date;
public:
	Event();
};

