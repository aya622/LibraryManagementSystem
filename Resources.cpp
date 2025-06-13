#include "Resources.h"
#include <iostream>
#include<string>
using namespace std;

Resources::Resources(string id, string t,string a, int year, string type, string cat): resourceID(id), title(t), author(a), publicationYear(year), isAvailable(true), resourceType(type), category(cat) {}

void Resources::displayDetails() const {
    cout << "ID: " << resourceID << "\nTitle: " << title << "\nAuthor: " << author << "\nYear: " << publicationYear << "\nAvailable: " << (isAvailable ? "Yes" : "No") << "\nType: " << resourceType << "\nCategory: " << category <<endl;
}

bool Resources::checkAvailability() const { return isAvailable; }
void Resources::setAvailability(bool available) { isAvailable = available; }
int Resources::getID() const { return resourceID; }
string Resources::getType() const { return resourceType; }
string Resources::getTitle() const { return title; }
string Resources::getAuthor() const { return author; }
string Resources::getCategory() const { return category; }