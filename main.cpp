#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Library.h"
#include "Book.h"
#include "Article.h"
#include "Thesis.h"
#include "DigitalContent.h"
#include "User.h"

using namespace std;

int main() {
    Library library;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. Add Article\n";
        cout << "3. Add Thesis\n";
        cout << "4. Add Digital Content\n";
        cout << "5. Register User\n";
        cout << "6. Borrow Resource\n";
        cout << "7. Return Resource\n";
        cout << "8. Search Resources by Title\n";
        cout << "9. Filter Resources by Category\n";
        cout << "10. View All Resources\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                // Add Book
                int id, year, edition, pages;
                string title, author, isbn, publisher, category;
                cout << "Enter Book ID: "; cin >> id;
                cout << "Title: "; cin.ignore(); getline(cin, title);
                cout << "Author: "; getline(cin, author);
                cout << "Publication Year: "; cin >> year;
                cout << "ISBN: "; cin >> isbn;
                cout << "Publisher: "; cin >> publisher;
                cout << "Edition: "; cin >> edition;
                cout << "Number of Pages: "; cin >> pages;
                cout << "Category: "; cin >> category;

                auto book = make_unique<Book>(id, title, author, year, "Book", category, isbn, publisher, edition, pages);
                library.addResource(move(book));
                cout << "Book added successfully!\n";
                break;
            }

            case 2: {
                 // Add Article
             int id, year;
             string title, author, doi, journal, category;
             cout << "Enter Article ID: "; cin >> id;
             cout << "Title: "; cin.ignore(); getline(cin, title);
             cout << "Author: "; getline(cin, author);
             cout << "Publication Year: "; cin >> year;
             cout << "DOI: "; cin >> doi;
             cout << "Journal Name: "; cin >> journal;
             cout << "Category: "; cin >> category;

             auto article = make_unique<Article>(id, title, author, year, category, doi, journal);
             library.addResource(move(article));
             cout << "Article added successfully!\n";
             break;
            }

            case 3: {
                // Add Thesis
                int id, year;
                string title, author, uni, degree, advisor, category;
                vector<string> keywords;
                cout << "Enter Thesis ID: "; cin >> id;
                cout << "Title: "; cin.ignore(); getline(cin, title);
                cout << "Author: "; getline(cin, author);
                cout << "Publication Year: "; cin >> year;
                cout << "University: "; cin >> uni;
                cout << "Degree Type: "; cin >> degree;
                cout << "Advisor: "; cin >> advisor;
                cout << "Category: "; cin >> category;

                cout << "Enter keywords (type 'done' to finish): ";
                string keyword;
                while (cin >> keyword && keyword != "done") {
                    keywords.push_back(keyword);
                }

                auto thesis = make_unique<Thesis>(id, title, author, year, category, uni, degree, advisor, keywords);
                library.addResource(move(thesis));
                cout << "Thesis added successfully!\n";
                break;
            }

            case 4: {
                // Add Digital Content
                int id, fileSizeMB, year;
                string title, author, format, url, category;
                cout << "Enter Digital Content ID: "; cin >> id;
                cout << "Title: "; cin.ignore(); getline(cin, title);
                cout << "Author: "; getline(cin, author);
                cout << "Publication Year: "; cin >> year;
                cout << "Format (PDF/MP4/etc): "; cin >> format;
                cout << "URL: "; cin >> url;
                cout << "File Size (in MB): "; cin >> fileSizeMB;
                cout << "Category: "; cin >> category;

                auto digital = make_unique<DigitalContent>(id, title, author, year, category, format, url, fileSizeMB);
                library.addResource(move(digital));
                cout << "Digital content added successfully!\n";
                break;
            }

            case 5: {
                // Register User
                int id, limit;
                string name, email;
                cout << "Enter User ID: "; cin >> id;
                cout << "Name: "; cin.ignore(); getline(cin, name);
                cout << "Email: "; getline(cin, email);
                cout << "Max Borrow Limit: "; cin >> limit;

                auto user = make_unique<User>(id, name, email, limit);
                library.addUser(move(user));
                cout << "User registered successfully!\n";
                break;
            }

            case 6: {
                // Borrow Resource
                string userID, resID;
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Resource ID: ";
                cin >> resID;

                if(library.borrowResource(userID, resID)) {
                    cout << "Borrow successful!\n";
                } else {
                    cout << "Failed to borrow. Check availability or limit.\n";
                }
                break;
            }

            case 7: {
                // Return Resource
                string userID, resID;
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Resource ID: ";
                cin >> resID;
                library.returnResource(userID, resID);
                cout << "Returned successfully!\n";
                break;
            }

            case 8: {
                // Search by Title
                string keyword;
                cout << "Enter search keyword (title): ";
                cin.ignore(); getline(cin, keyword);

                vector<Resources*> results = library.searchByTitle(keyword);
                cout << "\nSearch Results:\n";
                for (auto res : results) {
                    res->displayDetails();
                    cout << "----------------------\n";
                }
                break;
            }

            case 9: {
                // Filter by Category
                string category;
                cout << "Enter category (e.g., Programming, Science): ";
                cin >> category;

                vector<Resources*> results = library.filterByCategory(category);
                cout << "\nFiltered Results:\n";
                for (auto res : results) {
                    res->displayDetails();
                    cout << "----------------------\n";
                }
                break;
            }

            case 10: {
                // Display All Resources
                library.displayAllResources();
                break;
            }

            case 11:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 11);

    return 0;
}