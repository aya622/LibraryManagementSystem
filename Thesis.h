#ifndef THESIS_H
#define THESIS_H

#include "Resources.h"
#include <string>
#include <vector>
using namespace std;

class Thesis : public Resources {
private:
    string university;
    string degreeType;
    string advisor;
    vector<string> keywords;

public:
    Thesis(int id, const string& title, const string& author,
           int year, const string& cat, const string& uni,
           const string& degree, const string& adv, const vector<string>& keys);

    void displayDetails() const override;
    string getTitle() const override;
    string getUniversity() const { return university; }
};

#endif // THESIS_H