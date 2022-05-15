#include "Hall.h"

//Implementation of the functions and constructors in the Hall.h

Hall::Hall(unsigned int _id, unsigned int _rows, unsigned int _columns) {
	assert(_rows > 0 && _columns > 0);
	this->id = _id;
	this->rows = _rows;
	this->columns = _columns;
}

unsigned int Hall::getId() const {
	return this->id;
}

unsigned int Hall::getRows() const {
	return this->rows;
}

unsigned int Hall::getColumns() const {
	return this->columns;
}