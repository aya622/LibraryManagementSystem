#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <ctime>
using namespace std;

class Reservation {
private:
    string reservationID;
    string userID;
    string resourceID;
    time_t requestTime;

public:
    Reservation(const string& rid, const string& uid, const string& resID);

    string getReservationID() const { return reservationID; }
    string getResourceID() const { return resourceID; }
    string getUserID() const { return userID; }

    bool isEligible(const Resource* res) const;
};

#endif // RESERVATION_H