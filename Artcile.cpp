#include "Article.h"
#include <iostream>
#include<string>
using namespace std;

Article::Article(int id, const string& title, const string& author, int year, const string& cat, const string& doiVal, const string& journal, int vol, int iss, const string& abstr) : Resources(id, title, author, year, "Article", cat), doi(doiVal), journalName(journal), volume(vol), issue(iss), abstractText(abstr) {}

void Article::displayDetails() const {
    Resources::displayDetails();
    cout << "DOI: " << doi << "\nJournal: " << journalName << "\nVolume: " << volume << "\nIssue: " << issue << "\nAbstract: " << abstractText << endl;
}
    string Article::getDOI() const { return doi; }
    string Article::getJournalName() const { return journalName; }
    string Article::getTitle() const {
    return title + " (" + journalName + ")"; // Include journal name
}