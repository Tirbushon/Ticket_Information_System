#include "Ticket.h"

// Implementation of the functions and constructors in the Ticket.h


Ticket::Ticket(std::string _performance, Date _date, unsigned int _status, std::string _password, std::string _note) {
	this->performance = _performance;
	this->date = _date;
	this->status = _status;
	this->password = _password;
	this->note = _note;
}

std::string Ticket::getPerformance() const {
	return this->performance;
}

Date Ticket::getDate() const {
	return this->date;
}

unsigned int Ticket::getStatus() const {
	return this->status;
}

void Ticket::setStatus(unsigned int _status) {
	this->status = _status;
}

std::string Ticket::getPassword() const {
	return this->password;
}

std::string Ticket::getNote() const {
	return this->note;
}