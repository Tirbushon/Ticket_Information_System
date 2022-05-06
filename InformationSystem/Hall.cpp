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
			if (e.getDate() == _event.getDate())
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

unsigned int Hall::getFreeSeats(Event& event, Date date) {
	int index = 0;
	bool isCorrectEvent = false;
	int result = 0;
	for (int i = 0; i < events.size(); i++) {
		if (event.getName() == events[i].getName() && event.getDate() == date) {
			isCorrectEvent = true;
			index = i;
		}
	}
	if (isCorrectEvent) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				
			}
		}
	}
}

unsigned int** Hall::getSeats() const {
	return this->seats;
}

void Hall::setSeatsForEvent(Event& _event) {
}

Hall::~Hall() {
	for (int i = 0; i < rows; i++) {
		delete[] seats[i];
	}
	delete[] seats;
}

