#include <string>
#include <ctime> // For time_t
#ifndef LOAN_H
#define LOAN_H
using namespace std;

class Loan {
private:
    string loanID;
    string resourceID;  // ID of the borrowed resource (Book, Article, etc.)
    string userID;      // ID of the user who borrowed it
    time_t dueDate;          // When the resource must be returned
    bool isOverdue;          // True if the due date has passed

public:
    Loan(std::string lid, std::string rid, std::string uid, time_t due);
    
    // Getters
    string getLoanID() const;
    string getResourceID() const;
    string getUserID() const;
    time_t getDueDate() const;
    bool getIsOverdue() const;

    // Business logic
    bool checkOverdue() const;
};
#endif