#pragma once
#include "Event.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

class Hall
{
private:
	int id = 0;
	unsigned int rows;
	unsigned int columns;
	unsigned int** seats;
	Event* events;
public:
	Hall();
	Hall(unsigned int, unsigned int);
	Hall& operator=(const Hall&);
	Hall(const Hall&);
	int getId() const;
	~Hall();
};

