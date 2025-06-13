#ifndef RESOURCES_H
#define RESOURCES_H
#include<string> 
using namespace std;
class Resources {
    protected:

    int resourceID;
    string title;
    string author;
    int publicationYear;
    bool isAvailable;
    string resourceType;
    string category;

    public:
     Resources(int id, string t, string a, int year, string type, string cat);
     virtual ~Resources() = default;
     virtual void displayDetails() const;
     bool checkAvailability() const;
     void setAvailability(bool available);
     string getID() const;
     string getType() const;
     virtual string getTitle() const;
     virtual string getAuthor() const;
     virtual string getCategory() const;
       
};

#endif