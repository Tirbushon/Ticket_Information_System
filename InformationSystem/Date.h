#pragma once
#include <iostream>
#include <stdexcept>

//add validations for leap year and even or odd months

class Date
{
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	//add hour ??
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	void printDate() const;
};

