#include "Event.h"

//Implementation of the functions and constructors, destructor in the Event.h

Event::Event() {
	name = "";
	id = 0;
	size = 0;
}

Event::Event(std::string _name, unsigned int _id, Date _date) {
	name = _name;
	id = _id;
	date = _date;
}

Event::Event(const Event& other) {
	name = other.name;
	id = other.id;
	size = other.size;
	date = other.date;
	seats = new unsigned int[size];
	for (int i = 0; i < size; i++) {
		seats[i] = other.seats[i];
	}
}

Event Event::operator=(const Event& other) {
	if (this != &other) {
		name = other.name;
		date = other.date;
		size = other.size;
		id = other.id;
		unsigned int* temp = new unsigned int[size];
		for (int i = 0; i < size; i++) {
			temp[i] = other.seats[i];
		}
		delete[] seats;
		seats = temp;
	}
	return *this;
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

void Event::setSeats(unsigned int _rows, unsigned int _columns) {
	size = _rows * _columns;
	seats = new unsigned int[size];
	std::fill_n(seats, size, 0);
}

unsigned int Event::getSize() const {
	return this->size;
}


unsigned int* Event::getSeats() const {
	return seats;
}

Event::~Event() {
	delete[] seats;
}
