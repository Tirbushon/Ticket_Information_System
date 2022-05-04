#include "Date.h"
#include "Event.h"
#include "Hall.h"

int main() {
	Date date(21, 2, 2022);
	Event event("Krasavicata i zvqra", 1, date);
	Hall hall(3, 4, 1);
	hall.addEvent(event);
	hall.printEvents();
	std::cout << "---------adding another event -----------\n";
	Date date1(20, 3, 2980);
	Event event2("Mn dobre", 1, date1);
	hall.addEvent(event2);
	hall.printEvents();
	std::cout << "---------adding another event -----------\n";
	Date date2(21, 2, 2022);
	Event event3("Oshte po dobre", 1, date2);
	hall.addEvent(event3);
	return 0;
}