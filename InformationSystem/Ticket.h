#pragma once
#include <string>
#include "Date.h"

class Ticket
{
private:
	std::string performance;
	Date date;
	//used for knowing whether the ticket is bought, reserved, or free
	//by corresponding values 2,1,0
	unsigned int status;
	std::string password;
public:
	Ticket(std::string, Date, unsigned int);
	std::string getPerformance() const;
	Date getDate() const;
	unsigned int getStatus() const;
	void setStatus(unsigned int status);
};

