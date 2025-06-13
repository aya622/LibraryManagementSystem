#include "Book.h"
#include<string>
#include<iostream>
using namespace std;
Book::Book(int id, string t, string a, int year, string type, string cat, string isbn, string pub, int ed, int pages) : Resources(id, t, a, year, type, cat), ISBN(isbn), publisher(pub), edition(ed), numPages(pages) {}
void Book::displayDetails() const {
    Resources::displayDetails();
    cout << "ISBN: " << ISBN << "\nPublisher: " << publisher << "\nEdition: " << edition <<"\nNumber of pages: " << numPages << endl;
}
string Book::getTitle() const {
    return "📘 " + title; 
}

string Book::getAuthor() const {
    return author; 
}