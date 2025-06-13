#include "DigitalContent.h"
#include <iostream>
#include<string>
using namespace std;

DigitalContent::DigitalContent(int id, const string& title, const string& author, int year, const string& cat, const string& fmt, const string& link, int size): Resources(id, title, author, year, "DigitalContent", cat), format(fmt), url(link), fileSizeMB(size) {}

void DigitalContent::displayDetails() const {
    Resources::displayDetails();
    cout << "Format: " << format << "\nURL: " << url << "\nFile Size: " << fileSizeMB << " MB" << endl;
}