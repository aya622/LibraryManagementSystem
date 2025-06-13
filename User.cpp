#include "User.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

User::User(int id, string n,string e, int limit)
    : userID(id), name(n), email(e), maxBorrowLimit(limit) {}

bool User::canBorrow() const { return currentLoans.size() < maxBorrowLimit; }

void User::borrowResource(const std::string& resourceID) {
    if (canBorrow())
     currentLoans.push_back(resourceID);
}

void User::returnResource(const std::string& resourceID) {
    for (auto it = currentLoans.begin(); it != currentLoans.end(); ++it) {
        if (*it == resourceID) {
            currentLoans.erase(it);
            break;
        }
    }
}
int User::getID() const { return userID; }