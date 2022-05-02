#include "Date.h"


//sets the date to 01.01.2000
Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(unsigned int _day, unsigned int _month, unsigned int _year) {
	try {
		setDay(_day);
		setMonth(_month);
		setYear(_year);
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

unsigned int Date::getDay() const {
	return this->day;
}

unsigned int Date::getMonth() const {
	return this->month;
}

unsigned int Date::getYear() const {
	return this->year;
}

void Date::setYear(unsigned int _year) {
	this->year = _year;
}

void Date::setMonth(unsigned int _month) {
	if (_month < 12 && _month > 0)
		this->month = _month;
	else
		throw std::invalid_argument("invalid month");
}

void Date::setDay(unsigned int _day) {
	if (_day < 32 && _day > 0)
		this->day = _day;
	else
		throw std::invalid_argument("invalid day");
}

void Date::printDate() const {
	std::cout << getDay() << " " << getMonth() << " " << getYear() << '\n';
}