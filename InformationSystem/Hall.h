#pragma once
#include "Event.h"
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>



class Hall
{
private:
	int id = 0;
	unsigned int rows;
	unsigned int columns;
	unsigned int** seats;
	std::vector<Event> events;
public:
	Hall();
	Hall(unsigned int, unsigned int);
	Hall& operator=(const Hall&);
	Hall(const Hall&);
	int getId() const;
	~Hall();
};

