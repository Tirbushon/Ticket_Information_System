#include "Hall.h"

Hall::Hall(unsigned int _rows, unsigned int _columns, unsigned int _id) {
	assert(_rows > 0 && _columns > 0);
	this->id = _id;
	this->rows = _rows;
	this->columns = _columns;
	this->id += 1;
	seats = new unsigned int*[rows];
	for (int i = 0; i < rows; i++) {
		seats[i] = new unsigned int[columns];
	}

	//populate in a private function
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			seats[i][j] = 0;
		}
	}
}

int Hall::getId() const {
	return this->id;
}

Event Hall::getIndexEvent(unsigned int index) const {
	return events.at(index);
}

void Hall::addEvent(Event& _event) {
	try {
		for (Event e : events) {
			//replace with operator== in Event class
			if (e.getDate().getDay() == _event.getDate().getDay() &&
				e.getDate().getMonth() == _event.getDate().getMonth() &&
				e.getDate().getYear() == _event.getDate().getYear())
				throw std::invalid_argument("There is already a performance on that date");
		}
		events.push_back(_event);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

void Hall::printEvents() const {
	for (Event e : events) {
		e.printEvent();
	}
}

Hall::~Hall() {
	for (int i = 0; i < rows; i++) {
		delete[] seats[i];
	}
	delete[] seats;
}

