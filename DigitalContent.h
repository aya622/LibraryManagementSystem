#ifndef DIGITALCONTENT_H
#define DIGITALCONTENT_H

#include "Resources.h"
#include <string>
using namespace std;

class DigitalContent : public Resources {
private:
    string format; // e.g., PDF, MP4
    string url;
    int fileSizeMB;

public:
    DigitalContent(int id, const string& title, const string& author, int year, const string& cat, const string& fmt, const string& link, int size);

    void displayDetails() const override;

    string getFormat() const { return format; }
};

#endif // DIGITALCONTENT_H