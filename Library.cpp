#include "library.h"
using namespace std;

void Library::addResource(unique_ptr<Resources> res) {
    resources.push_back(move(res));
}

Resources* Library::findResource(const string& id) {
    for (auto& res : resources) {
        if (res->getID() == id) return res.get();
    }
    return nullptr;
}
void Library::addUser(unique_ptr<User> user) {
    users.push_back(move(user));
}

User* Library::findUser(const string& id) {
    for (auto& user : users) {
        if (user->getID() == id) return user.get();
    }
    return nullptr;
}

bool Library::borrowResource(const string& userID, const string& resourceID) {
    User* user = findUser(userID);
    Resource* res = findResource(resourceID);
    if (!user || !res || !res->checkAvailability() || !user->canBorrow()) return false;
    
    // Loan logic here (simplified)
    res->setAvailability(false);
    user->borrowResource(resourceID);
    return true;
}
void Library::displayAllResources() const {
    cout << "\n All Resources \n";
    for (const auto& res : resources) {
        res->displayDetails();
        cout << "\n";
    }
}
bool Library::returnResource(const string& userID, const string& resourceID) {
    User* user = findUser(userID);
    Resource* res = findResource(resourceID);

    if (!user || !res || res->checkAvailability()) {
        return false;
    }

    res->setAvailability(true);
    user->returnResource(resourceID);
    return true;
}
vector<Resources*> Library::searchByTitle(const string& keyword) {
    vector<Resource*> results;
    for (auto& res : resources) {
        if (res->getTitle().find(keyword) != string::npos) {
            results.push_back(res.get());
        }
    }
    return results;
}
vector<Resources*> Library::searchByAuthor(const string& keyword) {
    vector<Resource*> results;
    for (auto& res : resources) {
        if (res->getAuthor().find(keyword) != string::npos) {
            results.push_back(res.get());
        }
    }
    return results;
}
vector<Resources*> Library::filterByCategory(const string& category) {
    vector<Resource*> results;
    for (auto& res : resources) {
        if (res->getCategory() == category) {
            results.push_back(res.get());
        }
    }
    return results;
}
vector<Resources*> Library::filterByAvailability(bool available) {
    vector<Resource*> results;
    for (auto& res : resources) {
        if (res->checkAvailability() == available) {
            results.push_back(res.get());
        }
    }
    return results;
}