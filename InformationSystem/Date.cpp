#include "Date.h"

// Implementation of the functions and constructors in the Date.h

Date::Date() {
	day = "";
	month = "";
	year = "";
}

Date::Date(std::string fullDate) {
	if (std::stoi(fullDate.substr(8, 2)) > 0 &&
		std::stoi(fullDate.substr(8, 2)) < 32 &&
		std::stoi(fullDate.substr(5, 2)) > 0 &&
		std::stoi(fullDate.substr(5, 2)) < 13
		&& std::stoi(fullDate.substr(0, 4)) >= 1980 &&
		std::stoi(fullDate.substr(0, 4)) < 3000) {

		this->day = fullDate.substr(8, 2);
		this->month = fullDate.substr(5, 2);
		this->year = fullDate.substr(0, 4);
	}
	else {
		this->day = "";
		this->month = "";
		this->year = "";
	}
}

std::string Date::toString() {
	return year + "-" + month + "-" + day;
}

void Date::printDate() {
	std::cout << this->year << "-" << this->month << "-" << this->day;
}

bool Date::checkDate() {
	// months with 31 days //
	if (this->month == "01" || this->month == "03" || this->month == "05" || this->month == "07" || this->month == "8" || this->month == "10" || this->month == "12") {
		return true;
	}
	// months with 30 days //
	else if (this->month == "04" || this->month == "06" || this->month == "09" || this->month == "11") {
		if (this->day == "31") {
			return false;
		}
		else {
			return true;
		}
	}
	// february //
	else if (this->month == "2") {
		if (std::stoi(this->year) % 4 == 0) {
			if (std::stoi(this->day) > 29) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			if (std::stoi(this->day) > 28) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	else if (this->day == "" || this->month == "" || this->year == "") {
		return false;
	}
	else {
		return false;
	}
}

