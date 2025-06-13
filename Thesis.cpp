#include "Thesis.h"
#include <iostream>
#include<string>
using namespace std;

Thesis::Thesis(int id, const string& title, const string& author, int year, const string& cat, const string& uni, const string& degree, const string& adv, const vector<string>& keys) : Resources(id, title, author, year, "Thesis", cat), university(uni), degreeType(degree), advisor(adv), keywords(keys) {}
string Thesis::getTitle() const {
    return title + " (" + degreeType + " Thesis)";
}
void Thesis::displayDetails() const {
    Resources::displayDetails();
    cout << "University: " << university << "\nDegree Type: " << degreeType << "\nAdvisor: " << advisor << "\nKeywords: ";
    for (const auto& k : keywords) cout << k << " ";
    cout << endl;
}