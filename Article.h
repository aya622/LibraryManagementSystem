#ifndef ARTICLE_H
#define ARTICLE_H
#include "Resources.h"
#include <string>
using namespace std;

class Article : public Resources {
private:
    string doi;
    string journalName;
    int volume;
    int issue;
    string abstractText;

public:
    Article(int id, const string& title, const string& author,
            int year, const string& cat, const string& doi,
            const string& journal, int vol, int iss, const string& abstr);

    void displayDetails() const override;
    
    // Getters
    string getDOI() const { return doi; }
    string getJournalName() const { return journalName; }
    string getTitle() const override;

};

#endif