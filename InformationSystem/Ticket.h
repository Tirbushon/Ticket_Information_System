#pragma once
#include "Date.h"

//A ticket class representing a ticket for an event.
//@performance - the event's performance
//@date - the event's date
//@status - representing the ticket's status:
// 0 - for unreserved ticket, 1 - for reserved ticket, 2 - for bought ticket
//@password - when a ticket is reserved it requires a password to be bought
//@note - a note for the buyer

class Ticket
{
private:
	std::string performance;
	Date date;
	unsigned int status;
	std::string password;
	std::string note;
public:
	Ticket(std::string, Date, unsigned int, std::string, std::string);
	std::string getPerformance() const;
	Date getDate() const;
	unsigned int getStatus() const;
	void setStatus(unsigned int status);
	std::string getPassword() const;
	std::string getNote() const;
};

