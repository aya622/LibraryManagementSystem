#ifndef BOOK_H
#define BOOK_H
#include "Resources.h"
#include <string>
using namespace std ;
class Book : public Resources {
    protected:
    string ISBN;
    string publisher;
    int edition;
    int numPages;
    public:
    Book(int id, string t, string a, int year, string type, string cat, string isbn, string pub, int ed, int pages);
    void displayDetails() const override ;
    string getTitle() const override;
    string getAuthor() const override;
};
#endif
