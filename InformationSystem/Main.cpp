#include "Commands.h"

int main() {
	try {
		Commands c;
		c.loadHalls();
		c.loadTickets();
		std::string line = "";
		while (std::getline(std::cin, line)) {
			std::string command;
			std::stringstream ss(line);
			std::getline(ss, command, ' ');
			if (command == "add") {
				std::getline(ss, command, ' ');
				std::string performanceName = command;
				std::getline(ss, command, ' ');
				std::string hallId = command;
				std::getline(ss, command, ' ');
				std::string date = command;
				c.addEvent(performanceName, hallId, date);
			}
			else if (command == "check") {
				std::getline(ss, command, ' ');
				std::string performanceName = command;
				std::getline(ss, command, ' ');
				std::string date = command;
				c.checkFreeSeats(performanceName, date);
			}
			else if (command == "reserve") {
				std::getline(ss, command, ' ');
				std::string performanceName = command;
				std::getline(ss, command, ' ');
				std::string date = command;
				std::getline(ss, command, ' ');
				std::string row = command;
				std::getline(ss, command, ' ');
				std::string place = command;
				std::getline(ss, command, ' ');
				std::string password = command;
				std::getline(ss, command, ' ');
				std::string note = command;
				c.reserveATicket(performanceName, date, row, place, password, note);
			}
			else if (command == "remove") {
				std::getline(ss, command, ' ');
				std::string name = command;
				std::getline(ss, command, ' ');
				std::string date = command;
				std::getline(ss, command, ' ');
				std::string password = command;
				c.removeReservation(name, date, password);
			}
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}