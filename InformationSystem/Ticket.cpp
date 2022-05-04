#include "Ticket.h"

Ticket::Ticket(std::string _performance, Date _date, bool _bought) {
	this->performance = _performance;
	this->date = _date;
	this->bought = _bought;
}

std::string Ticket::getPerformance() const {
	return this->performance;
}

Date Ticket::getDate() const {
	return this->date;
}

bool Ticket::getBought() const {
	return this->bought;
}

void Ticket::setBought(bool _bought) {
	this->bought = _bought;
}