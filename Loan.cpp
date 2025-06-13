#include "loan.h"
#include <ctime>
#include <cmath> // For ceil() in fine calculation

Loan::Loan(string lid, string rid, string uid, time_t due) : loanID(lid), resourceID(rid), userID(uid), dueDate(due), isOverdue(false) {}

// --- Getters ---
string Loan::getLoanID() const { return loanID; }
string Loan::getResourceID() const { return resourceID; }
string Loan::getUserID() const { return userID; }
time_t Loan::getDueDate() const { return dueDate; }
bool Loan::getIsOverdue() const { return isOverdue; }

// --- Business Logic ---
bool Loan::checkOverdue() const {
    time_t now = time(nullptr);
    isOverdue = (now > dueDate);
    return isOverdue;
}
