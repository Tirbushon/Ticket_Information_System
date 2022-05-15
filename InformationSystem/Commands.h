#pragma once
#include "Hall.h"

//Commands class representing the commands used in the console application
//@myFile - used for opening the files with the respective information
//@halls - a vector used to contain all the halls information from its file
//@events - a vector used to contain all the events information from its file
//@tickets - a vector used to contain all the tickets information from its file

class Commands
{
private:
	std::fstream myFile;
	std::vector<Hall> halls;
	std::vector<Event> events;
	std::vector<Ticket> tickets;
public:
	//opens a file with tickets and fills the tickets vector
	//file name is "tickets.txt"
	//format is name,date,status,password,note 
	//(check Ticket.h for more clarification for parameters explanation)
	void loadTickets();
	//opens the halls file and fills the halls vector
	//file name is "halls.txt"
	//its format is id,rows,columns 
	//(check Hall.h for more clarification)
	void loadHalls();
	//opens the events file and fills the events vector
	//file name is "events.txt"
	//its format is name,id,date 
	//(check Events.h for more clarification)
	void loadEvents();
	//adds an event from the console
	void addEvent(std::string, std::string, std::string);
	//checks which seats are empty(an event's seat's status is 0)
	void checkFreeSeats(std::string, std::string);
	//reserves a ticket(sets an event's seat's status to 1)
	//sets a password so that the client can buy the ticket after the reservation
	void reserveATicket(std::string, std::string, std::string, std::string, std::string, std::string);
	//removes a reservation(sets an event's seat's status to 0)
	//if the client enters the correct password it removes the reservation
	void removeReservation(std::string, std::string, std::string);
};

