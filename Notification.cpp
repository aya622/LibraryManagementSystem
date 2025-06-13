#include "Notification.h"
#include <iostream>
#include <ctime>
using namespace std;

Notification::Notification(const string& uid, const string& msg) : userID(uid), message(msg), timestamp(time(nullptr)), isRead(false) {}

void Notification::display() const {
    cout << "[ " << (isRead ? "READ" : "NEW") << " ] "
              << ctime(&timestamp) << ": " << message << endl;
}