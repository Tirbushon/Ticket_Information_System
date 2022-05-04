#pragma once
#include "Date.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <vector>

class Event
{
private:
	std::string name;
	unsigned int id;
	Date date;
	std::vector<Ticket> tickets;
public:
	Event(std::string, unsigned int, Date);
	std::string getName() const;
	unsigned int getId() const;
	Date getDate() const;
	void setName(std::string);
	void setId(unsigned int);
	void printEvent() const;
	void addTicket(Ticket&);
};

