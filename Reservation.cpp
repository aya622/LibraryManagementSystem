#include "Reservation.h"
#include <string>
using namespace std;

Reservation::Reservation(const string& rid, const string& uid, const string& resID) : reservationID(rid), userID(uid), resourceID(resID), requestTime(time(nullptr)) {}

bool Reservation::isEligible(const Resource* res) const {
    return res && !res->checkAvailability();
}