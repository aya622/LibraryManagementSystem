#ifndef LIBRARYEVENT_H
#define LIBRARYEVENT_H
#include<sting>
#include <string>
#include <ctime>
using namespace std;

class LibraryEvent {
private:
    string title;
    string description;
    time_t startTime;
    time_t endTime;
    string location;

public:
    LibraryEvent(const string& t, const string& d, time_t start, time_t end, const string& loc);
    void display() const;
};

#endif // LIBRARYEVENT_H