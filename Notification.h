#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>
#include <ctime>
using namespace std;

class Notification {
private:
    string userID;
    string message;
    time_t timestamp;
    bool isRead;

public:
    Notification(const string& uid, const string& msg);

    void display() const;
    void markAsRead() { isRead = true; }
    bool getIsRead() const { return isRead; }
};

#endif // NOTIFICATION_H