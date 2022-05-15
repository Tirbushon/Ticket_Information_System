#pragma once
#include "Event.h"

//A simple hall class representing a hall
//@id - number of hall
//@rows - number of rows in the hall
//@columns - number of columns in the hall

class Hall
{
private:
	unsigned int id;
	unsigned int rows;
	unsigned int columns;
public:
	Hall(unsigned int, unsigned int, unsigned int);
	unsigned int getId() const;
	unsigned int getRows() const;
	unsigned int getColumns() const;
};

