#include "Book.h"

using namespace std;

Book::Book(string t, string a, string c, bool status)
    : title(t), author(a), category(c), isBorrowed(status) {
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getCategory() const { return category; }
bool Book::getStatus() const { return isBorrowed; }

void Book::borrow() { isBorrowed = true; }
void Book::returnBook() { isBorrowed = false; }

void Book::display(int index) const {
    cout << setw(4) << index << " | "
        << setw(10) << left << category << " | "
        << setw(20) << left << title << " | "
        << setw(15) << left << author << " | "
        << (isBorrowed ? "借出" : "可借") << endl;
}

string Book::toString() const {
    return category + "," + title + "," + author + "," + (isBorrowed ? "1" : "0");
}