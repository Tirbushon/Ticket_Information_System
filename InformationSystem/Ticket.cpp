#include "Ticket.h"

Ticket::Ticket(std::string _performance, Date _date, unsigned int _status) {
	this->performance = _performance;
	this->date = _date;
	this->status = _status;
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