#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

using namespace std;

class Member {
private:
    string name;
    int memberId;
    bool isVIP;
    vector<string> borrowedTitles;

public:
    Member(string n = "", int id = 0, bool vip = false);

    string getName() const;
    int getId() const;
    bool getVIP() const;
    const vector<string>& getBorrowedList() const;

    bool borrowBook(const string& title);
    bool returnBook(const string& title);

    string toString() const;
    void display() const;
};

#endif