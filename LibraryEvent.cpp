#include "LibraryEvent.h"
#include <iostream>
#include <ctime>
#include<string>
using namespace std;

LibraryEvent::LibraryEvent(const string& t, const string& d, time_t start, time_t end, const string& loc) : title(t), description(d), startTime(start), endTime(end), location(loc) {}

void LibraryEvent::display() const {
    cout << "Title: " << title << "\nDescription: " << description << "\nStart: " << ctime(&startTime) << "End: " << ctime(&endTime) << "Location: " << location << endl;
}