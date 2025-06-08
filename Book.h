#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Book {
private:
    string title;
    string author;
    string category;
    bool isBorrowed;

public:
    Book(string t = "", string a = "", string c = "", bool status = false);

    string getTitle() const;
    string getAuthor() const;
    string getCategory() const;
    bool getStatus() const;

    void borrow();
    void returnBook();

    void display(int index) const;
    string toString() const;
};

#endif