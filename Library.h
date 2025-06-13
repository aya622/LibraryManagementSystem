#include "Resources.h"
#include "user.h"
#include "Loan.h"
#include <vector>
#include <memory>
using namespace std;

class Library {
    vector<unique_ptr<Resources>> resources;
    vector<unique_ptr<User>> users;
    vector<unique_ptr<Loan>> activeLoans;

public:
    void addResource(unique_ptr<Resources> res);
    Resources* findResource(const string& id);
    void addUser(unique_ptr<User> user);
    User* findUser(const string& id);
    bool borrowResource(const string& userID, const string& resourceID);
    void displayAllResources() const;
    bool returnResource(const string& userID, const string& resourceID);
    //searching
    vector<Resources*> searchByTitle(const string& keyword);
    vector<Resources*> searchByAuthor(const string& keyword);
    vector<Resources*> filterByCategory(const string& category);
    vector<Resources*> filterByAvailability(bool available);
};