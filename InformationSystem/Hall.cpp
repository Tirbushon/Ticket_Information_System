#include "Hall.h"

Hall::Hall(unsigned int _rows, unsigned int _columns) {
	assert(_rows > 0 && _columns > 0);
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

Hall::~Hall() {
	for (int i = 0; i < rows; i++) {
		delete[] seats[i];
	}
	delete[] seats;
}

