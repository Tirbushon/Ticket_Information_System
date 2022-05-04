#pragma once
#include <string>
#include "Date.h"

class Ticket
{
private:
	std::string performance;
	Date date;
	bool bought;
public:
	Ticket(std::string, Date, bool);
	std::string getPerformance() const;
	Date getDate() const;
	bool getBought() const;
	void setBought(bool);
};

