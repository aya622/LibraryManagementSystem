#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User {
    protected:
    int userID;
    string name;
    string email;
    int maxBorrowLimit;
    vector<string> currentLoans;
    public:
    User(int id, string n, string e, int limit);
    virtual ~User()=default;
    bool canBorrow() const;
    void borrowResource(const string& resourceID);
    void returnResource(const string& resourceID);
    int getID() const;

};
#endif