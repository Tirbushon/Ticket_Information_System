#pragma once
#include "Date.h"
#include "Ticket.h"

//Event class representing a single event.
//@name - event's name
//@id - the number of hall room where the event is played
//@size - the number of seats in a hall for an event
//@seats - dynamic array used to represent seats,
// where each seat index is used for its status(0,1,2) (check Ticket class's status parameter for more clarification)
//@date - the date when the event is played

class Event
{
private:
	std::string name;
	unsigned int id;
	unsigned int size;
	unsigned int* seats = nullptr;
	Date date;
public:
	Event();
	Event(std::string, unsigned int, Date);
	Event(const Event&);
	Event operator=(const Event&);
	std::string getName() const;
	unsigned int getId() const;
	Date getDate() const;
	void setName(std::string);
	void setId(unsigned int);
	void setSeats(unsigned int, unsigned int);
	unsigned int getSize() const;
	unsigned int* getSeats() const;
	~Event();
};

