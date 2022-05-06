#include "Event.h"


Event::Event(std::string _name, unsigned int _id, Date _date) {
	this->name = _name;
	this->id = _id;
	this->date = _date;
}

std::string Event::getName() const {
	return this->name;
}

unsigned int Event::getId() const {
	return this->id;
}

Date Event::getDate() const {
	return this->date;
}

void Event::setName(std::string _name) {
	this->name = _name;
}

void Event::setId(unsigned int _id) {
	this->id = _id;
}

void Event::addTicket(Ticket& ticket) {
	//add in Date operator==
	//if (ticket.getPerformance() == name && ticket.getDate() == date)
		tickets.push_back(ticket);
}


void Event::printEvent() const {
	std::cout << getName() << " " << getId() << " ";
	date.printDate();
}