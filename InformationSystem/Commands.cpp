#include "Commands.h"

// Implementation of the functions and constructors in the Commands.h


void Commands::loadTickets() {

	myFile.open("tickets.txt");
	if (myFile.is_open()) 
		std::cout << "Tickets file opened successfully" << '\n';
	

	std::string performanceName = "";
	Date date;
	unsigned int ticketStatus = 0;
	std::string ticketPassword = "";
	std::string ticketNote = "";
	std::string line = "";
	std::string column = "";

	while (std::getline(myFile, line)) {
		std::stringstream ss(line);
		int counter = 0;
		while (std::getline(ss, column, ',')) {
			if (counter == 0) {
				performanceName = column;
			}
			else if (counter == 1) {
				date = column;
			}
			else if (counter == 2) {
				ticketStatus = std::stoi(column);
			}
			else if (counter == 3) {
				ticketPassword = column;
			}
			else if (counter == 4) {
				ticketNote = column;
			}
			else {
				break;
			}
			counter++;
		}
		Ticket ticket(performanceName, date, ticketStatus, ticketPassword, ticketNote);
		tickets.push_back(ticket);
	}
	myFile.close();
}

void Commands::loadHalls() {

	myFile.open("halls.txt");
	if (myFile.is_open())
		std::cout << "Halls file opened successfully" << '\n';

	std::string column = "";
	std::string line = "";
	unsigned int hallNumber = 0;
	unsigned int hallRows = 0;
	unsigned int hallColumns = 0;

	while (std::getline(myFile, line)) {
		std::stringstream ss(line);
		int counter = 0;
		while (std::getline(ss, column, ',')) {
			if (counter == 0) {
				hallNumber = std::stoi(column);
			}
			else if (counter == 1) {
				hallRows = std::stoi(column);
			}
			else if (counter == 2) {
				hallColumns = std::stoi(column);
			}
			else {
				break;
			}
			counter++;
		}
		Hall hall(hallNumber, hallRows, hallColumns);
		halls.push_back(hall);
	}
	myFile.close();
}

void Commands::loadEvents() {
	myFile.open("events.txt");
	if (myFile.is_open()) {
		std::cout << "Events file opened successfully\n";
	}

	std::string column = "";
	std::string line = "";
	std::string performanceName = "";
	unsigned int eventIdHall = 0;
	Date date;
	while (std::getline(myFile, line)) {
		int counter = 0;
		std::stringstream ss(line);
		while (std::getline(ss, column, ',')) {
			if (counter == 0) {
				performanceName = column;
			}
			else if (counter == 1) {
				eventIdHall = std::stoi(column);
			}
			else if (counter == 2) {
				date = column;
			}
			else
				break;
			counter++;
		}
		Event e(performanceName, eventIdHall, date);
		for (int i = 0; i < halls.size(); i++) {
			if (halls[i].getId() == eventIdHall)
				e.setSeats(halls[i].getRows(), halls[i].getColumns());
		}
		events.push_back(e);
	}
	myFile.close();
}


//_date needs to be in format yyyy-mm-dd
void Commands::addEvent(std::string _name, std::string _id, std::string _date) {
	myFile.open("events.txt", std::ios_base::out | std::ios_base::trunc);
	bool isCorrectId = false;
	bool isTaken = false;
	int rows = 0;
	int columns = 0;
	for (int i = 0; i < halls.size(); i++) {
		if (std::stoi(_id) == halls[i].getId()) {
			isCorrectId = true;
			rows = halls[i].getRows();
			columns = halls[i].getColumns();
			break;
		}
	}
	if (isCorrectId) {
		for (int i = 0; i < events.size(); i++) {
			if (std::stoi(_id) == events[i].getId()) {
				if (events[i].getDate().toString() == _date)
					isTaken = true;
			}
		}
	}
	else {
		myFile.close();
		throw std::invalid_argument("hall doesnt exist");
	}
	if (!isTaken) {
		Event e(_name, std::stoi(_id), _date);
		events.push_back(e);
		e.setSeats(rows, columns);
		for (Event tempEvent : events) {
			myFile << tempEvent.getName() << "," << tempEvent.getId() << ',' <<  tempEvent.getDate().toString() << '\n';
		}
		myFile.close();
	}
	else {
		myFile.close();
		throw std::invalid_argument("date is already taken");
	}
}

void Commands::checkFreeSeats(std::string _name, std::string _date) {
	for (Event &e : events) {
		std::cout << e.getName() << "," << e.getDate().toString() << '\n';
		if(e.getName() == _name && e.getDate().toString() == _date)
			for (int i = 0; i < e.getSize(); i++) {
				if (e.getSeats()[i] == 0)
					std::cout << i + 1 << '\n';
			}
	}
	std::cout << '\n';
}


void Commands::reserveATicket(std::string _name, std::string _date, std::string _row, std::string place, std::string _password, std::string _note) {
	myFile.open("tickets.txt", std::ios_base::out | std::ios_base::trunc);
	int columns = 0;
	for (Event& e : events) {
		if (e.getName() == _name && e.getDate().toString() == _date) {
			for (Hall& h : halls) {
				if (e.getId() == h.getId())
					columns = h.getColumns();
			}
			if (e.getSeats()[(std::stoi(_row) * columns) + std::stoi(place)] == 0) {
				Ticket t(_name, _date, 1, _password, _note);
				tickets.push_back(t);
			}
			else {
				std::cout << "seat is already taken" << '\n';
			}
			for (Ticket& ticket : tickets) {
				myFile << ticket.getPerformance() << "," 
					<< ticket.getDate().toString() << "," 
					<< ticket.getStatus() << "," 
					<< ticket.getPassword() << "," 
					<< ticket.getNote() << '\n';
			}
		}
		else {
			myFile.close();
			throw "date or performance name is wrong";
		}
	}
	myFile.close();
}

void Commands::removeReservation(std::string _name, std::string _date, std::string _password) {
	myFile.open("tickets.txt", std::ios_base::out | std::ios_base::trunc);
	std::vector<Ticket> temp;
	for (Ticket& t : tickets) {
		if (t.getPerformance() == _name && t.getDate().toString() == _date && t.getPassword() == _password) {
			std::cout << "Removed!" << '\n';
			continue;
		}
		else {
			temp.push_back(t);
		}
	}
	for (Ticket& ticket : temp) {
		myFile << ticket.getPerformance() << ","
			<< ticket.getDate().toString() << ","
			<< ticket.getStatus() << ","
			<< ticket.getPassword() << ","
			<< ticket.getNote() << '\n';
	}
	myFile.close();
}
